// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>

std::vector<char> Func_Deleted(std::vector<char> figures, float i);

struct Data {
    char record;
    std::vector<Data*> heirs;
};

class Tree {
 private:
    int dimension;

 public:
    Data* root;
    explicit Tree(std::vector<char> hate) : dimension(0) {
        root = new Data;
        root->record = '0';
        for (int i = 0; i < hate.size(); i++) {
            Data* newData = new Data;
            newData->record = hate[i];
            root->heirs.push_back(newData);
        }
        for (int j = 0; j < hate.size(); j++) {
            std::vector<char> tk = hate;
            tk = Func_Deleted(tk, j);
            adding_an_heir(tk, root->heirs[j]);
        }
    }
    void AddedHeirs(Data* people, char value) {
        Data* Head = new Data;
        Head->record = value;
        Head->heirs.push_back(Head);
    }
    void adding_an_heir(std::vector<char> vong, Data* people) {
        if (vong.empty()) {
            return;
        }
        for (int i = 0; i < vong.size(); i++) {
            Data* newData = new Data;
            newData->record = vong[i];
            people->heirs.push_back(newData);
            std::vector<char> tk = vong;
            tk = Func_Deleted(tk, i);
            adding_an_heir(tk, newData);
        }
    }
    std::vector<std::vector<char>> getPermanents(int c) const {
        std::vector<char> permanent;
        std::vector<std::vector<char>> permanents;
        getRecursive(root, c, permanent, permanents);
        return permanents;
    }
    void getRecursive(Data* data, int residuary,
        std::vector<char> permanent, const std::vector<std::vector<char>>& permanents) const {
        if (residuary == 0) {
            std::vector<std::vector<char>>& nonPermanentss = const_cast<std::vector<std::vector<char>>&>(permanents);
            nonPermanentss.push_back(permanent);
            return;
        }
        for (Data* Friend : data->heirs) {
            std::vector<char> newPermanent = permanent;
            newPermanent.push_back(Friend->record);
            getRecursive(Friend, residuary - 1, newPermanent, permanents);
        }
    }
};

std::vector<char> getPerm(const Tree& tree, int count);

#endif  // INCLUDE_TREE_H_
