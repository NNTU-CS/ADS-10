// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    std::vector<char> elements;
    int size = 0, permutations = 0;

 public:
    explicit Tree(const std::vector<char> vector) : elements{vector} {
        elements = vector;
        for (int i = 0; i < elements.size(); i++) {
            size++;
        }
        if (size) {
            permutations = 1;
        }
        for (int i = 2; i <= size; i++) {
            permutations *= i;
        }
    }

    int get_size() const { return size; }

    int get_permutations() const { return permutations; }
};

#endif  // INCLUDE_TREE_H_
