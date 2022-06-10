// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> childList = {};
    };
    Node* root;

    void MakeTree(Node* _root, std::vector<char> setSmbls, int j = -1) {
        if (j != -1)
            setSmbls.erase(setSmbls.begin() + j);
        if (setSmbls.empty()) {
            return;
        } else {
            for (int i = 0; i < setSmbls.size(); i++) {
                _root->childList.push_back(new Node);
                _root->childList[i]->value = setSmbls[i];
                MakeTree(_root->childList[i], setSmbls, i);
            }
        }
    }

    std::vector<std::vector<char>> prmtns = {};

    void Perms(Node* _root, std::vector<char> perm = {}) {
        if (_root->value != '*')
            perm.push_back(_root->value);
        if (_root->childList.size() == 0) {
            prmtns.push_back(perm);
        } else {
            for (int i = 0; i < _root->childList.size(); i++)
                Perms(_root->childList[i], perm);
        }
    }

 public:
    explicit Tree(std::vector<char> setSmbls) {
        root = new Node;
        root->value = '*';
        MakeTree(root, setSmbls);
    }

    std::vector<char> getPerm(int n) {
        Perms(root);
        if (n > prmtns.size()) {
            std::vector<char> null_arr = {};
            return null_arr;
        } else {
            return prmtns[n - 1];
        }
    }
};

#endif  // INCLUDE_TREE_H_
