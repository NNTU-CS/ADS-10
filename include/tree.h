#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <cstddef>

class Tree {
 private:
    struct Node {
        std::vector<Node*> child;
        char value;
        Node(char val) : value(val) {}
    };
    Node* root;
    std::vector<std::vector<char>> consta;

 public:
    explicit Tree(const std::vector<char>& in) {
        root = new Node('\0');
        std::vector<char> used;
        buildTree(root, in);
        Perm(root, used);
    }

    ~Tree() {
        clearTree(root);
    }

    void clearTree(Node* node) {
        for (Node* child : node->child) {
            clearTree(child);
        }
        delete node;
    }

    void buildTree(Node* node, std::vector<char> in) {
        if (!in.empty()) {
            for (size_t i = 0; i < in.size(); ++i) {
                std::vector<char> temp(in.begin(), in.end());
                temp.erase(temp.begin() + i);
                Node* next = new Node(in[i]);
                node->child.push_back(next);
                buildTree(next, temp);
            }
        }
    }

    void Perm(Node* node, std::vector<char> used) {
        for (size_t i = 0; i < node->child.size(); ++i) {
            used.push_back(node->child[i]->value);
            if (node->child[i]->child.empty()) {
                consta.push_back(used);
            }
            Perm(node->child[i], used);
            used.pop_back();
        }
    }

    std::vector<char> GetPerm(int i) const {
        if (i < 0 || static_cast<size_t>(i) >= consta.size()) {
            return std::vector<char>();
        }
        return consta[i];
    }
};

#endif  // INCLUDE_TREE_H_
