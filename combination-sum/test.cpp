
#include <iostream>
#include <vector>
#include "../include/vector.h"

int main() {
    std::vector<int> vect = {1, 2, 3, 4, 5};

    // Specify the index to remove
    int index = 2; // Removing the element at index 2 (value 3)

    // Check if the index is within the valid range
    if (index >= 0 && index < vect.size()) {
        vect.erase(vect.begin() + index);
    }

    // Print the updated vector
    vec::print(vect, "vect"); 

    return 0;
}
