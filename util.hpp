#include "util.h"

template<class T>
T ReadAndValidate() {
    T n;
    std::cout << "enter value:";
    std::cout.flush();
    std::cin >> n;

    while (std::cin.fail() == 1 || n < 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n'); //throw away 1000 chars, or next end of line
        std::cout << "\nincorrect value, please enter correct value";
        std::cin >> n;
    }
    // std::cout << "\n entered: " << n << std::endl;
    return n;
}