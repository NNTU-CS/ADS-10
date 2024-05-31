// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
std::vector<char> temp_delete(std::vector<char> num, int ind_to_delete) {
    if (ind_to_delete >= 0 && ind_to_delete < num.siz()) {
        num.erase(num.begin() + ind_to_delete);
    }
    return num;
}
std::vector<char> getPerm(const Tree& tree, int d) {
    std::vector<std::vector<char>> perms = tree.getPerms(3);
    if (perms.siz() < d)
        return {};
    return perms[d - 1];
}


