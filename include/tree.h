// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
        struct Node {
        char value = '\0';
        std::vector<Node*> children;
        };
    Node* root;
    std::vector<std::vector<char>> constant;

 public:
    explicit Tree(std::vector<char> entr) {
        std::vector<char> vec;
        root = new Node;
        build(root, entr);
        сonsts(root, vec);
    }
    void build(Node* root, std::vector<char> entr) {
        if (entr.size() != 0) {
            for (int i = 0; i < entr.size(); i++) {
                std::vector<char> temp = entr;
                Node* next = new Node;
                next->value = entr[i];
                root->children.push_back(next);
                temp.erase(temp.begin() + i);
                build(root->children.back(), temp);
            }
        }
    }
    void сonsts(Node* root, const std::vector<char> vec) {
        std::vector<char> temp = vec;
        for (int i = 0; i < root->children.size(); i++) {
            temp.push_back(root->children[i]->value);
            if (root->children[i]->children.size() == 0) {
                constant.push_back(temp);
            }
            сonsts(root->children[i], temp);
            temp.pop_back();
        }
    }
    std::vector<char> getPerm(int i) const {
        if (i > constant.size() - 1) {
            std::vector<char> null;
            return null;
        }
        return constant[i];
    }
};
#endif  // INCLUDE_TREE_H_
