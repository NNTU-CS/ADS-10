// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

struct Tree::Node {
  char data;
  std::vector<Node*> next_foor;
};

void Tree::perm(Node* root, std::string ch = "") {
  if (!root->next_foor.size()) {
    ch += root->data;
    permutations.push_back(ch);
  }
  if (root->data != '*') {
    ch += root->data;
  }
  for (int i = 0; i < root->next_foor.size(); ++i) {
    perm(root->next_foor[i], ch);
  }
}

void Tree::makeTree(Node* root, std::vector<char> way) {
  if (!way.size()) {
    return;
  }
  if (root->data != '*') {
    for (int i = 0; i < way.size(); ++i) {
      if (way[i] == root->data) {
        way.erase(way.begin() + i);
        break;
      }
    }
  }
  for (int i = 0; i < way.size(); ++i) {
    root->next_foor.push_back(new Node);
  }
  for (int i = 0; i < root->next_foor.size(); ++i) {
    root->next_foor[i]->data = way[i];
  }
  for (int i = 0; i < root->next_foor.size(); ++i) {
    makeTree(root->next_foor[i], way);
  }
}

Tree::Tree(const std::vector<char> &data) {
  root = new Node();
  root->data = '*';
  makeTree(root, data);
  perm(root);
}

std::string Tree::operator [] (const unsigned int i) const {
  if (i >= permutations.size() || i < 0) {
    return "";
  }
  return permutations[i];
}

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string temp = tree[n - 1];
  std::vector<char> wishperm;
  for (int i = 0; i < temp.length(); ++i) {
    wishperm.push_back(temp[i]);
  }
  return wishperm;
}
