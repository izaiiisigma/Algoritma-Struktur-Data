#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string platNomor;
    string jenis;
    string namaPemilik;
    string alamat;
    string kota;
};

int main() {
    Kendaraan mobil;
    
    // Mengisi data sesuai soal
    mobil.platNomor = "DA1234MK";
    mobil.jenis = "RUSH";
    mobil.namaPemilik = "Andika Hartanto";
    mobil.alamat = "Jl. Kayu Tangi 1";
    mobil.kota = "Banjarmasin";

    // Output
    cout << "a. Plat Nomor Kendaraan : " << mobil.platNomor << endl;
    cout << "b. Jenis Kendaraan      : " << mobil.jenis << endl;
    cout << "c. Nama Pemilik         : " << mobil.namaPemilik << endl;
    cout << "d. Alamat               : " << mobil.alamat << endl;
    cout << "e. Kota                 : " << mobil.kota << endl;

    return 0;
}