// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string Perms_str = tree[n - 1];
  std::vector<char> Perms_done;
  for (int i = 0; i < Perms_str.length(); i++) {
    Perms_done.push_back(Perms_str[i]);
  }
  return Perms_done;
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
    root->new_nnn[i]->n_val = trl[i];
  }
  for (int i = 0; i < root->new_nnn.size(); i++) {
    buildTree(root->new_nnn[i], trl);
  }
}

void Tree::gen_perms(Node* parnt, std::string symb = "") {
  if (!parnt->new_nnn.size()) {
    symb += parnt->n_val;
    perms.push_back(symb);
  }
  if (parnt->n_val != '*') {
    symb += parnt->n_val;
  }
  for (int i = 0; i < parnt->new_nnn.size(); i++) {
    gen_perms(parnt->new_nnn[i], symb);
  }
}

Tree::Tree(const std::vector<char> val) {
  root = new Node();
  root->n_val = '*';
  buildTree(root, val);
  gen_perms(root);
}

std::string Tree::operator[] (unsigned int i) const {
  if (perm.size() <= i) {
    return "";
  }
  if (i < 0) {
    throw std::string("index wrng");
  }
  return perms[i];
}
