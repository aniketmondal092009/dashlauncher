#include "fzf.hpp"
#include <iostream>
#include <vector>


int counter = sizeof(items) / sizeof(items[0]);

void hello() {
    std::cout << "hello world" << std::endl;
}


void print_items() {

    for (int i = 0; i < counter; i++) {
        std::cout << items[i] << std::endl;
    }

}


void filteritems() {
    std::vector<int> arr(counter);
}


