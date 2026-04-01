#ifndef STRING_H
#define STRING_H

#include <stddef.h>

typedef struct {
    const char *data;
    size_t count;
} String;

size_t length(const char *string);

void println(String string);

String newstring(const char *string);

#endif
