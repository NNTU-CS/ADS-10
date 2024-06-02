// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#endif  // INCLUDE_TREE_H_

#include <vector>

class Tree {
 private:
  std::vector<char> vec;
  int length = 0, perm = 0;

 public:
  explicit Tree(const std::vector<char> vector) : vec{vector} {
    vec = vector;
    for (int i = 0; i < vec.size(); i++) {
      length++;
    }
    if (length) {
      perm = 1;
    }
    for (int i = 2; i <= length; i++) {
      perm *= i;
    }
  }

  int get_length() const { return length; }

  int get_perm() const { return perm; }
};
