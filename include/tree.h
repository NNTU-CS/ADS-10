// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    bool isRootPerem = false;
    char valPerem;
    std::vector<Node*> pointersPerem;
};

class Tree {
private:
    Node* root;
    std::vector<std::vector<char> > perms;

    void insert(Node* root, const std::vector<char>& vec) {
        for (char c : vec) {
            Node* tmp = new Node;
            tmp->valPerem = c;
            root->pointersPerem.push_back(tmp);
            std::vector<char> remainingChars(vec);
            remainingChars.erase(std::find(remainingChars.begin(),
                remainingChars.end(), c));
            insert(tmp, remainingChars);
        }
    }

    void findPerms(Node* root, std::vector<char> vec) {
        if (!root->isRootPerem) vec.push_back(root->valPerem);
        if (root->pointersPerem.empty()) perms.push_back(vec);
        for (Node* child : root->pointersPerem) findPerms(child, vec);
    }

public:
    explicit Tree(const std::vector<char>& vec) {
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
