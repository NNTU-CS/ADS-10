// Copyright 2022 CheginArtyom
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <cstdint>
#include <string>
#include <vector>

class Tree {
 private:
    struct Node;
    std::vector<std::string> repl;
    Node* parent;

    void createTree(Node* parent, std::vector<char> trail);

    void perms(Node* parent, std::string symb);

 public:
    explicit Tree(const std::vector<char>);

    std::string operator[] (unsigned int i) const;
};

#endif  // INCLUDE_TREE_H_
