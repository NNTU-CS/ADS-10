// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

std::vector<char> getPermu(const Tree &tree, int permIndex) {
    std::vector<std::vector<char>> allPerms = tree.getAllPermutations();
    std::vector<char> result;
    if (permIndex > 0 && permIndex <= allPerms.size()) {
        result = allPerms[permIndex - 1];
    }
    return result;
}

