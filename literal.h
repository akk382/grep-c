//
// Created by Arun on 10/13/2025.
//

#ifndef LITERAL_AUTOMATON_H
#define LITERAL_AUTOMATON_H

#include "regex_class.h"

// typedef enum LiteralState {
//     LITERAL_START, // START State
//     LITERAL_MATCHED // FINAL state
// } LiteralState;

int match_literal_anywhere(RegexClass*, const char*, char);
int match_next_literal(RegexClass*, const char*, char);
int rematch_next_literal(RegexClass*, const char*, char);

#endif //LITERAL_AUTOMATON_H
