// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 public:
  explicit Tree(std::vector<char> init) :root(nullptr) {
    createPermutations(init);
  }
  std::vector<std::vector<char>> getPerm() const {
    return permutations;
  }

 private:
  struct Node {
    char symbol;
    std::vector<Node*> descen_p;
    explicit Node(char symbol_one = '\0') :symbol(symbol_one) {}
  };
  Node* root;
  std::vector<std::vector<char>> permutations;

  void addNode(Node* new_root, std::vector<char> row_first) {
    if (!new_root) {
      root = new_root = new Node;
    }
    for (char symbol : row_first) {
      Node* temp = new Node(symbol);
      new_root->descen_p.push_back(temp);
      std::vector<char> newRow(row_first);
       newRow.erase(std::find(newRow.begin(), \
                              newRow.end(), symbol));
      addNode(temp, newRow);
    }
  }

  void evadeTree(Node* new_root, std::vector<char> row_first) {
    if (new_root != nullptr && new_root->symbol != '\0')
      row_first.push_back(new_root->symbol);
    if (new_root->descen_p.empty())
      permutations.push_back(row_first);
    for (Node* descen_p : new_root->descen_p) {
      evadeTree(descen_p, row_first);
    }
  }

  void createPermutations(std::vector<char> row_first) {
    addNode(root, row_first);
    evadeTree(root, {});
  }
};
#endif  // INCLUDE_TREE_H_
