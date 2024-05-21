#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengecek apakah suatu karakter adalah huruf vokal
bool Vokal_133(char huruf_133) {
    huruf_133 = tolower(huruf_133); // Mengubah huruf menjadi huruf kecil untuk memudahkan pengecekan
    return huruf_133 == 'a' || huruf_133 == 'e' || huruf_133 == 'i' || huruf_133 == 'o' || huruf_133 == 'u';
}

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int banyakVokal_133(const string& kalimat_133) {
    int count = 0;
    for (char ch : kalimat_133) { 
        if (Vokal_133(ch)) {  
            count++;  
        }
    }
    return count; 
}

int main() {
    string data_133;

    cout << "Masukkan sebuah kalimat: "; // Masukkan Input kalimat yang ingin dihitung jumlah huruf vokalnya
    getline(cin, data_133); // Menerima input kalimat dari pengguna

    int JumlahVokal_133 = banyakVokal_133(data_133); // Menghitung jumlah huruf vokal dalam kalimat
    cout << "Jumlah huruf vokal yang ada dalam kalimat: " << JumlahVokal_133 << endl; // Menampilkan hasil jumlah huruf vokal dari kalimat yang dimasukkan

    return 0;
}
