// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string perm_string = tree[n - 1];
  std::vector<char> permisdone;
  for (int i = 0; i < perm_string.length(); i++) {
    permisdone.push_back(perm_string[i]);
  }
  return permisdone;
}

struct Tree::Node {
  char nvalue;
  std::vector<Node*> child;
};

void Tree::createTree(Node* parent, std::vector<char> trail) {
  if (!trail.size()) {
    return;
  }
  if (parent->nvalue != '*') {
    for (auto i = trail.begin(); i < trail.end(); i++) {
      if (*i == parent->nvalue) {
        trail.erase(i);
        break;
      }
    }
  }
  for (int i = 0; i < trail.size(); i++) {
    parent->child.push_back(new Node);
  }
  for (int i = 0; i < parent->child.size(); i++) {
    parent->child[i]->nvalue = trail[i];
  }
  for (int i = 0; i < parent->child.size(); i++) {
    createTree(parent->child[i], trail);
  }
}

void Tree::perms(Node* parent, std::string symb = "") {
  if (!parent->child.size()) {
    symb += parent->nvalue;
    repl.push_back(symb);
  }
  if (parent->nvalue != '*') {
    symb += parent->nvalue;
  }
  for (int i = 0; i < parent->child.size(); i++) {
    perms(parent->child[i], symb);
  }
}

Tree::Tree(const std::vector<char> val) {
  parent = new Node();
  parent->nvalue = '*';
  createTree(parent, val);
  perms(parent);
}

std::string Tree::operator[] (unsigned int i) const {
  if (i >= repl.size()) {
    return "";
  }
  if (i < 0) {
    throw std::string("Wrong index!");
  }
  return repl[i];
}
