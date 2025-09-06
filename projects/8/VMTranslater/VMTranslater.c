#include "VMTranslater.h"
#include "Parser.h"
#include "CodeWriter.h"
#include <stdio.h>
#include <string.h>

void translate_code(const char *vm_code_file) {
	/*
	* Control the translation process 
	*
	*/

	// open the input vm file
	FILE* vmfp = fopen(vm_code_file, "r");

	// create the ouput asm filename
	const char* asm_code_file = create_output_filename(vm_code_file);
	FILE* asmfp = fopen(asm_code_file, "w");


	// start to parse the input file and write to ouput file
	char line[MAX_COMMAND_LENGTH];
	line[0] = '\0';

	while (fgets(line, sizeof(line), vmfp)) {
		
		// Get the command (the real command)
		line[strcspn(line, "\n")] = '\0'; // turn "\n" to '\0'
		
		// Remove comment 
		removeComment(line);

		// Skip empty line
		if (isEmptyLine(line)) {
			continue;
		}

		// Trim white spaces
		trimSpaces(line);

		char* arg1;
		arg1 = get_arg1(line);

		int arg2 = 0;

		CommandType type = commandType(line);

		// comment the original cmd

		fprintf(asmfp, "\n//%s\n", line);
		if (type == C_PUSH || type == C_POP) {
			arg2 = get_arg2(line);
			writePushPop(asmfp, type, arg1, arg2); 
		} else if (type == C_ARITHMETIC) {
			writeArithmetic(asmfp, arg1);	
		} else if (type == C_LABEL) {
			writeLabel(asmfp, arg1);
		} else if (type == C_GOTO) {
			writeGoto(asmfp, arg1);
		} else if (type == C_IF) {
			writeIf(asmfp, arg1);
		} 
		
	}

	// close in/out file
	fclose(asmfp);
	fclose(vmfp);
}


