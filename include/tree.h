// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
struct Node {
std::vector<Node*> children;
char value;
};
    Node* root;
std::vector<std::vector<char>> constan;

 public:
    explicit Tree(std::vector<char> entr) {
        std::vector<char> vec;
        root = new Node;
        buildTree(root, entr);
        constan(root, vec);
    }
    std::vector<char> getPerm(const Tree& tree, int n) {
        if (n == 0) {
            return permutation;
        }
        for (Node* child : Node->children) {
            permutation.push_back(child->data);
            std::vector<char> result = getperm(child, --n, permutation);
            if (!result.empty()) {
                return result;
            }
            permutation.pop_back();
        }
        return {};
    }
std::vector<char> getperm(const Tree& tree, int n) {
    std::vector<char> permutation;
    return Tree::getperm(Tree::Node* constan&, int&,
     std::vector<char>&) constan);
}
};

#endif  // INCLUDE_TREE_H_
