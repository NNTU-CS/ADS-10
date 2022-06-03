// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> bran;
  };
  Node *root;
  std::string pointers[1000] = { "" };
  void make(Node *root, std::vector<char> vec) {
    if (vec.size()) {
      if (root->value != 'x') {
        for (auto i = vec.begin(); i != vec.end(); ++i) {
          if (*i == root->value) {
            vec.erase(i);
            break;
          }
        }
      }
      for (int i = 0; i < vec.size(); ++i) {
        root->bran.push_back(new Node);
      }
      for (int i = 0; i < root->bran.size(); ++i) {
        root->bran[i]->value = vec[i];
      }
      for (int i = 0; i < root->bran.size(); ++i) {
        make(root->bran[i], vec);
      }
    }
    return;
  }
  void permutate(Node *root, std::string w) {
  if (!root->bran.size()) {
    w += root->value;
    int n = 0;
    while (pointers[n] != "")
      ++n;
    pointers[n] = w;
    return;
  }
  if (root->value != '*') {
    w += root->value;
  }
  for (int i = 0; i < root->bran.size(); ++i) {
    permutate(root->bran[i], w);
  }
}

 public:
  std::string permutt(int i) const {
       return pointers[i - 1];
  }
  explicit Tree(std::vector<char> vec) {
    root = new Node;
    root -> value = '*';
    make(root, vec);
    permutate(root, "");
  }
};

#endif  // INCLUDE_TREE_H_
