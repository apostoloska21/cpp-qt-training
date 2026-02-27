#include "Matrica.h"
#include <iostream>
#include <iomanip>

Matrica::Matrica(int rr, int cc) {
    r = (rr > 0 ? rr : 1);
    c = (cc > 0 ? cc : 1);
    data = new int[r * c];
    assert(data != nullptr);
    for (int i = 0; i < r * c; i++) data[i] = 0;
}

Matrica::Matrica(const Matrica &other) : r(other.r), c(other.c) {
    data = new int[r * c];
    assert(data != nullptr);
    for (int i = 0; i < r * c; i++) data[i] = other.data[i];
}

Matrica::~Matrica() {
    delete[] data;
}

Matrica &Matrica::operator=(const Matrica &right) {
    if (&right != this) {
        // self-assignment check (isto kako Array)
        if (r * c != right.r * right.c) {
            delete[] data;
            data = new int[right.r * right.c];
            assert(data != nullptr);
        }
        r = right.r;
        c = right.c;
        for (int i = 0; i < r * c; i++) data[i] = right.data[i];
    }
    return *this;
}

bool Matrica::operator==(const Matrica &right) const {
    if (r != right.r || c != right.c) return false;
    for (int i = 0; i < r * c; i++)
        if (data[i] != right.data[i]) return false;
    return true;
}

int *Matrica::operator[](int i) {
    assert(0 <= i && i < r);
    return &data[i * c];
}

const int *Matrica::operator[](int i) const {
    assert(0 <= i && i < r);
    return &data[i * c];
}

Matrica Matrica::operator+(const Matrica &right) const {
    assert(r == right.r && c == right.c);
    Matrica res(r, c);
    for (int i = 0; i < r * c; i++) res.data[i] = data[i] + right.data[i];
    return res;
}

Matrica Matrica::operator-(const Matrica &right) const {
    assert(r == right.r && c == right.c);
    Matrica res(r, c);
    for (int i = 0; i < r * c; i++) res.data[i] = data[i] - right.data[i];
    return res;
}

Matrica Matrica::operator*(int k) const {
    Matrica res(r, c);
    for (int i = 0; i < r * c; i++) res.data[i] = data[i] * k;
    return res;
}

Matrica Matrica::operator*(const Matrica &right) const {
    assert(c == right.r);
    Matrica res(r, right.c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < right.c; j++) {
            int sum = 0;
            for (int k = 0; k < c; k++) {
                sum += (*this)[i][k] * right[k][j];
            }
            res[i][j] = sum;
        }
    }
    return res;
}

std::istream &operator>>(std::istream &in, Matrica &m) {
    for (int i = 0; i < m.r; i++)
        for (int j = 0; j < m.c; j++)
            in >> m[i][j];
    return in;
}

std::ostream &operator<<(std::ostream &out, const Matrica &m) {
    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            out << std::setw(6) << m[i][j];
        }
        out << '\n';
    }
    return out;
}


int main() {
    Matrica A(2, 3), B(3, 2);

    std::cout << "Vnesi A (2x3):\n";
    std::cin >> A;
    std::cout << "Vnesi B (3x2):\n";
    std::cin >> B;

    std::cout << "\nA:\n" << A;
    std::cout << "\nB:\n" << B;

    Matrica C = A * B;
    std::cout << "\nA*B:\n" << C;

    std::cout << "\n2*A:\n" << (2 * A);
    return 0;
}
