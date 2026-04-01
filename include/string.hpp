#ifndef STRING_HPP
#define STRING_HPP

#include <cstddef>
#include <iostream>
#include <cstdio>

struct String {
    const char *data;
    size_t count;
};


inline size_t length(const char *string) {
    size_t len = 0;
    while (*string != '\0') {
        len++;
        string++;
    }
    return len;
}

inline void println(String string) {
    std::cout << string.data << std::endl;
}

inline void println(const char *s) {
    std::cout << s << std::endl;
}

inline String newstring(const char *string) {
    return String{ string, length(string) };
}

#endif
