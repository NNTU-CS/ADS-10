// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    bool Root = false;
    char value;
    std::vector<Node*> Permut;
};

class Tree {
 private:
    Node* root;
    std::vector<std::vector<char> > p;

    void append(Node* root, const std::vector<char>& Vector) {
        for (char c : Vector) {
            Node* temp = new Node;
            temp->value = c;
            root->Permut.push_back(temp);
            std::vector<char> remainingChars(Vector);
            remainingChars.erase(std::find(remainingChars.begin(),
                remainingChars.end(), c));
            append(temp, remainingChars);
        }
    }

    void findP(Node* root, std::vector<char> Vector) { 
        if (!root->Root) Vector.push_back(root->value);
        if (root->Permut.empty()) p.push_back(Vector);
        for (Node* child : root->Permut) findP(child, Vector);
    }


 public:
    explicit Tree(const std::vector<char>& Vector) {
        root = new Node;
        root->Root = true;
        append(root, Vector);
        std::vector<char> current;
        findP(root, current);
    }

    std::vector<std::vector<char> > getPermutations() const { 
        return p;
    }
};
#endif  // INCLUDE_TREE_H_
