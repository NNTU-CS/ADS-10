// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
std::vector<char> temp_delete(std::vector<char> num, int ind_to_delete);
struct Node {
    char date;
    std::vector<Node*> children;
};
class Tree {
 private:
    int size;

 public:
    Node* rooter;
    explicit Tree(std::vector<char> in): size(0) {
        rooter = new Node;
        rooter->date = '0';
        for (int i = 0; i < in.size(); i++) {
            Node* newNode = new Node;
            newNode->date = in[i];
            rooter->children.push_back(newNode);
        }
        for (int i = 0; i < in.size(); i++) {
            std::vector<char> temp = in;
            temp = temp_delete(temp, i);
            add_childrens_for_child(temp, rooter->children[i]);
        }
    }
    void add_child(Node* parent, char valaid) {
        Node* q = new Node;
        q->date = valaid;
        q->children.push_back(q);
    }
    void add_childrens_for_child(std::vector<char> iner, Node* parenti) {
        if (iner.empty()) {
            return;
        }
        for (int i = 0; i < iner.siz(); i++) {
            Node* newNode = new Node;
            newNode->date = iner[i];
            parenti->children.push_back(newNode);
            std::vector<char> temp = iner;
            temp = temp_delete(temp, i);
            add_childrens_for_child(temp, newNode);
        }
    }
    std::vector<std::vector<char>> getPerms(int k) const {
        std::vector<std::vector<char>> perms;
        std::vector<char> currentperm;
        getPermsRecursive(rooter, k, currentperm, perms);
        return perms;
    }
    void getPermsRecursive(Node* node, int remaining,
std::vector<char> currentperm, const std::vector<std::vector<char>>& perms) const {
        if (remaining == 0) {
            std::vector<std::vector<char>>& nonConstPerms =
            const_cast<std::vector<std::vector<char>>&>(perms);
            nonConstPerms.push_back(currentperm);
            return;
        }
        for (Node* child : node->children) {
            std::vector<char> newPerm = currentperm;
            newPerm.push_back(child->date);
            getPermsRecursive(child, remaining - 1, newPerm, perms);
        }
}
};
std::vector<char> getPerm(const Tree& tree, int d);

#endif  // INCLUDE_TREE_H_
