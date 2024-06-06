// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <cstdint>
#include <string>
#include <vector>

class Tree {
 private:
    struct Node;
    std::vector<std::string> p;
    Node* s;

    void createTree(Node* s, std::vector<char> tr);

    void perems(Node* s, std::string symb);

 public:
    explicit Tree(const std::vector<char>);

    std::string operator[] (unsigned int i) const;
};

#endif  // INCLUDE_TREE_H_
