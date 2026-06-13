#include <iostream>
#define max 5
using namespace std;

struct Tumpukan {
    int atas;
    int data[max];
} Tumpuk;

void inisialisasi() {
    Tumpuk.atas = -1;
}

int kosong() {
    if (Tumpuk.atas == -1) return 1;
    else return 0;
}

int penuh() {
    if (Tumpuk.atas == max - 1) return 1;
    else return 0;
}

void input(int data) {
    if (kosong() == 1) { 
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack" << endl;
    } else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack" << endl;
    } else {
        cout << "Tumpukan Penuh" << endl; 
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil: " << Tumpuk.data[Tumpuk.atas] << endl;
        Tumpuk.atas--;
    } else {
        cout << "Data Kosong" << endl;
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) { 
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
        cout << endl;
    } else {
        cout << "Tumpukan Kosong" << endl;
    }
}

int main() {
    inisialisasi();
    input(10);
    tampil();
    input(20);
    tampil();
    hapus();
    tampil();
    hapus();
    tampil();
    return 0;
}
