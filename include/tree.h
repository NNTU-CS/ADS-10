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
    Node* roter;
    explicit Tree(std::vector<char> in): size(0) {
        roter = new Node;
        roter->date = '0';
        for (int i = 0; i < in.size(); i++) {
            Node* newNode = new Node;
            newNode->date = in[i];
            roter->children.push_back(newNode);
        }
        for (int i = 0; i < in.size(); i++) {
            std::vector<char> tmp = in;
            tmp = temp_delete(tmp, i);
            add_childrens_for_child(tmp, roter->children[i]);
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
        for (int i = 0; i < iner.size(); i++) {
            Node* newNode = new Node;
            newNode->date = iner[i];
            parenti->children.push_back(newNode);
            std::vector<char> tmp = iner;
            tmp = temp_delete(tmp, i);
            add_childrens_for_child(tmp, newNode);
        }
    }
    std::vector<std::vector<char>> getPerms(int k) const {
        std::vector<std::vector<char>> perms;
        std::vector<char> curperm;
        getPermsRecursive(roter, k, curperm, perms);
        return perms;
    }
    void getPermsRecursive(Node* node, int remaining,
std::vector<char> curperm, const std::vector<std::vector<char>>& perms) const {
        if (remaining == 0) {
            std::vector<std::vector<char>>& nonConstPerms =
            const_cast<std::vector<std::vector<char>>&>(perms);
            nonConstPerms.push_back(curperm);
            return;
        }
        for (Node* child : node->children) {
            std::vector<char> newPerm = curperm;
            newPerm.push_back(child->date);
            getPermsRecursive(child, remaining - 1, newPerm, perms);
        }
}
};
std::vector<char> getPerm(const Tree& tree, int d);

#endif  // INCLUDE_TREE_H_
