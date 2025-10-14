//
// Created by Arun on 10/14/2025.
//

#include "regex_matcher.h"

#include "literal.h"
#include "regex_tokenizer.h"
#include "utility.h"

int match(const char* input_string, const char* pattern) {
    Lexer lexer;
    init_lexer(&lexer, pattern);
    tokenize(&lexer);

    print_tokens(lexer);

    // TODO: We need struct with Token and Value(for literals);
}
