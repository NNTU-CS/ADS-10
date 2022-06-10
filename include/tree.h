// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <vector>
#include <string>

struct Node {
  char symb;
  Node *parent;
  std::vector<Node> option;
};

class Tree {
 private:
  Node *root = new Node;
  std::vector<Node> combinations;
  void makeStructureTree(std::vector<char> array) {
    makeNode(root, array);
    conlink(root);
  }
  void makeNode(Node* crown, std::vector<char> array) {
    for (int j = 0; j < array.size(); j++) {
      Node *elem = new Node();
      elem->symb = array[j];
      crown->option.push_back(*elem);
      if (array.size() > 0) {
        makeNode(&crown->option[j], requireArray(array, array[j]));
      }
    }
  }
  void conlink(Node *crown) {
    for (Node &child : crown->option) {
      child.parent = crown;
      conlink(&child);
    }
    if (crown->option.size() == 0) {
      combinations.push_back(*crown);
    }
  }
  std::vector<char> requireArray(std::vector<char> array, char value) {
    std::vector<char>::iterator position = std::find(array.begin(),
    array.end(), value);
    if (position != array.end())
      array.erase(position);
    return array;
  }

 public:
  explicit Tree(std::vector<char> array) {
    makeStructureTree(array);
  }
  std::vector<char> getCombinationsByNumber(Tree tree, int number) {
    if (number > combinations.size()) {
      return {};
    }
    std::vector<char> result;
    Node current = combinations[number-1];
    while (current.parent) {
      result.push_back(current.symb);
      current = *current.parent;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
#endif  // INCLUDE_TREE_H_
