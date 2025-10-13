//
// Created by Arun on 10/13/2025.
//

#include "digit.h"

#include <ctype.h>

// \d
int digit_match_anywhere(RegexClass* curr_state, const char* input_string) {
    if (!*curr_state) *curr_state = DIGIT;
    while (*input_string) {
        switch (*curr_state) {
            case DIGIT: if (isdigit(*input_string)) *curr_state = DIGIT_MATCHED; break;
            case DIGIT_MATCHED: break;
            default: ;
        }
        input_string++;
    }
    return *curr_state == DIGIT_MATCHED;
}

int match_next_digit(RegexClass* curr_state, const char* input_string) {
    if (!input_string || *input_string == '\0') return 0;
    if (!*curr_state) *curr_state = DIGIT;
    switch (*curr_state) {
        case DIGIT: if (isdigit(*input_string)) *curr_state = DIGIT_MATCHED; break;
        case DIGIT_MATCHED: break;
        default: ;
    }
    return *curr_state == DIGIT_MATCHED;
}

int rematch_next_digit(RegexClass* curr_state, const char* input_string) {
    if (!input_string || *input_string == '\0') return 0;
    if (!*curr_state) *curr_state = DIGIT;
    switch (*curr_state) {
        case DIGIT_MATCHED:
        case DIGIT: if (isdigit(*input_string)) *curr_state = DIGIT_MATCHED; break;
        default: ;
    }
    return *curr_state == DIGIT_MATCHED;
}