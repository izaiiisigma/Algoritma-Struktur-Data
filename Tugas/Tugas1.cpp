#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();
void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int hitungNode() {
    if (isEmpty()) return 0;
    int count = 1;
    TNode *bantu = head;
    while (bantu->next != head) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

int main() {
    init();
    do {
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "====================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch (pil) {
            case 1: tambahDepan(); break;
            case 2: tambahBelakang(); break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5: tampilkan(); break;
            case 6: reset(); break;
            case 7: cariData(); break;
            case 8: hapusData(); break;
            case 9: sisipkanSebelum(); break;
            case 10: sisipkanSetelah(); break;
            default:
                cout << "\nTERIMA KASIH" << endl;
        }

        if (pil < 11) {
            cout << "\nPress Enter to continue!" << endl;
            cin.ignore();
            cin.get();
        }

    } while (pil < 11);
    return 0;
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (head == NULL) return 1;
    else return 0;
}

// 1. MODIFIKASI tambahDepan()
//    - Menerima beberapa data dalam satu baris, dipisah spasi
//    - Urutan linked list SAMA dengan urutan input
void tambahDepan() {
    cin.ignore();
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    string baris;
    getline(cin, baris);

    // Pecah baris menjadi token per spasi
    stringstream ss(baris);
    string token;
    // Tampung semua token dulu agar bisa dimasukkan terbalik
    // supaya urutan di linked list sama dengan urutan input
    string tokens[255];
    int jumlah = 0;
    while (ss >> token) {
        tokens[jumlah++] = token;
    }

    // Masukkan dari belakang ke depan agar urutan tetap sesuai input
    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = baru;

        if (isEmpty()) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }

    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    TNode *baru;
    baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if (isEmpty() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

// 3. MODIFIKASI hapusDepan()
//    - Menghapus node pada posisi ke-N dari depan
//    - Jika N > jumlah node, yang dihapus adalah tail
void hapusDepan() {
    if (isEmpty() == 0) {
        int n;
        cout << "Hapus node ke berapa dari depan? : ";
        cin >> n;

        int total = hitungNode();

        // Jika N lebih besar dari jumlah node, hapus tail
        if (n > total) {
            cout << "N melebihi jumlah node, node tail yang akan dihapus." << endl;
            dataHapus = tail->data;
            if (head == tail) {
                delete tail;
                init();
            } else {
                TNode *newTail = head;
                while (newTail->next != tail) newTail = newTail->next;
                delete tail;
                tail = newTail;
                tail->next = head;
            }
            cout << "Data \"" << dataHapus << "\" (tail) berhasil dihapus." << endl;
            return;
        }

        // Hapus node ke-N dari depan
        if (n == 1) {
            // Hapus head
            dataHapus = head->data;
            if (head == tail) {
                delete head;
                init();
            } else {
                TNode *hapus = head;
                head = head->next;
                tail->next = head;
                delete hapus;
            }
        } else {
            // Traversal sampai node ke-(N-1)
            TNode *sebelum = head;
            for (int i = 1; i < n - 1; i++) sebelum = sebelum->next;
            TNode *hapus = sebelum->next;
            dataHapus = hapus->data;

            if (hapus == tail) {
                tail = sebelum;
                tail->next = head;
            } else {
                sebelum->next = hapus->next;
            }
            delete hapus;
        }

        cout << "Data \"" << dataHapus << "\" pada posisi ke-" << n << " dari depan berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

// 2. MODIFIKASI hapusBelakang()
//    - Menghapus node ke-N dari belakang
//    - Jika N > jumlah node, yang dihapus adalah head
void hapusBelakang() {
    if (isEmpty() == 0) {
        int n;
        cout << "Hapus node ke berapa dari belakang? : ";
        cin >> n;

        int total = hitungNode();

        // Jika N lebih besar dari jumlah node, hapus head
        if (n > total) {
            cout << "N melebihi jumlah node, node head yang akan dihapus." << endl;
            dataHapus = head->data;
            if (head == tail) {
                delete head;
                init();
            } else {
                TNode *hapus = head;
                head = head->next;
                tail->next = head;
                delete hapus;
            }
            cout << "Data \"" << dataHapus << "\" (head) berhasil dihapus." << endl;
            return;
        }

        // Posisi dari depan = total - n + 1
        int posisiDepan = total - n + 1;

        if (posisiDepan == 1) {
            // Hapus head
            dataHapus = head->data;
            if (head == tail) {
                delete head;
                init();
            } else {
                TNode *hapus = head;
                head = head->next;
                tail->next = head;
                delete hapus;
            }
        } else {
            // Traversal ke node sebelum target
            TNode *sebelum = head;
            for (int i = 1; i < posisiDepan - 1; i++) sebelum = sebelum->next;
            TNode *hapus = sebelum->next;
            dataHapus = hapus->data;

            if (hapus == tail) {
                tail = sebelum;
                tail->next = head;
            } else {
                sebelum->next = hapus->next;
            }
            delete hapus;
        }

        cout << "Data \"" << dataHapus << "\" pada posisi ke-" << n << " dari belakang berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void tampilkan() {
    if (isEmpty() == 0) {
        TNode *bantu;
        bantu = head;
        do {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

// 4. MODIFIKASI reset()
//    - Node dihapus satu per satu
//    - Setiap penghapusan menampilkan node ke berapa dan isinya
void reset() {
    if (isEmpty() == 0) {
        int nodeKe = 1;
        while (!isEmpty()) {
            TNode *hapus = head;
            cout << "Menghapus node ke-" << nodeKe << " : \"" << hapus->data << "\"" << endl;

            if (head == tail) {
                delete hapus;
                init();
            } else {
                head = head->next;
                tail->next = head;
                delete hapus;
            }
            nodeKe++;
        }
        cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void cariData() {
    if (isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dicari : ";
        cin >> cari;

        TNode *bantu, *bantuTampilkan;
        bool apaDitemukan = false;
        bantu = head;

        do {
            if (cari == bantu->data) {
                cout << "Setiap data yang berada di dalam tanda kurung siku ([...]) "
                     << "merupakan data yang anda cari." << endl;
                cout << "Linked List : ";
                bantuTampilkan = head;
                do {
                    if (cari == bantuTampilkan->data) cout << "[" << bantuTampilkan->data << "] ";
                    else cout << bantuTampilkan->data << ' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while (bantuTampilkan != head);
                apaDitemukan = true;
                cout << endl;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (!apaDitemukan)
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusData() {
    if (isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;
        bantu = head;

        do {
            bantu2 = bantu;
            if (cari == bantu->data) {
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if (bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while (bantu != head);

        if (apaDitemukan) {
            for (int i = 0; i < hitung; i++) {
                if (hapus[i] == head) { hapusDepan(); }
                else if (hapus[i] == tail) { hapusBelakang(); }
                else { delete hapus[i]; }
            }
            cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List telah dihapus." << endl;
        } else cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSebelum() {
    if (isEmpty() == 0) {
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda = false;
        bantu = head;
        sebelum = tail;

        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

        do {
            if (nextData == bantu->data) { apaAda = true; break; }
            else { sebelum = bantu; bantu = bantu->next; }
        } while (bantu != head);

        if (apaAda) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;
            if (bantu == head) head = baru;
            cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \"" << nextData << "\"." << endl;
        } else cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSetelah() {
    if (isEmpty() == 0) {
        TNode *bantu;
        string prevData;
        bool apaAda = false;
        bantu = head;

        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

        do {
            if (prevData == bantu->data) { apaAda = true; break; }
            else bantu = bantu->next;
        } while (bantu != head);

        if (apaAda) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;
            if (bantu == tail) tail = baru;
            cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \"" << prevData << "\"." << endl;
        } else cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}