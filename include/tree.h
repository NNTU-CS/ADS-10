// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char number;
    std::vector<Node*> v;
  };
  Node* root = nullptr;
  std::vector<std::string> change;
  void addNode(Node* root, std::vector<char> vec) {
    if (root->number != 'x') {
      for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == root->number) {
          for (int j = i; j < vec.size() - 1; ++j) {
            vec[j] = vec[j + 1];
          }
          vec.pop_back();
          break;
        }
      }
    }
    for (int i = 0; i < vec.size(); ++i) {
      root->v.push_back(new Node());
    }
    for (int i = 0; i < root->v.size(); ++i) {
      root->v[i]->number = vec[i];
    }
    for (int i = 0; i < root->v.size(); ++i) {
      addNode(root->v[i], vec);
    }
  }
  void array1(Node* root, std::string sym = "") {
    if (root->number != 'x' && root->v.size() != 0) {
      sym += root->number;
    }
    if (root->v.size() == 0) {
      sym += root->number;
      change.push_back(sym);
      sym = "";
    }
    for (int i = 0; i < root->v.size(); ++i) {
      array1(root->v[i], sym);
    }
  }

 public:
  explicit Tree(std::vector<char> vec) {
    root = new Node();
    root->number = 'x';
    addNode(root, vec);
    array1(root);
  }
  std::string getChange(int n) const {
    if (n > change.size()) {
      return "";
    } else {
      return change[n - 1];
    }
  }
};
#endif  // INCLUDE_TREE_H_
