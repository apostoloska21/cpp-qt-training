//04

#include "dropki.h"
#include  <iostream>
#include <math.h>
using namespace std;

Dropki::Dropki(int b, int i) {
    set(b, i);
}

void Dropki::set(int b, int i) {
    if (i==0) {
        broitel = 0;
        imenitel=1;
    }
    else {
        broitel = b;
        imenitel = i;
        normalize();
        reduce();
    }
}
int Dropki::gcd(int a, int b) { //ova go koristam za da reduciram 2/4 - 1/2
    a=abs(a);
    b=abs(b);
    if (a==0) return (b==0 ? 1:b);
    while (b!=0) {
        int res=a%b;
        a=b;
        b=res;
    }
    return (a==0?1:a);
}

void Dropki::normalize() { //ako imenitelot e negativen, menuvaj znaci
    if (imenitel<0) {
        imenitel=-imenitel;
        broitel=-broitel;
    }
}
void Dropki::reduce() {
    if (broitel==0) {
        imenitel=1;
        return;
    }
    int g=gcd(broitel,imenitel);
    broitel/=g;
    imenitel/=g;
}
Dropki Dropki::soberi(const Dropki &d) const {
    return Dropki(broitel * d.imenitel +d.broitel * imenitel, imenitel*d.imenitel);
}
Dropki Dropki::odzemi(const Dropki &d) const {
    return Dropki(broitel*d.imenitel - d.broitel * imenitel, imenitel*d.imenitel);
}
Dropki Dropki::pomnozi(const Dropki &d) const {
    return Dropki(broitel*d.broitel, imenitel*d.broitel);
}
Dropki Dropki::podeli(const Dropki &d) const {
    if (d.broitel==0) return Dropki(0, 1);
    return Dropki(broitel*d.imenitel, imenitel*d.broitel);
}
void Dropki::pecati() const {
  cout << broitel << "/" << imenitel;
}
void Dropki::pecatiRealno() const {
    cout << static_cast<double>(broitel) / imenitel;
}

int main() {
    int a, b, c, d;

    cout << "Vnesi prva dropka (broitel imenitel): ";
    cin >> a >> b;
   cout << "Vnesi vtora dropka (broitel imenitel): ";
    cin >> c >> d;

    Dropki x(a, b), y(c, d);

    cout << "\nX = "; x.pecati(); cout << " = "; x.pecatiRealno();
   cout << "\nY = "; y.pecati(); cout << " = "; y.pecatiRealno();

    Dropki s = x.soberi(y);
    Dropki o = x.odzemi(y);
    Dropki m = x.pomnozi(y);
    Dropki p = x.podeli(y);

    cout << "\n\nX + Y = "; s.pecati(); cout << " = "; s.pecatiRealno();
   cout << "\nX - Y = "; o.pecati(); cout << " = "; o.pecatiRealno();
    cout << "\nX * Y = "; m.pecati(); cout << " = "; m.pecatiRealno();
    cout << "\nX / Y = "; p.pecati(); cout << " = "; p.pecatiRealno();

    cout << "\n";
    return 0;
}