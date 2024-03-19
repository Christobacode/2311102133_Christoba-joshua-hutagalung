#include <iostream>
using namespace std;

int main() {
    int jmlhElemen_133;
    // User menginputkan jumlah elemen array
    cout << "Masukkan jumlah elemen array: ";
    cin >> jmlhElemen_133;

    // Mendeklarasikan array dengan ukuran yang dimasukkan oleh pengguna
    int arr[jmlhElemen_133];

    // Menginputkan nilai untuk setiap elemen array
    cout << "Masukkan nilai untuk setiap elemen array: " << endl;
    for(int i = 0; i < jmlhElemen_133; ++i) {
        cout << "Elemen " << i + 1 << " : ";
        cin >> arr[i];
    }

    // Menampilkan menu pilihan 
    int pilih_133;
    // menggunakan perulangan do while agar saat sudah selesai di menu maksimum contohnya nanti dia bakal looping lgi ke menu awal
    do {
        cout << "---- MENU BY JOSHUA ----" << endl;
        cout << "1. Mencari Nilai Maksimum\n";
        cout << "2. Mencari Nilai Minimum\n";
        cout << "3. Mencari Nilai Rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih_133;

        // Melakukan operasi sesuai dengan pilihan user
        switch(pilih_133) {
            case 1: {
                // Mencari nilai maksimum
                int max_133 = arr[0];
                for(int i = 1; i < jmlhElemen_133; i++) {
                    if(arr[i] > max_133) {
                        max_133 = arr[i];
                    }
                }
                cout << "Hasil nilai maksimumnya adalah: " << max_133 << endl;
                break;
            }
            case 2: {
                // Mencari nilai minimum
                int min_133 = arr[0];
                for(int i = 1; i < jmlhElemen_133; i++) {
                    if(arr[i] < min_133) {
                        min_133 = arr[i];
                    }
                }
                cout << "Hasil nilai minimumnya adalah: " << min_133 << endl;
                break;
            }
            case 3: {
                // Mencari nilai rata-rata
                double rataRata_133 = 0;
                for(int i = 0; i < jmlhElemen_133; i++) {
                    rataRata_133 += arr[i];
                }
                rataRata_133 /= jmlhElemen_133;
                cout << "Hasil nilai rata-ratanya adalah: " << rataRata_133 << endl;
                break;
            }
            case 4: {
                // Mengakhiri program
                cout << "Anda keluar dari program" << endl;
                break;
            }
            default:
                // Jika inputan tidak ada di pilihan
                cout << "Pilihan anda tidak tersedia" << endl;
        }
    } while(pilih_133 != 4);

    return 0;
}
