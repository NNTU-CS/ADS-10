// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
std::vector<char> temp_delete(std::vector<char> numbers, int index_to_del);
struct Node {
    char d;
    std::vector<Node*> childs;
};
class Tree {
 private:
    int size;

 public:
    Node* root;
    explicit Tree(std::vector<char> in): size(0) {
        root = new Node;
        root->d = '0';
        for (int i = 0; i < in.size(); i++) {
            Node* newNode = new Node;
            newNode->d = in[i];
            root->childs.push_back(newNode);
        }
        for (int i = 0; i < in.size(); i++) {
            std::vector<char> temp = in;
            temp = temp_delete(temp, i);
            add_childs_for_child(temp, root->childs[i]);
        }
    }
    void add_child(Node* parent, char val) {
        Node* h = new Node;
        h->d = val;
        h->childs.push_back(h);
    }
    void add_childs_for_child(std::vector<char> in, Node* parent) {
        if (in.empty()) {
            return;
        }
        for (int i = 0; i < in.size(); i++) {
            Node* newNode = new Node;
            newNode->d = in[i];
            parent->childs.push_back(newNode);
            std::vector<char> temp = in;
            temp = temp_delete(temp, i);
            add_childs_for_child(temp, newNode);
        }
    }
    std::vector<std::vector<char>> getPerms(int k) const {
        std::vector<std::vector<char>> ps;
        std::vector<char> p;
        getPsRecursive(root, k, pe, ps);
        return ps;
    }
    void getPsRecursive(Node* node, int remaining,
std::vector<char> p, const std::vector<std::vector<char>>& ps) const {
        if (remaining == 0) {
            std::vector<std::vector<char>>& nonConstPs =
            const_cast<std::vector<std::vector<char>>&>(ps);
            nonConstPs.push_back(p);
            return;
        }
        for (Node* child : node->childs) {
            std::vector<char> newP = p;
            newP.push_back(child->data);
            getPsRecursive(child, remaining - 1, newP, ps);
        }
}
};
std::vector<char> getPerm(const Tree& tree, int d);

#endif  // INCLUDE_TREE_H_
