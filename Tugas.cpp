#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class RekeningBank {

protected:

string namaNasabah;

string nomorRekening;

double saldo;

public:

RekeningBank(string nama, string noRek, double saldoAwal)

: namaNasabah(nama), nomorRekening(noRek), saldo(saldoAwal) {}

virtual void potongAdmin() = 0; // pure virtual

virtual ~RekeningBank() {}

string getNama() const { return namaNasabah; }
string getNomorRekening() const { return nomorRekening; }

double getSaldo() const { return saldo; }
virtual void tampilInfo() const {

cout << " Nasabah : " << namaNasabah << endl;

cout << " No. Rek : " << nomorRekening << endl;

cout << " Saldo : Rp " << saldo << endl;

}
};


class RekeningSyariah : public RekeningBank {

public:

RekeningSyariah(string nama, string noRek, double saldoAwal)

: RekeningBank(nama, noRek, saldoAwal) {}



void potongAdmin() override {

cout << " [Syariah] Tidak ada potongan admin (prinsip syariah)." << endl;

}

void tampilInfo() const override {

cout << " Jenis : Rekening Syariah" << endl;

RekeningBank::tampilInfo();

}
};

class RekeningKonvensional : public RekeningBank {

private:

static const double BIAYA_ADMIN;



public:

RekeningKonvensional(string nama, string noRek, double saldoAwal)

: RekeningBank(nama, noRek, saldoAwal) {}

void potongAdmin() override {

if (saldo >= BIAYA_ADMIN) {

saldo -= BIAYA_ADMIN;

cout << " [Konvensional] Biaya admin Rp " << BIAYA_ADMIN

<< " berhasil dipotong." << endl;

} else {

cout << " [Konvensional] Saldo tidak cukup untuk biaya admin!" << endl;

}

}

void tampilInfo() const override {

cout << " Jenis : Rekening Konvensional" << endl;

RekeningBank::tampilInfo();

}

};

const double RekeningKonvensional::BIAYA_ADMIN = 15000.0;