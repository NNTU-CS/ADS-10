// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string Perm_str = tree[n - 1];
  std::vector<char> Perm_done;
  for (int i = 0; i < Perm_str.length(); i++) {
    Perm_done.push_back(Perm_str[i]);
  }
  return Perm_done;
}
struct Tree::Node {
  char n_val;
  std::vector<Node*> new_nnn;
};

void Tree::buildTree(Node* root, std::vector<char> trl) {
  if (!trl.size()) {
    return;
  }
  if (root->n_val != '*') {
    for (auto i = trl.begin(); i < trl.end(); i++) {
      if (*i == root->n_val) {
        trl.erase(i);
        break;
      }
    }
  }
  for (int i = 0; i < trl.size(); i++) {
    root->new_nnn.push_back(new Node);
  }
  for (int i = 0; i < root->new_nnn.size(); i++) {
    root->new_nnn[i]->n_val = trail[i];
  }
  for (int i = 0; i < root->new_nnn.size(); i++) {
    buildTree(root->new_nnn[i], trl);
  }
}

void Tree::gen_perm(Node* parnt, std::string symb = "") {
  if (!parnt->new_nnn.size()) {
    symb += parnt->n_val;
    perm.push_back(symb);
  }
  if (parnt->n_val != '*') {
    symb += parnt->n_val;
  }
  for (int i = 0; i < parnt->new_nnn.size(); i++) {
    gen_perm(parnt->new_nnn[i], symb);
  }
}

Tree::Tree(const std::vector<char> val) {
  root = new Node();
  root->n_val = '*';
  buildTree(root, val);
  gen_perm(root);
}

std::string Tree::opertr[] (unsigned int i) const {
  if (perm.size() <= i) {
    return "";
  }
  if (i < 0) {
    throw std::string("index wrng");
  }
  return perm[i];
}
