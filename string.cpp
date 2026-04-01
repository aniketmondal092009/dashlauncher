
#include <stdio.h>
#include "string.h"

size_t length(const char *string) {
    size_t len = 0;

    while (*string != '\0') {
        len++;
        string++;
    }

    return len;
}

void println(String string) {
    printf("%s\n", string.data);
}

String newstring(const char *string) {
    return (String) {
        .data = string,
        .count = length(string),
    };
}

