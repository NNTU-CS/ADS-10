// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
std::vector<char> temp_delete(std::vector<char> numbers, int index_to_del) {
    if (index_to_del >= 0 && index_to_del < numbers.size()) {
        numbers.erase(numbers.begin() + index_to_del);
    }
    return numbers;
}
std::vector<char> getPerm(const Tree& tree, int d) {
    std::vector<std::vector<char>> ps = tree.getPs(3);
    if (perms.size() < d)
        return {};
    return ps[d - 1];
}
