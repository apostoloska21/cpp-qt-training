#ifndef VEZBI_CPP_QT_STEDAC_H
#define VEZBI_CPP_QT_STEDAC_H
#include "chovek.h"

class Stedac {
private:
    Chovek covek;
    double bilans;
    double kredit;

    static double kamata;
    static int brojStedaci;

    public:
    Stedac(const Chovek& covek, double bilans=0.0, double kredit=0.0);

    static void setKamata(double kamata);
    static double getKamata();
    static int getBrojStedaci();
    static double getBilans();
    void dodadiKamata();
    void pecati() const;

    friend ostream& operator<<(ostream& os, const Stedac& s);


    ~Stedac();
};

#endif //VEZBI_CPP_QT_STEDAC_H