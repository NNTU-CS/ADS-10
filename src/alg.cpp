// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> udal(std::vector<char> chis, int por_nom) {
    if (por_nom >= 0 && por_nom < chis.size()) {
        chis.erase(chis.begin() + por_nom);
    }
    return chis;
}
std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
    std::vector<std::vector<char>> recs = tree.receive(3);
    if (recs.size() < n)
        return {};
    return recs[n - 1];
}
