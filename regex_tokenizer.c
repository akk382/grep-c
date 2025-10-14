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
    lexer->tokens = malloc(2 * strlen(pattern) * sizeof(RegexToken));
    lexer->token_pos = 0;
}

void add_concat(Lexer* lexer) {
    RegexToken prev_token = lexer->tokens[lexer->token_pos - 1];
    if (lexer->token_pos != 0 && prev_token.lexeme != BEGIN_T &&
        prev_token.lexeme != STAR_T && prev_token.lexeme != PLUS_T && prev_token.lexeme != CONCAT_T)
        lexer->tokens[lexer->token_pos++] = (RegexToken) { CONCAT_T, 0 };
}

void tokenize(Lexer* lexer) {
    while (lexer->curr_char) {
        switch (lexer->curr_char) {
            case '\\':
                advance(lexer);
                switch (lexer->curr_char) {
                    case '\\': lexer->tokens[lexer->token_pos++] = (RegexToken) { B_SLASH_T, 0 }; break;
                    case 'd': lexer->tokens[lexer->token_pos++] = (RegexToken) { DIGIT_T, 0 }; break;
                    case '*':
                    case '+':
                    default: exit(1); // Any other char = literal for now.
                }
                break;
            case 'd':
                add_concat(lexer);
                lexer->tokens[lexer->token_pos++] = (RegexToken) { DIGIT_T, 0 };
                break;
            case '*': lexer->tokens[lexer->token_pos++] = (RegexToken) { STAR_T, 0 }; break;
            case '+': lexer->tokens[lexer->token_pos++] = (RegexToken) { PLUS_T, 0 }; break;
            case '^': lexer->tokens[lexer->token_pos++] = (RegexToken) { BEGIN_T, 0 }; break;
            case '$': lexer->tokens[lexer->token_pos++] = (RegexToken) { END_T, 0 }; break;
            default:
                add_concat(lexer);
                lexer->tokens[lexer->token_pos++] = (RegexToken) { LITERAL_T, lexer->curr_char };
                break;
        }
        advance(lexer);
    }
    lexer->tokens[lexer->token_pos++] = (RegexToken) { EOL_T, 0 };
}
