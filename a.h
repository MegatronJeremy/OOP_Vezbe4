#ifndef OOP_VEZBE4_A_H
#define OOP_VEZBE4_A_H

#include "kvadar.h"

class A {
public:
    void writeKvadar(const Kvadar &k) const {
        cout << k.a << " " << k.b << " " << k.c;
    }
};


#endif //OOP_VEZBE4_A_H
