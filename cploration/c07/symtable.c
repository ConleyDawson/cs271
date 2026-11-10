/****************************************
 * C-ploration 7 for CS 271
 *
 * [NAME] Conley Dawson
 * [TERM] FALL 2026
 *
 ****************************************/
#include "symtable.h"
#include <string.h>

Symbol* hashArray[SYMBOL_TABLE_SIZE];

int hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        // hash * 33 + c
        hash = ((hash << 5) + hash) + c;
    }

    return hash % SYMBOL_TABLE_SIZE;
}

void symtable_insert(char *key, hack_addr addr) {
    Symbol *symbol = (Symbol*) malloc(sizeof(Symbol));
    symbol->name = strdup(key);
    symbol->address = addr;

    // Get the hash.
    int hashIndex = hash(key);

    // Move in array until an empty or deleted cell.
    while (hashArray[hashIndex] != NULL) {
        // Go to next cell
        ++hashIndex;

        // Wrap around the table.
        hashIndex %= SYMBOL_TABLE_SIZE;
    }

    hashArray[hashIndex] = symbol;
}

Symbol *symtable_find(char * key) {
    // Get the hash.
    int hashIndex = hash(key);

    // Move in array until empty.
    while (hashArray[hashIndex] != NULL) {
        if (strcmp(hashArray[hashIndex]->name, key) == 0) {
            return hashArray[hashIndex];
        }

        // Go to next cell.
        ++hashIndex;

        // Wrap around the table.
        hashIndex %= SYMBOL_TABLE_SIZE;
    }

    return NULL;
}
