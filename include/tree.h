// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> lower_level_nodes;
        explicit Node(char val) : value(val) {}
    };
    Node* root;
    std::vector<std::vector<char>> permutations;
    void createTree(const std::vector<char>& numbers, Node* parent) {
        for (char num : numbers) {
            Node* child = new Node(num);
            parent->lower_level_nodes.push_back(child);
            std::vector<char> new_num(numbers);
            new_num.erase(std::find(new_num.begin(), new_num.end(), num));
            createTree(new_num, child);
        }
    }
    void GenPerm(Node* root, std::vector<char> perm) {
        perm.push_back(root->value);
        if (root->lower_level_nodes.empty()) {
            permutations.push_back(perm);
        }
        for (Node* child : root->lower_level_nodes) {
            GenPerm(child, perm);
        }
        perm.pop_back();
    }

 public:
    explicit Tree(const std::vector<char>& numbers) {
        root = new Node('*');
        createTree(numbers, root);
        GenPerm(root, {});
    }
    const int GetSize() const {
        return root->lower_level_nodes.size();
    }
    std::vector<char> GetPerm(int n) const {
        return permutations[n];
    }
};
#endif  // INCLUDE_TREE_H_
