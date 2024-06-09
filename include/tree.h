// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

struct Leaf {
    std::vector<Leaf*> leaves;
    char symb;
    explicit Leaf(char symb) : symb(symb) {}
};

class Tree {
 private:
    Leaf* host;

    std::vector<char> ModernVect(std::vector \
        <char> digits, char sym) {
        std::vector<char> ResVect;
        for (char c : digits) {
            if (c != sym) {
                ResVect.push_back(c);
            }
        }
        return ResVect;
    }

    void CreateNewGen(Leaf* curs, std::vector<char> digits) {
        curs->leaves.resize(digits.size());
        for (int i = 0; i < digits.size(); i++) {
            curs->leaves[i] = new Leaf(digits[i]);
        }
    }

    void LeafAd(std::vector<char> digits, Leaf* curs) {
        std::vector<char> tempVect;
        tempVect = ModernVect(digits, curs->symb);
        if (tempVect.size()) {
            CreateNewGen(curs, tempVect);
            for (Leaf* branch : curs->leaves) {
                LeafAd(tempVect, branch);
            }
        }
    }

 public:
    Tree() : host(nullptr) {}

    explicit Tree(std::vector<char> in) {
        host = new Leaf(' ');
        LeafAd(in, host);
    }

    Leaf* gethost() {
        return host;
    }
};

int factor(int);
std::vector<char> CreateDigit(Leaf*, int, std::vector<char>);

#endif  // INCLUDE_TREE_H_
