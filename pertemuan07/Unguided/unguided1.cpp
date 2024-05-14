#include <iostream>
using namespace std;

// Struktur data untuk setiap elemen di linked list
struct Node {
    string data_133; // Menyimpan data berupa string
    Node* next; // Pointer ke node berikutnya
};

// Pointer yang menunjuk ke depan (front) dan belakang (back) dari antrian
Node* front = nullptr;
Node* back = nullptr;

// Fungsi untuk menambah data ke belakang antrian
void TambahData_133(string nama_133) {
    Node* baru = new Node; // Buat node baru
    baru->data_133 = nama_133; // Set data dari node baru
    baru->next = nullptr; // Set next node dari node baru ke nullptr

    if (back == nullptr) { // Jika antrian kosong
        front = baru; // Set front ke node baru
        back = baru; // Set back ke node baru
    } else { // Jika antrian tidak kosong
        back->next = baru; // Set next dari node belakang ke node baru
        back = baru; // Update node belakang ke node baru
    }
}

// Fungsi untuk mengurangi data dari depan antrian
void KurangiAntrian_133() {
    if (front == nullptr) { // Jika antrian kosong
        cout << "Antrian masih kosong" << endl;
    } else { // Jika antrian tidak kosong
        Node* temp = front; // Simpan node depan ke temp
        front = front->next; // Pindahkan front ke node berikutnya
        delete temp; // Hapus node depan yang lama
    }
}

// Fungsi untuk menghitung banyaknya data dalam antrian
int jumlahAntrian_133() {
    int count_133 = 0; // Inisialisasi penghitung
    Node* current_133 = front; // Mulai dari depan antrian
    while (current_133 != nullptr) { // Iterasi sampai akhir antrian
        count_133++; // Tambah penghitung
        current_133 = current_133->next; // Pindah ke node berikutnya
    }
    return count_133; // Kembalikan jumlah elemen dalam antrian
}

// Fungsi untuk menghapus seluruh antrian
void HapusAntrian_133() {
    while (front != nullptr) { // Iterasi sampai antrian kosong
        Node* temp = front; // Simpan node depan ke temp
        front = front->next; // Pindahkan front ke node berikutnya
        delete temp; // Hapus node depan yang lama
    }
    back = nullptr; // Set back ke nullptr setelah antrian kosong
}

// Fungsi untuk menampilkan data dalam antrian
void TampilAntrian_133() {
    cout << "Data antrian = " << endl;
    Node* current = front; // Mulai dari depan antrian
    int i = 1; // Inisialisasi nomor antrian
    int MaksimalAntrian_133 = 5; // Batas maksimal tampilan antrian
    while (current != nullptr) { // Iterasi sampai akhir antrian
        cout << i << ". " << current->data_133 << endl; // Tampilkan data
        current = current->next; // Pindah ke node berikutnya
        i++; // Tambah nomor antrian
    }
    for (; i <= MaksimalAntrian_133; i++) { // Tambah elemen kosong jika kurang dari batas maksimal
        cout << i << ". " << "(Kosong)" << endl;
    }
}

int main() {
    // Menambah 3 data nama ke dalam antrian
    TambahData_133("Alya");
    TambahData_133("Kiki");
    TambahData_133("Artika");

    // Menampilkan data yang sudah ditambahkan
    TampilAntrian_133();

    // Mengurangi data dari depan antrian
    KurangiAntrian_133();

    // Menampilkan data setelah dikurangi
    TampilAntrian_133();

    // Menghapus seluruh antrian
    HapusAntrian_133();

    // Menampilkan data setelah dihapus
    TampilAntrian_133();

    return 0;
}
