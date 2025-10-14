//
// Created by Arun on 10/14/2025.
//

#include <stdio.h>

#include "assert.h"
#include "regex_class.h"
#include "star.h"

void test_star() {
    // star(RegexClass* curr_class, const char* input_string, const char literal)

    // --------------------- Positive ---------------------
    RegexClass curr = DIGIT;
    const char* input_string = "12345";
    int res = star(&curr, input_string, NULL);
    assert("test_star d*: ", res, 1);

    curr = DIGIT_MATCHED;
    star(&curr, input_string + 1, NULL);
    assert("test_star d*: ", res, 1);

    curr = LITERAL;
    input_string = "xxxxxxxxx";
    char literal = 'x';
    star(&curr, input_string, &literal);
    assert("test_star c*: ", res, 1);

    curr = LITERAL_MATCHED;
    literal = 'x';
    star(&curr, input_string + 1, &literal);
    assert("test_star c*: ", res, 1);

    // --------------- Negative --------------------------
    curr = DIGIT;
    input_string = "Hello, World!";
    res = star(&curr, input_string, NULL);
    assert("test_star d*: ", res, 1);

    curr = DIGIT_MATCHED;
    star(&curr, input_string + 1, NULL);
    assert("test_star d*: ", res, 1);

    curr = LITERAL;
    input_string = "yyyyyyy";
    literal = 'x';
    star(&curr, input_string, &literal);
    assert("test_star c*: ", res, 1);

    curr = LITERAL_MATCHED;
    input_string = "xyyyyyy";
    literal = 'x';
    star(&curr, input_string + 1, &literal);
    assert("test_star c*: ", res, 1);
}

int main4() {
    test_star();
}