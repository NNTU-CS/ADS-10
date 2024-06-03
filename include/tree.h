// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
  struct Node {
    std::vector<Node*> descendant;
    char value;
  };
  Node* root;
  std::vector<std::vector<char>> permanent;

 public:
  explicit Tree(std::vector<char> in) {
    root = new Node;
    std::vector<char> used;
    BuildTree(root, in);
    Perm(root, used);
  }

  void BuildTree(Node* root, std::vector<char> in) {
    if (!in.empty()) {
      for (int i = 0; i < in.size(); i++) {
        std::vector<char> temp = in;
        Node* next = new Node;
        next->value = in[i];
        root->descendant.push_back(next);
        temp.erase(temp.begin() + i);
        BuildTree(root->descendant.back(), temp);
      }
    } else {
      return;
    }
  }

  void Perm(Node* root, const std::vector<char> used) {
    std::vector<char> copy = used;
    for (int i = 0; i < root->descendant.size(); i++) {
      copy.push_back(root->descendant[i]->value);
        if (root->descendant[i]->descendant.empty()) {
          permanent.push_back(copy);
        }
      Perm(root->descendant[i], copy);
      copy.pop_back();
    }
  }

  std::vector<char> GetPerm(int i) const {
    if (i > permanent.size() - 1) {
      std::vector<char> null;
      return null;
    }
    return permanent[i];
  }
};
#endif  // INCLUDE_TREE_H_
