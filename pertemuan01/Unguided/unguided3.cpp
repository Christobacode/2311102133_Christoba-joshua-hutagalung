/*
oleh Christoba Joshua Hutagalung - 2311102133
*/
// Unguided 3 program fungsi map
#include <iostream>
#include <map> // Library supaya bisa menggunakan fungsi map dibawah

using namespace std;

int main() {
    
    // Deklarasi map dengan key string dan value int
    map<string, int> nilaiMahasiswa_2133;
  
    // Menambahkan elemen-elemen ke dalam map
    nilaiMahasiswa_2133["Sabil_2133"] = 90;
    nilaiMahasiswa_2133["AgusLapar_2133"] = 87;
    nilaiMahasiswa_2133["ZakiKiyotaka_2133"] = 50;

    cout << "~~~ Daftar nilai mahasiswa ~~~" << endl;

    int i_2133 = 1; // Nomor urut mahasiswa dimulai dari 1
    for (const auto& pair_2133 : nilaiMahasiswa_2133) { // Loop untuk semua elemen map
        cout << "Mahasiswa" << i_2133++ << " " << pair_2133.first << " = " << pair_2133.second << endl;// Menampilkan elemen map yaitu nama mahasiswa dan nilainya
    }
    
    return 0;
}
