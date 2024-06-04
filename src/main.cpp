// Copyright 2022 NNTU-CS
#include  <vector>
#include  <iostream>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n);

int main() {
    vector<char> symbols = { 'A', 'B', 'C' };
    Tree tree(symbols);
    vector<char> perm1 = getPerm(tree, 1); //первая
    vector<char> perm2 = getPerm(tree, 3); //третья
    for (char c : perm1) {
        cout << c << " ";
    }
    cout << endl;
    for (char c : perm2) {
        cout << c << " ";
    }
   cout << std::endl;
}
