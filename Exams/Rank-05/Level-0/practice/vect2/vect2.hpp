#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class vect2 {

public:
    vect2( void ): _x(0), _y(0) {};
    ~vect2( void ) {};
    vect2( const int x, const int y ): _x(x), _y(y) {};
    vect2( const vect2 &other ): _x(other._x), _y(other._y) {};

    vect2 operator+( const vect2& other ) const { return vect2(_x + other._x, _y + other._y); };
    vect2 operator-( const vect2& other ) const { return vect2(_x - other._x, _y - other._y); };
    vect2& operator+=( const vect2& other ) { _x += other._x, _y += other._y; return *this; };
    vect2& operator-=( const vect2& other ) { _x -= other._x, _y -= other._y; return *this; };

    vect2 operator+( const int n ) const { return vect2(_x + n, _y + n); };
    vect2 operator-( const int n ) const { return vect2(_x - n, _y - n); };
    vect2 operator*( const int n ) const { return vect2(_x * n, _y * n); };

    vect2& operator+=( const int n ) { _x += n, _y += n; return *this; };
    vect2& operator-=( const int n ) { _x -= n, _y -= n; return *this; };
    vect2& operator*=( const int n ) { _x *= n, _y *= n; return *this; };

    vect2 operator++( int ) { vect2 tmp(*this); _x++, _y++; return  tmp; };
    vect2 operator--( int ) { vect2 tmp(*this); _x--, _y--; return  tmp; };
    vect2& operator++( void ) { ++_x, ++_y; return *this; };
    vect2& operator--( void ) { --_x, --_y; return *this; };

    bool operator==( const vect2& other ) const { return (_x == other._x) && (_y == other._y); };
    bool operator!=( const vect2& other ) const { return !(*this == other); };

    vect2& operator=( const vect2 &other ) {
        if (this != &other) {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    };

    int operator[]( int index ) const {
        if (index == 0) {
            return _x;
        } else if (index == 1) {
            return _y;
        }
        return -1;
    };

private:
    int _x, _y;

};

inline std::ostream& operator<<(std::ostream& os, const vect2& other) {
    os << "{" << other[0] << ", " << other[1] << "}";
    return os;
};

#endif
