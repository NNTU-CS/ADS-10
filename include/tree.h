// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <cstdint>
#include <string>
#include <vector>

class Tree {
private:
struct Node;
std::vectorstd::string perm;
Node* rootNode;

void constructTree(Node* parent, std::vector<char> trail);
void generatePerm(Node* parent, std::string currentPerm = "");
public:
explicit Tree(const std::vector<char>);

std::string getPerm(unsigned int index) const;
};

#endif  // INCLUDE_TREE_H_
