// Copyright 2022 NNTU-CS

#ifndef INCLUDE_TREE_H_

#define INCLUDE_TREE_H_

#include <string>

#include <vector>

#include <algorithm>



class Tree {

 private:

    struct Node {

      char val;

      std::vector<Node*> numbers;

    };

    Node* root;

    std::vector<std::string> permut;



    void makeNode(Node* root, std::vector<char> v) {

      if (!v.size()) {

        return;

      }

      if (root->val != '*') {

        v.erase(std::find(v.begin(), v.end(), root->val));

      }

      for (int i = 0; i < v.size(); i++) {

        root->numbers.push_back(new Node());

      }

      for (int i = 0; i < root->numbers.size(); i++) {

        root->numbers[i]->val = v[i];

        makeNode(root->numbers[i], v);

      }

    }



    void Perm(Node* root, std::string s = "") {

      if (!root->numbers.size()) {

        s += root->val;

        permut.push_back(s);

        return;

      }

      if (root->val != '*') {

        s += root->val;

      }

      for (int i = 0; i < root->numbers.size(); ++i) {

        Perm(root->numbers[i], s);

      }

    }



 public:

    explicit Tree(std::vector<char> v) {

      root = new Node();

      root->val = '*';

      makeNode(root, v);

      Perm(root);

    }



    std::string get(int i) const{

      if (i >= permut.size()) {

        return "";

      }

      return permut[i];

    }

};

#endif  // INCLUDE_TREE_H_
