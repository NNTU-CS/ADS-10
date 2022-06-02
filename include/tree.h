// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> list;
    };
    Node* root = nullptr;
    void create(Node* root, std::vector<char> x);
    void perest(Node* root, std::string line);
    std::vector<std::string> p;

 public:
    std::string take(int x) const;
    explicit Tree(std::vector<char> x) {
        root = new Node;
        root->value = '#';
        create(root, x);
        perest(root, "");
    }
};

std::string Tree::take(int x) const {
    if (p.size() >= x) {
        return p[x];
    } else {
        return "";
    }
}

void Tree::perest(Node* root, std::string line) {
    if (root->list.size()) {
        if (root->value != '#') {
            line = line + root->value;
        }
        int i = 0;
        while (i < root->list.size()) {
            perest(root->list[i], line);
            i++;
        }
    } else {
        line = line + root->value;
        p.push_back(line);
    }
}

void Tree::create(Node* root, std::vector<char> x) {
    if (x.size()) {
        if (root->value != '#') {
            auto i = x.begin();
            while (i != x.end()) {
                if (root->value == *i) {
                    x.erase(i);
                    break;
                }
                ++i;
            }
        }
    }
    int i = 0;
    while (i < x.size()) {
        Node* temp = new Node;
        root->list.push_back(temp);
        ++i;
    }
    int j = 0;
    while (j < root->list.size()) {
        root->list[j]->value = x[j];
        create(root->list[j], x);
        ++j;
    }
}

#endif  // INCLUDE_TREE_H_
