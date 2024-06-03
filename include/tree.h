// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    char valuePerem;
    std::vector<Node *> pointersPerem;
    bool isRootPerem = false;
};

class Tree {
 private:
    std::vector<std::vector<char> > perms;
    Node *root;

    void insert(Node *root, const std::vector<char> &vec) {
        for (char c : vec) {
            Node *temp = new Node;
            temp->valuePerem = c;
            root->pointersPerem.push_back(temp);
            std::vector<char> remainingChars(vec);
            remainingChars.erase(std::find(remainingChars.begin(),
                                           remainingChars.end(), c));
            insert(temp, remainingChars);
        }
    }

    void findPerms(Node *root, std::vector<char> vec) {
        if (!root->isRootPerem) vec.push_back(root->valuePerem);
        if (root->pointersPerem.empty()) perms.push_back(vec);
        for (Node *child : root->pointersPerem) findPerms(child, vec);
    }

 public:
    explicit Tree(const std::vector<char> &vec) {
        root = new Node;
        root->isRootPerem = true;
        insert(root, vec);
        std::vector<char> current;
        findPerms(root, current);
    }

    std::vector<std::vector<char> > getPermutations() const {
        return perms;
    }
};

#endif  // INCLUDE_TREE_H_
