// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>
#include <string>

class Tree {
 private:
  struct List {
    std::vector <List> list;
    char val;
  };
  List* root = nullptr;
  std::vector<char> combinations;
  int ncombinations = 0;
  int countcombinations = 0;
  std::vector<char> delelement(std::vector<char> arr, char value) {
    std::vector<char> extra;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] != value) {
        extra.push_back(arr[i]);
      }
    }
    return extra;
  }
  std::vector<List> createList(std::vector<char> vec, List* head) {
    std::vector<List> pvec;
    for (int i = 0; i < vec.size(); i++) {
      List* p = new List;
      p->val = vec[i];
      p->list = createList(delelement(vec, vec[i]), p);
      pvec.push_back(*p);
    }
    return pvec;
  }
  std::string getelement(List* cur, std::string str) {
    if (cur->val != 'o') {
      str += cur->val;
    }
    for (int i = 0; i < cur->list.size(); i++) {
      getelement(&cur->list[i], str);
    }
    if (str.length() == root->list.size()
        && ncombinations == countcombinations - 1 && combinations.empty()) {
      for (int i = 0; i < str.length(); i++) {
        combinations.push_back(str[i]);
      }
    } else if (str.length() == root->list.size()) {
      ncombinations += 1;
    }
    return str;
  }

 public:
  explicit Tree(std::vector<char> vec) {
    root = new List;
    root->val = 'o';
    root->list = createList(vec, root);
  }
  std::vector<char> getPerm(int n) {
    countcombinations = n;
    getelement(root, "");
    std::vector<char> result = combinations;
    combinations.clear();
    ncombinations = 0;
    return result;
  }
};
#endif  // INCLUDE_TREE_H_
