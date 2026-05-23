#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if (head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if (tail == NULL) return 1;
    return 0;
}

// Menghitung panjang list (untuk kebutuhan hapus ke-N)
int panjangH(){
    int count = 0;
    TNode *bantu = head;
    while (bantu != NULL){
        count++;
        bantu = bantu->next;
    }
    return count;
}

// TUGAS 1 - MODIFIKASI FUNGSI TAMBAH (multi-data per baris)
void tambahDepanH(){
    cout << "Masukkan data (pisahkan dengan spasi): ";
    cin.ignore();
    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    vector<string> dataList;
    while (ss >> token) dataList.push_back(token);

    if (dataList.empty()){
        cout << "Tidak ada data yang dimasukkan.";
        return;
    }

    // Insert dari belakang vector agar urutan input tetap di depan
    for (int i = (int)dataList.size() - 1; i >= 0; i--){
        TNode *baru = new TNode;
        baru->data = dataList[i];
        baru->next = NULL;
        baru->prev = NULL;
        if (isEmptyH() == 1){
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian depan.";
}

// Tambah Depan Head+Tail
void tambahDepanHT(){
    cout << "Masukkan data (pisahkan dengan spasi): ";
    cin.ignore();
    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    vector<string> dataList;
    while (ss >> token) dataList.push_back(token);

    if (dataList.empty()){
        cout << "Tidak ada data yang dimasukkan.";
        return;
    }

    for (int i = (int)dataList.size() - 1; i >= 0; i--){
        TNode *baru = new TNode;
        baru->data = dataList[i];
        baru->next = NULL;
        baru->prev = NULL;
        if (isEmptyHT() == 1){
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian depan.";
}

// Tambah Belakang Head
void tambahBelakangH(){
    cout << "Masukkan data (pisahkan dengan spasi): ";
    cin.ignore();
    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    vector<string> dataList;
    while (ss >> token) dataList.push_back(token);

    if (dataList.empty()){
        cout << "Tidak ada data yang dimasukkan.";
        return;
    }

    for (int i = 0; i < (int)dataList.size(); i++){
        TNode *baru = new TNode;
        baru->data = dataList[i];
        baru->next = NULL;
        baru->prev = NULL;
        if (isEmptyH() == 1){
            head = baru;
        } else {
            TNode *bantu = head;
            while (bantu->next != NULL) bantu = bantu->next;
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian belakang.";
}

// Tambah Belakang Head+Tail
void tambahBelakangHT(){
    cout << "Masukkan data (pisahkan dengan spasi): ";
    cin.ignore();
    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    vector<string> dataList;
    while (ss >> token) dataList.push_back(token);

    if (dataList.empty()){
        cout << "Tidak ada data yang dimasukkan.";
        return;
    }

    for (int i = 0; i < (int)dataList.size(); i++){
        TNode *baru = new TNode;
        baru->data = dataList[i];
        baru->next = NULL;
        baru->prev = NULL;
        if (isEmptyHT() == 1){
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian belakang.";
}

void tampilkanH(){
    TNode *bantu = head;
    if (isEmptyH() == 0){
        while (bantu != NULL){
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void tampilkanHT(){
    TNode *bantu = head;
    if (isEmptyHT() == 0){
        while (bantu != NULL){
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusDepanH(){
    TNode *hapus;
    string data;
    if (isEmptyH() == 0){
        hapus = head;
        data = hapus->data;
        if (head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
    } else cout << "Tidak terdapat data pada linked list";
}

void hapusDepanHT(){
    TNode *hapus;
    string data;
    if (isEmptyHT() == 0){
        hapus = head;
        data = hapus->data;
        if (head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
    } else cout << "Tidak terdapat data pada Linked List";
}

// TUGAS 4 - HAPUS BELAKANG KE-N DENGAN SISTEM MUNDUR
void hapusBelakangH(){
    if (isEmptyH() == 1){
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    int n;
    cout << "Hapus node ke-N dari belakang, masukkan N: ";
    cin >> n;

    int panjang = panjangH();

    // Sistem mundur jika N terlalu besar
    if (n > panjang){
        int nAsli = n;
        n = ((n - 1) % panjang) + 1;
        cout << "N=" << nAsli << " melebihi jumlah node (" << panjang
             << "), diubah menjadi N=" << n << " (sistem mundur)." << endl;
    }

    // Cari node ke-N dari belakang
    // Node ke-1 dari belakang = tail (atau node paling belakang)
    TNode *hapus = head;
    // Maju sebanyak (panjang - n) langkah dari head
    int langkah = panjang - n;
    for (int i = 0; i < langkah; i++) hapus = hapus->next;

    string data = hapus->data;

    if (hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;   // hapus adalah head

    if (hapus->next != NULL) hapus->next->prev = hapus->prev;

    delete hapus;
    cout << "Data \"" << data << "\" (node ke-" << n << " dari belakang) berhasil dihapus.";
}

void hapusBelakangHT(){
    if (isEmptyHT() == 1){
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    int n;
    cout << "Hapus node ke-N dari belakang, masukkan N: ";
    cin >> n;

    int panjang = panjangH();

    if (n > panjang){
        int nAsli = n;
        n = ((n - 1) % panjang) + 1;
        cout << "N=" << nAsli << " melebihi jumlah node (" << panjang
             << "), diubah menjadi N=" << n << " (sistem mundur)." << endl;
    }

    TNode *hapus = head;
    int langkah = panjang - n;
    for (int i = 0; i < langkah; i++) hapus = hapus->next;

    string data = hapus->data;

    if (hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;

    if (hapus->next != NULL) hapus->next->prev = hapus->prev;
    else tail = hapus->prev;   // hapus adalah tail

    delete hapus;
    cout << "Data \"" << data << "\" (node ke-" << n << " dari belakang) berhasil dihapus.";
}

// TUGAS 2 - HAPUS BERDASARKAN TARGET
void hapusTargetH(){
    if (isEmptyH() == 1){
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;

    TNode *bantu = head;
    int count = 0;

    while (bantu != NULL){
        TNode *next = bantu->next;
        if (bantu->data == target){
            // Putuskan sambungan
            if (bantu->prev != NULL) bantu->prev->next = bantu->next;
            else head = bantu->next;

            if (bantu->next != NULL) bantu->next->prev = bantu->prev;

            delete bantu;
            count++;
        }
        bantu = next;
    }

    if (count > 0)
        cout << "Sebanyak " << count << " node dengan data \"" << target << "\" berhasil dihapus.";
    else
        cout << "Data \"" << target << "\" tidak ditemukan dalam Linked List.";
}

void hapusTargetHT(){
    if (isEmptyHT() == 1){
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;

    TNode *bantu = head;
    int count = 0;

    while (bantu != NULL){
        TNode *next = bantu->next;
        if (bantu->data == target){
            if (bantu->prev != NULL) bantu->prev->next = bantu->next;
            else head = bantu->next;

            if (bantu->next != NULL) bantu->next->prev = bantu->prev;
            else tail = bantu->prev;

            delete bantu;
            count++;
        }
        bantu = next;
    }

    if (count > 0)
        cout << "Sebanyak " << count << " node dengan data \"" << target << "\" berhasil dihapus.";
    else
        cout << "Data \"" << target << "\" tidak ditemukan dalam Linked List.";
}

// TUGAS 3 - CLEAR BERGANTIAN DEPAN & BELAKANG
void clearH(){
    if (isEmptyH() == 1){
        cout << "Linked List sudah kosong.";
        return;
    }
    int urutan = 1;
    bool giliranDepan = true;   // mulai dari depan

    while (head != NULL){
        TNode *hapus;
        string data;

        if (giliranDepan){
            // Hapus dari depan
            hapus = head;
            data = hapus->data;
            if (head->next != NULL){
                head = head->next;
                head->prev = NULL;
            } else {
                head = NULL;
            }
        } else {
            // Hapus dari belakang: cari node terakhir
            hapus = head;
            while (hapus->next != NULL) hapus = hapus->next;
            data = hapus->data;
            if (hapus->prev != NULL){
                hapus->prev->next = NULL;
            } else {
                head = NULL;
            }
        }

        cout << "Penghapusan ke-" << urutan << ": \"" << data << "\"" << endl;
        delete hapus;
        urutan++;
        giliranDepan = !giliranDepan;
    }
    cout << "Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT(){
    if (isEmptyHT() == 1){
        cout << "Linked List sudah kosong.";
        return;
    }
    int urutan = 1;
    bool giliranDepan = true;

    while (head != NULL){
        TNode *hapus;
        string data;

        if (giliranDepan){
            hapus = head;
            data = hapus->data;
            if (head->next != NULL){
                head = head->next;
                head->prev = NULL;
            } else {
                head = NULL;
                tail = NULL;
            }
        } else {
            hapus = tail;
            data = hapus->data;
            if (tail->prev != NULL){
                tail = tail->prev;
                tail->next = NULL;
            } else {
                head = NULL;
                tail = NULL;
            }
        }

        cout << "Penghapusan ke-" << urutan << ": \"" << data << "\"" << endl;
        delete hapus;
        urutan++;
        giliranDepan = !giliranDepan;
    }
    cout << "Seluruh data pada Linked List telah dibersihkan.";
}

int main()
{
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "========================================" << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if (menu == 1){
        initH();
        do {
            cout << "Double Linked List Non Circular (DLLNC) [Head]" << endl;
            cout << "===============================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang (ke-N)" << endl;
            cout << "6. Hapus Target" << endl;
            cout << "7. Reset (Clear Bergantian)" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil){
            case 1: tambahDepanH();    break;
            case 2: tambahBelakangH(); break;
            case 3: tampilkanH();      break;
            case 4: hapusDepanH();     break;
            case 5: hapusBelakangH();  break;
            case 6: hapusTargetH();    break;
            case 7: clearH();          break;
            default:
                system("cls");
                goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 8);

    } else if (menu == 2){
        initHT();
        do {
            cout << "Double Linked List Non Circular (DLLNC) [Head & Tail]" << endl;
            cout << "======================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang (ke-N)" << endl;
            cout << "6. Hapus Target" << endl;
            cout << "7. Reset (Clear Bergantian)" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil){
            case 1: tambahDepanHT();    break;
            case 2: tambahBelakangHT(); break;
            case 3: tampilkanHT();      break;
            case 4: hapusDepanHT();     break;
            case 5: hapusBelakangHT();  break;
            case 6: hapusTargetHT();    break;
            case 7: clearHT();          break;
            default:
                system("cls");
                goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 8);

    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Muhammad Zaini Hafidz (NIM.2510817110003)." << endl;
    }
    return 0;
}