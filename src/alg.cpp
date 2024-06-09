// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> Delete(std::vector<char> numbers, int index) {
    if (index < numbers.size() && index >= 0) {
        numbers.erase(numbers.begin() + index);
    }
    return numbers;
}


std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> perm = tree.getPerms(3);
    if (perm.size() < n)
        return {};
    return perm[n - 1];
}
