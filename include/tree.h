// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 public:
    struct Node {
        char value;
        int minn, maxx;
        std::vector<Node*> children;
    };

 private:
    Node* root;
    Node* addNode(Node*, char, std::vector<char>, int, int);
    void delTree(Node*);

 public:
    Tree();
    explicit Tree(std::vector<char> c);
    ~Tree();
    std::vector<char> getPerm(int) const;
};


long double fact(int N);

Tree::Tree() {
    root = nullptr;
}

Tree::Tree(std::vector<char> c) {
    root = new Node;
    root->value = '*';
    root->minn = 0;
    root->maxx = fact(c.size()) - 1;
    addNode(root, '*', c, root->minn, root->maxx);
}

Tree::Node* Tree::addNode(Node* r, char v,
    std::vector<char> c, int minn, int maxx) {
    std::vector<char> c2;
    Node* n = nullptr;
    char value;
    int _minn, _maxx;
    int i, j;
    if (!c.empty()) {
        for (i = 0; i < c.size(); i++) {
            value = c[i];
            while (!c2.empty()) {
                c2.pop_back();
            }
            for (j = 0; j < c.size(); j++) {
                if (i != j) {
                    c2.push_back(c[j]);
                }
            }
            n = new Node;
            _minn = (maxx - minn + 1) / c.size() * i + minn;
            _maxx = (maxx - minn + 1) / c.size() * (i+1) + minn - 1;
            r->children.push_back(addNode(n, value, c2, _minn, _maxx));
        }
        r->value = v;
        r->minn = minn;
        r->maxx = maxx;
        n = r;
    } else {
        r->value = v;
        r->minn = -1;
        r->maxx = -1;
        n = r;
    }
    return n;
}

Tree::~Tree() {
    if (root != nullptr) {
       delTree(root);
    }
}


void Tree::delTree(Node* root) {
    int i;
    if (root != nullptr) {
        if (root->children.size() > 0) {
            for (i = 0; i < root->children.size(); i++) {
                delTree(root->children[i]);
            }
        } else {
            delete root;
        }
    }
}

std::vector<char> Tree::getPerm(int N) const {
    std::vector<char> result;
    Node* r;
    if (N > root->minn && N <= root->maxx + 1) {
        r = root;
        while (r->children[0]->minn != -1) {
            for (int i = 0; i < r->children.size(); i++) {
                if (N > r->children[i]->minn &&
                    N <= (r->children[i]->maxx + 1)) {
                    result.push_back(r->children[i]->value);
                    r = r->children[i];
                    break;
                }
            }
        }
        result.push_back(r->children[0]->value);
    }
    return result;
}
long double fact(int N) {
    if (N < 0) {
        return 0;
    }
    if (N == 0) {
        return 1;
    } else {
        return N * fact(N - 1);
    }
}
#endif  // INCLUDE_TREE_H_
