//
// Created by Arun on 10/14/2025.
//

#include "utility.h"

#include <stdio.h>
#include <stdlib.h>

void print_tokens(const Lexer lexer) {
    // ------ Print tokens -------
    const char* token = NULL;
    for (int i = 0; i < lexer.token_pos; i++) {
        switch (lexer.tokens[i].lexeme) {
            case BEGIN_T: token = "BEGIN_T"; break;
            case B_SLASH_T: token = "B_SLASH_T"; break;
            case LITERAL_T: token = "LITERAL_T"; break;
            case DIGIT_T: token = "DIGIT_T"; break;
            case STAR_T: token = "STAR_T"; break;
            case PLUS_T: token = "PLUS_T"; break;
            case CONCAT_T: token = "CONCAT_T"; break;
            case END_T: token = "END_T"; break;
            case EOL_T: token = "EOL_T"; break;
            default: exit(2);
        }
        printf("Token: %s\n", token);
    }

    printf("\nTotal tokens found: %d\n", lexer.token_pos);
}
