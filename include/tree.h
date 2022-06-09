// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
#include <algorithm>
struct Node {
  char sign;
  Node *parent;
  std::vector<Node> var;
};

class Tree {
 private:
  Node *root = new Node;
  std::vector<Node> permutations;
  void MakeTree(std::vector<char> arr) {
    createNode(root, arr);
    link(root);
  }
  void createNode(Node* head, std::vector<char> arr) {
    for (int i = 0; i < arr.size(); i++) {
      Node *item = new Node();
      item->sign = arr[i];
      head->var.push_back(*item);
      if (arr.size() > 0) {
        createNode(&head->var[i], expectArray(arr, arr[i]));
      }
    }
  }
  void link(Node *head) {
    for (Node &child : head->var) {
      child.parent = head;
      link(&child);
    }
    if (head->var.size() == 0) {
      permutations.push_back(*head);
    }
  }
  std::vector<char> expectArray(std::vector<char> arr, char value) {
    std::vector<char>::iterator position = std::find(arr.begin(),
                                                     arr.end(), value);
    if (position != arr.end()) {
      arr.erase(position);
    }
    return arr;
  }

 public:
  explicit Tree(std::vector<char> arr) {
    MakeTree(arr);
  }
  std::vector<char> GetElement(Tree tree, int m) {
    if (m > permutations.size()) {
      return {};
    }
    std::vector<char> res;
    Node cur = permutations[m - 1];
    while (cur.parent) {
      res.push_back(cur.sign);
      cur = *cur.parent;
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
#endif  // INCLUDE_TREE_H_
