// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <cstdint>
#include <string>
#include <vector>

class Drevo {
 private:
    struct Nd;
    std::vector<std::string> Premut;
    Nd* prava;
    void buildDrevo(Node* sir, std::vector<char> sled);
    void generatePermut(Node* sir, std::string Sim);
 public:
    explicit Drevo(const std::vector<char>);
    std::string operator[] (unsigned int y) const;
};
#endif  // INCLUDE_TREE_H_
