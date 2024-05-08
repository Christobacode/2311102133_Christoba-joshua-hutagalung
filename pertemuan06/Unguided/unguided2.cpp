#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
void balikKalimat_133(string kalimat_133) {
    stack<char> tumpukan_133;

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char c_133 : kalimat_133) {
        tumpukan_133.push(c_133);
    }

    string kalimatDibalik_133;
    // Mengambil karakter dari stack dan menyimpannya dalam kalimat yang dibalik
    while (!tumpukan_133.empty()) {
        kalimatDibalik_133 += tumpukan_133.top();
        tumpukan_133.pop();
    }

    // Menampilkan kalimat yang sudah dibalik
    cout << "Kalimat terbalik: " << kalimatDibalik_133 << endl;
}

int main() {
    string kalimat_133;

    // Meminta pengguna memasukkan sebuah kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_133);

    int jumlahKata_133 = 1;
    // Menghitung jumlah kata dalam kalimat
    for (char c_133 : kalimat_133) {
        if (c_133 == ' ') {
            jumlahKata_133++;
        }
    }

    // Memeriksa apakah jumlah kata kurang dari 3
    if (jumlahKata_133 < 3) {
        cout << "Kalimat harus terdiri minimal 3 kata" << endl;
    } else {
        // Memanggil fungsi untuk membalikkan kalimat dan menampilkan hasil kalimat yang sudah dibalik
        balikKalimat_133(kalimat_133);
    }

    return 0;
}
