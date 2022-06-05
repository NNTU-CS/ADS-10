// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    std::vector<std::string> permutations;
    struct Node;
    Node* root;
    
    void perm(Node*, std::string);
    
    void makeTree(Node*, std::vector<char>);
    
 public:
    explicit Tree(const std::vector<char> &);
    
    std::string operator [] (const unsigned int i) const;
};

#endif  // INCLUDE_TREE_H_
