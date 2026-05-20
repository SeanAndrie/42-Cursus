#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

# include "tree_bag.hpp"
# include "searchable_bag.hpp"

class searchable_tree_bag
    : public tree_bag, public searchable_bag {

public:
    searchable_tree_bag( void ): tree_bag() {};
    virtual ~searchable_tree_bag( void ) {};
    searchable_tree_bag( const searchable_tree_bag& other ): tree_bag(other) {};

    searchable_tree_bag& operator=( const searchable_tree_bag& other ) {
        if (this != &other) {
            tree_bag::operator=(other);
        }
        return *this;
    };

    virtual bool has( int num ) const {
        node *curr = this->tree;
        while (curr) {
            if (curr->value == num) {
                return true;
            } else if (num < curr->value) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return false;
    };

};

#endif
