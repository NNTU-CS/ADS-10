// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <string>
#include <vector>


class Tree {
 private:
    struct Node {
      char value;
      std::vector <Node*> childs;
    };
    Node* root;

    void createTree(Node* root, std::vector<char> numbers) {
      if (!numbers.size()) {
        return;
      }
      if (root->value != '*') {
        numbers.erase(std::find(numbers.begin(), numbers.end(), root->value));
      }
      for (int i = 0; i < numbers.size(); i++) {
        root->childs.push_back(new Node);
      }
      for (int i = 0; i < root->childs.size(); i++) {
        root->childs[i]->value = numbers[i];
        createTree(root->childs[i], numbers);
      }
    }

    std::vector<std::vector<char>> all_perm;

    void count_all_perm(Node* root, std::vector<char> temp) {
      if (root->value != '*') {
        temp.push_back(root->value);
      }
      if (!root->childs.size()) {
        all_perm.push_back(temp);
        return;
      }
      for (int i = 0; i < root->childs.size(); i++) {
        count_all_perm(root->childs[i], temp);
      }
    }

 public:
    std::vector<char> get_perm(int i) const {
      std::vector<char> empt;
      if (i >= all_perm.size()) return empt;
      return all_perm[i];
    }
    explicit Tree(std::vector<char> input) {
      root = new Node();
      root->value = '*';
      createTree(root, input);
      std::vector<char> temp_1;
      count_all_perm(root, temp_1);
    }
};
#endif  // INCLUDE_TREE_H_
