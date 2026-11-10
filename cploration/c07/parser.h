/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] Conley Dawson
 * [TERM] FALL 2026
 * 
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_LINE_LENGTH  200
#define MAX_LABEL_LENGTH  MAX_LINE_LENGTH - 2

typedef int16_t hack_addr;
typedef int16_t opcode;

enum instr_type {
    INVALID,
    A_TYPE,
    C_TYPE,
};

typedef struct c_instruction {
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;
} c_instruction;

typedef struct a_instruction {
    union location {
        hack_addr address;
        char label;
    } location;
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union instruction_content {
        a_instruction a_instruction;
        c_instruction c_instruction;
    } instruction_content;
    enum instr_type type;
} instruction;

/** function prototypes **/
char *strip(char *s);

void parse(FILE * file);

bool is_Atype(const char *s);

bool is_label(const char *s);

bool is_Ctype(const char *s);

char *extract_label(const char *line, char* label);
