// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> leaves;
    };
    Node* root;

    void rootConstr(Node* root, std::vector<char> time) {
        if (!time.size())
            return;
        if (root->value != '*') {
            for (auto syn = time.begin(); syn != time.end(); syn++)
                if (*syn == root->value) {
                    time.erase(syn);
                    break;
                }
        }
        for (size_t i = 0; i < time.size(); i++)
            root->leaves.push_back(new Node());
        for (size_t i = 0; i < root->leaves.size(); i++)
            root->leaves[i]->value = time[i];
        for (size_t i = 0; i < root->leaves.size(); i++)
            rootConstr(root->leaves[i], time);
    }

    std::vector<std::string> sw;
    void change(Node* root, std::string symb  = "") {
        if (!root->leaves.size()) {
            symb += root->value;
            sw.push_back(symb);
            return;
        }
        if (root->value != '*')
            symb  += root->value;
        for (size_t i = 0; i < root->leaves.size(); i++)
            change(root->leaves[i], symb);
    }

 public:
    std::string operator[](int i) const {
        if (i >= sw.size()) return "";
        return sw[i];
    }

    explicit Tree(std::vector<char> value) {
        root = new Node();
        root->value = '*';
        rootConstr(root, value);
        change(root);
    }
};
#endif  // INCLUDE_TREE_H_
