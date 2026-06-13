#include <iostream>
#include <string>
using namespace std;

int main() {
    char huruf;
    string kata;
    int angka;

    cout << "a. Masukkan sebuah huruf = "; cin >> huruf;
    cout << "b. Masukkan sebuah kata  = "; cin >> kata;
    cout << "c. Masukkan Angka        = "; cin >> angka;

    cout << "\nd. Huruf yang Anda masukkan adalah " << huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << angka << endl;

    return 0;
}