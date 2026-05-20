#ifndef SET_HPP
# define SET_HPP

# include "searchable_bag.hpp"

class set {

public:
    set( void ): _bag(0) {};
    ~set( void ) {};
    set( const set& other ): _bag(other._bag) {};
    set( searchable_bag* bag ): _bag(bag) {};
    set( searchable_bag& bag ): _bag(&bag) {};

    set& operator=( const set& other ) {
        if (this != &other) {
            _bag = other._bag;
        }
        return *this;
    };

    void insert( int num ) {
        if (!_bag)
            return ;
        if (!_bag->has(num))
            _bag->insert(num);
    };

    void insert( int *data, int count ) {
        if (!_bag || !data || count <= 0)
            return ;
        for (int i = 0; i < count; i++) {
            if (!_bag->has(data[i]))
                _bag->insert(data[i]);
        }
    };

    void clear( void ) {
        if (!_bag)
            return ;
        _bag->clear();
    };

    void print( void ) const {
        if (!_bag)
            return ;
        _bag->print();
    };

    bool has( int num ) const {
        if (!_bag)
            return false;
        return _bag->has(num);
    };

private:
    searchable_bag  *_bag;

};

#endif
