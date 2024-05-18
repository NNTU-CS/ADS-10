// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Tree {
    struct Node {
        char value;
        std::vector<Node*> under;
    };
    int countperm;
    Node* root;
    Node* addNode(Node* root, char value, int size);
    void delTree(Node*);
    void makeTree(Node* root, std::vector<char> in);
    int calculateperm(int num);
    void perm(int num, std::vector<char>& v, Node* root);

 public:
    Tree(std::vector<char> in);
    ~Tree();
    std::vector<char> getPerm(int num);
};
int Tree::calculateperm(int num) {
    if (num == 1) return 1;
    else return calculateperm(num - 1) * num;
}

Tree::Tree(std::vector<char> in) {
    countperm = calculateperm(in.size());
    root = nullptr;
    root = addNode(root, '\0', in.size());
    makeTree(root,in);
}
Tree::Node* Tree::addNode(Node* root, char value, int size) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->under.resize(size);
        fill(root->under.begin(), root->under.end(), nullptr);
    }
    return root;
}
void Tree::makeTree(Node* root, std::vector<char> in) {
    std::vector<char> temp;
    for (int i = 0; i < in.size(); ++i) {
        root->under[i] = addNode(root->under[i], in[i], in.size() - 1);
        temp = in;
        temp.erase(temp.begin() + i);
        makeTree(root->under[i], temp);
    }
}
void Tree::delTree(Node* root) {
    if (root == nullptr)
        return;
    for (int i = 0; i < root->under.size(); ++i)
        delTree(root->under[i]);
    delete root;
    root = nullptr;
}
Tree::~Tree() {
    if (root) {
        delTree(root);
    }
    return;
}
void Tree::perm(int num, std::vector<char>& v, Node* root) {
    float next;
    if (root->under.size() >1) {
        next = root->under[0]->under.size();
    } else {
        v.push_back(root->under[0]->value);
        return;
    }
    int g = 0;
    g = ceil(num / next);
    v.push_back(root->under[g - 1]->value);
    perm(num -next*(g-1), v, root->under[g - 1]);
}

std::vector<char> Tree::getPerm(int num) {
    std::vector<char> temp;
    if (num<= countperm)
        perm(num,temp,root);
    return temp;
}
#endif  // INCLUDE_TREE_H_
