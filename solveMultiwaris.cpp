#include <iostream>
using namespace std;

class orang {
public:
    int umur;

    orang(int pUmur) :
        umur(pUmur)
    {
        cout << "orang dibuat dengan umur " << umur << "th" << endl;
    }
};


class pekerja : public orang {
public:
    pekerja(int pUmur) :
        orang(pUmur)
    {
        cout << "pekerja dibuat" << endl;
    }
};


class pelajar : public orang {
public:
    pelajar(int pUmur) :
        orang(pUmur)
    {
        cout << "pelajar dibuat" << endl;
    }
};

class budi : public pekerja, public pelajar {
public:
    budi(int pUmur) :
        pekerja(pUmur),
        pelajar(pUmur)
    {
        cout << "Budi dibuat" << endl;
    }
};

int main() {
    budi A(12);
    return 0;
}
