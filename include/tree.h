// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <cmath>
class Tree {
    struct Node {
        char value;
        std::vector<Node*> down;
    };
    int perm_count;
    Node* root;
    Node* addNode(Node*, char, int);
    void makeTree(Node*, std::vector<char>);
    int calculateperm(int);
    void perm(int, std::vector<char>*, Node*) const;
    void delTree(Node*);

 public:
    explicit Tree(std::vector<char>);
    void perm(int, std::vector<char>*) const;
    int GetPermCount() const;
    ~Tree();
};
int Tree::calculateperm(int k) {
    if (k == 1) return 1;
    else
        return calculateperm(k - 1) * k;
}
Tree::Tree(std::vector<char> in) {
    perm_count = calculateperm(in.size());
    root = nullptr;
    root = addNode(root, '\0', in.size());
    makeTree(root, in);
}
Tree::Node* Tree::addNode(Node* root, char value, int size) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->down.resize(size);
        fill(root->down.begin(), root->down.end(), nullptr);
    }
    return root;
}
void Tree::makeTree(Node* root, std::vector<char> in) {
    std::vector<char> temp;
    for (int i = 0; i < in.size(); ++i) {
        root->down[i] = addNode(root->down[i], in[i], in.size() - 1);
        temp = in;
        temp.erase(temp.begin() + i);
        makeTree(root->down[i], temp);
    }
}
void Tree::delTree(Node* root) {
    if (root == nullptr)
        return;
    for (int i = 0; i < root->down.size(); ++i)
        delTree(root->down[i]);
    delete root;
    root = nullptr;
}
void Tree::perm(int num, std::vector<char>* vector, Node* root) const {
    float next;
    if (root->down.size() > 1) {
        next = root->down[0]->down.size();
    } else {
        vector->push_back(root->down[0]->value);
        return;
    }
    int g = ceil(num / next);
    vector->push_back(root->down[g - 1]->value);
    perm(num - next * (g - 1), vector, root->down[g - 1]);
}
void Tree::perm(int num, std::vector<char>* vector) const {
    float next;
    if (root->down.size() > 1) {
        next = root->down[0]->down.size();
    } else {
        (*vector).push_back(root->down[0]->value);
        return;
    }
    int g = ceil(num / next);
    (*vector).push_back(root->down[g - 1]->value);
    perm(num - next * (g - 1), vector, root->down[g - 1]);
}
int Tree::GetPermCount() const {
    return perm_count;
}
Tree::~Tree() {
    if (root) {
        delTree(root);
    }
}
#endif  // INCLUDE_TREE_H_
