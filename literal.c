//
// Created by Arun on 10/13/2025.
//

#include "literal.h"

#include <stdio.h>

// any character
int match_literal_anywhere(RegexClass* curr_state, const char* input_string, const char literal) {
    if (!*curr_state) *curr_state = LITERAL;
    while (*input_string) {
        switch (*curr_state) {
            case LITERAL: if (*input_string == literal) *curr_state = LITERAL_MATCHED; break;
            case LITERAL_MATCHED: break;
            default: ;
        }
        input_string++;
    }
    return *curr_state == LITERAL_MATCHED;
}

int match_next_literal(RegexClass* curr_state, const char* input_string, const char literal) {
    if (!input_string || *input_string == '\0') return 0;
    if (!*curr_state) *curr_state = LITERAL;
    switch (*curr_state) {
        case LITERAL: if (*input_string == literal) *curr_state = LITERAL_MATCHED; break;
        case LITERAL_MATCHED: break;
        default: ;
    }
    return *curr_state == LITERAL_MATCHED;
}

int rematch_next_literal(RegexClass* curr_state, const char* input_string, const char literal) {
    if (!input_string || *input_string == '\0') return 0;
    if (!*curr_state) *curr_state = LITERAL;
    switch (*curr_state) {
        case LITERAL_MATCHED:
        case LITERAL: if (*input_string == literal) *curr_state = LITERAL_MATCHED; break;
        default: ;
    }
    return *curr_state == LITERAL_MATCHED;
}
