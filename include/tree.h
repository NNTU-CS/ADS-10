// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> childs;
    };
    Node* root;

 public:
    int per_size;
    int n_fact;
    std::vector<char> data;
    std::vector<char> tmp_data;
    std::vector<char> v;

    int fact(int n) {
        int k = 1;
        for (int i = 2; i <= n; i++) {
            k *= i;
        }
        return k;
    }

    explicit Tree(std::vector<char> in): root(nullptr), n_fact(0), per_size(0) {
        if (root) {
            throw std::string("Error!");
        } else {
            if (!in.empty()) {
                v = in;
                per_size = in.size();
                n_fact = fact(per_size);
                root = new Node;
                root->value = '*';
                for (int i = 0; i < in.size(); i++) {
                    root->childs.push_back(new Node);
                    root->childs[i]->value = in[i];
                }
                for (int i = 0; i < in.size(); i++) {
                    std::vector<char> in_i;
                    for (int k = 0; k < in.size(); k++) {
                       if (k != i) {
                           in_i.push_back(in[k]);
                       } else {
                           data.push_back(in[i]);
                       }
                    }
                    if (!in_i.empty()) {
                        root->childs[i] = addChilds(root->childs[i], in_i);
                    }
                    for (int q = 0; q < in.size() - 1; q++) {
                        tmp_data.push_back(data[data.size() - 1]);
                        data.pop_back();
                    }
                    data.push_back(in[i]);
                    for (int q = 0; q < in.size() - 1; q++) {
                        data.push_back(tmp_data[tmp_data.size() - 1]);
                        tmp_data.pop_back();
                    }
                    tmp_data.clear();
                }
            }
        }
    }

    Node* addChilds(Node* root, std::vector<char> ch) {
        if (!root) {
            throw std::string("Error!");
        } else {
            if (!ch.empty()) {
                for (int j = 0; j < ch.size(); j++) {
                    root->childs.push_back(new Node);
                    root->childs[j]->value = ch[j];
                }
                for (int j = 0; j < ch.size(); j++) {
                    std::vector<char> in_j;
                    for (int k = 0; k < ch.size(); k++) {
                        if (k != j) {
                            in_j.push_back(ch[k]);
                        } else {
                            data.push_back(ch[j]);
                        }
                    }
                    if (!in_j.empty()) {
                        root->childs[j] = addChilds(root->childs[j], in_j);
                    }
                }
            }
        }
        return root;
    }
};

std::vector<char> getPerm(const Tree& tree, int n);
#endif  // INCLUDE_TREE_H_
