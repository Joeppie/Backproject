#include "util.h"

/**
 * This specification needs to be here, since templates are only compiled when 'compilation units' use them.
 * To avoid problems, a .hpp is used which is treated as a compilation unit.
 * This prevents confusion.
 * @tparam T the type of the value being read.
 * @return the value that was read from the std::in stream.
 */
template<class T>
T ReadAndValidate()
{
    T n;
    std::cout << ">";
    std::cout.flush();
    std::cin >> n;

    while (std::cin.fail() == 1 || n < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n'); //throw away 1000 chars, or next end of line
        std::cout << "\nincorrect value, please enter correct value\n>";
        std::cin >> n;
    }
    //Get rid of unconsumed enter that follows values to avoid 'autopress'  in press any key to continue.
    // an enter is always present, since it is used to terminate the input.
    std::cin.ignore(1000, '\n');
    return n;
}