// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    char value;
    std::vector<Node *> vch;
};

class Tree {
 private:
    Node *root;
    std::vector<std::vector<char>> allPer;

    void CreatTree(Node *root, std::vector<char> values) {
        if (values.empty()) {
            return;
        }
        if (!root) {
            root = new Node;
        }
        for (int i = 0; i < values.size(); i++) {
            std::vector<char> vCopyVal;
            copy(values.begin(), values.end(), vCopyVal.begin());
            Node *child = new Node;
            child->value = values[i];
            root->vch.push_back(child);
            vCopyVal.erase(vCopyVal.begin() + i);
            CreatTree(root->vch.back(), vCopyVal);
        }
    }

  void genPer(Node* node, const std::vector<char>& vCur) {
    std::vector<char> vCopyCur;
    copy(vCur.begin(), vCur.end(), vCopyCur.begin());
    for (int i = 0; i < node->vch.size(); i++) {
        vCopyCur.push_back(node->vch[i]->value);
        if (node->vch[i]->vch.empty()) {
            if (vCur.size() != 1) {
                allPer.emplace_back(vCopyCur);
            }
        } else {
            genPer(node->vch[i], vCopyCur);
        }
        vCopyCur.pop_back();
    }
}
 public:
    explicit Tree(std::vector<char> values): root(nullptr) {
        root = new Node;
        Tree(root, values);
        std::vector<char> vCur;
        genPer(root, vCur);
    }
    std::vector<char> getPermutation(int i) const {
        return allPer[i-1];
    }
};

#endif  // INCLUDE_TREE_H_
