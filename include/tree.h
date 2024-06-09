// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
public:
    explicit Tree(const std::vector<char>& in);
    std::vector<char> getPerm(int n);
private:
    void buildTree(const std::vector<char>& in);
    std::vector<char> getPermRecursive(int n, int level);
};

#endif  // INCLUDE_TREE_H_
