#include <iostream>

using namespace std;

// Definisikan struktur untuk node
struct node {
    string NamaMahasiswa_133; // Nama mahasiswa
    string NIM_133; // NIM mahasiswa
    node *next; // Pointer ke node berikutnya
};

// Definisikan pointer front dan back untuk antrian
node *front;
node *back;

// Fungsi untuk inisialisasi antrian
void Inisialisasi_133(){
    front = NULL; // Set front ke NULL
    back = NULL; // Set back ke NULL
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty_133(){
    return front == NULL; // Kembalikan true jika front NULL, sebaliknya false
}

// Fungsi untuk menambah data ke antrian
void TambahData_133(string Nama_133, string NIM_133){
    node *baru = new node; // Buat node baru
    baru->NamaMahasiswa_133 = Nama_133; // Set nama mahasiswa
    baru->NIM_133 = NIM_133; // Set NIM mahasiswa
    baru->next = NULL; // Set next pointer ke NULL

    // Periksa apakah antrian kosong
    if(isEmpty_133()){
        front = back = baru; // Set front dan back ke node baru
        back->next = NULL; // Pastikan next dari back adalah NULL
    } else {
        back->next = baru; // Hubungkan node baru ke akhir antrian
        back = baru; // Update back ke node baru
    }
}

// Fungsi untuk mengurangi data dari antrian
void KurangiAntrian_133(){
    node *hapus;
    if(!isEmpty_133()){
        if(front->next != NULL){
            hapus = front; // Set hapus ke node front
            front = front->next; // Pindahkan front ke node berikutnya
            delete hapus; // Hapus node lama front
        } else {
            front = back = NULL; // Jika hanya ada satu node, set front dan back ke NULL
        }
    }
}

// Fungsi untuk menghitung jumlah node dalam antrian
int HitungAntrian_133(){
    node *hitung;
    hitung = front;
    int jumlah_133 = 0;
    while(hitung != NULL){
        hitung = hitung->next; // Pindah ke node berikutnya
        jumlah_133++; // Tambah jumlah
    }
    return jumlah_133; // Kembalikan jumlah total
}

// Fungsi untuk menghapus semua node dalam antrian
void HapusAntrian_133(){
    node *hapus, *bantu;
    bantu = front;
    while(bantu != NULL){
        hapus = bantu; // Set hapus ke node saat ini
        bantu = bantu->next; // Pindah ke node berikutnya
        delete hapus; // Hapus node saat ini
    }
    front = back = NULL; // Set front dan back ke NULL
}

// Fungsi untuk menampilkan antrian
void TampilAntrian_133(){
    node *bantu;
    bantu = front;
    if(isEmpty_133()){
        cout << "Antrian kosong!" << endl; // Output Antrian kosong
    } else {
        cout << "--- Antrian Saat Ini ---" << endl;
        int NomorAntrian_133 = 1;
        while(bantu != NULL){
            cout << NomorAntrian_133 << ". " << bantu->NamaMahasiswa_133 << " - " << bantu->NIM_133 << endl;
            bantu = bantu->next; // Pindah ke node berikutnya
            NomorAntrian_133++; // Tambah nomor antrian
        }
    }
    cout << endl;
}

int main(){
    //Deklarasi variabel
    string NamaMhs_133, NIM_133;
    int Pilih_133;
    char Yakin_133;

    // Menu utama
    Menu:
    cout << "-----------------------------------------" << endl;
    cout << "-     MENU UTAMA ANTRIAN MAHASISWA      -" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Tambah antrian" << endl;
    cout << "2. Kurangi antrian" << endl;
    cout << "3. Hitung jumlah antrian" << endl;
    cout << "4. Hapus antrian" << endl;
    cout << "5. Tampilkan antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilihan Anda [1-6] = ";
    cin >> Pilih_133;
    cout << endl;

    // Switch case untuk menangani menu
    switch(Pilih_133){
        case 1:
            cout << "~~~ Tambah Antrian ~~~" << endl;
            cout << "Masukkan nama mahasiswa = ";
            cin >> NamaMhs_133;
            cout << "Masukkan NIM mahasiswa = ";
            cin >> NIM_133;
            TambahData_133(NamaMhs_133, NIM_133);
            cout << "Data mahasiswa telah tersimpan!" << endl;
            cout << endl;
            goto Menu; // Kembali ke menu utama
            break;
        case 2:
            cout << "~~~ Kurangi Antrian ~~~" << endl;
            if(isEmpty_133()){
                cout << "Antrian masih kosong!" << endl;
            } else {
                cout << "Apakah anda ingin mengurangi antrian (menghapus antrian pertama)? [y/n] = ";
                cin >> Yakin_133;
                if(Yakin_133 == 'y' || Yakin_133 == 'Y'){
                    KurangiAntrian_133();
                    cout << "Antrian telah berhasil dikurangi" << endl;
                } else if(Yakin_133 == 'n' || Yakin_133 == 'N'){
                    cout << "Aksi dibatalkan" << endl;
                }
            }
            cout << endl;
            goto Menu; // Kembali ke menu utama
            break;
        case 3:
            cout << "~~~ Hitung Jumlah Antrian ~~~" << endl;
            cout << "Antrian yang tersimpan saat ini sebanyak " << HitungAntrian_133() << endl;
            cout << endl;
            goto Menu; // Kembali ke menu utama
            break;
        case 4:
            cout << "~~~ Hapus Antrian ~~~" << endl;
            cout << "Apakah Anda yakin untuk menghapus seluruh antrian? [y/n] = ";
            cin >> Yakin_133;
            if(Yakin_133 == 'y' || Yakin_133 == 'Y'){
                HapusAntrian_133();
                cout << "Antrian telah berhasil dihapus" << endl;
            } else if(Yakin_133 == 'n' || Yakin_133 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto Menu; // Kembali ke menu utama
            break;
        case 5:
            TampilAntrian_133();
            cout << endl;
            goto Menu; // Kembali ke menu utama
            break;
        case 6:
            cout << "Anda telah keluar dari program" << endl;
            cout << endl;
            return 0; // Keluar dari program
            break;
        default:
            cout << "Pilihan yang anda masukkan salah!" << endl;
            cout << endl;
            goto Menu; // Kembali ke menu utama
            break;
    }
}
