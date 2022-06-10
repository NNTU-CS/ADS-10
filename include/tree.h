// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 public:
  std::string operator[](int x) const {
  if (x >= newtr.size()) {
    return "";
  }
  return newtr[x];
}
  explicit Tree(std::vector<char> item) {
  root = new Node;
  root->item = '*';
  change(root, item);
  build(root);
  }

 private:
  struct Node {
  char item;
  std::vector<Node*> des;
  };
  Node* root;
  std::vector<std::string> newtr;
  void build(Node* root, std::string vari = "") {
    if (!root->des.size()) {
      vari += root->item;
      newtr.push_back(vari);
      return;
    }
  if (root->item != '*') {
    vari += root->item;
  }
  for (int x = 0; x < root->des.size(); x++) {
    build(root->des[x], vari);
  }
}
void change(Node* root, std::vector<char> vtr) {
  if (!vtr.size()) {
    return;
  }
  if (root->item != '*') {
  for (auto x = vtr.begin(); x != vtr.end(); x++) {
    if (*x == root->item) {
      vtr.erase(x);
      break;
    }
  }
  }
  for (int x = 0; x < vtr.size(); x++) {
    root->des.push_back(new Node);
  }
  for (int x = 0; x < root->des.size(); x++) {
    root->des[x]->item = vtr[x];
  }
  for (unsigned int x = 0; x < root->des.size(); x++) {
    change(root->des[x], vtr);
  }
}
};
#endif  // INCLUDE_TREE_H_
