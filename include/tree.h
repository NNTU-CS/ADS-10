// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> brat;
    };
    Node* root;
    void Btr(Node* root, std::vector<char> circ) {
        if (!circ.size())
            return;
        if (root->value != '*') {
            for (auto u = circ.begin(); u != circ.end(); u++)
            if (*u == root->value) {
                circ.erase(u);
                break;
            }
        }
        for (size_t wh = 0; wh < circ.size(); wh++)
            root->brat.push_back(new Node());
        for (size_t wh = 0; wh < root->brat.size(); wh++)
            root->brat[wh]->value = circ[wh];
        for (size_t wh = 0; wh < root->brat.size(); wh++)
            Btr(root->brat[wh], circ);
    }
    std::vector<std::string> gree;
    void mus(Node* root, std::string str = "") {
        if (!root->brat.size()) {
            str += root->value;
            gree.push_back(str);
        }
        if (root->value != '*')
            str += root->value;
        for (size_t wh = 0; wh < root->brat.size(); wh++)
            mus(root->brat[wh], str);
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
