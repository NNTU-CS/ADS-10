// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char d;
    std::vector<Node*> s;
  };
  Node* root;
  std::string p[30] = { "" };
  void buildTree(Node*, std::vector<char>);
  void perm(Node*, std::string);

 public:
  explicit Tree(std::vector<char> v) {
    root = new Node;
    root -> d = 'x';
    buildTree(root, v);
    perm(root, "");
  }
  std::string gPermut(int i) const {
    return p[i - 1];
  }
};

void Tree::buildTree(Node* root, std::vector<char> link) {
  if (!link.size()) {
    return;
  }
  if (root->d != 'x') {
    for (std::vector<char>::iterator t = link.begin(); t != link.end(); ++t) {
      if (*t == root->d) {
        link.erase(t);
        break;
      }
    }
  }
  for (int temp = 0; temp < link.size(); ++temp) {
    root->s.push_back(new Node);
  }
  for (int temp = 0; temp < root->s.size(); ++temp) {
    root->s[temp]->d = link[temp];
  }
  for (int temp = 0; temp < root->s.size(); ++temp) {
    buildTree(root->s[temp], link);
  }
}

void Tree::perm(Node* root, std::string s) {
  if (!root->s.size()) {
    s += root->d;
    int z = 0;
    while (true) {
      if (p[z] == "") {
        p[z] = s;
        break;
      } else {
        ++z;
      }
    }
    return;
  }
  if (root->d != 'x') {
    s += root->d;
  }
  for (int i = 0; i < root->s.size(); ++i) {
    perm(root->s[i], s);
  }
}
#endif  // INCLUDE_TREE_H_
