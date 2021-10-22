#include <iostream>
#include "kvadar.h"
#include "a.h"

using namespace std;

/*bool bigger(const Kvadar &k1, const Kvadar &k2) {
//    return k1.getV() > k2.getV();

    double V1 = k1.a * k1.b * k1.c;         // Zelim direktno da izracunam
    double V2 = k2.a * k2.b * k2.c;
    return V1 > V2;
};*/

struct Node {
    Kvadar *kvad;
    Node *next;
    Node(Kvadar *kv) {
        kvad = kv;
        next = nullptr;
    }
    ~Node() {
        delete kvad;
    }
};

int main(int argc, const char *argv[]) {
//    Kvadar::setVm(300);
//    cout << Kvadar::getVm() << endl;
//    Kvadar *k1 = Kvadar::make(2, 4, 6);
//    Kvadar k2(2, 4, 6); <--- Vrsimo kontrolu, ne moze!

    Kvadar *k1 = Kvadar::make(1, 2, 3);
//    Kvadar k2(*k1); // Problem! Treba obrisati kopirajuci konstruktor!
//    Kvadar k3(k2);

    A a;
    a.writeKvadar(*k1);

    Kvadar::setVm(strtod(argv[1], nullptr));

    for (char j = 'd'; j == 'd' || j == 'D'; cout << "\nJos? ", cin >> j) {
        Node *head = nullptr, *tail = head;
        while (true) {
            cout << "a, b, c? ";
            if (Kvadar *kv = Kvadar::read()) {
                tail = (!head ? head : tail->next) = new Node(kv);
            } else break;
        }
        cout << "Zapremine: ";
        for (Node *curr = head; curr; curr = curr->next) {
            cout << curr->kvad->getV() << " ";
        }
        cout << endl << "Ukupna zapremina: " << Kvadar::getVt() << endl;
        while (head) {
            Node *old = head;
            head = head->next;
            delete old; // Poziva se destruktor (za struct je isto <- samo je sve u public klasi default)
        }
        cout << "Ukupna zapremina nakon brisanja: " << Kvadar::getVt() << endl;
    }
    return 0;
}