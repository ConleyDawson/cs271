/****************************************
 * C-ploration 3 for CS 271
 * 
 * [NAME] Conley Dawson
 * [TERM] FALL 2026
 * 
 ****************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH  200

// "argc" is the number of arguments passed
// "argv[]" is a pointer to an array of strings
int main(int argc, const char *argv[])
{	
	// arg[0] is the name of the binary, so we don't care about it.
	// we need just one argument, arg[1]

	// check that the argc is 2 (the binary name and the one expected arg)
	if (argc != 2)
	{
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// pointer to our input file "fin" for "file in"
	// "r" indicates read-only mode
	FILE *fin = fopen(argv[1], "r");

	// make sure the file is not null
	if (fin == NULL)
	{
		perror("Unable to open file!");
		exit(EXIT_FAILURE);
	}

	// Output file name
	char out_file[MAX_LINE_LENGTH];
	// add input file name
	strcat(out_file, argv[1]);
	// add .echo extension
	strcat(out_file, ".echo");

	// Open the output file
	// "w+" indicates write and overwrite
	FILE *fout = fopen(out_file, "w+");

	return 1;
}
