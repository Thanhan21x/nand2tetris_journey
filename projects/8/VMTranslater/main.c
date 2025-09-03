#include "VMTranslater.h"


int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	const char* input_file = argv[1];
	
	translate_code(input_file);


	return 1;

}
