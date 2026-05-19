#include "vect2.hpp"

std::ostream& operator<<(std::ostream& os, const vect2& other) {
    os << "{" << other[0] << ", " << other[1] << "}";
    return os;
}
