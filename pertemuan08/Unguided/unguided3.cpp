#include <iostream>

using namespace std;

int main() {
    // Deklarasi variabel
    int n_133 = 10; // Panjang array data
    int data_133[n_133] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Data yang akan dicari
    int target_133 = 4; // Angka yang dicari
    int count_133 = 0; // Variabel untuk menyimpan jumlah kemunculan angka 4

    // Melakukan pencarian sequential untuk menghitung banyaknya angka 4
    for (int i_133 = 0; i_133 < n_133; i_133++) {
        if (data_133[i_133] == target_133) {
            count_133++; // 
        }
    }

    // Menampilkan hasil pencarian 
    cout << "Data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Banyaknya angka " << target_133 << " dalam data adalah: " << count_133 << endl;

    return 0;
}
