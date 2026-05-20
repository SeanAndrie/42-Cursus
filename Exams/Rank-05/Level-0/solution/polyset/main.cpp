#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include <iostream>

/*
 * Bag
 *  |--> SearchableBag
 *  |--> ArrayBag
 *  |--> TreeBag
 *
 * SearchableArrayBag
 *  |--> ArrayBag
 *  |--> SearchableBag
 *
*/

int main(void) {

    int *arr = new int[5];
    for (size_t i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    searchable_array_bag b;

    b.insert(arr, 5);
    b.print();

    delete[] arr;

    return 0;
}
