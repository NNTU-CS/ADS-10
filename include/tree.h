// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> lowerNode;
        bool flag = false;
    };

    Node* first;

    std::vector<std::string> temp;

    void change(Node* first, std::string sym = "") {
        if (first->lowerNode.size() == 0) {
            sym += first->value;
            temp.push_back(sym);
        } else if (!first->flag) {
            sym += first->value;
        }
        for (int i = 0; i < first->lowerNode.size(); i++) {
            change(first->lowerNode[i], sym);
        }
    }

    int createTree(Node* first, std::vector<char> tempChar) {
        if (!tempChar.size()) {
            return 0;
        } else if (!first->flag) {
            for (auto i = tempChar.begin(); i != tempChar.end(); i++) {
                if (*i == first->value) {
                    tempChar.erase(i);
                    break;
                }
            }
        }
        for (int i = 0; i < tempChar.size(); i++) {
            first->lowerNode.push_back(new Node);
        }
        for (int i = 0; i < first->lowerNode.size(); ++i) {
            first->lowerNode[i]->value = tempChar[i];
        }
        for (int i = 0; i < first->lowerNode.size(); ++i) {
            createTree(first->lowerNode[i], tempChar);
        }
     return 0;
    }

 public:
    explicit Tree(std::vector<char> value) {
        first = new Node();
        first->flag = true;
        createTree(first, value);
        change(first);
    }
    std::string operator[](int i) const {
        if (i >= temp.size()) {
            return "";
        }
        return temp[i];
    }
};
#endif  // INCLUDE_TREE_H_
