// Copyright 2022 NNTU-CS
#include "tree.h" 
#include <iostream> 
#include <vector> 

std::vector<char> getPerm(const Tree& tree, int n);

void printVector(const std::vector<char>& vec) { 
    for (char ch : vec) { 
        std::cout << ch; 
    } 
    std::cout << std::endl; 
} 

int main() { 
    // Определяем входной вектор для дерева 
    std::vector<char> in = {'1', '2', '3'}; 

    // Создаем дерево 
    Tree tree(in); 

    // Запрашиваем первую перестановку 
    std::vector<char> result1 = getPerm(tree, 1);  //  123 
    std::cout << "Permutation #" << 1 << ": "; 
    printVector(result1); 

    // Запрашиваем вторую перестановку 
    std::vector<char> result2 = getPerm(tree, 2);  //  132 
    std::cout << "Permutation #" << 2 << ": "; 
    printVector(result2); 

    return 0; 
}
