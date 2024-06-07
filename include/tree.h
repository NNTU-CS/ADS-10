// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node*> child;
        char value;
    };
    Node* root;
    std::vector<std::vector<char>> consta;
 public:
    explicit Tree(std::vector<char> in) {
        root = new Node;
        std::vector<char> used;
        buildTree(root,in);
        Perm(root,used);
    }

    void buildTree(Node* root, std::vector<char> in) {
        if (!in.empty()) {
            for (int i = 0; i < in.size(); i++) {
                std::vector<char> temp;
                Node* next = new Node;
                next -> value;
                root -> child.push_back(next);
                temp.erase(temp.begin() + 1);
                buildTree(root -> child.back(), temp);
                }
            } else {
                return;
            } 
    }
    
    void Perm(Node* root, const std::vector<char> used) {
    std::vector<char> copy = used;
    for (int i = 0; i < root->child.size(); i++) {
      copy.push_back(root->child[i]->value);
        if (root->child[i]->child.empty()) {
          consta.push_back(copy);
        }
      Perm(root->child[i], copy);
      copy.pop_back();
    }
    }

    std::vector<char> GetPerm(int i) const {
    if (i > consta.size() - 1) {
      std::vector<char> null;
      return null;
    }
    return consta[i];
  }
};
#endif  // INCLUDE_TREE_H_
