// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
std::vector<char> temp_delete(std::vector<char> numbers, int index_to_del);
struct Node {
    char data;
    std::vector<Node*> children;
};
class Tree {
 private:
    int size;

 public:
    Node* root;
    explicit Tree(std::vector<char> in): size(0) {
        root = new Node;
        root->data = '0';
        for (int i = 0; i < in.size(); i++) {
            Node* newNode = new Node;
            newNode->data = in[i];
            root->children.push_back(newNode);
        }
        for (int i = 0; i < in.size(); i++) {
            std::vector<char> temp = in;
            temp = temp_delete(temp, i);
            add_childrens_for_child(temp, root->children[i]);
        }
    }
    void add_child(Node* parent, char val) {
        Node* h = new Node;
        h->data = val;
        h->children.push_back(h);
    }
    void add_childrens_for_child(std::vector<char> in, Node* parent) {
        if (in.empty()) {
            return;
        }
        for (int i = 0; i < in.size(); i++) {
            Node* newNode = new Node;
            newNode->data = in[i];
            parent->children.push_back(newNode);
            std::vector<char> temp = in;
            temp = temp_delete(temp, i);
            add_childrens_for_child(temp, newNode);
        }
    }
    std::vector<std::vector<char>> getPerms(int k) const {
        std::vector<std::vector<char>> perms;
        std::vector<char> perm;
        getPermsRecursive(root, k, perm, perms);
        return perms;
    }
    void getPermsRecursive(Node* node, int remaining,
std::vector<char> perm, const std::vector<std::vector<char>>& perms) const {
        if (remaining == 0) {
            std::vector<std::vector<char>>& nonConstPerms = const_cast<std::vector<std::vector<char>>&>(perms);
            nonConstPerms.push_back(perm);
            return;
        }
        for (Node* child : node->children) {
            std::vector<char> newPerm = perm;
            newPerm.push_back(child->data);
            getPermsRecursive(child, remaining - 1, newPerm, perms);
        }
}
};
std::vector<char> getPerm(const Tree& tree, int d);

#endif  // INCLUDE_TREE_H_
