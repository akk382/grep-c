cmake_minimum_required(VERSION 3.31)
project(grep_c C)

set(CMAKE_C_STANDARD 11)

add_executable(grep_c main.c
        literal.c
        literal.h
        digit.c
        digit.h
        star.c
        star.h
        concatenate.c
        concatenate.h
        regex_class.h
        plus.c
        plus.h
        digit_tester.c
        literal_tester.c
        assert.c
        assert.h
        star_tester.c
        concatenate_tester.c
        regex_tokenizer.c
        regex_tokenizer.h
        tokenizer_tester.c
        regex_matcher.c
        regex_matcher.h
        utility.c
        utility.h)
