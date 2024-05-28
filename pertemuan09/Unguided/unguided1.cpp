#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi untuk menampilkan graf dalam format matriks
void TampilGraph_133(int JumlahSimpul_2311102133, string* NamaSimpul_2311102133, int** BobotSimpul_133) {
    // Menampilkan baris pertama berupa nama simpul (nama kota)
    cout << setw(10) << " ";
    for (int i = 0; i < JumlahSimpul_2311102133; i++) {
        cout << setw(10) << NamaSimpul_2311102133[i];
    }
    cout << endl;

    // Menampilkan bobot kota dalam format matriks
    for (int baris_133 = 0; baris_133 < JumlahSimpul_2311102133; baris_133++) {
        cout << setw(10) << NamaSimpul_2311102133[baris_133];
        for (int kolom_133 = 0; kolom_133 < JumlahSimpul_2311102133; kolom_133++) {
            cout << setw(10) << BobotSimpul_133[baris_133][kolom_133];
        }
        cout << endl;
    }
}

int main() {
    int JumlahSimpul_2311102133;
    int Nomor_133 = 1;
    int Bobot_133;

    cout << "--- PROGRAM GRAPH SEDERHANA ---" << endl;

    // Pengguna diminta untuk memasukkan jumlah simpul (jumlah kota)
    cout << "Masukkan jumlah simpul = ";
    cin >> JumlahSimpul_2311102133;

    // Membuat array dinamis NamaSimpul_2311102133 berdasarkan input jumlah simpul
    string* NamaSimpul_2311102133 = new string[JumlahSimpul_2311102133];

    // Pengguna diminta untuk memasukkan nama-nama simpul (nama kota)
    cout << "--- Masukkan nama simpul ---" << endl; 
    for (int i = 0; i < JumlahSimpul_2311102133; i++) {
        cout << "Masukkan nama simpul " << Nomor_133++ << " = ";
        cin >> NamaSimpul_2311102133[i];
    }
    cout << endl;

    // Membuat array dinamis BobotSimpul_133 berdasarkan input jumlah simpul
    int** BobotSimpul_133 = new int*[JumlahSimpul_2311102133];
    for (int i = 0; i < JumlahSimpul_2311102133; i++) {
        BobotSimpul_133[i] = new int[JumlahSimpul_2311102133]();
    }

    // Pengguna diminta untuk memasukkan bobot antar simpul (antar kota)
    cout << "--- Masukkan Bobot Antar Simpul ---" << endl;
    for (int i = 0; i < JumlahSimpul_2311102133; i++) {
        for (int j = 0; j < JumlahSimpul_2311102133; j++) {
            if (i != j) {
                cout << "Bobot " << NamaSimpul_2311102133[i] << " --> " << NamaSimpul_2311102133[j] << " = ";
                cin >> Bobot_133;
                BobotSimpul_133[i][j] = Bobot_133;
            }
        }
    }
    cout << endl;

    // Memanggil fungsi TampilGraph_133 untuk menampilkan graf
    TampilGraph_133(JumlahSimpul_2311102133, NamaSimpul_2311102133, BobotSimpul_133);

    return 0;
}
