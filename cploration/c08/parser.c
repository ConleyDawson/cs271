/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] Conley Dawson
 * [TERM] FALL 2026
 * 
 ****************************************/
#include "parser.h"
#include <stdbool.h>
#include <string.h>
#include "error.h"
#include "symtable.h"


/* Function: strip
 * -------------
 * remove whitespace and comments from a line
 *
 * s: the char* string to strip
 *
 * returns: the stripped char* string
 */
char *strip(char *s){	

	char s_new[strlen(s) + 1];
	unsigned int i = 0;

	for (char *s2 = s; *s2; s2++) {
		if (*s2 == '/' && *(s2+1) == '/') {
			break;
		} else if (!isspace(*s2)) {
			s_new[i++] = *s2;
		}
	}

	s_new[i] = '\0';

	strcpy(s, s_new);
	
    return s;	
}

/* Function: parse
 * -------------
 * iterate each line in the file and strip whitespace and comments. 
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 */
void parse(FILE * file){
	
	char line[MAX_LINE_LENGTH];
	unsigned int line_num = 0;
	unsigned int instr_num = 0;

	while (fgets(line, sizeof(line), file)) {
		line_num++;
		if (instr_num > MAX_INSTRUCTIONS) {
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
		}
		strip(line);
		if (!*line) continue;
		char inst_type = '\0';
		if (is_Atype(line)) {
			inst_type = 'A';
		} else if (is_label(line)) {
			inst_type = 'L';
			char label[MAX_LINE_LENGTH];
			extract_label(line, label);
			strcpy(line, label);
			symtable_insert(label, instr_num);
		} else if (is_Ctype(line)) {
			inst_type = 'C';
		}
		printf("%u: %c  %s\n", instr_num, inst_type, line);
	}


	
}

bool is_Atype(const char *line) {
	return (line[0] == '@');
}

bool is_label(const char *line) {
	int last = strlen(line) - 1;
	return (line[0] == '(' && line[last] == ')');
}

bool is_Ctype(const char *line) {
	return (!is_Atype(line) && !is_label(line));
}

char *extract_label(const char *line, char* label) {
	// copy the contents of line to label
	strcpy(label, line);
	// get the length of the label
	// for example, "(LABEL)" is 7
	int length = strlen(label);
	// remove the first character "(" by moving everything left 1
	for (int i = 0; i < length; i++) {
		label[i] = label[i + 1];
	}
	int last = strlen(label) - 1;
	// remove the last character ")"
	label[last] = '\0';

	return label;
}
