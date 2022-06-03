// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> listok;
    };
    Node* root;

    void treeConstr(Node* root, std::vector<char> path) {
        if (!path.size())
            return;
        if (root->value != '*') {
            for (auto syn = path.begin(); syn != path.end(); syn++)
                if (*syn == root->value) {
                    path.erase(syn);
                    break;
                }
        }
        for (size_t i = 0; i < path.size(); i++)
            root->listok.push_back(new Node());
        for (size_t i = 0; i < root->listok.size(); i++)
            root->listok[i]->value = path[i];
        for (size_t i = 0; i < root->listok.size(); i++)
            treeConstr(root->listok[i], path);
    }

    std::vector<std::string> sw;
    void swapp(Node* root, std::string let = "") {
        if (!root->listok.size()) {
            let += root->value;
            sw.push_back(let);
            return;
        }
        if (root->value != '*')
            let += root->value;
        for (size_t i = 0; i < root->listok.size(); i++)
            swapp(root->listok[i], let);
    }

 public:
    std::string operator[](int i) const {
        if (i >= sw.size()) return "";
        return sw[i];
    }

    explicit Tree(std::vector<char> value) {
        root = new Node();
        root->value = '*';
        treeConstr(root, value);
        swapp(root);
    }
};

#endif  // INCLUDE_TREE_H_
