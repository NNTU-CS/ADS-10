// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <cstdint>
#include <string>
#include <vector>

class Tree {
 private:
    struct Nd;
    std::vector<std::string> Premut;
    Nd* prava;
    void buildTree(Nd* sir, std::vector<char> sled);
    void generatePermut(Nd* sir, std::string Sim);
 public:
    explicit Tree(const std::vector<char>);
    std::string operator[] (unsigned int y) const;
};
#endif  // INCLUDE_TREE_H_
