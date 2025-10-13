//
// Created by Arun on 10/13/2025.
//

#ifndef DIGIT_MATCHER_H
#define DIGIT_MATCHER_H

#include "regex_class.h"

// typedef enum DigitState {
//     DIGIT_START,
//     DIGIT_MATCHED
// } DigitState;

int digit_match_anywhere(RegexClass*, const char*);
int match_next_digit(RegexClass*, const char*);
int rematch_next_digit(RegexClass*, const char*);

#endif //DIGIT_MATCHER_H
