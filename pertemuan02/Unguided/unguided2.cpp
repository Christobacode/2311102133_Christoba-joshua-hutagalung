#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk menyimpan ukuran array
    int X_133, Y_133, Z_133;

    // Input ukuran array dari user
    cout << "Masukkan ukuran array x : ";
    cin >> X_133;
    cout << "Masukkan ukuran array y : ";
    cin >> Y_133;
    cout << "Masukkan ukuran array z : ";
    cin >> Z_133;

    // Deklarasi array dengan ukuran yang diinputkan oleh user
    int arr[X_133][Y_133][Z_133];

    // Input elemen array
    for (int x = 0; x < X_133; x++) {
        for (int y = 0; y < Y_133; y++) {
            for (int z = 0; z < Z_133; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < X_133; x++) {
        for (int y = 0; y < Y_133; y++) {
            for (int z = 0; z < Z_133; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < X_133; x++) {
        for (int y = 0; y < Y_133; y++) {
            for (int z = 0; z < Z_133; z++) {
                cout << arr[x][y][z] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
