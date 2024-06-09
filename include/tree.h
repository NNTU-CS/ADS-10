// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
  char elem;
  std::vector<Node*> childs;
  explicit Node(char c) : elem(c) {}
};

class Tree {
 public:
  std::vector<std::vector<char> > getPerm() const {
    std::vector <std::vector<char>> perm;
    std::vector<char> current;
    generatePermut(root, &current, &perm);
    return perm;
  }

  explicit Tree(const std::vector<char>& symbol) {
    root = new Node('\0');
    buildTree(symbol, root);
  }

 private:
  Node* root;
  void buildTree(const std::vector<char>& symbol, Node* parent) {
    for (char c : symbol) {
      Node* child = new Node(c);
      parent->childs.push_back(child);
      std::vector<char> remainingSymbol(symbol);
      remainingSymbol.erase(std::find(remainingSymbol.begin(),
        remainingSymbol.end(), c));
      buildTree(remainingSymbol, child);
    }
  }

  void generatePermut(Node* data, std::vector<char>* dataPermutation,
std::vector<std::vector<char>>* permutations) const {
    dataPermutation->push_back(data->elem);
    if (data->childs.empty()) {
      permutations->push_back(*dataPermutation);
    } else {
      for (Node* child : data->childs) {
        generatePermut(child, dataPermutation, permutations);
      }
    }
    dataPermutation->pop_back();
  }
};
#endif  // INCLUDE_TREE_H_
