// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>

std::vector<char> DeleteNoneNeed(std::vector<char> numbers, int index);

class ArrayElement {
     public:
    char data;
    std::vector<ArrayElement*> childs;
};

class Tree {
 private:
    int size;

 public:
    ArrayElement* rootArray;
    explicit Tree(std::vector<char> inData) {
        size = 0;
        rootArray = new ArrayElement;
        rootArray->data = '0';
        for (int i = 0; i < inData.size(); i++) {
            ArrayElement* newArrayElement = new ArrayElement;
            newArrayElement->data = inData[i];
            rootArray->childs.push_back(newArrayElement);
        }
        for (int i = 0; i < inData.size(); i++) {
            std::vector<char> NoneNeedElement = inData;
            NoneNeedElement = DeleteNoneNeed(NoneNeedElement, i);
           CrearNextChilds(NoneNeedElement, rootArray->childs[i]);
        }
    }


    void CrearNextChilds(std::vector<char> in, ArrayElement* parent) {
        if (in.empty()) {
            return;
        }
        for (int i = 0; i < in.size(); i++) {
            ArrayElement* newArrayElement = new ArrayElement;
            newArrayElement->data = in[i];
            parent->childs.push_back(newArrayElement);
            std::vector<char> NoneNeedElement = in;
            NoneNeedElement = DeleteNoneNeed(NoneNeedElement, i);
            CrearNextChilds(NoneNeedElement, newArrayElement);
        }
    }
     std::vector<std::vector<char>> getPerms(int k) const {
        std::vector<std::vector<char>> ps;
        std::vector<char> p;
        getPsRecursive(rootArray, k, p, ps);
        return ps;
    }
    void getPsRecursive(ArrayElement* iArrayElement, int remaining,
        std::vector<char> p, const std::vector<std::vector<char>>& ps) const {
        if (remaining == 0) {
            std::vector<std::vector<char>>& nonConstPs =
                const_cast<std::vector<std::vector<char>>&>(ps);
            nonConstPs.push_back(p);
            return;
        }
        for (ArrayElement* child : iArrayElement->childs) {
            std::vector<char> newP = p;
            newP.push_back(child->data);
            getPsRecursive(child, remaining - 1, newP, ps);
        }
    }
};

std::vector<char> getPerm(const Tree& tree, int d);

#endif  // INCLUDE_TREE_H_
