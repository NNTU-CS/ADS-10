// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Node {
 public:
    char val;
    std::vector<Node*> chil;
    Node(char val) : val(val) {}
};

class Tree {
 public:
    Tree(std::vector<char> el) {
        tor = new Node('\0');
        nud(tor, el);

    }
    void freeTree(Node* node) {
        for (Node* ch : node->chil) {
            freeTree(ch);
        }
        delete node;
    }
    std::vector<std::string> get(Node* node, std::string u) const {
        std::vector<std::string> temp;
        if (node->chil.empty()) {
            temp.push_back(u + node->val);
            return temp;
        }
        for (Node* child : node->chil) {
            std::vector<std::string> h = get(child, u + node->val);
            temp.insert(temp.end(), h.begin(), h.end());
        }
        return temp;
    }
    std::string dex(Node* node, int index) const {
        std::vector<std::string> al = get(node, "");
        if (index < 1 || index > al.size()) {
            return "0";
        }
        return al[index - 1];
    }
    Node* g_tor() const {
        return tor;
    }
 private:
    Node* tor;
    void nud(Node* node, std::vector<char> el) {
        if (el.empty()) {
            return;
        }
        for (char element : el) {
            Node* child = new Node(element);
            node->chil.push_back(child);
            std::vector<char> temp = el;
            temp.erase(std::remove(temp.begin(), temp.end(), element), temp.end());
            nud(child, temp);
        }
    }
};
#endif  // INCLUDE_TREE_H_
