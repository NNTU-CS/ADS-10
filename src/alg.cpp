// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
std::vector<char> delete(std::vector<char> digit, int code) {
    if (code >= 0 && code < digit.size()) {
        digit.erase(digit.begin() + code);
    }
    return digit;
}
std::vector<char> getPerm(const Tree& tree, int r) {
    std::vector<std::vector<char>> perms = tree.getPerms(3);
    if (perms.size() < r)
        return {};
    return perms[r - 1];
}
