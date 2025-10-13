//
// Created by Arun on 10/13/2025.
//

#include "star.h"

#include "digit.h"
#include "literal.h"

int star(RegexClass* curr_class, const char* input_string, const char literal) {
    // start with accepted state
    // make epsilon transition to the next state's(=curr state, because *) start state
    // match the class with automaton
    // if accepted, make epsilon transition to the accepted state -> loop

    switch (*curr_class) {
        case DIGIT:
        case DIGIT_MATCHED:
            while (rematch_next_digit(curr_class, input_string)) input_string++;
            return 1;
        case LITERAL:
        case LITERAL_MATCHED:
            while (rematch_next_literal(curr_class, input_string, literal)) input_string++;
            return 1;
        default: return 0;
    }
}
