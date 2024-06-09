// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>

struct stem {
    std::vector<stem*> leaves;
    char symbol;

    explicit stem(char symbol) : symbol(symbol) {}
};

class Tree {
 private:
    stem* root;

    std::vector<char> filterSymbols(std::vector<char> numbers, char symbol) {
        std::vector<char> mainVect;
        for (char a : numbers) {
            if (a != symbol) {
                mainVect.push_back(a);
            }
        }
        return mainVect;
    }

    void createChildren(stem* cur, std::vector<char> num) {
        cur->leaves.resize(num.size());
        for (int i = 0; i < num.size(); i++) {
            cur->leaves[i] = new stem(num[i]);
        }
    }

    void addLeafs(std::vector<char> num, stem* cur) {
        std::vector<char> updVect;
        updVect = filterSymbols(num, cur->symbol);
        if (!updVect.empty()) {
            createChildren(cur, updVect);
            for (int i = 0; i < cur->leaves.size(); i++) {
                addLeafs(updVect, cur->leaves[i]);
            }
        }
    }

 public:
    Tree() : root(nullptr) {}

    explicit Tree(std::vector<char> sym) {
        root = new stem(' ');
        addLeafs(sym, root);
    }

    stem* getRoot() {
        return root;
    }

    void displayBranches(stem* node) {
        if (node->leaves.empty()) {
            std::cout << node->symbol << std::endl;
            return;
        }
        if (!node->leaves.empty()) {
            for (int i = 0; i < node->leaves.size(); i++) {
                if (node->symbol != ' ') {
                    std::cout << node->symbol;
                }
                displayBranches(node->leaves[i]);
            }
        } else {
            std::cout << std::endl;
        }
    }

    void deleteTree(stem* node) {
        if (node) {
            for (stem* child : node->leaves) {
                deleteTree(child);
            }
            delete node;
        }
    }
};

int factorial(int);
std::vector<char> createNumber(stem*, int, std::vector<char>);

#endif  // INCLUDE_TREE_H_
