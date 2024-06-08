// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> DeleteNoneNeed(std::vector<char> numbers, int index) {
    if (index >= 0 && index < numbers.size()) {
        numbers.erase(numbers.begin() + index);
    }
    return numbers;
}


std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> ps = tree.getPerms(3);
    if (ps.size() < n)
        return {};
    return ps[n - 1];
}
