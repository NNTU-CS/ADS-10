// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
  struct Node {
    char value;
    std :: vector <Node*> childs;
  };
  Node* root;
  void creator(Node* root, std :: vector<char> path) {
    if (!path.size())
      return;
    if (root -> value != '*') {
      for (auto child = path.begin(); child != path.end();
           child++)
        if (*child == root -> value) {
          path.erase(child);
          break;
        }
    }
    for (size_t i = 0; i < path.size(); i++)
      root -> childs.push_back(new Node());
    for (size_t i = 0; i < root -> childs.size(); i++)
      root -> childs[i] -> value = path[i];
    for (size_t i = 0; i < root -> childs.size(); i++)
      creator(root -> childs[i], path);
  }

  std :: vector <std :: string> vect;
  void switcher(Node * root, std :: string znach = "") {
    if (!root -> childs.size()) {
      znach += root -> value;
      vect.push_back(znach);
    }
    if (root -> value != '*')
      znach += root -> value;
    for (size_t i = 0; i < root -> childs.size(); i++)
      switcher(root -> childs[i], znach);
  }

 public:
  std :: string operator[](int i) const {
    if (i >= vect.size())
      return "";
    return vect[i];
  }
  explicit Tree(std :: vector <char> value) {
    root = new Node();
    root -> value = '*';
    creator(root, value);
    switcher(root);
  }
};

#endif  // INCLUDE_TREE_H_
