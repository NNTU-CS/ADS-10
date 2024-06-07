// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    char vpx;
    bool isp = false;
    std::vector<Node*> point;
    explicit Node(char val) : vpx(val) {}
    ~Node() {
        for (auto child : point) {
            delete child;
        }
    }
};

class Tree {
 private:
    Node* cor;
    typedef std::vector<std::vector<char>> PermsType;
    PermsType p;
    void insertRecursive(Node* cor, const std::vector<char>& vec); 
    void insert(Node* cor, const std::vector<char>& vec); 
    void generatePerms(Node* cor, std::vector<char> vec);

 public:
    explicit Tree(const std::vector<char>& vec);
    ~Tree();
    std::vector<std::vector<char>> getP() const {
        return p;
    }
};

Tree::Tree(const std::vector<char>& vec) {
    cor = new Node;
    cor->isp = true;
    insert(cor, vec);
    std::vector<char> temp;
    generatePerms(cor, temp);
}

Tree::~Tree() {
    delete cor;
}

void Tree::insertRecursive(Node* cor, const std::vector<char>& vec) {
    if (vec.empty()) {
        return;
    }

    char c = *std::min_element(vec.begin(), vec.end());
    Node* s = new Node(c);
    cor->point.push_back(s);
    vec.erase(std::find(vec.begin(), vec.end(), c));
    insertRecursive(s, vec);
}

void Tree::insert(Node* cor, const std::vector<char>& vec) {
    for (char c : vec) {
        Node* s = new Node(c); 
        cor->point.push_back(s);

        std::vector<char> remainingChars(vec);
        remainingChars.erase(std::find(remainingChars.begin(),
            remainingChars.end(), c));

        insertRecursive(s, remainingChars);
    }
}

void Tree::generatePerms(Node* cor, std::vector<char> vec) {
    if (!cor->isp) vec.push_back(cor->vpx);
    if (cor->point.empty()) { 
        p.push_back(vec);
    } else { 
        for (Node* child : cor->point) { 
            std::vector<char> newVec = vec;
            generatePerms(child, newVec); 
        } 
    }
}

#endif  // INCLUDE_TREE_H_
