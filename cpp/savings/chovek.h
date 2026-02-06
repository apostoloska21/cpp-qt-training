#ifndef VEZBI_CPP_QT_CHOVEK_H
#define VEZBI_CPP_QT_CHOVEK_H
#include <string>
using namespace std;

class Chovek {
    private:
    string ime;
    string prezime;
    string adresa;
    string telefon;

    public:
    Chovek(){}
    Chovek(const string& ime, const string& prezime, const string& adresa, const string& telefon);
    void pecati() const;

    friend ostream& operator<<(ostream& os, const Chovek& s);

};

#endif //VEZBI_CPP_QT_CHOVEK_H