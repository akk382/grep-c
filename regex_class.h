//
// Created by Arun on 10/13/2025.
//

#ifndef REGEX_CLASS_H
#define REGEX_CLASS_H

typedef enum RegexClass {
    ANYWHERE, // Can match the first regex class anywhere in the input string
    START_STRING, // ^ -> starts with the next character/group/word
    END_STRING, // $ -> ends with the previous character/group/word
    DIGIT, // \d -> any digit
    DIGIT_MATCHED,
    LITERAL, // c -> any character
    LITERAL_MATCHED,
    STAR, // * -> zero of more of previous class
    PLUS, // + -> one or more of previous class
    QUE_MARK, // ? -> One or none of the previous class
    OR, // | -> Either the previous class or next class should match
} RegexClass;

// typedef struct Transition {
//     RegexClass type;
//     const char literal;
//     struct Transition* next;
// } Transition;

#endif //REGEX_CLASS_H
