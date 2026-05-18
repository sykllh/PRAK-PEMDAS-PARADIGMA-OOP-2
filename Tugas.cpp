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

};