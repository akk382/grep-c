//
// Created by Arun on 10/14/2025.
//

#ifndef REGEX_TOKENIZER_H
#define REGEX_TOKENIZER_H

typedef enum RegexLexeme {
    BEGIN_T,
    B_SLASH_T,
    LITERAL_T,
    DIGIT_T,
    STAR_T,
    PLUS_T,
    CONCAT_T,
    END_T,
    EOL_T, // when we encounter '\0';
} RegexLexeme;

typedef struct RegexToken {
    RegexLexeme lexeme;
    char value;
} RegexToken;


typedef struct Lexer {
    RegexToken* tokens;
    int token_pos;
    const char* pattern;
    char curr_char;
    int char_pos;
} Lexer;

void tokenize(Lexer*);
void init_lexer(Lexer*, const char*);

#endif //REGEX_TOKENIZER_H
