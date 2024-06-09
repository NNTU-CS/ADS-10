// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 public:
    explicit Tree(const std::vector<char>&);
    std::vector<std::vector<char>> getPermutations() const;
 private:
    struct Node {
        char chu;
	Node() : chu('*') {}
        std::vector<Node*> vec;
    };
    Node* newNode = nullptr;
    std::vector<std::vector<char>> permutations;
    void treeMaker(Node*, const std::vector<char>&);
    void permutationMaker(Node*, std::vector<char>);
    void treePermutationsMaker(const std::vector<char>&);
};

void Tree::treeMaker(Node* newNode, const std::vector<char>& sequence) {
    if (!newNode) {
        return;
    }

    for (const char& symbols : sequence) {
        Node* nd = new Node;
        nd->chu = symbols;
        newNode->vec.push_back(nd);

        std::vector<char> new_sequence;
        for (const char& chars : sequence) {
            if (chars != symbols) {
                new_sequence.push_back(chars);
            }
        }
        treeMaker(nd, new_sequence);
    }
}


void Tree::permutationMaker(Node* newNode, std::vector<char> variants) {
    if (newNode != nullptr && newNode->chu != '*') {
        variants.push_back(newNode->chu);
    }
    if (newNode->vec.empty()) {
        permutations.push_back(variants);
    } else {
        for (Node* next : newNode->vec) {
            permutationMaker(next, variants);
        }
    }
}

Tree::Tree(const std::vector<char>& vectorr) {
    newNode = new Node;
    treePermutationsMaker(vectorr);
}

void Tree::treePermutationsMaker(const std::vector<char>& vectorr) {
    treeMaker(newNode, vectorr);
    permutationMaker(newNode, {});
}

std::vector<std::vector<char>> Tree::getPermutations() const {
    return permutations;
}
#endif  // INCLUDE_TREE_H_
