#include <stdio.h>

#include "assert.h"
#include "literal.h"
#include "regex_class.h"
//
// Created by Arun on 10/14/2025.
//

void test_literal_match_anywhere_1() {
    const char* input_string = "Hello, 5 World!";
    RegexClass state = LITERAL;
    const int res = match_literal_anywhere(&state, input_string, 'e');
    assert("test_literal_match_anywhere_1", res, 1);
}

void test_literal_match_anywhere_2() {
    const char* input_string = "Hello, World!";
    RegexClass state = LITERAL;
    const int res = match_literal_anywhere(&state, input_string, 'z');
    assert("test_literal_match_anywhere_2", res, 0);
}

void test_literal_match_anywhere_3() {
    const char* input_string = "";
    RegexClass state = LITERAL;
    const int res = match_literal_anywhere(&state, input_string, 'r');
    assert("test_literal_match_anywhere_3", res, 0);
}

void test_literal_match_anywhere_4() {
    const char* input_string = NULL;
    RegexClass state = LITERAL;
    const int res = match_literal_anywhere(&state, input_string, 'r');
    assert("test_literal_match_anywhere_4", res, 0);
}

void test_next_literal_match_1() {
    const char* input_string = "Hello, 5 World!";
    RegexClass state = LITERAL;
    const int res = match_next_literal(&state, input_string, 'z');
    assert("test_next_literal_match_1", res, 0);
}

void test_next_literal_match_2() {
    const char* input_string = "Hello, 5 World!";
    RegexClass state = LITERAL;
    const int res = match_next_literal(&state, input_string + 7, '5');
    assert("test_next_literal_match_2", res, 1);
}

void test_next_literal_match_3() {
    const char* input_string = "";
    RegexClass state = LITERAL;
    const int res = match_next_literal(&state, input_string, '5');
    assert("test_next_literal_match_3", res, 0);
}

void test_next_literal_match_4() {
    const char* input_string = NULL;
    RegexClass state = LITERAL;
    const int res = match_next_literal(&state, input_string, '5');
    assert("test_next_literal_match_4", res, 0);
}

void test_rematch_next_literal_1() {
    const char* input_string = NULL;
    RegexClass state = LITERAL;
    const int res = rematch_next_literal(&state, input_string, '5');
    assert("test_rematch_next_literal_1", res, 0);
}

void test_rematch_next_literal_2() {
    const char* input_string = "";
    RegexClass state = LITERAL;
    const int res = rematch_next_literal(&state, input_string, '5');
    assert("test_rematch_next_literal_2", res, 0);
}

void test_rematch_next_literal_3() {
    const char* input_string = "Hello, World!";
    RegexClass state = LITERAL;
    const int res = rematch_next_literal(&state, input_string, 'w');
    assert("test_rematch_next_literal_3", res, 0);
}

void test_rematch_next_literal_4() {
    const char* input_string = "Hello, World!";
    RegexClass state = LITERAL;
    const int res = rematch_next_literal(&state, input_string + 7, 'W');
    const int res1 = rematch_next_literal(&state, input_string + 8, 'o');
    if (res == res1) printf("test_rematch_next_literal_4: SUCCESS\n");
    else printf("test_rematch_next_literal_4: FAILED\n");
}

int test_literal() {
    test_literal_match_anywhere_1();
    test_literal_match_anywhere_2();
    test_literal_match_anywhere_3();
    test_literal_match_anywhere_4();

    test_next_literal_match_1();
    test_next_literal_match_2();
    test_next_literal_match_3();
    test_next_literal_match_4();

    test_rematch_next_literal_1();
    test_rematch_next_literal_2();
    test_rematch_next_literal_3();
    test_rematch_next_literal_4();
}