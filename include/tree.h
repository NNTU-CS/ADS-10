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
      for (int a = 0; a < numbers.size(); a++) {
        root->childs.push_back(new Node);
      }
      for (int a = 0; a < root->childs.size(); a++) {
        root->childs[a]->value = numbers[a];
        createTree(root->childs[a], numbers);
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
      for (int a = 0; a < root->childs.size(); a++) {
        count_all_perm(root->childs[a], temp);
      }
    }

 public:
    std::vector<char> get_perm(int a) const {
      std::vector<char> empt;
      if (a >= all_perm.size()) return empt;
      return all_perm[a];
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
