//04

#ifndef DROPKI_H   //include guard - za a ne se vkluci zaglavjeto povejke pati
#define DROPKI_H

#include <iostream>

class Dropki {
public:
    Dropki(int b = 0, int i = 1);          // default + parametarski
    void set(int b, int i);                // postavi + validacija

    Dropki soberi(const Dropki& d) const; //soberi so d
    Dropki odzemi(const Dropki& d) const; //odzemi so d
    Dropki pomnozi(const Dropki& d) const; //pomnozi so d
    Dropki podeli(const Dropki& d) const;  // delit so d (d != 0)

    void pecati() const;                   // a/b
    void pecatiRealno() const;             // realen broj

private:
    int broitel;
    int imenitel;

    static int gcd(int a, int b); //reduciranje
    void normalize();  // imenitel > 0
    void reduce();     // skrati ja dropkata
};

#endif
