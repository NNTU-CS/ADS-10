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
  vector<Node*> ir;
  char vall;
  };
  Node* rroott;
  vector<string> iir2;
  void createTr(Node* rroott, vector<char> chch) {
  if (rroott->vall != '*') {
  chch.erase(find(chch.begin(), chch.end(), rroott->vall));
  }
  if (!chch.size()) {
  return;
  }
  for (size_t j = 0; j < chch.size(); j++)
  rroott->ir.push_back(new Node());
  for (size_t j = 0; j < rroott->ir.size(); j++) {
  rroott->ir[j]->vall = chch[j];
  createTr(rroott->ir[j], chch);
  }
  }
  void Permut(Node* rroott, string strr = "") {
  if (rroott->vall != '*') {
  strr += rroott->vall;
  }
  if (!rroott->ir.size()) {
  strr += rroott->vall;
  iir2.push_back(strr);
  return;
  }
  for (int j = 0; j < rroott->ir.size(); j++) {
  Permut(rroott->ir[j], strr);
  }
  }

 public:
  string operator[](int j) const {
  if (j >= iir2.size()) {
  return "";
  }
  return iir2[j];
  }
  explicit Tree(vector<char> vall) {
  rroott = new Node();
  rroott->vall = '*';
  createTr(rroott, vall);
  Permut(rroott);
  }
};
#endif  // INCLUDE_TREE_H_
