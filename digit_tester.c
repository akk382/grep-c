//
// Created by Arun on 10/14/2025.
//

#include <stdio.h>

#include "assert.h"
#include "digit.h"


void test_digit_match_anywhere_1() {
    const char* input_string = "Hello, 5 World!";
    RegexClass state = DIGIT;
    const int res = digit_match_anywhere(&state, input_string);
    assert("test_digit_match_anywhere_1", res, 1);
}

void test_digit_match_anywhere_2() {
    const char* input_string = "Hello, World!";
    RegexClass state = DIGIT;
    const int res = digit_match_anywhere(&state, input_string);
    assert("test_digit_match_anywhere_2", res, 0);
}

void test_digit_match_anywhere_3() {
    const char* input_string = "";
    RegexClass state = DIGIT;
    const int res = digit_match_anywhere(&state, input_string);
    assert("test_digit_match_anywhere_3", res, 0);
}

void test_digit_match_anywhere_4() {
    const char* input_string = NULL;
    RegexClass state = DIGIT;
    const int res = digit_match_anywhere(&state, input_string);
    assert("test_digit_match_anywhere_4", res, 0);
}

void test_next_digit_match_1() {
    const char* input_string = "Hello, 5 World!";
    RegexClass state = DIGIT;
    const int res = match_next_digit(&state, input_string);
    assert("test_next_digit_match_1", res, 0);
}

void test_next_digit_match_2() {
    const char* input_string = "Hello, 5 World!";
    RegexClass state = DIGIT;
    const int res = match_next_digit(&state, input_string + 7);
    assert("test_next_digit_match_2", res, 1);
}

void test_next_digit_match_3() {
    const char* input_string = "";
    RegexClass state = DIGIT;
    const int res = match_next_digit(&state, input_string);
    assert("test_next_digit_match_3", res, 0);
}

void test_next_digit_match_4() {
    const char* input_string = NULL;
    RegexClass state = DIGIT;
    const int res = match_next_digit(&state, input_string);
    assert("test_next_digit_match_4", res, 0);
}

void test_rematch_next_digit_1() {
    const char* input_string = NULL;
    RegexClass state = DIGIT;
    const int res = rematch_next_digit(&state, input_string);
    assert("test_rematch_next_digit_1", res, 0);
}

void test_rematch_next_digit_2() {
    const char* input_string = "";
    RegexClass state = DIGIT;
    const int res = rematch_next_digit(&state, input_string);
    assert("test_rematch_next_digit_2", res, 0);
}

void test_rematch_next_digit_3() {
    const char* input_string = "Hello, World!";
    RegexClass state = DIGIT;
    const int res = rematch_next_digit(&state, input_string);
    assert("test_rematch_next_digit_3", res, 0);
}

void test_rematch_next_digit_4() {
    const char* input_string = "Hello, 342 World!";
    RegexClass state = DIGIT;
    const int res = rematch_next_digit(&state, input_string + 7);
    const int res1 = rematch_next_digit(&state, input_string + 8);
    if (res == res1) printf("test_rematch_next_digit_4: SUCCESS\n");
    else printf("test_rematch_next_digit_4: FAILED\n");
}

int test_digit() {
    test_digit_match_anywhere_1();
    test_digit_match_anywhere_2();
    test_digit_match_anywhere_3();
    test_digit_match_anywhere_4();

    test_next_digit_match_1();
    test_next_digit_match_2();
    test_next_digit_match_3();
    test_next_digit_match_4();

    test_rematch_next_digit_1();
    test_rematch_next_digit_2();
    test_rematch_next_digit_3();
    test_rematch_next_digit_4();
}