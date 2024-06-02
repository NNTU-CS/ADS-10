// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>

struct Node {
    char value;
    std::vector<Node*> Leaves;
};

class Tree {
 public:
    Node* root;
    Tree(std::vector<char> v) {
        root = new Node;
        for (int i = 0; i < v.size(); i++) {
            root->Leaves.push_back(new Node);
        }
        for (int i = 0; i < v.size(); i++) {
            root->Leaves[i] = addNodes(v, root->Leaves[i], v[i]);
        }
    }

    Node* addNodes(std::vector<char> v, Node* node, int n) {
            node->value = n;
            for (int i = 0; i < v.size() - 1; i++) {
                Node* tmp = new Node;
                node->Leaves.push_back(tmp);
                std::vector<char> c;
                c = v;
                c.erase(std::find(c.begin(), c.end(), n));
                node->Leaves[i] = addNodes(c, node->Leaves[i], c[i]);
            }
        return node;
    }

    int depthTree() {
        int count = 0;
        if (root) {
            count++;
            Node* tmp = root->Leaves[0];
            while (tmp->Leaves.size() != 0) {
                count++;
                tmp = tmp->Leaves[0];
            }
            return count;
        } else {
            return 0;
        }
    }
};

std::vector<char> getPerm(const Tree&, int);

#endif  // INCLUDE_TREE_H_
