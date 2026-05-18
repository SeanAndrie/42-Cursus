#include "vect2.hpp"

int main(void)
{
    if (vect2(2, 2) * 2 == vect2(4, 4)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    return 0;
}
