#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>
#include <algorithm>

class Node {
public:
    std::vector<Node*> children;
    char value;

    explicit Node(char val) : value(val) {}

    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
};

class Tree {
public:
    Node* root;

    explicit Tree(const std::vector<char>& elements) {
        root = new Node('\0');
        buildTree(root, elements);
    }

    ~Tree() {
        delete root;
    }

    std::vector<std::string> getAllPermutations() {
        std::vector<std::string> permutations;
        genPerm(root, "", permutations);
        return permutations;
    }

private:
    void buildTree(Node* node, const std::vector<char>& elements) {
        for (char element : elements) {
            Node* child = new Node(element);
            node->children.push_back(child);
            std::vector<char> el = elements;
            el.erase(std::remove(el.begin(), el.end(), element), el.end());
            buildTree(child, el);
        }
    }

    void genPerm(Node* node, std::string cur, std::vector<std::string>& permutations) {
        if (node->value != '\0') {
            cur.push_back(node->value);
        }
        if (node->children.empty()) {
            permutations.push_back(cur);
            return;
        }
        for (auto child : node->children) {
            genPerm(child, cur, permutations);
        }
    }
};

std::vector<char> getPerm(Tree& tree, int index);

#endif  // INCLUDE_TREE_H_
