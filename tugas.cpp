#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RekeningBank {
protected:
    double saldo;

public:
    RekeningBank(double s) {
        saldo = s;
    }
    virtual void potongAdmin() = 0;

    void tampilkanSaldo() {
        cout << "Saldo akhir: Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {} // Mencegah memory leak
};


class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        cout << "Rekening Syariah -> Bebas biaya admin." << endl;
    }
};


class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Rekening Konvensional -> Potongan admin Rp 15.000" << endl;
    }
};


class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Rekening Premium -> Saldo di atas Rp 10JT, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Rekening Premium -> Saldo <= Rp 10JT, potongan admin Rp 50.000" << endl;
        }
    }
};

int main() {
    cout << "=== OTOMATISASI AKHIR BULAN BANK GIBRAN JAYA ===" << endl << endl;

    vector<RekeningBank*> daftarRekening;

    daftarRekening.push_back(new RekeningSyariah(5000000));
    daftarRekening.push_back(new RekeningKonvensional(5000000));
    
    daftarRekening.push_back(new RekeningPremium(15000000)); 
    daftarRekening.push_back(new RekeningPremium(8000000)); 

    cout << "--- Memproses Pemotongan Biaya Admin ---" << endl;
    for (RekeningBank* akun : daftarRekening) {
        akun->potongAdmin();
        akun->tampilkanSaldo();
        cout << endl;
    }

    for (RekeningBank* akun : daftarRekening) {
        delete akun;
    }
    daftarRekening.clear();

    return 0;
}