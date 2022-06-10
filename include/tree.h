// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#endif  // INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>

class Tree {
 private:
  struct Node {
        std::vector<Node*> points;
        char value;
  };
    Node* root;
    Node* current;
    std::vector <char> elements;
    std::string element;
    std::vector<char> perest;
    std::vector<std::vector<char>> result;

 public:
    explicit Tree(std::vector <char> in) {
        elements = in;
        element.resize(in.size());
        perest.resize(in.size());
        Node* root = new Node;
        root->value = '*';
        transition(in, -1, 0, root);
    }
    Node* createNode(char value) {
        Node* temp = new Node;
        temp->value = value;
        return temp;
    }
    void transition(std::vector<char> in, int k, int number, Node* root) {
        if (in.size() == 1) {
            result.push_back(perest);
            return;
        }
        auto iter = in.cbegin();
        if (k >= 0) {
            number++;
            in.erase(iter + k);
        }
        for (int i = 0; i < in.size(); i++) {
            root->points.push_back(createNode(in[i]));
            perest[number] = in[i];
            transition(in, i, number, root->points[i]);
        }
    }
    std::vector<char> getResult(Tree tree, int num){
     if (num > result.size()) return {};
     return result[num-1];
    }
};
