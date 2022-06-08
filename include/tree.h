// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
#include <algorithm>
using std::string;
using std::vector;
class Tree {
 private:
  struct Node {
  char vl;
  vector<Node*> v1;
  };
  vector<string> i1;
  Node* rod;
  void createTr(Node* rod, vector<char> chh) {
  if (rod->vl != '*') {
  chh.erase(find(chh.begin(), chh.end(), rod->vl));
  }
  if (!chh.size()) {
  return;
  }
  for (size_t j = 0; j < chh.size(); j++)
  rod->v1.push_back(new Node());
  for (size_t j = 0; j < rod->v1.size(); j++) {
  rod->v1[j]->vl = chh[j];
  createTr(rod->v1[j], chh);
  }
  }
  void Permut(Node* rod, string strr = "") {
  if (rod->vl != '*')
  strr += rod->vl;
  if (!rod->v1.size()) {
  strr += rod->vl;
  i1.push_back(strr);
  return;
  }
  for (int j = 0; j < rod->v1.size(); j++)
  Permut(rod->v1[j], strr);
  }

 public:
  string operator[](int j) const {
  if (j >= i1.size()) {
  return "";
  }
  return i1[j];
  }
  explicit Tree(vector<char> vl) {
  rod = new Node();
  rod->vl = '*';
  createTr(rod, vl);
  Permut(rod);
  }
};
#endif  // INCLUDE_TREE_H_
