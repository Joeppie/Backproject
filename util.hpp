#include "util.h"

/**
 * This specification needs to be here, since templates are only genereated when 'compilation units' use them.
 * To avoid problems, a .hpp is used which is treated as a source file and influces the header (and is included by header) to avoid
 * conflicting or lacking implementations, which lead to very confusing errors.
 * @tparam T the type of the value being read.
 * @return the value that wa sread from the std::in stream.
 */
template<class T>
T ReadAndValidate()
{
    T n;
    std::cout << "enter value:\n>";
    std::cout.flush();
    std::cin >> n;

    while (std::cin.fail() == 1 || n < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n'); //throw away 1000 chars, or next end of line
        std::cout << "\nincorrect value, please enter correct value\n>";
        std::cin >> n;
        std::cin.ignore(1000, '\n'); //throw away 1000 chars, or next end of line
    }
    return n;
}