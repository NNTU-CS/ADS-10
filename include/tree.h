// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char number;
    std::vector<Node*> sheet;
  };
  Node* root1;
  std::vector<std::string> subst;
  void NewTree(Node* root1,  std::vector<char> NewFig) {
    if (!NewFig.size()) {
      return;
    }
    if (root1->number != '*') {
     for (auto x = NewFig.begin(); x != NewFig.end(); ++x) {
        if (*x == root1->number) {
          NewFig.erase(x);
          break;
        }
      }
    }
    for (size_t i = 0; i < NewFig.size(); ++i) {
      root1->sheet.push_back(new Node);
    }
    for (size_t i = 0; i < root1->sheet.size(); ++i) {
      root1->sheet[i]->number = NewFig[i];
    }
    for (size_t i = 0; i < root1->sheet.size(); ++i) {
      NewTree(root1->sheet[i], NewFig);
    }
  }
  void Substitution(Node*root1, std::string s = "") {
    if (!root1->sheet.size()) {
      s += root1->number;
      subst.push_back(s);
      return;
    }
    if (root1->number != '*') {
      s += root1->number;
    }
    for (size_t i = 0; i < root1->sheet.size(); ++i) {
      Substitution(root1->sheet[i], s);
    }
  }


 public:
  explicit Tree(std::vector<char> b) {
    root1 = new Node();
    root1->number = '*';
    NewTree(root1, b);
    Substitution(root1);
  }
  std::string operator[](int i) const {
    if (i >= subst.size()) {
      return "";
    }
    return subst[i];
  }
};

#endif  // INCLUDE_TREE_H_
