// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int num) {
    int i = 0;
    std::string chisla = tree[--num];
    std::vector<char> result;
    while (i < chisla.size()) {
        result.push_back(chisla[i]);
        i++;
    }
    return result;
}
