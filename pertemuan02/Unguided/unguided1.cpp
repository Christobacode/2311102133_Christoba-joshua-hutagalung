#include <iostream>

using namespace std;

int main() {
    //Deklarasi variabel untuk menyimpan panjang array
    int panjangArray_133;
    //Deklarasi array setelah meminta panjang array dari pengguna
    int array_133[panjangArray_133];
    cout << "Masukkan panjang array: ";
    cin >> panjangArray_133;

    //Meminta user untuk menginputkan nilai untuk setiap elemen array
    cout << "Masukkan nilai untuk setiap indeks array:\n";
    for (int i = 0; i < panjangArray_133; ++i) {
        cout << "Masukkan nilai untuk indeks " << i << ": ";
        cin >> array_133[i];
    }

    // Menampilkan data array yang tadi diinputkan oleh user
    cout << "Data array : ";
    for (int i = 0; i < panjangArray_133; ++i) {
        cout << array_133[i] << " ";
    }
    cout << endl;

    // Menampilkan nomor genap dari array
    cout << "Nomor genap : ";
    for (int i = 0; i < panjangArray_133; ++i) {
        if (array_133[i] % 2 == 0) {
            cout << array_133[i] << ", ";
        }
    }
    cout << endl;

    // Menampilkan nomor ganjil dari array
    cout << "Nomor ganjil : ";
    for (int i = 0; i < panjangArray_133; ++i) {
        if (array_133[i] % 2 != 0) {
            cout << array_133[i] << ", ";
        }
    }
    cout << endl;

    return 0;
}
