// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include  <vector>
using namespace std;
class Tree {
private:
    struct Node {
        vector<Node*> ch;
        char value;
    };
    Node* root;
    vector<vector<char>> constant;

public:
    tree(vector<char> entr);
    void buildTree(Node* root, vector<char> entr);
    void constan(Node* root, const vector<char> vect);
    vector<char> getConst(int i)const;
};

Tree::tree(vector<char> entr) {
    vector<char> vec;
    root = new Node;
    buildTree(root, entr);
    constan(root, vec);
}

void Tree::buildTree(Node* root, vector<char> entr) {
    if (entr.size() == 0) {//если вектор пустой?
        return;
    }
    else {
        for (int i = 0; i < entr.size(); i++) {
            vector<char> temp = entr;
            Node* nextU = new Node;
            nextU->value = entr[i];
            root->ch.push_back(nextU);
            temp.erase(temp.begin() + i);
            buildTree(root->ch.back(), temp);
        }
    }
}

void Tree::constan(Node* root, const vector<char> vect) {
    vector<char> temp1 = vect;
    for (int i = 0; i < root->ch.size(); i++) {
        temp1.push_back(root->ch[i]->value);
        if (root->ch[i]->ch.size() == 0) {
            constant.push_back(temp1);
        }
        constan(root->ch[i], temp1);
        temp1.pop_back();
    }
}

vector<char> Tree::getConst(int i)const {
    if (i > constant.size() - 1) {
        vector<char> null;
        return null;
    }
    return constant[i];
}

#endif  // INCLUDE_TREE_H_
