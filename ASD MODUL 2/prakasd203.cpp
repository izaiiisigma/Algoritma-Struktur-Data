#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10 // [cite: 258]
using namespace std;

int PIL, F, R;
char Q[n]; // [cite: 267]

void Inisialisasi() {
    F = -1;
    R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Queue Penuh!" << endl;
    } else {
        char HURUF;
        cout << "Masukkan Huruf: "; cin >> HURUF;
        if (F == -1) F = 0;
        R++;
        Q[R] = HURUF;
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Data " << Q[F] << " keluar dari antrian." << endl;
        F++;
        if (F > R) Inisialisasi(); // Reset jika semua sudah diambil
    }
}

void CETAKLAYAR() {
    if (F == -1) {
        cout << "Queue Kosong!" << endl;
    } else {
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    char PILIHAN[1];
    Inisialisasi();
    do {
        cout << "QUEUE" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN: "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1: INSERT(); break;
            case 2: DELETE(); break;
            case 3: CETAKLAYAR(); break;
        }
        if (PIL < 4) {
            cout << "press any key to continue" << endl;
            getch();
            system("cls");
        }
    } while (PIL < 4);
    cout << "TERIMA KASIH" << endl;
    return 0;
}