// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

struct Node {
    std::vector<Node *> children;
    char value;
};

class Tree {
 private:
    Node *root;
    std::vector<std::vector<char>> result;

    void initTree(Node *node, std::vector<char> values) {
        if (values.empty()) {
            return;
        }

        for (int i = 0; i < values.size(); i++) {
            std::vector<char> restValues = values;
            Node *child = new Node;
            child->value = values[i];
            node->children.push_back(child);
            restValues.erase(restValues.begin() + i);
            initTree(node->children.back(), restValues);
        }
    }

    void permute(Node* node, const std::vector<char>& temp) {
        std::vector<char> updatedCurrent = temp;

        for (int i = 0; i < node->children.size(); i++) {
            updatedCurrent.push_back(node->children[i]->value);

            if (node->children[i]->children.empty()) {
                result.push_back(updatedCurrent);
            }

            permute(node->children[i], updatedCurrent);
            updatedCurrent.pop_back();
        }
    }

 public:
    explicit Tree(std::vector<char> values) {
        root = new Node;
        initTree(root, values);
        std::vector<char> temp;
        permute(root, temp);
    }

    std::vector<char> getPermutation(int index) const {
        return result[index];
    }
};

#endif  // INCLUDE_TREE_H_
