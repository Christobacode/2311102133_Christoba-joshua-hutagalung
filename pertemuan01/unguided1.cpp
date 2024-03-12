/*
oleh Christoba Joshua Hutagalung - 2311102133
*/
// Unguided 1 program menggunakan tipe data primitif
#include <iostream>

using namespace std;
float phi_2133 = 3.14; // Menggunakan nama variabel dengan akhiran _2133
int FungsiPenjumlahan_2133(int b1_2133, int b2_2133) { // Fungsi buat hitung tambah
    return b1_2133 + b2_2133;
}

int FungsiPengurangan_2133(int b3_2133, int b4_2133) {  // Fungsi buat hitung pengurangan
    return b3_2133 - b4_2133;
}

int FungsiLuasSegitiga_2133(int alas_2133, int tinggi_2133) { // Fungsi buat hitung luas segitiga
    return 0.5 * alas_2133 * tinggi_2133;
}

int main()
{
    int Pilih_2133, b1_2133, b2_2133, b3_2133, b4_2133, alas_2133, tinggi_2133;//Deklarasi variabel
    ulang_2133:
    cout << "~~~~~~Menu Perhitungan~~~~~~" << endl;//output menu awal menu perhitungan
    cout << "1.Penjumlahan" << endl;
    cout << "2.Pengurangan" << endl;
    cout << "3.Hitung luas segitiga" << endl;
    cout << "4.Keluar" << endl;
    cout << "Masukkan Pilihan : ";
    cin >> Pilih_2133;

    switch(Pilih_2133) {
    case 1 :
    //Operator pertambahan
        cout << "Masukkan bilangan pertama : ";
        cin >> b1_2133;
        cout << "Masukkan bilangan kedua : ";
        cin >> b2_2133;
        cout << "Total penjumlahannya adalah : " << FungsiPenjumlahan_2133(b1_2133 , b2_2133) << endl;// Menampilkan output hasil operasi pertambahan
        cout << endl;
        goto ulang_2133;// Buat ulang ke menu awal
        break;
    case 2 :
    //Operator pengurangan
        cout << "Masukkan bilangan pertama : ";
        cin >> b3_2133;
        cout << "Masukkan bilangan kedua : ";
        cin >> b4_2133;
        cout << "Total penngurangannya adalah : " << FungsiPengurangan_2133(b3_2133 , b4_2133) << endl;// Menampilkan output hasil operasi pengurangan
        goto ulang_2133;// Buat ulang ke menu awal
        break;
    case 3 :
    //Operator hitung luas segitiga
        cout << "Masukkan alas segitiga : ";
        cin >> alas_2133;
        cout << "Masukkan tinggi segitiga : ";
        cin >> tinggi_2133;
        cout << "Hasil luas segitiga : " << FungsiLuasSegitiga_2133(alas_2133, tinggi_2133) << endl;// Menampilkan output hasil operasi hitung luas
        cout << endl;
        goto ulang_2133;// Buat ulang ke menu awal
        break;
    case 4 :
    //Perintah keluar dari program dengan break
        cout << "Keluar dari program" << endl;// Mengakhiri program
        break;
    }
    return 0;
}
