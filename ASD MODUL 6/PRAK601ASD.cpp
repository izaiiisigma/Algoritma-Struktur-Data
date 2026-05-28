#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

int randomNum(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void sequentialSearching()
{
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++)
    {
        data[i] = randomNum(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1)
    {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d", save);
    }
    else
    {
        printf("Data tidak ada!\n");
    }
}

void binarySearching()
{
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n--------------------------------------------------------------------------------\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true)
    {
        cout << "Angka ditemukan! ";
    }
    else
        cout << "Angka tidak ditemukan!";
}

void jelaskanPerbedaan()
{
    clrscr();
    cout << "========================================\n";
    cout << "  PERBEDAAN SEQUENTIAL DAN BINARY SEARCHING\n";
    cout << "========================================\n\n";

    cout << "1. SEQUENTIAL SEARCHING\n";
    cout << "   Cara Kerja:\n";
    cout << "   - Mencari data dengan memeriksa setiap elemen satu per satu\n";
    cout << "     dari awal hingga akhir array secara berurutan.\n\n";
    cout << "   Kelebihan:\n";
    cout << "   - Sederhana dan mudah diimplementasikan.\n";
    cout << "   - Dapat digunakan pada data yang TIDAK terurut.\n";
    cout << "   - Cocok untuk data dalam jumlah kecil.\n\n";
    cout << "   Kekurangan:\n";
    cout << "   - Tidak efisien untuk data dalam jumlah besar.\n";
    cout << "   - Kompleksitas waktu O(n), semakin banyak data\n";
    cout << "     semakin lambat proses pencariannya.\n\n";

    cout << "----------------------------------------\n\n";

    cout << "2. BINARY SEARCHING\n";
    cout << "   Cara Kerja:\n";
    cout << "   - Mencari data dengan membagi array menjadi dua bagian,\n";
    cout << "     lalu membandingkan nilai tengah dengan data yang dicari.\n";
    cout << "   - Jika data lebih kecil, cari di bagian kiri; jika lebih\n";
    cout << "     besar, cari di bagian kanan. Ulangi hingga ditemukan.\n\n";
    cout << "   Kelebihan:\n";
    cout << "   - Sangat efisien untuk data dalam jumlah besar.\n";
    cout << "   - Kompleksitas waktu O(log n), jauh lebih cepat\n";
    cout << "     dibandingkan Sequential Searching.\n\n";
    cout << "   Kekurangan:\n";
    cout << "   - Data HARUS dalam keadaan terurut terlebih dahulu.\n";
    cout << "   - Lebih kompleks dalam implementasinya.\n";
    cout << "   - Membutuhkan langkah pengurutan sebelum pencarian.\n\n";

    cout << "========================================\n";
}

int main()
{
    int pilih;

    do
    {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            sequentialSearching();
            cout << "\n\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            break;
        case 2:
            binarySearching();
            cout << "\n\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            break;
        case 3:
            jelaskanPerbedaan();
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilih != 4);

    return 0;
}