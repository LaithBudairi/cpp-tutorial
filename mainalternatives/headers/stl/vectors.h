//
// Created by LaithB on 11/29/2020.
//

#ifndef CPP_TUTORIAL_VECTORS_H
#define CPP_TUTORIAL_VECTORS_H
void vectors();
class Box {
    int l = 0, b = 0, h = 0;

public:

    Box() {

    }

    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }

    Box(const Box& B) : l(B.l), b(B.b), h(B.h){}

    int getLength() {
        return l;
    }

    int getBreadth() {
        return b;
    }

    int getHeight() {
        return h;
    }

    long long CalculateVolume() {
        return l * b * h;
    }

    bool operator<(Box& B) {
        if(l < B.l) {
            return true;
        }
        else if(l == B.l && b < B.b) {
            return true;
        }
        else if(l == B.l && b == B.b && h < B.h) {
            return true;
        }
        else {
            return false;
        }
    }
};

std::ostream& operator<<(std::ostream& out, Box& B) {
    out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
    return out;
};
#endif //CPP_TUTORIAL_VECTORS_H
