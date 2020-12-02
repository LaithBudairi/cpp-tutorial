//
// Created by LaithB on 12/2/2020.
//
#include "iostream"

#ifndef CPP_TUTORIAL_NAMESPACES_H
#define CPP_TUTORIAL_NAMESPACES_H
namespace a {
    void print() {
        std::cout << "function from namespace a\n";
    }
}

namespace b {
    void print() {
        std::cout << "function from namespace b\n\n";
    }
};
void namespaces() {
    a::print();
    b::print();
}
#endif //CPP_TUTORIAL_NAMESPACES_H
