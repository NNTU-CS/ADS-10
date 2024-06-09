// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
struct Node {
std::vector<Node*> children;
char value;
};
    Node* root;
std::vector<std::vector<char>> constan;

 public:
void buildTree(Node* root, std::vector<char> enter) {
    if (enter.size() == 0) {
        return;
    } else {
        for (int i = 0; i < enter.size(); i++) {
            std::vector<char> temp = enter;
            Node* nextknot = new Node;
            nextknot->value = enter[i];
            root->children.push_back(nextknot);
            temp.erase(temp.begin() + i);
            buildTree(root->children.back(), temp);
        }
    }
}
void constan(Node* root, const std::vector<char> vect) {
    std::vector<char> temp1 = vect;
    for (int i = 0; i < root->children.size(); i++) {
        temp1.push_back(root->children[i]->value);
        if (root->children[i]->children.size() == 0) {
            constan.push_back(temp1);
        }
        constan(root->children[i], temp1);
        temp1.pop_back();
    }
}
    explicit Tree(std::vector<char> enter) {
        std::vector<char> vec;
        root = new Node;
        buildTree(root, enter);
        constan(root, vec);
    }
std::vector<char> getConst(int i)const {
    if (i > constan.size() - 1) {
        std::vector<char> null;
        return null;
    }
    return constan[i];
}
};

#endif  // INCLUDE_TREE_H_
