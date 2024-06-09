// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node *> childs;
        char value;
    };
    Node *root;
    std::vector<std::vector<char>> permuts;

    void buildTree(Node *node, std::vector<char> values) {
        if (!node) {
            node = new Node;
        }
        if (values.empty()) {
            return;
        }
        for (int i = 0; i < values.size(); i++) {
            std::vector<char> remValues = values;
            Node *chil = new Node;
            chil->value = values[i];
            node->childs.push_back(chil);
            remValues.erase(remValues.begin() + i);
            buildTree(node->childs.back(), remValues);
        }
    }
    void generatePermuts(Node* node, const std::vector<char>& current) {
        std::vector<char> newCurrent = current;
        for (int i = 0; i < node->childs.size(); i++) {
            newCurrent.push_back(node->childs[i]->value);
            if (node->childs[i]->childs.empty()) {
                if (current.size() != 1) {
                    permuts.push_back(newCurrent);
                }
            }
            generatePermuts(node->childs[i], newCurrent);
            newCurrent.pop_back();
        }
    }

 public:
    explicit Tree(std::vector<char> values): root(nullptr) {
        root = new Node;
        buildTree(root, values);
        std::vector<char> current;
        generatePermuts(root, current);
    }
    std::vector<char> getPermut(int index) const {
        if (index < 0 || index >= permuts.size()) {
            return std::vector<char>();
        }
        return permuts[index];
    }
};
#endif  // INCLUDE_TREE_H_
