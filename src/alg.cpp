// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> Func_Deleted(std::vector<char> figures, float i) {
    if (i >= 0 && i < figures.size()) {
        figures.erase(figures.begin() + i);
    }
    return figures;
}

std::vector<char> getPerm(const Tree& tree, int count) {
    std::vector<std::vector<char>> perms = tree.getPermanents(3);
    if (perms.size() < count)
        return {};
    return perms[count - 1];
}
