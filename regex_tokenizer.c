//
// Created by Arun on 10/14/2025.
//

#include "regex_tokenizer.h"

#include <stdlib.h>
#include <string.h>

void advance(Lexer* lexer) {
    lexer->char_pos++;
    lexer->curr_char = lexer->pattern[lexer->char_pos];
}

void init_lexer(Lexer* lexer, const char* pattern) {
    lexer->pattern = pattern;
    lexer->char_pos = 0;
    lexer->curr_char = pattern[0];
    lexer->tokens = malloc(2 * strlen(pattern) * sizeof(RegexTokens));
    lexer->token_pos = 0;
}

void tokenize(Lexer* lexer) {
    while (lexer->curr_char) {
        switch (lexer->curr_char) {
            case '\\':
                advance(lexer);
                switch (lexer->curr_char) {
                    case '\\': lexer->tokens[lexer->token_pos++] = B_SLASH_T; break;
                    case 'd': lexer->tokens[lexer->token_pos++] = DIGIT_T; break;
                    case '*':
                    case '+':
                    default: exit(1); // Any other char = literal for now.
                }
                break;
            case 'd':
                if (lexer->token_pos != 0) lexer->tokens[lexer->token_pos++] = CONCAT_T;
                lexer->tokens[lexer->token_pos++] = DIGIT_T;
                break;
            case '*': lexer->tokens[lexer->token_pos++] = STAR_T; break;
            case '+': lexer->tokens[lexer->token_pos++] = PLUS_T; break;
            default:
                if (lexer->token_pos != 0) lexer->tokens[lexer->token_pos++] = CONCAT_T;
                lexer->tokens[lexer->token_pos++] = LITERAL_T;
                break;
        }
        advance(lexer);
    }
    lexer->tokens[lexer->token_pos++] = EOL_T;
}