// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>

class Tree {
 private:
  struct Node {
        std::vector<Node*> dots;
        char values;
  };
    Node* root;
    Node* current;
    std::vector <char> components;
    std::string component;
    std::vector<char> transfer;
    std::vector<std::vector<char>> result;

 public:
    explicit Tree(std::vector <char> in) {
        components = in;
        component.resize(in.size());
        transfer.resize(in.size());
        Node* root = new Node;
        root->values = '*';
        cross(in, -1, 0, root);
    }
    Node* createNode(char values) {
        Node* temp = new Node;
        temp->values = values;
        return temp;
    }
    void cross(std::vector<char> in, int j, int number, Node* root) {
        if (in.size() == 1) {
            result.push_back(transfer);
            return;
        }
      auto iteration = in.cbegin();
        if (j >= 0) {
            number++;
            in.erase(iteration + j);
        }
        for (int i = 0; i < in.size(); i++) {
            root->dots.push_back(createNode(in[i]));
            transfer[number] = in[i];
            cross(in, i, number, root->dots[i]);
        }
    }
    std::vector<char> getResult(Tree tree, int numb){
     if (numb > result.size()) return {};
     return result[numb-1];
    }
};
#endif  // INCLUDE_TREE_H_
