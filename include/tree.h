// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>

std::vector<char> Delete(std::vector<char> numbers, int index);

class Array {
 public:
    char data;
    std::vector<Array*> childs;
};

class Tree {
 private:
    int size;

 public:
    Array* rootArray;
    explicit Tree(std::vector<char> inData) {
        size = 0;
        rootArray = new Array;
        rootArray->data = '0';
        for (int i = 0; i < inData.size(); i++) {
            Array* newArray = new Array;
            newArray->data = inData[i];
            rootArray->childs.push_back(newArray);
        }
        for (int i = 0; i < inData.size(); i++) {
            std::vector<char> NoneNeed = inData;
            NoneNeed = Delete(NoneNeed, i);
            Next(NoneNeed, rootArray->childs[i]);
        }
    }


    void Next(std::vector<char> in, Array* parent) {
        if (in.empty()) {
            return;
        }
        for (int i = 0; i < in.size(); i++) {
            Arrayt* newArray = new Array;
            newArray->data = in[i];
            parent->childs.push_back(newArray);
            std::vector<char> NoneNeed = in;
            NoneNeed = Delete(NoneNeed, i);
            Next(NoneNeed, newArray);
        }
    }
     std::vector<std::vector<char>> getPerms(int k) const {
        std::vector<std::vector<char>> perm;
        std::vector<char> p;
        getPerm(rootArray, k, p, perm);
        return perm;
    }
    void getPerm(Array* iArray, int remains,
        std::vector<char> p, const std::vector<std::vector<char>>& perm) const {
        if (remains == 0) {
            std::vector<std::vector<char>>& nonConstPerm =
                const_cast<std::vector<std::vector<char>>&>(perm);
            nonConstPerm.push_back(p);
            return;
        }
        for (Array* child : iArray->childs) {
            std::vector<char> newP = p;
            newP.push_back(child->data);
            getPerm(child, remains - 1, newP, perm);
        }
    }
};

std::vector<char> getPerm(const Tree& tree, int d);

#endif  // INCLUDE_TREE_H_
