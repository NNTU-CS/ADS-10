// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
 private:
    std::vector<std::vector<char>> result;

    std::vector<std::vector<char>> permute(std::vector<char>& values) {
    if (values.size() == 1) {
      std::vector<char> toAppend = {values.back()};
      result.push_back(toAppend);
      return result;
    }

    for (int i = 0; i < values.size(); i++) {
      char c = values.back();
      values.pop_back();

      std::vector<std::vector<char>> perms = permute(values);

      for (auto& perm : perms) {
        perm.push_back(c);
        result.push_back(perm);
      }

      values.push_back(c);
    }

    return result;
    }

 public:
    explicit Tree(std::vector<char> values) {
        result = permute(values);
    }

    std::vector<char> getPermutation(int index) const {
        return result[index];
    }
};

#endif  // INCLUDE_TREE_H_
