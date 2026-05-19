#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>      // std::reverse
# include <iostream>
# include <algorithm>   // std::max

/*
** NOTE: List of important methods to implement
**       - String Constructor (strip leading zeroes)
**       - Explicit uint constructor
**       - Addition operation by value and reference (Traverse from LSB; Handle carry)
**       - uint converter help function (for digit-shift overloads)
**
**       - Digit-shift methods by value and reference (<<, >>, <<=,, >>=)
**          - `<<` : append zeroes by 'n'
**          - `>>` : `value / 10^n` or trim value from LSB to length of value 
**                 : return bigint(0) when n is greater than the length of value
**
**       - Comparison overloads (>, <, >=, <=, !=, ==)
**          - `>`/`<`: When length differs, compare by length. Otherwise, compare lexicographically
*/

// Redefined because I'm lazy
typedef unsigned int uint32_t;

// Big-endian first
class bigint {

public:
    bigint( void ): _value("0") {};
    ~bigint( void ) {};

    // NOTE:    Checks for leading zeroes; Strips leading zeroes from string when present.
    bigint( const std::string& value ) {
        size_t start = value.find_first_not_of('0');
        _value = (start == std::string::npos) ? "0" : value.substr(start);
    };

    bigint( const bigint& other ): _value(other._value) {};

    /*
    **  NOTE:   Set to explicit to flag that this constructor cannot be used for implicit conversion.
    **          Reverse string to ensure that it is stored in big endian
    */
    explicit bigint( uint32_t n ): _value(n ? "" : "0") {
        while (n > 0) {
            _value += static_cast<char>((n % 10) + '0');
            n /= 10;
        }
        std::reverse(_value.begin(), _value.end());
    };

    bigint& operator=( const bigint& other ) {
        if (this != &other) {
            _value = other._value;
        }
        return *this;
    };

    // NOTE: `carry` integer division
    bigint operator+( const bigint& other ) const {
        std::string res = "";
        uint32_t carry = 0;
        std::string a = _value;
        std::string b = other._value;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        size_t i = 0;
        while (i < std::max(a.length(), b.length()) || carry) {
            uint32_t a_i = (i < a.length()) ? a[i] - '0' : 0;
            uint32_t b_i = (i < b.length()) ? b[i] - '0' : 0;
            uint32_t sum = carry + a_i + b_i;
            res += static_cast<char>(sum % 10 + '0');
            carry = sum / 10;
            i++;
        }
        std::reverse(res.begin(), res.end());
        return bigint(res);
    };

    bigint& operator+=( const bigint& other ) { *this = *this + other; return *this; };

    // NOTE: Helper function for uint32_t constructor for digit-shifting
    uint32_t toUInt( void ) const {
        uint32_t res = 0;
        size_t i = 0;
        while (i < _value.length()) {
            res = res * 10 + (_value[i++] - '0');
        }
        return res;
    }

    bigint operator<<( uint32_t n ) const { return bigint(_value + std::string(n, '0')); };

    // NOTE: Same as `value / 10^n` (ex. 1337 >> 2 = 13)
    bigint operator>>( uint32_t n ) const { return (n >= _value.length()) ? bigint() : bigint(_value.substr(0, _value.length() - n)); };

    bigint operator<<( const bigint& other ) const { return *this << other.toUInt(); };
    bigint operator>>( const bigint& other ) const { return *this >> other.toUInt(); };

    bigint& operator<<=( uint32_t n ) { *this = *this << n; return *this; };
    bigint& operator>>=( uint32_t n ) { *this = *this >> n; return *this; };
    bigint& operator<<=( const bigint& other ) { *this = *this << other; return *this; };
    bigint& operator>>=( const bigint& other ) { *this = *this >> other; return *this; };

    bool operator==( const bigint& other ) const { return _value == other._value; };
    bool operator!=( const bigint& other ) const { return !(_value == other._value); };

    // NOTE: Length comparison when string lengths difffer; Otherwise, lexicographical comparision
    bool operator>( const bigint& other ) const {
        if (_value.length() != other._value.length()) {
            return (_value.length() > other._value.length());
        }
        return (_value > other._value);
    };

    bool operator>=( const bigint& other ) const { return *this > other || *this == other; };
    bool operator<( const bigint& other ) const { return !(*this >= other); };
    bool operator<=( const bigint& other ) const { return !(*this > other); };

    bigint operator++( int ) { bigint temp(*this); *this = *this + bigint(1); return temp; };
    bigint& operator++( void ) { *this  = bigint(1) + *this ; return *this; };

    std::string getValue( void ) const { return _value; };

private:
    std::string _value;

};

inline std::ostream& operator<<(std::ostream& os, const bigint& other) {
    os << other.getValue();
    return os;
};

#endif
