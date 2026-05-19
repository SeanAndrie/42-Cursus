#include <iostream>
#include <cassert>
#include "vect2.hpp"

void test_addition() {
    std::cout << "=== Addition ===" << std::endl;

    vect2 a(1, 2);
    vect2 b(3, 4);
    std::cout << "{1,2} + {3,4} = " << a + b << std::endl; // {4, 6}

    vect2 zero(0, 0);
    std::cout << "{0,0} + {3,4} = " << zero + b << std::endl; // {3, 4}

    vect2 neg(-1, -2);
    std::cout << "{-1,-2} + {3,4} = " << neg + b << std::endl; // {2, 2}

    assert(a + b == vect2(4, 6));
    assert(zero + b == b);
    assert(neg + b == vect2(2, 2));
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_subtraction() {
    std::cout << "=== Subtraction ===" << std::endl;

    vect2 a(5, 10);
    vect2 b(3, 4);
    std::cout << "{5,10} - {3,4} = " << a - b << std::endl; // {2, 6}

    vect2 zero(0, 0);
    std::cout << "{5,10} - {0,0} = " << a - zero << std::endl; // {5, 10}

    std::cout << "{3,4} - {5,10} = " << b - a << std::endl; // {-2, -6}

    assert(a - b == vect2(2, 6));
    assert(a - zero == a);
    assert(b - a == vect2(-2, -6));
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_scalar_multiplication() {
    std::cout << "=== Scalar Multiplication ===" << std::endl;

    vect2 a(2, 2);
    std::cout << "{2,2} * 2 = " << a * 2 << std::endl; // {4, 4}
    std::cout << "{2,2} * 0 = " << a * 0 << std::endl; // {0, 0}
    std::cout << "{2,2} * -1 = " << a * -1 << std::endl; // {-2, -2}

    assert(a * 2 == vect2(4, 4)); // subject's own example
    assert(a * 0 == vect2(0, 0));
    assert(a * -1 == vect2(-2, -2));
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_indexing() {
    std::cout << "=== Indexing ===" << std::endl;

    vect2 a(7, 13);
    std::cout << "a[0] = " << a[0] << std::endl; // 7
    std::cout << "a[1] = " << a[1] << std::endl; // 13

    assert(a[0] == 7);
    assert(a[1] == 13);
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_print() {
    std::cout << "=== Print ===" << std::endl;

    vect2 a(3, 4);
    // subject requires: << v << produces same as << "{" << v[0] << ", " << v[1] << "}"
    std::cout << "vect2(3,4): " << a << std::endl; // {3, 4}
    std::cout << "vect2(0,0): " << vect2(0, 0) << std::endl; // {0, 0}
    std::cout << "vect2(-1,-2): " << vect2(-1, -2) << std::endl; // {-1, -2}
    std::cout << "PASSED" << std::endl << std::endl;
}

int main() {
    test_addition();
    test_subtraction();
    test_scalar_multiplication();
    test_indexing();
    test_print();
    std::cout << "=== ALL TESTS PASSED ===" << std::endl;
    return 0;
}
