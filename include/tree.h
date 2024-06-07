// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

struct Node {
    bool isRoot = false;
    char vall;
    std::vector<Node*> nodevec;
    explicit Node(char sym = '\0') :vall(sym) {}
};
class Tree {
 public:
    explicit Tree(const std::vector<char>& vect) {
        root = new Node;
        root->isRoot = true;
        adding(root, vect);
        std::vector<char> actual;
        dodgeTRee(root, actual);
    }
    std::vector<std::vector<char>> getPerem() const {
        return permutations;
    }

 private:
    Node* root;
    std::vector<std::vector<char>> permutations;
    void adding(Node* newroot1, std::vector<char> symbol) {
        if (!newroot1) {
            root = newroot1 = new Node;
        }
        for (char vall : symbol) {
            Node* temp = new Node(vall);
            newroot1->nodevec.push_back(temp);
            std::vector<char> newRow(symbol);
            newRow.erase(std::find(newRow.begin(), \
      newRow.end(), vall));
            adding(temp, newRow);
        }
    }
    void dodgeTRee(Node* newroot2, std::vector<char> row) {
        if (newroot2 != nullptr && newroot2->vall != '\0')
            row.push_back(newroot2->vall);
        if (newroot2->nodevec.empty())
            permutations.push_back(row);
        for (Node* descen : newroot2->nodevec) {
            dodgeTRee(descen, row);
        }
    }

    void createPermutations(std::vector<char> symbol) {
        adding(root, symbol);
        dodgeTRee(root, {});
    }
};
#endif  // INCLUDE_TREE_H_
