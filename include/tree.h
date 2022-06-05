// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> bratList;
    };
    Node* root;
    void createtree(Node* root, std::vector<char> circle) {
        if (!circle.size())
            return;
        if (root->value != '*') {
            for (auto i = circle.begin(); i != circle.end(); i++) {
             if (*i == root->value) {
              circle.erase(i);
              break;
             }
            }
        }
        for (size_t wh = 0; wh < circle.size(); wh++) {
         root->bratList.push_back(new Node());
        }
        for (size_t wh = 0; wh < root->bratList.size(); wh++) {
         root->bratList[wh]->value = circle[wh];
        }
        for (size_t wh = 0; wh < root->bratList.size(); wh++) {
         createtree(root->bratList[wh], circle);
        }
    }
    std::vector<std::string> gree;
    void pr(Node* root, std::string str = "") {
        if (!root->bratList.size()) {
            str += root->value;
            gree.push_back(str);
        }
        if (root->value != '*') {
         str += root->value;
        }
        for (size_t wh = 0; wh < root->bratList.size(); wh++) {
         pr(root->bratList[wh], str);
        }
    }

 public:
    std::string operator[](int j) const {
        if (j >= gree.size()) {
         return "";
        }
        return gree[j];
    }
    explicit Tree(std::vector<char> value) {
        root = new Node();
        root->value = '*';
        createtree(root, value);
        pr(root);
    }
};

#endif  // INCLUDE_TREE_H_
