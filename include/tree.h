// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Tree {
 private:
  struct Node {
    std::vector<Node*> child;
    char value;
  };
  Node* root;
  std::vector<std::vector<char>> constant;

 public:
  explicit Tree(std::vector<char> entry) {
    std::vector<char> vec;
    root = new Node;
    BuildTree(root, entry);
    Constant(root, vec);
  }
  void BuildTree(Node* root, std::vector<char> entry) {
    if (entry.size() != 0) {
      for (int i = 0; i < entry.size(); i++) {
        std::vector<char> tempVec = entry;
        Node* next = new Node;
        next->value = entry[i];
        root->child.push_back(next);
        tempVec.erase(tempVec.begin() + i);
        BuildTree(root->child.back(), tempVec);
      }
    } else {
      return;
    }
  }
  void Constant(Node* root, const std::vector<char> vec) {
    std::vector<char> tempVec = vec;
    for (int i = 0; i < root->child.size(); i++) {
      tempVec.push_back(root->child[i]->value);
      if (root->child[i]->child.size() == 0) {
        constant.push_back(tempVec);
      }
      Constant(root->child[i], tempVec);
      tempVec.pop_back();
    }
  }
  std::vector<char> getConst(int i) const {
    if (i > constant.size() - 1) {
      std::vector<char> null;
      return null;
    }
    return constant[i];
  }
};
#endif  // INCLUDE_TREE_H_	#endif  // INCLUDE_TREE_H_
