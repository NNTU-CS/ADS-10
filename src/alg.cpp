#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> p = tree.getP();
    if (n <= p.size()) {
        return p[n - 1];
    }
    return {};
}
