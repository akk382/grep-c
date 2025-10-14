//
// Created by Arun on 10/14/2025.
//

#include "assert.h"

void assert(const char* test_name, const int result, const int expected) {
    printf("%s: %s\n", test_name, result == expected ? "SUCCESS": "FAILED");
}
