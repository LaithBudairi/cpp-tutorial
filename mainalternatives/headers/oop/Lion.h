//
// Created by LaithB on 11/12/2020.
//

#ifndef CPP_TUTORIAL_LION_H
#define CPP_TUTORIAL_LION_H

#include "Animal.h"

class Lion : public Animal {
public:
    Lion();
    Lion(char classification);

    char classification = 'C';

    void eat();
};
#endif //CPP_TUTORIAL_LION_H
