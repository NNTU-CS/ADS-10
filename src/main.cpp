// Copyright 2022 NNTU-CS
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n);

int main() {
  std::vector<char> in = {'1', '3', '5', '7'};
    Tree tree(in);

    tree.generateAllPermutations();

    std::vector<char> result1 = getPerm(tree, 1);
    std::vector<char> result2 = getPerm(tree, 2); 

    return 0;
}
