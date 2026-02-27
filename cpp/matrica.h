#ifndef MATRICA_H
#define MATRICA_H

#include <iosfwd>   // ostream, istream
#include <cassert>

class Matrica {
    friend std::ostream& operator<<(std::ostream&, const Matrica&);
    friend std::istream& operator>>(std::istream&, Matrica&);

public:
    Matrica(int r = 1, int c = 1);
    Matrica(const Matrica& other);
    ~Matrica();

    Matrica& operator=(const Matrica& right);

    bool operator==(const Matrica& right) const;
    bool operator!=(const Matrica& right) const { return !(*this == right); }

    // za matrix[i][j]
    int* operator[](int i);
    const int* operator[](int i) const;

    Matrica operator+(const Matrica& right) const;
    Matrica operator-(const Matrica& right) const;
    Matrica operator*(const Matrica& right) const; // matrix × matrix

    Matrica operator*(int k) const;       // matrix × scalar
    friend Matrica operator*(int k, const Matrica& m) { return m * k; }

    int rows() const { return r; }
    int cols() const { return c; }

private:
    int r, c;
    int* data; // r*c, row-major

    int index(int i, int j) const { return i * c + j; }
};

#endif
