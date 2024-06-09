// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

class Node {
public:
    char data;
    std::vector<Node*> children;
    Node(char value) {
        data = value;
    }
};
class Tree {
public:
    Node* root;
    Tree(std::vector<char>& input) {
        root = new Node('\0');
        for (char value : input) {
            Node* child = new Node(value);
            root->children.push_back(child);
        }
    }
    std::vector<char> getperm(Node* node, int& n, std::vector<char>& permutation) {
        if (n == 0) {
            return permutation;
        }
        for (Node* child : node->children) {
            permutation.push_back(child->data);
            std::vector<char> result = getperm(child, --n, permutation);
            if (!result.empty()) {
                return result;
            }
            permutation.pop_back();
        }
        return {};
    }
};
std::vector<char> getperm(const Tree& tree, int n) {
    std::vector<char> permutation;
    return tree.getperm(tree.root, n, permutation);
}

#endif  // INCLUDE_TREE_H_
