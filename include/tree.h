// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
      char value;
      std::vector<Node*> branch;
    };
    Node* root;
    std::vector<std::string> perm;

    void makeTree(Node* root, std::vector<char> vec) {
      if (!vec.size()) {
        return;
      }
      if (root->value != '*') {
        vec.erase(std::find(vec.begin(), vec.end(), root->value));
      }
      for (int i = 0; i < vec.size(); i++) {
        root->branch.push_back(new Node());
      }
      for (int i = 0; i < root->branch.size(); i++) {
        root->branch[i]->value = vec[i];
        makeTree(root->branch[i], vec);
      }
    }

    void Perm(Node* root, std::string s = "") {
      if (!root->branch.size()) {
        s += root->value;
        perm.push_back(s);
        return;
      }
      if (root->value != '*') {
        s += root->value;
      }
      for (int i = 0; i < root->branch.size(); ++i) {
        Perm(root->branch[i], s);
      }
    }

 public:
    explicit Tree(std::vector<char> vec) {
      root = new Node();
      root->value = '*';
      makeTree(root, vec);
      Perm(root);
    }

    std::string get(int i) const{
      if (i >= perm.size()) {
        return "";
      }
      return perm[i];
    }
};
#endif  // INCLUDE_TREE_H_
