// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
        char simp;
        std::vector<Node*> leaves;
        Node() : simp('0') {}
    };
    Node* radix = nullptr;
    std::vector<std::vector<char>> permutations;
    void castTree(Node*, const std::vector<char>&);
    void castPermutations(Node*, std::vector<char>);
    void castTreePermutations(const std::vector<char>&);
 public:
    explicit Tree(const std::vector<char>&);
    std::vector<std::vector<char>> getPermutations() const;
};

void Tree::castTree(Node* radix, const std::vector<char>& order) {
    if (!radix) return;

    for (const char& symb : order) {
        Node* temp = new Node;
        temp->simp = symb;
        radix->leaves.push_back(temp);

        std::vector<char> new_order;
        for (const char& ch : order) {
            if (ch != symb) {
                new_order.push_back(ch);
            }
        }

        castTree(temp, new_order);
    }
}


void Tree::castPermutations(Node* radix, std::vector<char> variation) {
    if (radix != nullptr && radix->simp != '0')
        variation.push_back(radix->simp);
    if (radix->leaves.empty())
        permutations.push_back(variation);
    else {
        for (Node* child : radix->leaves) {
            castPermutations(child, variation);
        }
    }
}

void Tree::castTreePermutations(const std::vector<char>& vector_) {
    castTree(radix, vector_);
    castPermutations(radix, {});
}

Tree::Tree(const std::vector<char>& vector_) {
    radix = new Node;
    castTreePermutations(vector_);
}

std::vector<std::vector<char>> Tree::getPermutations() const {
    return permutations;
}
#endif  // INCLUDE_TREE_H_
