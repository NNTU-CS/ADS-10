// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    Tree tree1 = tree;
    std::vector<char> rer;
    tree1.print();
    std::vector<std::vector<char>> res = tree1.Perm();
    if (n - 1 > res.size())
        return rer;
    auto it = std::remove(res[n - 1].begin(), res[n - 1].end(), '*');
    res[n - 1].erase(it, res[n - 1].end());
    return res[n - 1];
}
