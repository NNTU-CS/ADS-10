// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> rear;
    };
    Node* root;
    void Btr(Node* root, std::vector<char> number) {
        if (!number.size())
            return;
        if (root->value != '*') {
            for (auto u = number.begin(); u != number.end(); u++)
            if (*u == root->value) {
                number.erase(u);
                break;
            }
        }
        for (size_t a = 0; a < number.size(); a++)
            root->rear.push_back(new Node());
        for (size_t a = 0; a < root->rear.size(); a++)
            root->rear[a]->value = number[a];
        for (size_t a = 0; a < root->rear.size(); a++)
            Btr(root->rear[a], number);
    }
    std::vector<std::string> gree;
    void mus(Node* root, std::string str = "") {
        if (!root->rear.size()) {
            str += root->value;
            gree.push_back(str);
        }
        if (root->value != '*')
            str += root->value;
        for (size_t a = 0; a < root->rear.size(); a++)
            mus(root->rear[a], str);
    }

 public:
    std::string operator[](int i) const {
        if (i >= gree.size())
            return "";
        return gree[i];
    }
    explicit Tree(std::vector<char> value) {
        root = new Node();
        root->value = '*';
        Btr(root, value);
        mus(root);
    }
};
#endif  // INCLUDE_TREE_H_
