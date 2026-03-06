#include <iostream>
#include <vector>
using namespace std;

time_t createDate(int day, int month, int year) {
    tm t = {};
    t.tm_mday = day;
    t.tm_mon = month - 1;
    t.tm_year = year - 1900;
    t.tm_hour = 12;
    return mktime(&t);
}
string formatDate(time_t date) {
    char buffer[20];
    tm *t = localtime(&date);
    strftime(buffer, sizeof(buffer), "%d.%m.%Y", t);
    return string(buffer);
}

time_t addMonths(time_t date, int months) {
    tm t = *localtime(&date);
    t.tm_mon += months;
    return mktime(&t);
}

time_t addYears(time_t date, int years) {
    tm t = *localtime(&date);
    t.tm_year += years;
    return mktime(&t);
}

double daysBetween(time_t from, time_t to) {
    return difftime(to, from) / (60 * 60 * 24);
}
class Zivotno {
    protected:
    time_t datum_na_rajganje;
    time_t datum_na_donesuvanje_na_zivotno;
    string pol;
    string ime;
    time_t datum_na_posledna_vakcina;
public:
    Zivotno(time_t datum_na_rajganje, time_t datum_na_donesuvanje_na_zivotno, string& pol, string& ime, time_t datum_na_posledna_vakcina)
    :datum_na_rajganje(datum_na_rajganje), datum_na_donesuvanje_na_zivotno(datum_na_donesuvanje_na_zivotno), pol(pol), ime(ime), datum_na_posledna_vakcina(datum_na_posledna_vakcina) {
        this->datum_na_rajganje = datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = datum_na_donesuvanje_na_zivotno;
        this->pol = pol;
        this->ime = ime;
        this->datum_na_posledna_vakcina = datum_na_posledna_vakcina;
    };
    Zivotno(const Zivotno &z) {
        this->datum_na_rajganje = z.datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = z.datum_na_donesuvanje_na_zivotno;
        this->pol = z.pol;
        this->ime = z.ime;
        this->datum_na_posledna_vakcina = z.datum_na_posledna_vakcina;
    }

    virtual void prikaziPodatoci() const {
        cout << "Ime: " << ime << endl;
        cout << "Pol: " << pol << endl;
        cout << "Datum na ragjanje: " << formatDate(datum_na_rajganje) << endl;
        cout << "Datum na donesuvanje vo zoo: " << formatDate(datum_na_donesuvanje_na_zivotno) << endl;
        cout << "Datum na posledna vakcina: " << formatDate(datum_na_posledna_vakcina) << endl;
    }
    virtual time_t presmetaj_vakcinacija()const=0;
    virtual string tip() const = 0;

    ~Zivotno(){};
};
class Vlekaci: public Zivotno {
    protected:
    time_t datum_na_sledna_vakcinacija;
public:
    Vlekaci(time_t datum_na_sledna_vakcinacija, time_t datum_na_rajganje, time_t datum_na_donesuvanje_na_zivotno, string& pol, string& ime, time_t datum_na_posledna_vakcina) : Zivotno( datum_na_rajganje,  datum_na_donesuvanje_na_zivotno,  pol,  ime, datum_na_posledna_vakcina),
        datum_na_sledna_vakcinacija(datum_na_sledna_vakcinacija) {
        this->datum_na_sledna_vakcinacija = datum_na_sledna_vakcinacija;
        this->datum_na_rajganje = datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = datum_na_donesuvanje_na_zivotno;
        this->pol = pol;
        this->ime = ime;
        this->datum_na_posledna_vakcina = datum_na_posledna_vakcina;
    }

    Vlekaci(const Vlekaci &v):Zivotno(v){
        this->datum_na_sledna_vakcinacija = v.datum_na_sledna_vakcinacija;
        this->datum_na_rajganje = v.datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = v.datum_na_donesuvanje_na_zivotno;
        this->pol = v.pol;
        this->ime = v.ime;
        this->datum_na_posledna_vakcina = v.datum_na_posledna_vakcina;
    }
    void prikaziPodatoci() const override {
        cout << "[Vlekac]" << endl;
        Zivotno::prikaziPodatoci();
        cout << "Datum na sledna vakcinacija: " << formatDate(datum_na_sledna_vakcinacija) << endl;
    }
    time_t presmetaj_vakcinacija() const override {
        return datum_na_sledna_vakcinacija;
    }
    string tip() const override {
        return "vlekac";
    }
    ~Vlekaci(){};
};

class Ptici : public Zivotno {
    protected:
    bool letac;
public:
    Ptici(bool letac, time_t datum_na_rajganje, time_t datum_na_donesuvanje_na_zivotno, string& pol, string& ime, time_t datum_na_posledna_vakcina) : Zivotno( datum_na_rajganje,  datum_na_donesuvanje_na_zivotno,  pol,  ime, datum_na_posledna_vakcina) {
        this->letac = letac;
        this->datum_na_rajganje = datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = datum_na_donesuvanje_na_zivotno;
        this->pol = pol;
        this->ime = ime;
        this->datum_na_posledna_vakcina = datum_na_posledna_vakcina;
    }
    Ptici(const Ptici &p):Zivotno(p) {
       this->letac = p.letac;
        this->datum_na_rajganje = p.datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = p.datum_na_donesuvanje_na_zivotno;
        this->pol = p.pol;
        this->ime = p.ime;
        this->datum_na_posledna_vakcina = p.datum_na_posledna_vakcina;
    }
    void prikaziPodatoci() const override {
        cout << "[Ptica]" << endl;
        Zivotno::prikaziPodatoci();
        cout << "Letac: " << (letac ? "da" : "ne") << endl;
        cout << "Sledna vakcinacija: " << formatDate(presmetaj_vakcinacija()) << endl;
    }
    time_t presmetaj_vakcinacija() const override {
        return addMonths(datum_na_posledna_vakcina, 6);
    }
    string tip() const override {
        return "ptica";
    }
    ~Ptici(){};
};

class Cicaci : public Zivotno {
    protected:
    bool prezivar;
    public:
    Cicaci(bool prezivar, time_t datum_na_rajganje, time_t datum_na_donesuvanje_na_zivotno, string pol, string ime, time_t datum_na_posledna_vakcina) : Zivotno( datum_na_rajganje,  datum_na_donesuvanje_na_zivotno,  pol,  ime, datum_na_posledna_vakcina) {
        this->prezivar = prezivar;
        this->datum_na_rajganje = datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = datum_na_donesuvanje_na_zivotno;
        this->pol = pol;
        this->ime = ime;
        this->datum_na_posledna_vakcina = datum_na_posledna_vakcina;
    }
    Cicaci(const Cicaci &c):Zivotno(c) {
      this->prezivar = c.prezivar;
        this->datum_na_rajganje = c.datum_na_rajganje;
        this->datum_na_donesuvanje_na_zivotno = c.datum_na_donesuvanje_na_zivotno;
        this->pol = c.pol;
        this->ime = c.ime;
        this->datum_na_posledna_vakcina =c.datum_na_posledna_vakcina;
    }
    void prikaziPodatoci() const override {
        cout << "[Cicac]" << endl;
        Zivotno::prikaziPodatoci();
        cout << "Prezivar: " << (prezivar ? "da" : "ne") << endl;
        cout << "Sledna vakcinacija: " << formatDate(presmetaj_vakcinacija()) << endl;
    }

    time_t presmetaj_vakcinacija() const override {
        return addMonths(datum_na_posledna_vakcina, 6);
    }
    string tip() const override {
        return "cicac";
    }

    ~Cicaci(){};

};
time_t vnesiDatum() {
    int d, m, y;
    cin >> d >> m >> y;
    return createDate(d, m, y);
}

void dodadiZivotno(vector<Zivotno*>& zoo) {
    int izbor;
    cout << "Izberi tip na zivotno:\n";
    cout << "1. Vlekac\n2. Ptica\n3. Cicac\n";
    cin >> izbor;

    string pol, ime;
    time_t datumRagjanje, datumDonesuvanje, datumPoslednaVakcina;

    cout << "Vnesi ime: ";
    cin >> ime;

    cout << "Vnesi pol (m/z): ";
    cin >> pol;

    cout << "Vnesi datum na ragjanje (dd mm yyyy): ";
    datumRagjanje = vnesiDatum();

    cout << "Vnesi datum na donesuvanje vo zoo (dd mm yyyy): ";
    datumDonesuvanje = vnesiDatum();

    cout << "Vnesi datum na posledna vakcina (dd mm yyyy): ";
    datumPoslednaVakcina = vnesiDatum();

    if (izbor == 1) {
        time_t datumSlednaVakcinacija;
        cout << "Vnesi datum na sledna vakcinacija (dd mm yyyy): ";
        datumSlednaVakcinacija = vnesiDatum();

        zoo.push_back(new Vlekaci(
            datumSlednaVakcinacija,
            datumRagjanje,
            datumDonesuvanje,
            pol,
            ime,
            datumPoslednaVakcina
        ));
    }
    else if (izbor == 2) {
        bool letac;
        cout << "Dali e letac? (1/0): ";
        cin >> letac;

        zoo.push_back(new Ptici(
            letac,
            datumRagjanje,
            datumDonesuvanje,
            pol,
            ime,
            datumPoslednaVakcina
        ));
    }
    else if (izbor == 3) {
        bool prezivar;
        cout << "Dali e prezivar? (1/0): ";
        cin >> prezivar;

        zoo.push_back(new Cicaci(
            prezivar,
            datumRagjanje,
            datumDonesuvanje,
            pol,
            ime,
            datumPoslednaVakcina
        ));
    }
    else {
        cout << "Nevaliden izbor.\n";
    }
}
void prikaziBrojnaSostojba(const vector<Zivotno*>& zoo) {
    int brVlekaci = 0, brPtici = 0, brCicaci = 0;

    for (auto z : zoo) {
        if (z->tip() == "vlekac") brVlekaci++;
        else if (z->tip() == "ptica") brPtici++;
        else if (z->tip() == "cicac") brCicaci++;
    }

    cout << "Vkupno zivotni: " << zoo.size() << endl;
    cout << "Vlekaci: " << brVlekaci << endl;
    cout << "Ptici: " << brPtici << endl;
    cout << "Cicaci: " << brCicaci << endl;
}

void prikaziOdDadenaGrupa(const vector<Zivotno*>& zoo) {
    string grupa;
    cout << "Vnesi grupa (vlekac/ptica/cicac): ";
    cin >> grupa;

    bool najdeno = false;
    for (auto z : zoo) {
        if (z->tip() == grupa) {
            z->prikaziPodatoci();
            najdeno = true;
        }
    }

    if (!najdeno) {
        cout << "Nema zivotni od taa grupa." << endl;
    }
}

void prikaziCelaLista(const vector<Zivotno*>& zoo) {
    if (zoo.empty()) {
        cout << "Listata e prazna." << endl;
        return;
    }

    for (auto z : zoo) {
        z->prikaziPodatoci();
    }
}

void prikaziVakcinacijaVo1Nedela(const vector<Zivotno*>& zoo) {
    time_t sega = time(nullptr);
    bool najdeno = false;

    for (auto z : zoo) {
        time_t slednaVakcinacija = z->presmetaj_vakcinacija();
        double denovi = daysBetween(sega, slednaVakcinacija);

        if (denovi >= 0 && denovi <= 7) {
            z->prikaziPodatoci();
            cout << "Treba da se vakcinira vo rok od 1 nedela." << endl;
            najdeno = true;
        }
    }

    if (!najdeno) {
        cout << "Nema zivotni koi treba da se vakciniraat vo rok od 1 nedela." << endl;
    }
}

int main() {
    vector<Zivotno*> zoo;
    int izbor;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Dodavanje na zivotno vo listata\n";
        cout << "2. Prikazuvanje na brojna sostojba\n";
        cout << "3. Prikazuvanje na zivotni od dadena grupa\n";
        cout << "4. P1rikazuvanje na celata lista\n";
        cout << "5. Prikazuvanje na site zivotni koi treba da se vakciniraat vo rok od 1 nedela\n";
        cout << "6. Izlez\n";
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1:
                dodadiZivotno(zoo);
                break;
            case 2:
                prikaziBrojnaSostojba(zoo);
                break;
            case 3:
                prikaziOdDadenaGrupa(zoo);
                break;
            case 4:
                prikaziCelaLista(zoo);
                break;
            case 5:
                prikaziVakcinacijaVo1Nedela(zoo);
                break;
            case 6:
                cout << "Izlez od programata.\n";
                break;
            default:
                cout << "Nevaliden izbor.\n";
        }

    } while (izbor != 6);

    for (auto z : zoo) {
        delete z;
    }

    return 0;
}
