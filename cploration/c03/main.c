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

	return 1;
}
