// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#pragma once

#include <vector>
#include <iostream>
#include <string>

class Tree {
 private:
        struct Pnode {
                char val;
                std::vector <Pnode> list;
        };

        Pnode* root = nullptr;
        int main = 0;
        std::vector<char> various;
        int current = 0;

       std::vector<char> deleteParts(std::vector<char> arr, char val) {
                std::vector<char> line;
                for (int i = 0; i < arr.size(); i++) {
                         if (arr[i] != val)
                            line.push_back(arr[i]);
                }
                return line;
        }

        std::vector<Pnode> create(std::vector<char> node, Pnode* top) {
                std::vector<Pnode> temp;
                for (int i = 0; i < node.size(); i++) {
                        Pnode* tmp = new Pnode;
                        tmp->val = node[i];
                        tmp->list = create(deleteParts(node, node[i]), tmp);
                        temp.push_back(*tmp);
                }
                return temp;
        }

         std::string getElements(Pnode* cur, std::string target) {
                if (cur->val != '*') target = target + cur->val;
                for (int i = 0; i < cur->list.size(); i++)
                         getElements(&cur->list[i], target);
                if ((target.length() == root->list.size())
                     && current == main - 1 && various.empty()) {
                       for (int i = 0; i < target.length(); i++)
                               various.push_back(target[i]);
                } else {
                       if (target.length() == root->list.size())
                         current++;
                }
                return target;
          }

 public:
        explicit Tree(std::vector<char> node) {
                root = new Pnode;
                root->val = '*';
                root->list = create(node, root);
        }

        std::vector<char> getPerm(int n) {
                main = n;
                getElements(root, "");
                std::vector<char> result = various;
                various.clear();
                current = 0;
                return result;
        }
};

#endif  // INCLUDE_TREE_H_
