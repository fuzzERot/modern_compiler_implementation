#include <iostream>
#include <cassert>


#include "prog1.hpp"
#include "program.hpp"

int main() {
    volatile bool wait = false;
    while(wait) {
        ;
    }

    std::cout << "Testing maxargs..." << std::endl;
    auto ret = maxargs(prog());
    assert(ret == 2);
    std::cout << "Correct" << std::endl;

    

    return 0;
}
