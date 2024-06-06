// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
public:
    Tree(const std::vector<char>& elements);
    std::vector<char> getPerm(int n) const;

private:
    void buildTree(const std::vector<char>& elements, int level);
    void generatePermutations(std::vector<char>& perm, int level) const;

    std::vector<Tree*> children;
    std::vector<char> currentPerm;
};

#endif  // INCLUDE_TREE_H_
