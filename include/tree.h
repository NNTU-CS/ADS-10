// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
std::vector<char> temp_delete(std::vector<char> numbers, int index_to_del);
struct Done {
    char data;
    std::vector<Done*> children;
};
class Tree {
 private:
    int size;

 public:
    Done* root;
    explicit Tree(std::vector<char> in): size(0) {
        root = new Done;
        root->data = '0';
        for (int i = 0; i < in.size(); i++) {
            Done* newDone = new Done;
            newDone->data = in[i];
            root->children.push_back(newDone);
        }
        for (int i = 0; i < in.size(); i++) {
            std::vector<char> temp = in;
            temp = temp_delete(temp, i);
            add_childrens_for_child(temp, root->children[i]);
        }
    }
    void add_child(Done* parent, char val) {
        Done* h = new Done;
        h->data = val;
        h->children.push_back(h);
    }
    void add_childrens_for_child(std::vector<char> in, Done* paren) {
        if (in.empty()) {
            return;
        }
        for (int i = 0; i < in.size(); i++) {
            Done* newDone = new Done;
            newDone->data = in[i];
            paren->children.push_back(newDone);
            std::vector<char> temp = in;
            temp = temp_delete(temp, i);
            add_childrens_for_child(temp, newDone);
        }
    }
    std::vector<std::vector<char>> getPerms(int k) const {
        std::vector<std::vector<char>> perms;
        std::vector<char> perm;
        getPermsRecursive(root, k, perm, perms);
        return perms;
    }
    void getPermsRecursive(Done* node, int remaining,
std::vector<char> perm, const std::vector<std::vector<char>>& perms) const {
        if (remaining == 0) {
            std::vector<std::vector<char>>& nonConstPerms =
            const_cast<std::vector<std::vector<char>>&>(perms);
            nonConstPerms.push_back(perm);
            return;
        }
        for (Done* child : node->children) {
            std::vector<char> newPerm = perm;
            newPerm.push_back(child->data);
            getPermsRecursive(child, remaining - 1, newPerm, perms);
        }
}
};
std::vector<char> getPerm(const Tree& tree, int d);
#endif  // INCLUDE_TREE_H_
