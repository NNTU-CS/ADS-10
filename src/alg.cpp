#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    return tree.getPermutation(n - 1);
}
