#ifndef CODEWRITER_H
#define CODEWRITER_H
#include "Parser.h"
#include <stdlib.h>
#include <stdio.h>
// get the name of the output file
char* create_output_filename(const char* input_filename);


// 
void writeArithmetic(FILE* fp, const char* cmd);

//
void writePushPop(FILE* fp, CommandType type, const char* seg, int idx);

/*
* This function is called when processing the whole directory project
* where each file is a class file.
*/
char* setFileName(const char* fileName); 

/*
* Writes assembly code that effects the label command.
*/
void writeLabel(FILE* fp, const char* label);

/*
* Writes assembly code that effects the goto command.
*/
void writeGoto(FILE* fp, const char* label);

/*
* Write assembly code that effects the if-goto commnand.
*/
void writeIf(FILE* fp, const char* label);

/*
* Write assembly code that effects the function command.
*/
void writeFunction(FILE* fp, const char* functionName, int nVars);

/*
* Write assembly code that effects the call command.
*/
void writeCall(FILE* fp, const char* functionName, int nArgs);

/*
* Write assembly code that effects the return command;
*/
void writeReturn(FILE* fp);

#endif
