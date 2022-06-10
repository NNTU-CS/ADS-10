// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <vector>
#include <string>

struct Node {
    char sym;
    Node *parent;
    std::vector<Node> var;
};

class Tree {
 private:
    Node *root = new Node;
    std::vector<Node> permutations;
    void makeTree(std::vector<char> array) {
        createNode(root, array);
        link(root);
    }
    void createNode(Node* head, std::vector<char> array) {
        for (int i = 0; i < array.size(); i++) {
            Node *el = new Node();
            el->sym = array[i];
            head->var.push_back(*el);
            if (array.size() > 0) {
                createNode(&head->var[i], expectArray(array, array[i]));
            }
        }
    }
    void link(Node *head) {
        for (Node &child : head->var) {
            child.parent = head;
            link(&child);
        }
        if (head->var.size() == 0) {
            permutations.push_back(*head);
        }
    }
    std::vector<char> expectArray(std::vector<char> array, char value) {
        std::vector<char>::iterator position = std::find(array.begin(),
                                                         array.end(), value);
        if (position != array.end())
            array.erase(position);
        return array;
    }

 public:
    explicit Tree(std::vector<char> array) {
        makeTree(array);
    }
    std::vector<char> getPermutationByNumber(Tree tree, int number){
        if (number > permutations.size()) {
            return {};
        }
        std::vector<char> res;
        Node current = permutations[number-1];
        while (current.parent) {
            res.push_back(current.sym);
            current = *current.parent;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

#endif  // INCLUDE_TREE_H_
