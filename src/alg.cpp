// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::string Permut_string = tree[n - 1];
    std::vector<char> PermutDone;
    for (int y = 0; y < Permut_string.length(); y++) {
        PermutDone.push_back(Permut_string[y]);
    }
    return PermutDone;
}

struct Tree::Nd {
    char NVal;
    std::vector<Nd*> NewN;
};

void Tree::buildTree(Nd* prava, std::vector<char> sled) {
    if (!sled.size()) {
        return;
    }
    if (prava->NVal != '*') {
        for (auto y = sled.begin(); y < sled.end(); y++) {
            if (*y == prava->NVal) {
                sled.erase(y);
                break;
            }
        }
    }
    for (int y = 0; y < sled.size(); y++) {
        prava->NewN.push_back(new Nd);
    }
    for (int y = 0; y < prava->NewN.size(); y++) {
        prava->NewN[y]->NVal = sled[y];
    }
    for (int y = 0; y < prava->NewN.size(); y++) {
        buildTree(prava->NewN[y], sled);
    }
}

void Tree::generatePermut(Nd* roditel, std::string symvol = "") {
    if (!roditel->NewN.size()) {
        symvol += roditel->NVal;
        Premut.push_back(symvol);
    }
    if (roditel->NVal != '*') {
        symvol += roditel->NVal;
    }
    for (int y = 0; y < roditel->NewN.size(); y++) {
        generatePermut(roditel->NewN[y], symvol);
    }
}

Tree::Tree(const std::vector<char> Val) {
    prava = new Nd();
    prava->NVal = '*';
    buildTree(prava, Val);
    generatePermut(prava);
}

std::string Tree::operator[] (unsigned int y) const {
    if (y >= Premut.size()) {
        return "";
    }
    if (y < 0) {
        throw std::string("ne prvilno");
    }
    return Premut[y];
}
