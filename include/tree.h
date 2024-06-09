// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
std::vector<char> delete_del(std::vector<char> digit, int code);
struct Vertex {
    char memory;
    std::vector<Vertex*> childs;
};
class Tree {
 private:
    int size;

 public:
    Vertex* origin;
    explicit Tree(std::vector<char> in): size(0) {
        origin = new Vertex;
        origin->memory = '0';
        for (int i = 0; i < in.size(); i++) {
            Vertex* newVertex = new Vertex;
            newVertex->memory = in[i];
            origin->childs.push_back(newVertex);
        }
        for (int i = 0; i < in.size(); i++) {
            std::vector<char> pace = in;
            pace = delete_del(pace, i);
            add_childs(pace, origin->childs[i]);
        }
    }
    void add_child(Vertex* par, char vallue) {
        Vertex* m = new Vertex;
        m->memory = vallue;
        m->childs.push_back(m);
    }
    void add_childs(std::vector<char> in, Vertex* par) {
        if (in.empty()) {
            return;
        }
        for (int i = 0; i < in.size(); i++) {
            Vertex* newVertex = new Vertex;
            newVertex->memory = in[i];
            par->childs.push_back(newVertex);
            std::vector<char> pace = in;
            pace = delete_del(pace, i);
            add_childs(pace, newVertex);
        }
    }
    std::vector<std::vector<char>> getPerms(int l) const {
        std::vector<std::vector<char>> perms;
        std::vector<char> perm;
        getPermsRecursive(origin, l, perm, perms);
        return perms;
    }
    void getPermsRecursive(Vertex* vertex, int residual,
std::vector<char> perm, const std::vector<std::vector<char>>& perms) const {
        if (residual == 0) {
            std::vector<std::vector<char>>& nonConstPerms =
            const_cast<std::vector<std::vector<char>>&>(perms);
            nonConstPerms.push_back(perm);
            return;
        }
        for (Vertex* child : vertex->childs) {
            std::vector<char> newPerm = perm;
            newPerm.push_back(child->memory);
            getPermsRecursive(child, residual - 1, newPerm, perms);
        }
}
};
std::vector<char> getPerm(const Tree& tree, int r);

#endif  // INCLUDE_TREE_H_


