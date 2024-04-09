#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Deklarasi isi tabel sebanyak 100
const int TableSize_133 = 100;

// Deklarasi class HashNode
class HashNode
{
public:
    string nama_133; // Nama mahasiswa
    string NIM_133;  // NIM mahasiswa
    int nilai_133;   // Nilai mahasiswa

    // Deklarasi konstruktor HashNode
    HashNode(string name_133, string nim_133, int grade_133) : nama_133(name_133), NIM_133(nim_133), nilai_133(grade_133) {}
};

// Deklarasi class HashMap
class HashMap
{
private:
    vector<HashNode *> table_133[TableSize_133]; // Tabel hash untuk menyimpan node-node

    // Fungsi hash untuk menghitung nilai hash dari sebuah string
    int hashFunc_133(string key_133)
    {
        int hashValue_133 = 0;
        for (char c : key_133)
        {
            hashValue_133 += c;
        }
        return hashValue_133 % TableSize_133;
    }

public:
    // Fungsi untuk menambahkan data baru ke tabel
    void Tambah(string name_133, string nim_133, int nilai_133)
    {
        int hashValue = hashFunc_133(nim_133); // Hitung nilai hash dari NIM mahasiswa

        // Periksa apakah data dengan NIM yang sama sudah ada
        for (auto node : table_133[hashValue])
        {
            if (node->NIM_133 == nim_133)
            {
                node->nama_133 = name_133; // Jika sudah ada, perbarui nama dan nilai
                node->nilai_133 = nilai_133;
                cout << "Data mahasiswa dengan NIM " << nim_133 << " berhasil diperbarui" << endl;
                return;
            }
        }

        // Jika tidak ada data dengan NIM yang sama, buat node baru dan tambahkan ke tabel
        table_133[hashValue].push_back(new HashNode(name_133, nim_133, nilai_133));
        cout << "Data mahasiswa berhasil ditambahkan" << endl;
    }

    // Fungsi untuk mencari data berdasarkan NIM
    void CariByNIM(string nim_133)
    {
        bool found = false;
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama"
             << "|" << left << setw(14) << "NIM"
             << "|" << left << setw(13) << "Nilai"
             << "|" << endl;
        cout << "---------------------------------------------" << endl;

        int hashValue = hashFunc_133(nim_133); // Hitung nilai hash dari NIM mahasiswa

        for (auto node : table_133[hashValue])
        {
            if (node->NIM_133 == nim_133)
            {
                cout << "|" << left << setw(14) << node->nama_133 << "|" << left << setw(14) << node->NIM_133 << "|" << left << setw(13) << node->nilai_133 << "|" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Data mahasiswa dengan NIM " << nim_133 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    // Fungsi untuk mencari data berdasarkan rentang nilai
    void CariByGradeRange(int minGrade_133, int maxGrade_133)
    {
        bool found = false;
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama"
             << "|" << left << setw(14) << "NIM"
             << "|" << left << setw(13) << "Nilai"
             << "|" << endl;
        cout << "---------------------------------------------" << endl;

        for (int i = 0; i < TableSize_133; i++)
        {
            for (auto node : table_133[i])
            {
                if (node->nilai_133 >= minGrade_133 && node->nilai_133 <= maxGrade_133)
                {
                    cout << "|" << left << setw(14) << node->nama_133 << "|" << left << setw(14) << node->NIM_133 << "|" << left << setw(13) << node->nilai_133 << "|" << endl;
                    found = true;
                }
            }
        }

        if (!found)
        {
            cout << "Data mahasiswa dengan rentang nilai " << minGrade_133 << " - " << maxGrade_133 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    // Fungsi untuk menghapus data berdasarkan NIM
    void Hapus(string nim_133)
    {
        int hashValue = hashFunc_133(nim_133); // Hitung nilai hash dari NIM mahasiswa

        auto &nodes = table_133[hashValue];

        // Gunakan iterator aman untuk iterasi dan hapus elemen
        for (auto it = nodes.begin(); it != nodes.end(); ++it)
        {
            if ((*it)->NIM_133 == nim_133)
            {
                // Hapus node dari memori
                delete *it;
                // Hapus node dari vektor
                nodes.erase(it);
                cout << "Data mahasiswa dengan NIM " << nim_133 << " berhasil dihapus" << endl;
                return;
            }
        }

        // Jika tidak ada node dengan NIM yang sesuai setelah iterasi selesai, tampilkan pesan
        cout << "Data mahasiswa dengan NIM " << nim_133 << " tidak ditemukan" << endl;
    }

    // Fungsi untuk menampilkan seluruh data di tabel
    void TampilkanData()
    {
        cout << "-------------- DATA MAHASISWA --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama"
             << "|" << left << setw(14) << "NIM"
             << "|" << left << setw(13) << "Nilai"
             << "|" << endl;
        cout << "---------------------------------------------" << endl;

        for (int i = 0; i < TableSize_133; i++)
        {
            for (auto node : table_133[i])
            {
                cout << "|" << left << setw(14) << node->nama_133 << "|" << left << setw(14) << node->NIM_133 << "|" << left << setw(13) << node->nilai_133 << "|" << endl;
            }
        }
        cout << "---------------------------------------------" << endl;
    }
};

int main()
{
    HashMap mahasiswaMap; // Objek untuk memanipulasi data mahasiswa
    int choice_133, nilai_133, minNilai_133, maxNilai_133;
    string nama_133, NIM_133;

    while (true)
    {
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
        cin >> choice_133; // Input pilihan menu dari pengguna
        cout << endl;

        switch (choice_133)
        {
        case 1:
            cout << "---------------- TAMBAH DATA ----------------" << endl;
            cout << "Masukkan nama mahasiswa   : ";
            cin >> nama_133;
            cout << "Masukkan NIM mahasiswa    : ";
            cin >> NIM_133;
            cout << "Masukkan nilai mahasiswa  : ";
            cin >> nilai_133;
            mahasiswaMap.Tambah(nama_133, NIM_133, nilai_133); // Panggil fungsi untuk menambahkan data
            cout << endl;
            break;
        case 2:
            cout << "---------------- HAPUS DATA -----------------" << endl;
            cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
            cin >> NIM_133;
            mahasiswaMap.Hapus(NIM_133); // Panggil fungsi untuk menghapus data
            cout << endl;
            break;
        case 3:
            cout << "----------- CARI DATA BERDASARKAN NIM ----------" << endl;
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> NIM_133;
            mahasiswaMap.CariByNIM(NIM_133); // Panggil fungsi untuk mencari data berdasarkan NIM
            cout << endl;
            break;
        case 4:
            cout << "----------- CARI DATA BERDASARKAN RENTANG NILAI ----------" << endl;
            cout << "Masukkan rentang nilai (minimum dan maksimum):" << endl;
            cout << "Minimum Nilai: ";
            cin >> minNilai_133;
            cout << "Maksimum Nilai: ";
            cin >> maxNilai_133;
            mahasiswaMap.CariByGradeRange(minNilai_133, maxNilai_133); // Panggil fungsi untuk mencari data berdasarkan rentang nilai
            cout << endl;
            break;
        case 5:
            mahasiswaMap.TampilkanData(); // Panggil fungsi untuk menampilkan seluruh data mahasiswa
            cout << endl;
            break;
        case 6:
            cout << "Terima kasih telah menggunakan program!" << endl;
            return 0; // Keluar dari program
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            cout << endl;
            break;
        }
    }

    return 0;
}
