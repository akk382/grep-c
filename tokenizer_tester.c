//
// Created by Arun on 10/14/2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "regex_tokenizer.h"

int main5() {
    Lexer lexer;
    const char* pattern = "cfsg\\d";
    init_lexer(&lexer, pattern);
    tokenize(&lexer);

    RegexTokens* mem_to_free = lexer.tokens;

    // ------ Print tokens -------
    const char* token = NULL;
    for (int i = 0; i < lexer.token_pos; i++) {
        switch (lexer.tokens[i]) {
            case 0: token = "BEGIN_T"; break;
            case 1: token = "B_SLASH_T"; break;
            case 2: token = "LITERAL_T"; break;
            case 3: token = "DIGIT_T"; break;
            case 4: token = "STAR_T"; break;
            case 5: token = "PLUS_T"; break;
            case 6: token = "CONCAT_T"; break;
            case 7: token = "END_T"; break;
            case 8: token = "EOL_T"; break;
            default: exit(2);
        }
        printf("Token: %s\n", token);
    }

    printf("\nTotal tokens found: %d\n", lexer.token_pos);

    free(mem_to_free);

    return 0;
}
