#include <iostream>
#include <cassert>
#include "bigint.hpp"

void test_construction() {
    std::cout << "=== Construction ===" << std::endl;
    bigint a;                          // default
    bigint b("12345");                 // from string
    bigint c(bigint(42u));             // from uint
    bigint d("0");                     // zero string
    bigint e("000042");                // leading zeros stripped

    std::cout << "default:        " << a << std::endl; // 0
    std::cout << "string 12345:   " << b << std::endl; // 12345
    std::cout << "uint 42:        " << c << std::endl; // 42
    std::cout << "zero string:    " << d << std::endl; // 0
    std::cout << "leading zeros:  " << e << std::endl; // 42

    assert(a == bigint("0"));
    assert(b == bigint("12345"));
    assert(c == bigint("42"));
    assert(d == bigint("0"));
    assert(e == bigint("42"));
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_addition() {
    std::cout << "=== Addition ===" << std::endl;

    bigint a("999");
    bigint b("1");
    std::cout << "999 + 1 = "         << a + b             << std::endl; // 1000

    bigint c("0");
    bigint d("42");
    std::cout << "0 + 42 = "          << c + d             << std::endl; // 42

    bigint e("99999999999999999999");
    bigint f("1");
    std::cout << "99999999999999999999 + 1 = " << e + f    << std::endl; // 100000000000000000000

    bigint g("123456789");
    g += bigint("987654321");
    std::cout << "123456789 += 987654321 = "   << g        << std::endl; // 1111111110

    assert(a + b == bigint("1000"));
    assert(c + d == bigint("42"));
    assert(g == bigint("1111111110"));
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_comparison() {
    std::cout << "=== Comparison ===" << std::endl;

    bigint a("100");
    bigint b("99");
    bigint c("100");

    std::cout << "100 == 100: " << (a == c) << std::endl; // 1
    std::cout << "100 != 99:  " << (a != b) << std::endl; // 1
    std::cout << "100 > 99:   " << (a > b)  << std::endl; // 1
    std::cout << "99 < 100:   " << (b < a)  << std::endl; // 1
    std::cout << "100 >= 100: " << (a >= c) << std::endl; // 1
    std::cout << "100 <= 100: " << (a <= c) << std::endl; // 1
    std::cout << "99 >= 100:  " << (b >= a) << std::endl; // 0
    std::cout << "100 <= 99:  " << (a <= b) << std::endl; // 0

    // same length, different value
    bigint d("19");
    bigint e("21");
    std::cout << "19 < 21:    " << (d < e)  << std::endl; // 1
    std::cout << "21 > 19:    " << (e > d)  << std::endl; // 1

    assert(a == c);
    assert(a != b);
    assert(a > b);
    assert(b < a);
    assert(a >= c);
    assert(a <= c);
    assert(d < e);
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_digitshift() {
    std::cout << "=== Digit Shift ===" << std::endl;

    bigint a("42");
    std::cout << "42 << 3 = "  << (a << 3u)           << std::endl; // 42000
    std::cout << "42 << 0 = "  << (a << 0u)           << std::endl; // 42

    bigint b("1337");
    std::cout << "1337 >> 2 = " << (b >> 2u)          << std::endl; // 13
    std::cout << "1337 >> 0 = " << (b >> 0u)          << std::endl; // 1337

    // edge cases
    std::cout << "42 >> 5 = "  << (a >> 5u)           << std::endl; // 0
    std::cout << "42 >> 2 = "  << (a >> 2u)           << std::endl; // 0
    std::cout << "1000 >> 2 = "<< (bigint("1000") >> 2u) << std::endl; // 10

    // bigint shift argument
    std::cout << "42 << bigint(3) = " << (a << bigint("3")) << std::endl; // 42000

    // compound assignment
    bigint c("5");
    c <<= 3u;
    std::cout << "5 <<= 3 = " << c << std::endl; // 5000
    c >>= 2u;
    std::cout << "5000 >>= 2 = " << c << std::endl; // 50

    assert((a << 3u) == bigint("42000"));
    assert((b >> 2u) == bigint("13"));
    assert((a >> 5u) == bigint("0"));
    assert((bigint("1000") >> 2u) == bigint("10"));
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_increment() {
    std::cout << "=== Increment ===" << std::endl;

    bigint a("41");
    std::cout << "pre  ++41 = " << ++a << std::endl; // 42
    std::cout << "after:      " << a   << std::endl; // 42

    bigint b("41");
    std::cout << "post 41++ = " << b++ << std::endl; // 41
    std::cout << "after:      " << b   << std::endl; // 42

    // carry case
    bigint c("999");
    std::cout << "pre ++999 = " << ++c << std::endl; // 1000

    assert(a == bigint("42"));
    assert(b == bigint("42"));
    assert(c == bigint("1000"));
    std::cout << "PASSED" << std::endl << std::endl;
}

void test_edge_cases() {
    std::cout << "=== Edge Cases ===" << std::endl;

    // zero arithmetic
    bigint zero;
    std::cout << "0 + 0 = "   << zero + zero          << std::endl; // 0
    std::cout << "0 << 5 = "  << (zero << 5u)         << std::endl; // 0 (or 00000 — check your output)
    std::cout << "0 >> 1 = "  << (zero >> 1u)         << std::endl; // 0

    // large number
    bigint large("99999999999999999999999999999999999999999999999999");
    bigint one("1");
    std::cout << "large + 1 = " << large + one        << std::endl;

    assert(zero + zero == bigint("0"));
    assert((zero >> 1u) == bigint("0"));
    std::cout << "PASSED" << std::endl << std::endl;
}

int main() {
    test_construction();
    test_addition();
    test_comparison();
    test_digitshift();
    test_increment();
    test_edge_cases();
    std::cout << "=== ALL TESTS PASSED ===" << std::endl;
    return 0;
}
