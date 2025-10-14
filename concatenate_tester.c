//
// Created by Arun on 10/14/2025.
//

#include "assert.h"
#include "concatenate.h"

void test_concatenate() {
    // int concatenate(RegexClass* curr_state, RegexClass* next_state, const char* input_string, const char* literal)
    RegexClass curr = LITERAL_MATCHED;
    RegexClass next = LITERAL;
    const char* input_str = "Hello, World!";
    char literal = 'e';

    // literal->literal
    int res = concatenate(&curr, &next, input_str+1, &literal);
    assert("test_concat: literal -> literal", res, 1);

    literal = 'x';
    res = concatenate(&curr, &next, input_str+1, &literal);
    assert("test_concat: literal -> literal", res, 0);

    // digit->digit
    curr = DIGIT_MATCHED;
    next = DIGIT;
    input_str = "Hello, 23 World!";

    res = concatenate(&curr, &next, input_str+8, NULL);
    assert("test_concat: digit -> digit", res, 1);

    res = concatenate(&curr, &next, input_str+10, NULL);
    assert("test_concat: digit -> digit", res, 0);

    // literal->digit
    curr = LITERAL_MATCHED;
    next = DIGIT;
    input_str = "Hello, 23 World!";

    res = concatenate(&curr, &next, input_str+8, NULL);
    assert("test_concat: literal -> digit", res, 1);

    res = concatenate(&curr, &next, input_str+10, NULL);
    assert("test_concat: literal -> digit", res, 0);

    // digit->literal
    curr = DIGIT_MATCHED;
    next = LITERAL;
    input_str = "Hello, 23 World!";
    literal = '3';

    res = concatenate(&curr, &next, input_str+8, &literal);
    assert("test_concat: digit -> literal", res, 1);

    literal = 'w';
    res = concatenate(&curr, &next, input_str+9, &literal);
    assert("test_concat: digit -> literal", res, 0);
}

int main() {
    test_concatenate();
}