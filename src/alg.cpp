// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string result = tree.getPermutation(tree.getRoot(), n);
    if (result != "0") {
        std::vector<char> characters;
        size_t i = 0;
        while (i < result.length() && result[i] != '\0') {
            characters.push_back(result[i]);
            i++;
        }
        return characters;
    } else {
        std::vector<char> characters;
        return characters;
    }
}
