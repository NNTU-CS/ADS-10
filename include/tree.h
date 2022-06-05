// Copyright 2022 NNTU - CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>

class Tree {
 private:
  struct  Branch {
    char Data;
    std::vector<Branch*> subsidiary;
  };
  Branch* root;
  std::vector <char> val;
  std::string element;
  std::vector<char> trunsf;
  std::vector <std::vector<char>> res;

 public:
  explicit Tree(std::vector <char> in) {
    val = in;
    element.resize(in.size());
    trunsf.resize(in.size());
    Branch* root = new Branch;
    root->Data = '*';
    transformm(in, -1, 0, root);
  }
  Branch* Create_Tree(char val) {
    Branch* temp = new Branch;
    temp->Data = val;
    return temp;
  }
  void transformm(std::vector <char> in, int b, int num, Branch* root) {
    if (in.size() == 1) {
      res.push_back(trunsf);
      return;
    }
    auto c = in.cbegin();
    if (b >= 0) {
      num++;
      in.erase(c + b);
    }
    for (int i = 0; i < in.size(); i++) {
      root->subsidiary.push_back(Create_Tree(in[i]));
      trunsf[num] = in[i];
      transformm(in, i, num, root->subsidiary[i]);
    }
  }
  std::vector<char> getPerm(Tree tree, int num) {
    if (num > res.size())return{};
    return res[num - 1];
  }
};
#endif  // INCLUDE_TREE_H_
