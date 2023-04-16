#include "gumbo.h"
#include <iostream>

int main() {
    GumboOutput* output = gumbo_parse("<h1>Hello, World!</h1>");
    // Do stuff with output->root
    std::cout << "I'm the best" << "\n";
    gumbo_destroy_output(&kGumboDefaultOptions, output);
}