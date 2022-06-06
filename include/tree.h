// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char zhach;
        std::vector<Node*> listik;
    };
    Node* root;

    void rootConstr(Node* root, std::vector<char> vrema) {
        if (!vrema.size())
            return;
        if (root->zhach != '*') {
            for (auto syn = vrema.begin(); syn != vrema.end(); syn++)
                if (*syn == root->zhach) {
                    vrema.erase(syn);
                    break;
                }
        }
        for (size_t i = 0; i < vrema.size(); i++)
            root->listik.push_back(new Node());
        for (size_t i = 0; i < root->listik.size(); i++)
            root->listik[i]->zhach = vrema[i];
        for (size_t i = 0; i < root->listik.size(); i++)
            rootConstr(root->listik[i], vrema);
    }

    std::vector<std::string> sw;
    void change(Node* root, std::string symb  = "") {
        if (!root->listik.size()) {
            symb += root->zhach;
            sw.push_back(symb);
            return;
        }
        if (root->zhach != '*')
            symb  += root->zhach;
        for (size_t i = 0; i < root->listik.size(); i++)
            change(root->listik[i], symb);
    }

 public:
    std::string operator[](int i) const {
        if (i >= sw.size()) return "";
        return sw[i];
    }

    explicit Tree(std::vector<char> zhach) {
        root = new Node();
        root->zhach = '*';
        rootConstr(root, zhach);
        change(root);
    }
};
#endif  // INCLUDE_TREE_H_
