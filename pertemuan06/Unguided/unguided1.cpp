#include <iostream>

using namespace std;

// Fungsi untuk menentukan apakah kata adalah palindrom atau tidak
bool checkPalindrom_133(string kata_133) {
    int length_133 = kata_133.length(); // Menghitung panjang kata
    // Looping untuk membandingkan setiap karakter dari awal dan akhir
    for(int i = 0; i < length_133 / 2; i++) {
        // Membandingkan karakter pada posisi i dengan karakter pada posisi (length_133 - i - 1)
        if(tolower(kata_133[i]) != tolower(kata_133[length_133 - i - 1])) {
            return false; // Jika tidak sama, kata bukan palindrom
        }
    }
    return true; // Jika semua karakter cocok, kata adalah palindrom
}

int main() {
    string inputKata_133;
    cout << "==== CEK KATA PALINDROM ====" << endl;
    cout << "Masukkan Kata: ";
    cin >> inputKata_133; // Menerima input kata dari pengguna

    // Memanggil fungsi untuk memeriksa apakah kata adalah palindrom atau tidak
    if(checkPalindrom_133(inputKata_133)) {
        cout << "Kata tersebut adalah Palindrom" << endl;
    } else {
        cout << "Kata tersebut bukan Palindrom" << endl;
    }
    return 0;
}
