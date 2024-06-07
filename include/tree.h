// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
  struct Node {
    std::vector<Node*> descendant;
    char val;
  };
  Node* root;
  std::vector<std::vector<char>> direct;

 public:
  explicit Tree(std::vector<char> in) {
    root = new Node;
    std::vector<char> used;
    build(root, in);
    post(root, used);
  }

  void build(Node* root, std::vector<char> in) {
    if (!in.empty()) {
      for (int i = 0; i < in.size(); i++) {
        std::vector<char> temp = in;
        Node* next = new Node;
        next->val = in[i];
        root->descendant.push_back(next);
        temp.erase(temp.begin() + i);
        build(root->descendant.back(), temp);
      }
    } else {
      return;
    }
  }

  void post(Node* root, const std::vector<char> used) {
    std::vector<char> copy = used;
    for (int i = 0; i < root->descendant.size(); i++) {
      copy.push_back(root->descendant[i]->val);
        if (root->descendant[i]->descendant.empty()) {
          direct.push_back(copy);
        }
      post(root->descendant[i], copy);
      copy.pop_back();
    }
  }

  std::vector<char> Getpost(int i) const {
    if (i > direct.size() - 1) {
      std::vector<char> null;
      return null;
    }
    return direct[i];
  }
};
#endif  // INCLUDE_TREE_H_
