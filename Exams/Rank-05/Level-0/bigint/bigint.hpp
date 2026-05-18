#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>

class bigint {

public:
    bigint( void );
    ~bigint( void );
    bigint( unsigned long long n );
    bigint( const bigint& other );
    bigint& operator=( const bigint& other );

private:
    

};

#endif
