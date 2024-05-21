#include <iostream>

using namespace std;

// Fungsi untuk melakukan pengurutan karakter dalam array menggunakan Bubble Sort
void bubbleSort_133(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Jika karakter ke-j lebih besar dari karakter ke-(j+1)
                char temp_133 = arr[j]; // Tukar karakter ke-j dan ke-(j+1)
                arr[j] = arr[j + 1];
                arr[j + 1] = temp_133;
            }
        }
    }
}

// Fungsi untuk melakukan pencarian biner pada array karakter yang telah diurutkan
int binarySearch_133(const char arr[], int kiri_133, int kanan_133, char cariHuruf_133) {
    while (kiri_133 <= kanan_133) {
        int tengah_133 = kiri_133 + (kanan_133 - kiri_133) / 2;

        if (arr[tengah_133] == cariHuruf_133) // Jika karakter di tengah adalah karakter yang dicari
            return tengah_133; // Mengembalikan indeks karakter yang ditemukan
        if (arr[tengah_133] < cariHuruf_133) // Jika karakter di tengah kurang dari karakter yang dicari
            kiri_133 = tengah_133 + 1; // Pindahkan batas pencarian ke kanan
        else // Jika karakter di tengah lebih besar dari karakter yang dicari
            kanan_133 = tengah_133 - 1; // Pindahkan batas pencarian ke kiri
    }

    return -1; // Mengembalikan -1 jika karakter tidak ditemukan dalam array
}

int main() {
    char masukan_133[100];
    char cariHuruf_133;

    cout << "Masukkan kalimat: ";
    cin.getline(masukan_133, 100);

    cout << "Masukkan Huruf yang ingin dicari dalam kalimat: ";
    cin >> cariHuruf_133;

    int length_133 = 0;
    while (masukan_133[length_133] != '\0') {
        length_133++;
    }

    bubbleSort_133(masukan_133, length_133); // Memanggil fungsi untuk mengurutkan karakter dalam array

    cout << "Kalimat diurutkan (a-z): " << masukan_133 << endl;

    int result_133 = binarySearch_133(masukan_133, 0, length_133 - 1, cariHuruf_133); // Memanggil fungsi untuk mencari karakter
    if (result_133 != -1) {
        cout << "Huruf : " << cariHuruf_133 << " ditemukan pada indeks ke- " << result_133 << " Pada kalimat yang telah diurutkan" << endl;
    } else {
        cout << "Huruf " << cariHuruf_133 << " Tidak ditemukan dalam kalimat " << endl;
    }
    return 0;
}
