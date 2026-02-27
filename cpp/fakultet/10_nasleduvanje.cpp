#include <cstring>
#include <iostream>
using namespace std;

class Vraboten {
private:
    char ime[100];
    char prezime[100];
    int godina_na_vrabotuvanje;

public:
    Vraboten() {
        postavi("", "", 0);
    }

    Vraboten(const char* ime = "", const char* prezime = "", int godina_na_vrabotuvanje = 0) {
        postavi(ime, prezime, godina_na_vrabotuvanje);
    }

    Vraboten(const Vraboten& v) {
        postavi(v.ime, v.prezime, v.godina_na_vrabotuvanje);
    }

    void postavi(const char* ime, const char* prezime, int godina_na_vrabotuvanje = 0) {
        strncpy(this->ime, ime, sizeof(this->ime) - 1);
        this->ime[sizeof(this->ime) - 1] = '\0';

        strncpy(this->prezime, prezime, sizeof(this->prezime) - 1);
        this->prezime[sizeof(this->prezime) - 1] = '\0';

        this->godina_na_vrabotuvanje = godina_na_vrabotuvanje;
    }

    virtual void prikazi_podatoci() const {
        cout << ime << " " << prezime << " " << godina_na_vrabotuvanje;
    }

    virtual ~Vraboten() {}
};

class Profesor : public Vraboten {
private:
    char zvanje[100];
    char oblast[100];
    int br_predmeti;

public:
    Profesor(const char* ime = "", const char* prezime = "", int godina = 0,
             const char* zvanje = "", const char* oblast = "", int br_predmeti = 0)
        : Vraboten(ime, prezime, godina)
    {
        postaviProfesor(zvanje, oblast, br_predmeti);
    }

    Profesor(const Profesor& p)
        : Vraboten(p)
    {
        postaviProfesor(p.zvanje, p.oblast, p.br_predmeti);
    }

    void postaviProfesor(const char* zvanje, const char* oblast, int br_predmeti) {
        strncpy(this->zvanje, zvanje, sizeof(this->zvanje) - 1);
        this->zvanje[sizeof(this->zvanje) - 1] = '\0';

        strncpy(this->oblast, oblast, sizeof(this->oblast) - 1);
        this->oblast[sizeof(this->oblast) - 1] = '\0';

        this->br_predmeti = br_predmeti;
    }

    void prikazi_podatoci() const override {
        Vraboten::prikazi_podatoci();
        cout << " zvanje: " << zvanje
             << " oblast: " << oblast
             << " br_predmeti: " << br_predmeti;
    }

    ~Profesor() override {}
};

class Asistent : public Vraboten {
private:
    char zvanje[100];
    char mentor[100];
    int br_predmeti;

public:
    Asistent(const char* ime = "", const char* prezime = "", int godina = 0,
             const char* zvanje = "", const char* mentor = "", int br_predmeti = 0)
        : Vraboten(ime, prezime, godina)
    {
        postaviAsistent(zvanje, mentor, br_predmeti);
    }

    Asistent(const Asistent& a)
        : Vraboten(a)
    {
        postaviAsistent(a.zvanje, a.mentor, a.br_predmeti);
    }

    void postaviAsistent(const char* z, const char* m, int br) {
        strncpy(this->zvanje, z, sizeof(this->zvanje) - 1);
        this->zvanje[sizeof(this->zvanje) - 1] = '\0';

        strncpy(this->mentor, m, sizeof(this->mentor) - 1);
        this->mentor[sizeof(this->mentor) - 1] = '\0';

        this->br_predmeti = br;
    }

    void prikazi_podatoci() const override {
        Vraboten::prikazi_podatoci();
        cout << " zvanje: " << zvanje
             << " mentor: " << mentor
             << " br_predmeti: " << br_predmeti;
    }

    ~Asistent() override {}
};

class Demonstrator : public Vraboten {
private:
    char od[100];
    char doo[100];

public:
    Demonstrator(const char* ime = "", const char* prezime = "", int godina = 0,
                 const char* od = "", const char* doo = "")
        : Vraboten(ime, prezime, godina)
    {
        postaviDemonstrator(od, doo);
    }

    Demonstrator(const Demonstrator& d)
        : Vraboten(d)
    {
        postaviDemonstrator(d.od, d.doo);
    }

    void postaviDemonstrator(const char* o, const char* d) {
        strncpy(this->od, o, sizeof(this->od) - 1);
        this->od[sizeof(this->od) - 1] = '\0';

        strncpy(this->doo, d, sizeof(this->doo) - 1);
        this->doo[sizeof(this->doo) - 1] = '\0';
    }

    void prikazi_podatoci() const override {
        Vraboten::prikazi_podatoci();
        cout << " rabotno_vreme: " << od << "-" << doo;
    }

    ~Demonstrator() override {}
};

int main() {
    Vraboten* lista[100];
    int n = 0;
    int opcija;

    do {
        cout << "\n1. Dodavanje nov vraboten\n";
        cout << "2. Prikazuvanje na listata\n";
        cout << "3. Kraj\n";
        cout << "Izbor: ";
        cin >> opcija;

        if (opcija == 1) {
            if (n >= 100) {
                cout << "Listata e polna!\n";
                continue;
            }

            int tip;
            cout << "Tip (1-profesor, 2-asistent, 3-demonstrator): ";
            cin >> tip;

            char ime[100], prezime[100];
            int godina;
            cout << "Ime: "; cin >> ime;
            cout << "Prezime: "; cin >> prezime;
            cout << "Godina: "; cin >> godina;

            if (tip == 1) {
                char zvanje[100], oblast[100];
                int br;
                cout << "Zvanje: "; cin >> zvanje;
                cout << "Oblast: "; cin >> oblast;
                cout << "Br predmeti: "; cin >> br;

                lista[n++] = new Profesor(ime, prezime, godina, zvanje, oblast, br);
            }
            else if (tip == 2) {
                char zvanje[100], mentor[100];
                int br;
                cout << "Zvanje: "; cin >> zvanje;
                cout << "Mentor: "; cin >> mentor;
                cout << "Br predmeti: "; cin >> br;

                lista[n++] = new Asistent(ime, prezime, godina, zvanje, mentor, br);
            }
            else if (tip == 3) {
                char od[100], doo[100];
                cout << "Rabotno vreme OD: "; cin >> od;
                cout << "Rabotno vreme DO: "; cin >> doo;

                lista[n++] = new Demonstrator(ime, prezime, godina, od, doo);
            }
            else {
                cout << "Nevaliden tip!\n";
            }
        }
        else if (opcija == 2) {
            for (int i = 0; i < n; i++) {
                lista[i]->prikazi_podatoci();
                cout << endl;
            }
        }

    } while (opcija != 3);

    for (int i = 0; i < n; i++) delete lista[i];
    return 0;
}
