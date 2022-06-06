// Copyright 2022 NNTU-CS
//Made by AndySter
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> nextNode;
    };
    Node* root;

    void rootBuild(Node* root, std::vector<char> path) {
        if (!path.size()) {
          return;
        }
        if (root -> value != '*') {
            for (auto syn = path.begin(); syn != path.end(); syn++) {
                if (*syn == root -> value) {
                    path.erase(syn);
                    break;
                }
            }
        }
        for (size_t a1 = 0; a1 < path.size(); a1++)
            root -> nextNode.push_back(new Node());
        for (size_t b1 = 0; b1 < root -> nextNode.size(); b1++)
            root -> nextNode[b1] -> value = path[b1];
        for (size_t c1 = 0; c1 < root -> nextNode.size(); c1++)
            rootBuild(root -> nextNode[c1], path);
    }

    std::vector<std::string> changeNode;
    void change(Node* root, std::string symb = "") {
        if (!root -> nextNode.size()) {
            symb += root -> value;
            changeNode.push_back(symb);
            return;
        }
        if (root -> value != '*')
            symb += root -> value;
        for (size_t i = 0; i < root -> nextNode.size(); i++)
            change(root -> nextNode[i], symb);
    }

 public:
    std::string operator[](int i) const {
        if ( i>= changeNode.size())
            return "";
        return changeNode[i];
    }

    explicit Tree(std::vector<char> value) {
        root = new Node();
        root -> value = '*';
        rootBuild(root, value);
        change(root);
    }
};

#endif  // INCLUDE_TREE_H_
