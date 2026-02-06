#include <iostream>
#include "stedac.h"
using namespace std;

Chovek::Chovek(const string& ime, const string& prezime, const string& adresa, const string& telefon):ime(ime), prezime(prezime), adresa(adresa), telefon(telefon) {}
void Chovek::pecati() const {
    cout<<ime<<" "<<prezime<<" "<<adresa<<" "<<telefon<<endl;
}

double Stedac::kamata=0.0;
int Stedac::brojStedaci=0;

Stedac::Stedac(const Chovek &covek, double bilans, double kredit):covek(covek), bilans(bilans), kredit(kredit) {
    ++Stedac::brojStedaci;
}

void Stedac::setKamata(double kamata) {
     kamata=(kamata>=0.0)?kamata:0.0;
}

double Stedac::getKamata() { return kamata; }
int Stedac::getBrojStedaci() { return brojStedaci; }

void Stedac::dodadiKamata() {
    bilans = bilans * (1.0 + kamata);
}

// void Stedac::pecati() const {
//     covek.pecati();
//     std::cout << " | bilans: " << bilans
//               << " | kredit: " << kredit;
// }
std::ostream& operator<<(std::ostream& os, const Stedac& s) {
    os << s.covek
       << " | bilans: " << s.bilans
       << " | kredit: " << s.kredit
       << " | kamata: " << Stedac::kamata;
    return os;
}

Stedac::~Stedac(){};
int main() {
    Stedac::setKamata(0.05);

    Chovek c1("Ana", "Anova", "Skopje", "070123456");
    Chovek c2("Bojan", "Bojanov", "Skopje", "071222333");

    cout << "Broj stedaci (start): " << Stedac::getBrojStedaci() << "\n";

    Stedac s1(c1, 1000.0, 0.0);
    Stedac s2(c2, 500.0, 200.0);

    cout << "Broj stedaci (po kreiranje): " << Stedac::getBrojStedaci() << "\n";

    s1.dodadiKamata();
    s2.dodadiKamata();

    s1.pecati(); cout << "\n";
    s2.pecati(); cout << "\n";

    cout << "Kamata: " << Stedac::getKamata() << "\n";
    cout << "Broj stedaci (pred kraj): " << Stedac::getBrojStedaci() << "\n";
    return 0;
}


