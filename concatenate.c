//
// Created by Arun on 10/13/2025.
//

#include "concatenate.h"

#include <stdio.h>

#include "digit.h"
#include "literal.h"

int match_next_class(RegexClass* curr_state, RegexClass* next_state, const char* input_string, const char* literal) {
    // make an empty transition to next state.
    // and then transition on the next automaton.

    switch (*next_state) {
        case DIGIT:
            switch (*curr_state) {
            case ANYWHERE: return digit_match_anywhere(next_state, input_string);
            default: return match_next_digit(next_state, input_string);
            }
        case LITERAL: if (!literal) return 0;
            switch (*curr_state) {
            case ANYWHERE: return match_literal_anywhere(next_state, input_string, *literal);
            default: return match_next_literal(next_state, input_string, *literal);
            }
        default: return 0;
    }
}

int concatenate(RegexClass* curr_state, RegexClass* next_state, const char* input_string, const char* literal) {
    switch (*curr_state) {
        case DIGIT_MATCHED:
            return match_next_class(curr_state, next_state, input_string, literal);
        case LITERAL_MATCHED:
            return match_next_class(curr_state, next_state, input_string, literal);
        case LITERAL:
        case DIGIT:
        default: return 0;
    }
}
