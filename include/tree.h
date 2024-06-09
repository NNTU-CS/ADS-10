// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
std::vector<char> udal(std::vector<char> chis, int por_nom);
struct Knot {
    std::vector<Knot*> potom;
    char info;
};
class Tree {
 private:
    int pazm;

 public:
    Knot* orig;
    explicit Tree(std::vector<char> vhod) : pazm(0) {
        orig = new Knot;
        orig->info = '0';
        for (int j = 0; j < vhod.size(); j++) {
            Knot* newKnot = new Knot;
            newKnot->info = vhod[j];
            orig->potom.push_back(newKnot);
        }
        for (int j = 0; j < vhod.size(); j++) {
            std::vector<char> timing = vhod;
            timing = udal(timing, j);
            next(timing, orig->potom[j]);
        }
    }
    void dob_potom(Knot* rod, char znach) {
        Knot* r = new Knot;
        r->info = znach;
        r->potom.push_back(r);
    }
    void next(std::vector<char> vhod, Knot* rod) {
        if (vhod.empty()) {
            return;
        }
        for (int j = 0; j < vhod.size(); j++) {
            Knot* newKnot = new Knot;
            newKnot->info = vhod[j];
            rod->potom.push_back(newKnot);
            std::vector<char> timing = vhod;
            timing = udal(timing, j);
            next(timing, newKnot);
        }
    }
    std::vector<std::vector<char>> receive(int l) const {
        std::vector<std::vector<char>> recs;
        std::vector<char> rec;
        recieverecurs(orig, l, rec, recs);
        return recs;
    }
    void recieverecurs(Knot* knot, int residual, std::vector<char> rec,
        const std::vector<std::vector<char>>& recs) const {
        if (residual == 0) {
            std::vector<std::vector<char>>& recsno =
                const_cast<std::vector<std::vector<char>>&>(recs);
            recsno.push_back(rec);
            return;
        }
        for (Knot* potom : knot->potom) {
            std::vector<char> newrec = rec;
            newrec.push_back(potom->info);
            recieverecurs(potom, residual - 1, newrec, recs);
        }
    }
};
std::vector<char> getPerm(const Tree& tree, int n);
#endif  // INCLUDE_TREE_H_
