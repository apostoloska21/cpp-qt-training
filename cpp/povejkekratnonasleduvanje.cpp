#include <iostream>
#include <vector>
using namespace std;

class Oblik {
    protected:
    string ime;
public:
    static int brojacOblik;
    Oblik(string n="Nepoznat") : ime(n) {
        brojacOblik++;
    }
    virtual ~Oblik() {
        brojacOblik--;
    }
    virtual double povrsina() const =0;
    virtual double volumen() const { return 0;}
    virtual void pecati() const {
        cout<<"Oblik: "<<ime<<", Povrsina: "<<povrsina()<<endl;
    }
    static void pokaziBrojac() {
        cout<<"Oblik: "<<brojacOblik<<endl;
    }
};
int Oblik::brojacOblik=0;

class DvoDimenzionalni : public virtual Oblik {
    protected:
    static int brojac2D;
public:
    DvoDimenzionalni(string n) : Oblik(n) {
        brojac2D++;
    }
    virtual ~DvoDimenzionalni() {
        brojac2D--;
    }
    double volumen() const override {
        return 0;
    }
    static void pokaziBrojac() {
        cout<<"Brojac 2D: "<<brojac2D<<endl;
    }
};
int DvoDimenzionalni::brojac2D=0;

class TroDimenzionalni : public virtual Oblik {
    protected:
    static int brojac3D;
    public:
    TroDimenzionalni(string n): Oblik(n) {
        brojac3D++;
    }
    virtual ~TroDimenzionalni() {
        brojac3D--;
    }
    static void pokaziBrojac() {
        cout<<"Brojac 3D: "<<brojac3D<<endl;
    }
};
int TroDimenzionalni::brojac3D=0;

//  2D oblici

class Krug: public DvoDimenzionalni {
    double radius;
public:
    Krug(double r=1.0): DvoDimenzionalni("Krug"), radius(r) {}
        double povrsina() const override {
            return M_PI * radius * radius;
        }
    };
class Cetvrt:public DvoDimenzionalni {
    double strana;
public:
    Cetvrt(double s=1.0): DvoDimenzionalni("Cetvrt"), strana(s) {}
    double povrsina() const override {
        return strana*strana;
    }
};

class Trijagolnik:public DvoDimenzionalni {
    double a, b, c;
public:
    Trijagolnik(double x=1, double y=1, double z=1): DvoDimenzionalni("Trijagolnik"), a(x), b(y), c(z) {};
    double povrsina() const override {
        double s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};

//3D oblici
class Sfera : public TroDimenzionalni {
    double radius;
public:
    Sfera(double r = 1.0) : TroDimenzionalni("Sfera"), radius(r) {}
    double povrsina() const override { return 4 * M_PI * radius * radius; }
    double volumen() const override { return (4.0 / 3) * M_PI * radius * radius * radius; }
    void pecati() const override {
        cout << "Sfera: " << ime << ", Povrsina: " << povrsina() << ", Volumen: " << volumen() << endl;
    }
};

class Kub : public TroDimenzionalni {
    double strana;
public:
    Kub(double s = 1.0) : TroDimenzionalni("Kub"), strana(s) {}
    double povrsina() const override { return 6 * strana * strana; }
    double volumen() const override { return strana * strana * strana; }
};

class Cilinder : public TroDimenzionalni {
    double radius, visina;
public:
    Cilinder(double r = 1.0, double h = 1.0) : TroDimenzionalni("Cilinder"), radius(r), visina(h) {}
    double povrsina() const override { return 2 * M_PI * radius * (radius + visina); }
    double volumen() const override { return M_PI * radius * radius * visina; }
};
int main() {
    vector<Oblik*> oblici;
    int izbor;
    char prodolzi;

    do {
        cout << "\n=== meni za kreiranje na oblici ===" << endl;
        cout << "1. Krug (radius)" << endl;
        cout << "2. Cetvrt (strana)" << endl;
        cout << "3. Trijagolnik (a,b,c)" << endl;
        cout << "4. Sfera (radius)" << endl;
        cout << "5. Kub (strana)" << endl;
        cout << "6. Cilinder (radius, visina)" << endl;
        cout << "7. Pecati site oblici" << endl;
        cout << "8. Pecati brojaci" << endl;
        cout << "0. Izlez" << endl;
        cout << "Izbor: ";
        cin >> izbor;

        double p1, p2 = 0, p3 = 0;
        switch (izbor) {
            case 1:
                cout << "Radius: "; cin >> p1;
                oblici.push_back(new Krug(p1));
                break;
            case 2:
                cout << "Strana: "; cin >> p1;
                oblici.push_back(new Cetvrt(p1));
                break;
            case 3:
                cout << "a: "; cin >> p1;
                cout << "b: "; cin >> p2;
                cout << "c: "; cin >> p3;
                oblici.push_back(new Trijagolnik(p1, p2, p3));
                break;
            case 4:
                cout << "Radius: "; cin >> p1;
                oblici.push_back(new Sfera(p1));
                break;
            case 5:
                cout << "Strana: "; cin >> p1;
                oblici.push_back(new Kub(p1));
                break;
            case 6:
                cout << "Radius: "; cin >> p1;
                cout << "Visina: "; cin >> p2;
                oblici.push_back(new Cilinder(p1, p2));
                break;
            case 7:
                cout << "\n=== Сите објекти ===" << endl;
                for (auto o : oblici) {
                    o->pecati();
                }
                break;
            case 8:
                cout << "\n=== Бројачи ===" << endl;
                Oblik::pokaziBrojac();
                DvoDimenzionalni::pokaziBrojac();
                TroDimenzionalni::pokaziBrojac();
                break;
            case 0:
                break;
            default:
                cout << "Nevaliden izbor!" << endl;
        }

        if (izbor >= 1 && izbor <= 6) {
            cout << "Kreiran obekt! Prodolzi? (d/n): ";
            cin >> prodolzi;
        }
    } while (izbor != 0 && (izbor >=1 && izbor <=6 ? prodolzi == 'd' || prodolzi == 'D' : true));

    // osloboduvanje na memorija
    for (auto o : oblici) {
        delete o;
    }
    oblici.clear();

    cout << "Kraj na programata." << endl;
    return 0;
}

