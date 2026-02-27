//
// Created by Martina Apostoloska on 24.2.26.
//
#include <iostream>
#include <ctime>
#include <iomanip>
#include <utility>
using namespace std;

class Datum {
protected:
    int den;
    int mesec;
    int godina;

    public:
    Datum(const int den=0, const int mesec=0, const int godina=0) :den(den), mesec(mesec), godina(godina) {
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
    }

    Datum(const Datum& d) {
        this->den=d.den;
        this->mesec=d.mesec;
        this->godina=d.godina;
    }

    void pecati() const {
        cout<<den<<"/"<<mesec<<"/"<<godina<<endl;
    }

    int get_den() const {
        return den;
    }

    int get_mesec() const {
        return mesec;
    }

    int get_godina() const {
        return godina;
    }
    Datum plusDena(int n) const {
        int d = den + n;
        int m = mesec;
        int g = godina;

        while (d > 30) { d -= 30; m++; }
        while (m > 12) { m -= 12; g++; }
        return Datum(d, m, g);
    }


    bool operator<=(const Datum& other) const {
        if (godina != other.godina) return godina < other.godina;
        if (mesec != other.mesec) return mesec < other.mesec;
        return den <= other.den;
    }
    virtual ~Datum(){}
};

class Artikl{
    private:
    string ime_na_artikl;
    int golemina;
    double cena;
    Datum donesen_vo_prodavnica;

public:
    Artikl(const string ime_na_artikl=" ", const int golemina=0, const double cena=0, const Datum& donesen = Datum()) : ime_na_artikl((ime_na_artikl)), golemina(golemina), cena(cena), donesen_vo_prodavnica(donesen) {

    }


    string get_ime_na_artikl() const {
        return ime_na_artikl;
    }

    void set_ime_na_artikl(const string &ime_na_artikl) {
        this->ime_na_artikl = ime_na_artikl;
    }

     int get_golemina() const {
        return golemina;
    }

    void set_golemina(int golemina) {
        this->golemina = golemina;
    }

    double get_cena() const {
        return cena;
    }

    void set_cena(double cena) {
        this->cena = cena;
    }

    Datum get_donesen_vo_prodavnica() const {
        return donesen_vo_prodavnica;
    }

    void set_donesen_vo_prodavnica(const Datum &donesen_vo_prodavnica) {
        this->donesen_vo_prodavnica = donesen_vo_prodavnica;
    }

    virtual void Prikazi_Podatoci() const {
        cout << "Ime: " << ime_na_artikl
             << ", Golemina: " << golemina
             << ", Cena: " << fixed << setprecision(2)  << cena
             << ", Donesen: ";
        donesen_vo_prodavnica.pecati();
    }

    virtual Datum Presmetaj_nabavka() const = 0;

    virtual string grupa() const = 0;

    virtual ~Artikl() {}

};
class Pantaloni : public Artikl {
private:
    Datum datum_na_sledna_nabavka;
    public:
    Pantaloni(const Datum& datum_na_sledna,
                string ime_na_artikl,
                int golemina,
                double cena,
                const Datum& donesen)
          : Artikl(ime_na_artikl, golemina, cena, donesen),
            datum_na_sledna_nabavka(donesen.plusDena(30)) {

    }
Datum Presmetaj_nabavka() const {
       Datum datum=datum_na_sledna_nabavka;
        int nov_den = datum.get_den() + 30;
        int mesec = datum.get_mesec();
        int godina = datum.get_godina();

        if (nov_den > 30) {
            nov_den -= 30;
            mesec++;
        }
        if (mesec > 12) {
            mesec =1;
            godina++;
        }
        return Datum(nov_den, mesec, godina);
    }
    string grupa() const override{
        return "Pantaloni";
    }

    void Prikazi_Podatoci() const {
        Artikl::Prikazi_Podatoci();
        cout<<"Sledna nabavka: ";
        datum_na_sledna_nabavka.pecati();
        cout<<endl;

    }

};

class Kosuli : public Artikl {
private:
    bool poPotreba;
    Datum datum_nabavka;

    public:
    Kosuli(const string ime_na_artikl, int golemina, double cena, const Datum& donesen, bool poPotreba, const Datum& datum_nabavka):Artikl(ime_na_artikl, golemina, cena, donesen), poPotreba(poPotreba), datum_nabavka(datum_nabavka) {
    }

Datum Presmetaj_nabavka() const {
         if (!poPotreba) {
             cout<<"vo red, nema potreba";
             return datum_nabavka;
         }
    }
    string grupa() const override {
        return "Kosuli";
    }

};
static void pecatiMeni() {
    cout << "\n--- MENI ---\n";
    cout << "1. Dodavanje na artikl vo listata\n";
    cout << "2. Prikazuvanje na artikli od dadena grupa\n";
    cout << "3. Prikazuvanje na celata lista (so vkupna cena)\n";
    cout << "4. Artikli za nabavka vo rok od 1 nedela + vkupno pari\n";
    cout << "5. Izlez\n";
    cout << "Izbor: ";
}
#include <vector>
#include <limits>

int main() {
    vector<Artikl*> lista;

    int izbor = 0;

    while (izbor != 5) {
        pecatiMeni();
        cin >> izbor;

        if (izbor == 1) {
            int tip, den, mesec, godina, golemina;
            double cena;
            string ime;

            cout << "Vnesi tip na artikl (1-Pantaloni, 2-Kosuli): ";
            cin >> tip;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Vnesi ime na artikl: ";
            getline(cin, ime);

            cout << "Vnesi golemina: ";
            cin >> golemina;

            cout << "Vnesi cena: ";
            cin >> cena;

            cout << "Vnesi datum na donesen_vo_prodavnica (den mesec godina): ";
            cin >> den >> mesec >> godina;
            Datum donesen(den, mesec, godina);

            if (tip == 1) {
                // pantaloni: sledna nabavka sekoj mesec -> donesen + 30
                Datum datum_na_sledna = donesen.plusDena(30);

                lista.push_back(new Pantaloni(datum_na_sledna, ime, golemina, cena, donesen));
                cout << "Dodadeni Pantaloni.\n";
            }
            else if (tip == 2) {
                int x;
                cout << "Dali kosulite se po potreba za nabavka? (1=DA, 0=NE): ";
                cin >> x;
                bool poPotreba = (x == 1);

                Datum datum_nabavka;
                if (poPotreba) {
                    cout << "Vnesi datum na nabavka (den mesec godina): ";
                    cin >> den >> mesec >> godina;
                    datum_nabavka = Datum(den, mesec, godina);
                } else {
                    // dalecen datum za da ne vleguva vo "vo rok od 1 nedela"
                    datum_nabavka = Datum(30, 12, 9999);
                }

                lista.push_back(new Kosuli(ime, golemina, cena, donesen, poPotreba, datum_nabavka));
                cout << "Dodadena Kosula.\n";
            }
            else {
                cout << "Nevaliden tip!\n";
            }
        }
        else if (izbor == 2) {
            int g;
            cout << "Izberi grupa (1-Pantaloni, 2-Kosuli): ";
            cin >> g;
            string barana_grupa = (g == 1 ? "Pantaloni" : "Kosuli");

            for (Artikl* a : lista) {
                if (a->grupa() == barana_grupa) {
                    a->Prikazi_Podatoci();
                    cout << "\n";
                }
            }
        }
        else if (izbor == 3) {
            double vkupno = 0.0;
            for (Artikl* a : lista) {
                a->Prikazi_Podatoci();
                cout << "\n";
                vkupno += a->get_cena();
            }
            cout << "VKUPNA CENA: " << fixed << setprecision(2) << vkupno << "\n";
        }
        else if (izbor == 4) {
            int den, mesec, godina;
            cout << "Vnesi denesen datum (den mesec godina): ";
            cin >> den >> mesec >> godina;
            Datum denes(den, mesec, godina);

            Datum limit = denes.plusDena(7); // 1 nedela

            double suma = 0.0;
            for (Artikl* a : lista) {
                Datum nab = a->Presmetaj_nabavka();
                if (nab <= limit) {
                    a->Prikazi_Podatoci();
                    cout << "\n";
                    suma += a->get_cena();
                }
            }
            cout << "VKUPNO PARI (za 1 nedela): " << fixed << setprecision(2) << suma << "\n";
        }
        else if (izbor == 5) {
            cout << "Izlez.\n";
        }
        else {
            cout << "Nevalidna opcija.\n";
        }
    }

    for (Artikl* a : lista) delete a;
    return 0;
}
