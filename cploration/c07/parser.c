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

	while (fgets(line, sizeof(line), file)) {
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
		} else if (is_Ctype(line)) {
			inst_type = 'C';
		}
		printf("%c  %s\n", inst_type, line);
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
