// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
    std::string p = tree.dex(tree.g_tor(), n);
    if (p != "0") {
        std::vector<char> q;
        for (char x : p) {
            if (x != '\0') {
                q.push_back(x);
            }
        }
        return q;
    } 
    else {
        std::vector<char> q;
        return q;
    }
}
