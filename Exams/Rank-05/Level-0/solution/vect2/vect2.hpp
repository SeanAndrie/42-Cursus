#ifndef VECT2_HPP
#define VECT2_HPP

# include <iostream>

/*
**  NOTE: List of operation overloads to implement
**       - Arithmetic by value & reference (+, -, *, /)
**       - Scalar Arithmetic by value & reference
**       - Equal to and Not Equal to  (== , !=)
**       - Indexing (0, 1 only)
**       - Post/Pre Increment/Decrement (Pre -> by reference, Post -> by value)
**       - Outstream overload
*/

class vect2 {

private:
    int _x;
    int _y;

public:
    vect2( void ): _x(0), _y(0) {};
    ~vect2( void ) {};
    vect2( const int x, const int y ): _x(x), _y(y) {};
    vect2( const vect2& other ): _x(other._x), _y(other._y) {};

    vect2 operator+( const vect2& other ) const { return vect2(_x + other._x, _y + other._y); };
    vect2 operator-( const vect2& other ) const { return vect2(_x - other._x, _y - other._y); };
    vect2 operator/( const vect2& other ) const { return vect2(_x / other._x, _y / other._y); };
    vect2 operator*( const vect2& other ) const { return vect2(_x * other._x, _y * other._y); };

    vect2& operator+=( const vect2& other ) { _x += other._x, _y += other._y; return *this; };
    vect2& operator-=( const vect2& other ) { _x -= other._x, _y -= other._y; return *this; };
    vect2& operator/=( const vect2& other ) { _x /= other._x, _y /= other._y; return *this; };
    vect2& operator*=( const vect2& other ) { _x *= other._x, _y *= other._y; return *this; };

    vect2 operator+( const int n ) { return vect2(_x + n, _y + n); };
    vect2 operator-( const int n ) { return vect2(_x - n, _y - n); };
    vect2 operator/( const int n ) { return vect2(_x / n, _y / n); };
    vect2 operator*( const int n ) { return vect2(_x * n, _y * n); };

    vect2& operator+=( const int n ) { _x += n, _y += n; return *this; };
    vect2& operator-=( const int n ) { _x -= n, _y -= n; return *this; };
    vect2& operator/=( const int n ) { _x /= n, _y /= n; return *this; };
    vect2& operator*=( const int n ) { _x *= n, _y *= n; return *this; };

    vect2& operator=( const vect2& other ) {
        if (this != &other) {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    };

    // int get_x( void ) const { return _x; };
    // int get_y( void ) const { return _y; };

    int operator[](int index) const {
        if (index == 0) {
            return _x;
        } else if (index == 1) {
            return _y;
        }
        std::cerr << "vect2: invalid index\n";
        return -1;
    };

    vect2& operator++( void ) { ++_x; ++_y; return *this; };
    vect2& operator--( void ) { --_x; --_y; return *this; };
    vect2 operator++( int ) { vect2 tmp(*this); _x++, _y++; return tmp; };
    vect2 operator--( int ) { vect2 tmp(*this); _x--, _y--; return tmp; };

    bool operator==( const vect2& other ) const { return (_x == other._x) && (_y == other._y); };
    bool operator!=( const vect2& other ) const { return !(*this == other); };

};

std::ostream& operator<<(std::ostream& os, const vect2& other);

#endif
