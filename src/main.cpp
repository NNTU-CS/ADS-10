// Copyright 2022 NNTU-CS
#include "tree.h"
#include <iostream>

int main() {
    // определяем входной вектор для дерева
    std::vector<char> in = {'1', '2', '3'};
    // создаем дерево
    Tree tree(in);
    // запрашиваем первую перестановку
    std::vector<char> result1 = getPerm(tree, 1);  // 123
    for (char c : result1) std::cout << c;
    std::cout << std::endl;
    // запрашиваем вторую перестановку
    std::vector<char> result2 = getPerm(tree, 2);  // 132
    for (char c : result2) std::cout << c;
    std::cout << std::endl;
    return 0;
}
