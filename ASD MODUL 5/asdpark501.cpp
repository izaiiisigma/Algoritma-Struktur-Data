#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

// INSERTION SORT (NAMA)
void insertionSort(string arr) {
    int n = arr.length();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "\n[Insertion Sort] Hasil pengurutan Nama: " << arr << "\n\n";
}

// MERGE SORT (NAMA)
void merge(string &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    string L = arr.substr(l, n1);
    string R = arr.substr(m + 1, n2);
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(string &arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r); 
}

void doMergeSort(string arr) {
    int n = arr.length();
    if (n > 0) {
        mergeSort(arr, 0, n - 1);
    }
    cout << "\n[Merge Sort] Hasil pengurutan Nama: " << arr << "\n\n";
}

// SHELL SORT (NAMA)
void shellSort(string arr) {
    int n = arr.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    cout << "\n[Shell Sort] Hasil pengurutan Nama: " << arr << "\n\n";
}

// QUICK SORT (NIM)
int partition(string &arr, int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(string &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void doQuickSort(string arr) {
    int n = arr.length();
    if (n > 0) {
        quickSort(arr, 0, n - 1);
    }
    cout << "\n[Quick Sort] Hasil pengurutan NIM: " << arr << "\n\n";
}

// BUBBLE SORT (NIM)
void bubbleSort(string arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "\n[Bubble Sort] Hasil pengurutan NIM: " << arr << "\n\n";
}

// SELECTION SORT (NIM)
void selectionSort(string arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
    cout << "\n[Selection Sort] Hasil pengurutan NIM: " << arr << "\n\n";
}

int main() {
    int pilihan;
    string nama;
    string nim;
    
    do {

        cout << "-------------------------\n";
        cout << "|        SORTING        |\n";
        cout << "-------------------------\n";
        cout << " 1. Insertion Sort\n";
        cout << " 2. Merge Sort\n";
        cout << " 3. Shell Sort\n";
        cout << " 4. Quick Sort\n";
        cout << " 5. Bubble Sort\n";
        cout << " 6. Selection Sort\n";
        cout << " 7. Exit\n";
        cout << "-------------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                insertionSort(nama);
                break;
            case 2:
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                doMergeSort(nama);
                break;
            case 3:
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                shellSort(nama);
                break;
            case 4:
                cout << "Masukkan NIM: ";
                cin >> nim;
                doQuickSort(nim);
                break;
            case 5:
                cout << "Masukkan NIM: ";
                cin >> nim;
                bubbleSort(nim);
                break;
            case 6:
                cout << "Masukkan NIM: ";
                cin >> nim;
                selectionSort(nim);
                break;
            case 7:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n\n";
        }
    } while (pilihan != 7);
    
    return 0;
}