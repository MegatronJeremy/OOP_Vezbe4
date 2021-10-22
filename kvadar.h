#ifndef OOP_VEZBE4_KVADAR_H
#define OOP_VEZBE4_KVADAR_H

#include <iostream>
using namespace std;

class Kvadar {
    static double Vt, Vm;
    double a, b, c;
    Kvadar(double aa, double bb, double cc) {       // Treba se definisati i kopirajuci konstruktor! I dalje se moze napraviti!
        a = aa; b = bb; c = cc;
    }
public:
    friend class A;

    Kvadar(const Kvadar &k) = delete;   // Brise se kopirajuci konstrukro

    static double getVm() { return Vm; }    // Staticka metoda nema this --> nije vezana za objekat (moze se pozivati bez objekta)
    static bool setVm(double max) {
       if (max < Vt) return false;
       Vm = max;
//       this->Vmax = max; nema this
       return true;
    }
    static double getVt() { return Vt; }
    static Kvadar *make(double a, double b, double c) {
        double V = a * b * c;
        if (a <= 0 || b <= 0 || c <= 0 || V+Vt > Vm)
            return nullptr;
        Vt += V;
        return new Kvadar(a, b, c);
    }
    static Kvadar *read() {
        double a, b, c;
        cin >> a >> b >> c;
        return make(a, b, c);
    }
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getV() const { return a * b * c; }
    void write() const {
        cout << "kvadar[" << a << ", " << b << ", " << c << "]";
    }
//    friend bool bigger(const Kvadar &k1, Kvadar &k2);   // F-ja ima pravo pristupa na sva polja
    friend bool bigger(const Kvadar &k1, const Kvadar &k2) { // Moze se i ovako definisati (nema this jedino - prijateljska f-ja)
        //    return k1.getV() > k2.getV();
        double V1 = k1.a * k1.b * k1.c;         // Zelim direktno da izracunam
        double V2 = k2.a * k2.b * k2.c;
        return V1 > V2;
    };
    // veci(k1, k2)

    bool bigger(const Kvadar &k) const {
        return getV() > k.getV();
    }
    // k1.veci(k2);
    ~Kvadar() {
        Vt -= a * b * c;
    }
};


#endif //OOP_VEZBE4_KVADAR_H
