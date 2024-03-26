#include <iostream>
#include <iomanip>

using namespace std;

// Definisi struktur node untuk menyimpan data barang skincare
struct node
{
    string barang_133;
    int harga_133;
    node *prev; // Pointer ke node sebelumnya
    node *next; // Pointer ke node berikutnya
};

node *head; // Pointer ke node pertama
node *tail; // Pointer ke node terakhir

// Prosedur inisialisasi
void Inisialisasi_133()
{
    head = nullptr;
    tail = nullptr;
}

// Prosedur tambah node
void TambahNode_133(string produk_133, int harga_133, int posisi)
{
    if (posisi < 1)
    {
        cout << "Node berada diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        // Buat node baru
        node *baru = new node;
        baru->barang_133 = produk_133;
        baru->harga_133 = harga_133;
        baru->next = head;
        baru->prev = nullptr;
        // Periksa jika tidak kosong, atur node sebelumnya ke node baru
        if (head != nullptr)
        {
            head->prev = baru;
        }
        else
        {
            tail = baru;
        }
        head = baru; // Atur head ke node baru
    }
    else
    {
        // Cari node di posisi yang diinginkan
        node *current = head;
        node *baru = new node;
        baru->barang_133 = produk_133;
        baru->harga_133 = harga_133;
        baru->next = nullptr;
        baru->prev = nullptr;
        int hitung = 1;
        // Iterasi untuk mencapai posisi yang diinginkan
        while (hitung < posisi - 1)
        {
            hitung++;
            current = current->next;
        }
        baru->next = current->next;
        baru->prev = current;
        // Periksa jika tidak kosong, atur node sebelumnya ke node baru
        if (current->next != nullptr)
        {
            current->next->prev = baru;
        }
        else
        {
            tail = baru;
        }
        current->next = baru; // Atur node berikutnya dari current ke node baru
    }
}

// Prosedur hapus node
void HapusNode_133(int posisi)
{
    if (posisi < 1)
    {
        cout << "Posisi node berada diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        // Hapus node pertama
        node *current = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete current;
    }
    else
    {
        // Hapus node di posisi yang diinginkan
        node *current = head;
        int hitung = 1;
        // Iterasi untuk mencapai posisi yang diinginkan
        while (hitung < posisi)
        {
            hitung++;
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

// Fungsi untuk mengupdate data
bool UpdateData_133(string ProdukLama_133, string ProdukBaru_133, int HargaBaru_133)
{
    node *current = head;
    // Iterasi untuk mencari data dengan nama produk lama
    while (current != nullptr)
    {
        if (current->barang_133 == ProdukLama_133)
        {
            // Update nama dan harga produk
            current->barang_133 = ProdukBaru_133;
            current->harga_133 = HargaBaru_133;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Prosedur untuk menghapus semua data
void HapusSemua_133()
{
    node *current = head;
    // Iterasi untuk menghapus semua node
    while (current != nullptr)
    {
        node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

// Prosedur untuk menampilkan data
void TampilData_133()
{
    node *current = head;
    if (head != nullptr)
    {
        cout << left << setw(20) << "- Nama Produk -" << right << setw(5) << "- Harga -" << endl;
        // Iterasi untuk menampilkan semua data
        while (current != nullptr)
        {
            cout << left << setw(20) << current->barang_133 << right << setw(7) << current->harga_133 << endl;
            current = current->next;
        }
    }
    cout << endl;
}

// Fungsi utama
int main()
{
    int pilih, HargaBaru_133, Posisi;
    string ProdukBaru_133, ProdukLama_133;
    Inisialisasi_133(); // Inisialisasi list
    cout << "--- DAFTAR PRODUK SKINCARE ---" << endl;
    // Tambahkan beberapa data awal
    TambahNode_133("Hanasui", 30000, 1);
    TambahNode_133("Wardah", 50000, 1);
    TambahNode_133("Skintific", 100000, 1);
    TambahNode_133("Somethinc", 150000, 1);
    TambahNode_133("Originote", 60000, 1);
    TampilData_133(); // Tampilkan data

Menu:
    // Menu operasi
    cout << "--- TOKO SKINCARE PURWOKERTO ---" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Tambah data urutan tertentu" << endl;
    cout << "5. Hapus data urutan tertentu" << endl;
    cout << "6. Hapus seluruh data" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "8. Exit" << endl;
    cout << "Pilihan anda = ";
    cin >> pilih;
    cout << endl;

    switch (pilih)
    {
    case 1:
        cout << "- Tambah Data Produk -" << endl;
        cout << "Masukkan nama produk yang ingin ditambahkan = ";
        cin >> ProdukBaru_133;
        cout << "Masukkan harga produk = ";
        cin >> HargaBaru_133;
        // Panggil prosedur untuk menambahkan data pada posisi pertama
        TambahNode_133(ProdukBaru_133, HargaBaru_133, 1);
        cout << "Produk telah ditambahkan" << endl;
        cout << endl;
        goto Menu; // Kembali ke menu
        break;
    case 2:
        cout << "- Hapus Data Produk Pertama - " << endl;
        // Panggil prosedur untuk menghapus data pada posisi pertama
        HapusNode_133(1);
        cout << "Data produk ke-1 telah dihapus" << endl;
        cout << endl;
        goto Menu; // Kembali ke menu
        break;
    case 3:
        cout << "- Update Data Produk -" << endl;
        cout << "Masukkan produk lama yang ingin diganti = ";
        cin >> ProdukLama_133;
        cout << "Masukkan nama produk baru = ";
        cin >> ProdukBaru_133;
        cout << "Masukkan harga produk baru = ";
        cin >> HargaBaru_133;
        // Panggil prosedur untuk mengupdate data
        UpdateData_133(ProdukLama_133, ProdukBaru_133, HargaBaru_133);
        cout << "Produk telah diupdate" << endl;
        cout << endl;
        goto Menu; // Kembali ke menu
        break;
    case 4:
        cout << "- Tambah Data Urutan Tertentu -" << endl;
        cout << "Nama baru produk = ";
        cin >> ProdukBaru_133;
        cout << "Harga baru produk = ";
        cin >> HargaBaru_133;
        cout << "Posisi produk = ";
        cin >> Posisi;
        // Panggil prosedur untuk menambahkan data pada posisi tertentu
        TambahNode_133(ProdukBaru_133, HargaBaru_133, Posisi);
        cout << "Produk baru telah ditambahkan" << endl;
        cout << endl;
        goto Menu; // Kembali ke menu
        break;
    case 5:
        cout << "- Hapus Data Urutan Tertentu -" << endl;
        cout << "Masukkan urutan produk yang ingin dihapus = ";
        cin >> Posisi;
        // Panggil prosedur untuk menghapus data pada posisi tertentu
        HapusNode_133(Posisi);
        cout << "Produk urutan ke-" << Posisi << " telah dihapus" << endl;
        cout << endl;
        goto Menu; // Kembali ke menu
        break;
    case 6:
        cout << "- Hapus Seluruh Data -" << endl;
        // Panggil prosedur untuk menghapus semua data
        HapusSemua_133();
        cout << "Seluruh data telah dihapus" << endl;
        cout << endl;
        goto Menu; // Kembali ke menu
        break;
    case 7:
        cout << "- Tampilkan Data -" << endl;
        // Panggil prosedur untuk menampilkan semua data
        TampilData_133();
        cout << endl;
        goto Menu; // Kembali ke menu
        break;
    case 8:
        cout << "Anda telah keluar" << endl;
        return 0; // Keluar dari program
    default:
        cout << "Pilihan tidak ada di menu" << endl;
        cout << endl;
        goto Menu; // Kembali ke menu jika pilihan tidak valid
        break;
    }
}
