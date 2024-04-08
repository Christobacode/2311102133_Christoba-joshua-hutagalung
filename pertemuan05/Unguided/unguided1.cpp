#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

// Deklarasi isi tabel sebanyak 100
const int TableSize = 100;

// Deklarasi class HashNode
class HashNode {
public:
    string nama_133;    // Nama mahasiswa
    string NIM_133;     // NIM mahasiswa
    int nilai_133;      // Nilai mahasiswa

    // Deklarasi konstruktor HashNode
    HashNode(string name, string nim, int grade) : nama_133(name), NIM_133(nim), nilai_133(grade) {}
};

// Deklarasi class HashMap
class HashMap {
private:
    vector<HashNode*> table_133[TableSize];  // Tabel hash untuk menyimpan node-node

    // Fungsi hash untuk menghitung nilai hash dari sebuah string
    int hashFunc(string key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue += c;
        }
        return hashValue % TableSize;   // Mengembalikan nilai hash dalam rentang 0 hingga TableSize-1
    }

public:
    // Fungsi untuk menambahkan data baru ke tabel
    void Tambah(string name_133, string NIM_133, int nilai_133) {
        int hashValue = hashFunc(name_133);    // Hitung nilai hash dari nama mahasiswa

        // Periksa apakah data dengan nama yang sama sudah ada
        for (auto node : table_133[hashValue]) {
            if (node->nama_133 == name_133) {
                node->NIM_133 = NIM_133;    // Jika sudah ada, perbarui NIM dan nilai
                node->nilai_133 = nilai_133;
                return;
            }
        }

        // Jika tidak ada data dengan nama yang sama, buat node baru dan tambahkan ke tabel
        table_133[hashValue].push_back(new HashNode(name_133, NIM_133, nilai_133));
    }

    // Fungsi untuk mencari data berdasarkan NIM
    void CariByNIM(string NIM_133) {
        bool found = false;
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;

        for (int i = 0; i < TableSize; i++) {
            for (auto node : table_133[i]) {
                if (node->NIM_133 == NIM_133) {    // Temukan node dengan NIM yang sesuai
                    cout << "|" << left << setw(14) << node->nama_133 << "|" << left << setw(14) << node->NIM_133 << "|" << left << setw(13) << node->nilai_133 << "|" << endl;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "Data mahasiswa dengan NIM " << NIM_133 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    // Fungsi untuk mencari data berdasarkan rentang nilai (80-90)
    void CariByGradeRange(int minGrade_133, int maxGrade_133) {
        bool found = false;
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;

        for (int i = 0; i < TableSize; i++) {
            for (auto node : table_133[i]) {
                if (node->nilai_133 >= minGrade_133 && node->nilai_133 <= maxGrade_133) {    // Temukan node dengan nilai dalam rentang yang ditentukan
                    cout << "|" << left << setw(14) << node->nama_133 << "|" << left << setw(14) << node->NIM_133 << "|" << left << setw(13) << node->nilai_133 << "|" << endl;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "Data mahasiswa dengan rentang nilai " << minGrade_133 << " - " << maxGrade_133 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    // Fungsi untuk menghapus data berdasarkan NIM
    void Hapus(string NIM_133) {
        int hashValue = hashFunc(NIM_133);    // Hitung nilai hash dari NIM

        for (auto it = table_133[hashValue].begin(); it != table_133[hashValue].end(); ++it) {
            if ((*it)->NIM_133 == NIM_133) {   // Temukan dan hapus node dengan NIM yang sesuai
                table_133[hashValue].erase(it);
                cout << "Data mahasiswa dengan NIM " << NIM_133 << " berhasil dihapus" << endl;
                return;
            }
        }

        cout << "Data mahasiswa dengan NIM " << NIM_133 << " tidak ditemukan" << endl;
    }

    // Fungsi untuk menampilkan seluruh data di tabel
    void TampilkanData() {
        cout << "-------------- DATA MAHASISWA --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;

        for (int i = 0; i < TableSize; i++) {
            for (auto node : table_133[i]) {
                cout << "|" << left << setw(14) << node->nama_133 << "|" << left << setw(14) << node->NIM_133 << "|" << left << setw(13) << node->nilai_133 << "|" << endl;
            }
        }
        cout << "---------------------------------------------" << endl;
    }
};

int main() {
    HashMap mahasiswaMap;   // Objek untuk memanipulasi data mahasiswa
    int choice_133, nilai_133, minNilai_133, maxNilai_133;
    string nama_133, NIM_133;

    while (true) {
        // Tampilkan menu interaktif untuk pengguna
        cout << "--------------- DATA MAHASISWA --------------" << endl;
        cout << " 1. Tambah Data                             " << endl;
        cout << " 2. Hapus Data                              " << endl;
        cout << " 3. Cari Data Berdasarkan NIM               " << endl;
        cout << " 4. Cari Data Berdasarkan Rentang Nilai     " << endl;
        cout << " 5. Tampilkan Data                          " << endl;
        cout << " 6. Keluar                                  " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Masukkan pilihan anda = ";
        cin >> choice_133;    // Input pilihan menu dari pengguna
        cout << endl;

        switch (choice_133) {
            case 1:
                cout << "---------------- TAMBAH DATA ----------------" << endl;
                cout << "Masukkan nama mahasiswa   : ";
                cin >> nama_133;
                cout << "Masukkan NIM mahasiswa    : ";
                cin >> NIM_133;
                cout << "Masukkan nilai mahasiswa  : ";
                cin >> nilai_133;
                mahasiswaMap.Tambah(nama_133, NIM_133, nilai_133);    // Panggil fungsi untuk menambahkan data
                cout << "Data mahasiswa berhasil ditambahkan" << endl;
                cout << endl;
                break;
            case 2:
                cout << "---------------- HAPUS DATA -----------------" << endl;
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> NIM_133;
                mahasiswaMap.Hapus(NIM_133);    // Panggil fungsi untuk menghapus data
                cout << endl;
                break;
            case 3:
                cout << "----------- CARI DATA BERDASARKAN NIM ----------" << endl;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> NIM_133;
                mahasiswaMap.CariByNIM(NIM_133);    // Panggil fungsi untuk mencari data berdasarkan NIM
                cout << endl;
                break;
            case 4:
                cout << "----------- CARI DATA BERDASARKAN RENTANG NILAI (80-90) ----------" << endl;
                minNilai_133 = 80;
                maxNilai_133 = 90;
                mahasiswaMap.CariByGradeRange(minNilai_133, maxNilai_133);    // Panggil fungsi untuk mencari data berdasarkan rentang nilai
                cout << endl;
                break;
            case 5:
                mahasiswaMap.TampilkanData();    // Panggil fungsi untuk menampilkan seluruh data mahasiswa
                cout << endl;
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program!" << endl;
                return 0;    // Keluar dari program
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                cout << endl;
                break;
        }
    }

    return 0;
}
