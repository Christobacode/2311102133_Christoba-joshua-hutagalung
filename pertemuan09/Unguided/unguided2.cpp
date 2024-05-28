#include <iostream>
#include <iomanip>
using namespace std;

// Struktur data untuk node dalam pohon
struct Pohon
{
    char data;                    // Data yang disimpan dalam node
    Pohon *left, *right, *parent; // Pointer ke node anak kiri, anak kanan, dan parent
};
Pohon *root, *baru; // Pointer ke root pohon dan node baru

// Fungsi untuk inisialisasi pohon
void init()
{
    root = NULL; // Inisialisasi root pohon menjadi NULL
}

// Fungsi untuk memeriksa apakah pohon kosong atau tidak
bool isEmpty()
{
    return root == NULL; // Mengembalikan true jika root adalah NULL, false jika tidak
}

// Fungsi untuk membuat node baru sebagai root
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon(); // Alokasi memori untuk node root baru
        root->data = data;  // Isi data node root dengan data yang diberikan
        root->left = NULL;  // Inisialisasi pointer ke anak kiri dan anak kanan menjadi NULL
        root->right = NULL;
        root->parent = NULL; // Pointer ke parent diatur NULL karena root adalah node teratas
        cout << "\n Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl; // Pesan kesalahan jika pohon sudah ada
    }
}

// Fungsi untuk menambahkan node sebagai anak kiri dari node yang diberikan
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl; // Pesan kesalahan jika node sudah memiliki anak kiri
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon(); // Alokasi memori untuk node baru
            baru->data = data;         // Isi data node baru dengan data yang diberikan
            baru->left = NULL;         // Inisialisasi pointer ke anak kiri dan anak kanan menjadi NULL
            baru->right = NULL;
            baru->parent = node; // Pointer ke parent diatur ke node yang diberikan
            node->left = baru;   // Pointer dari node yang diberikan ke anak kiri diatur ke node baru
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru; // Mengembalikan pointer ke node baru
        }
    }
}

// Fungsi untuk menambahkan node sebagai anak kanan dari node yang diberikan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl; // Pesan kesalahan jika node sudah memiliki anak kanan
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon(); // Alokasi memori untuk node baru
            baru->data = data;         // Isi data node baru dengan data yang diberikan
            baru->left = NULL;         // Inisialisasi pointer ke anak kiri dan anak kanan menjadi NULL
            baru->right = NULL;
            baru->parent = node; // Pointer ke parent diatur ke node yang diberikan
            node->right = baru;  // Pointer dari node yang diberikan ke anak kanan diatur ke node baru
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru; // Mengembalikan pointer ke node baru
        }
    }
}

// Fungsi untuk mengubah data node yang diberikan
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl; // Pesan kesalahan jika node yang ingin diubah tidak ada
        }
        else
        {
            char temp = node->data;                                                    // Simpan data asli node
            node->data = data;                                                         // Ubah data node dengan data yang baru
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl; // Konfirmasi perubahan
        }
    }
}

// Fungsi untuk mengambil data dari node yang diberikan
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan kesalahan jika node yang ditunjuk tidak ada
        }
        else
        {
            cout << "\n Data node: " << node->data << endl; // Tampilkan data node yang ditunjuk
        }
    }
}

// Fungsi untuk mencari dan menampilkan informasi tentang node yang diberikan
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan kesalahan jika node yang ditunjuk tidak ada
        }
        else
        {
            cout << "\n Data Node: " << node->data << endl; // Tampilkan data node yang ditunjuk
            cout << " Root: " << root->data << endl;        // Tampilkan data root
            // Tampilkan parent, sibling, dan anak
            // Tampilkan parent, sibling, dan anak kiri-kanan dari node
            if (!node->parent)
                cout << " Parent: (tidak punya parent)" << endl; // Jika node tidak memiliki parent, tampilkan pesan
            else
                cout << " Parent: " << node->parent->data << endl; // Jika node memiliki parent, tampilkan data parent

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling: " << node->parent->left->data << endl; // Jika node adalah anak kanan, tampilkan sibling kiri
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling: " << node->parent->right->data << endl; // Jika node adalah anak kiri, tampilkan sibling kanan
            else
                cout << " Sibling: (tidak punya sibling)" << endl; // Jika node tidak memiliki sibling, tampilkan pesan

            if (!node->left)
                cout << " Child Kiri: (tidak punya Child kiri)" << endl; // Jika node tidak memiliki anak kiri, tampilkan pesan
            else
                cout << " Child Kiri: " << node->left->data << endl; // Jika node memiliki anak kiri, tampilkan data anak kiri

            if (!node->right)
                cout << " Child Kanan: (tidak punya Child kanan)" << endl; // Jika node tidak memiliki anak kanan, tampilkan pesan
            else
                cout << " Child Kanan: " << node->right->data << endl; // Jika node memiliki anak kanan, tampilkan data anak kanan
        }
    }
}

// Fungsi rekursif untuk traversal pre-order dari pohon
void preOrder(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", "; // Tampilkan data node
            preOrder(node->left);              // Rekursi ke anak kiri
            preOrder(node->right);             // Rekursi ke anak kanan
        }
    }
}

// Fungsi rekursif untuk traversal in-order dari pohon
void inOrder(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);               // Rekursi ke anak kiri
            cout << " " << node->data << ", "; // Tampilkan data node
            inOrder(node->right);              // Rekursi ke anak kanan
        }
    }
}

// Fungsi rekursif untuk traversal post-order dari pohon
void postOrder(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);             // Rekursi ke anak kiri
            postOrder(node->right);            // Rekursi ke anak kanan
            cout << " " << node->data << ", "; // Tampilkan data node
        }
    }
}

// Fungsi untuk menghapus seluruh pohon
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);  // Rekursi untuk menghapus anak kiri
            deleteTree(node->right); // Rekursi untuk menghapus anak kanan
            if (node == root)
            {
                delete root; // Hapus root jika tidak punya parent
                root = NULL;
            }
            else
            {
                delete node; // Hapus node jika bukan root
            }
        }
    }
}

// Fungsi untuk menghapus subtree yang dimulai dari node yang diberikan
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        deleteTree(node->left);                                                   // Hapus anak kiri
        deleteTree(node->right);                                                  // Hapus anak kanan
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl; // Konfirmasi penghapusan subtree
    }
}

// Fungsi untuk menghapus seluruh pohon
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else
    {
        deleteTree(root);                             // Hapus seluruh pohon
        cout << "\n Pohon berhasil dihapus." << endl; // Konfirmasi penghapusan pohon
    }
}

// Fungsi untuk menghitung jumlah node dalam pohon
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0; // Mengembalikan 0 jika node kosong
        }
        else
        {
            return 1 + size(node->left) + size(node->right); // Menghitung jumlah node secara rekursif
        }
    }
}

// Fungsi untuk menghitung tinggi pohon
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0; // Mengembalikan 0 jika node kosong
        }
        else
        {
            int heightKiri = height(node->left);  // Hitung tinggi anak kiri secara rekursif
            int heightKanan = height(node->right); // Hitung tinggi anak kanan secara rekursif
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1; // Mengembalikan tinggi anak kiri ditambah 1
            }
            else
            {
                return heightKanan + 1; // Mengembalikan tinggi anak kanan ditambah 1
            }
        }
    }
}

// Fungsi untuk menampilkan karakteristik pohon
void characteristic()
{
    cout << "\n ukuran pohon: " << size(root) << endl;                      // Tampilkan jumlah node dalam pohon
    cout << " tinggi pohon: " << height(root) << endl;                      // Tampilkan tinggi pohon
    cout << " Rata-rata node pohon: " << size(root) / height(root) << endl; // Tampilkan rata-rata node per level
}

// Fungsi untuk menampilkan anak kiri dan kanan dari node yang diberikan
void displayChildren(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else if (!node)
    {
        cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan kesalahan jika node tidak ada
    }
    else
    {
        if (node->left)
            cout << " Child Kiri: " << node->left->data << endl; // Tampilkan data anak kiri jika ada
        else
            cout << " Child Kiri: (tidak punya Child kiri)" << endl; // Tampilkan pesan jika tidak ada anak kiri

        if (node->right)
            cout << " Child Kanan: " << node->right->data << endl; // Tampilkan data anak kanan jika ada
        else
            cout << " Child Kanan: (tidak punya Child kanan)" << endl; // Tampilkan pesan jika tidak ada anak kanan
    }
}

// Fungsi untuk menampilkan semua keturunan dari node yang diberikan
void displayDescendants(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan kesalahan jika pohon belum ada
    }
    else if (!node)
    {
        cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan kesalahan jika node tidak ada
    }
    else
    {
        cout << " Keturunan dari " << node->data << ": "; // Tampilkan pesan dengan data node yang diberikan
        preOrder(node);                                   // Panggil fungsi preOrder untuk menampilkan keturunan
        cout << endl;
    }
}

// Fungsi untuk mencari node dengan data yang diberikan
Pohon *findNode(Pohon *node, char data)
{
    if (node == NULL)
        return NULL;
    if (node->data == data)
        return node;

    Pohon *leftNode = findNode(node->left, data); // Cari node pada anak kiri secara rekursif
    if (leftNode != NULL)
        return leftNode;

    return findNode(node->right, data); // Cari node pada anak kanan secara rekursif
}

// Fungsi utama
int main()
{
    init(); // Inisialisasi pohon
    int pilih_133;
    char data_133;
    Pohon *node = nullptr;

    do
    {
        cout << "\nMenu:\n";
        // Tampilkan menu
        cout << "1. Buat Pohon\n";
        cout << "2. Tambah kiri\n";
        cout << "3. Tambah kanan\n";
        cout << "4. Perbarui Node\n";
        cout << "5. Mengambil Node\n";
        cout << "6. Temukan Node\n";
        cout << "7. Tampilkan node\n";
        cout << "8. Tampilkan keturunan (child)\n";
        cout << "9. Sifat\n";
        cout << "10. PreOrder Traversal\n";
        cout << "11. InOrder Traversal\n";
        cout << "12. PostOrder Traversal\n";
        cout << "13. Hapus pohon\n";
        cout << "14. Keluar\n";
        cout << "Masukkan pilihan : ";
        cin >> pilih_133; // Menerima input dari pengguna

        // Switch untuk memproses pilihan pengguna
        switch (pilih_133)
        {
        // Kasus 1: Buat Pohon
        case 1:
            cout << "Masukkan root: ";
            cin >> data_133;
            buatNode(data_133);
            break;

        // Kasus 2: Tambah kiri
        case 2:
            cout << "Masukkan data node baru: ";
            cin >> data_133;
            cout << "Masukkan data parent baru: ";
            char parentDataLeft;
            cin >> parentDataLeft;
            node = findNode(root, parentDataLeft);
            if (node != nullptr)
                insertLeft(data_133, node);
            break;

        // Kasus 3: Tambah kanan
        case 3:
            cout << "Masukkan data node baru: ";
            cin >> data_133;
            cout << "Masukkan data parent baru: ";
            char parentDataRight;
            cin >> parentDataRight;
            node = findNode(root, parentDataRight);
            if (node != nullptr)
                insertRight(data_133, node);
            break;

        // Kasus 4: Perbarui Node
        case 4:
            cout << "Masukan data yang ingin diubah: ";
            cin >> data_133;
            cout << "Masukkan node baru: ";
            char newData;
            cin >> newData;
            node = findNode(root, data_133);
            if (node != nullptr)
                update(newData, node);
            break;

        // Kasus 5: Mengambil Node
        case 5:
            cout << "Masukan data yang akan diambil: ";
            cin >> data_133;
            node = findNode(root, data_133);
            retrieve(node);
            break;

        // Kasus 6: Temukan Node
        case 6:
            cout << "Masukkan data yang akan ditemukan: ";
            cin >> data_133;
            node = findNode(root, data_133);
            find(node);
            break;

        // Kasus 7: Tampilkan node
        case 7:
            cout << "Masukan data untuk yang ingin ditampilkan: ";
            cin >> data_133;
            node = findNode(root, data_133);
            displayChildren(node);
            break;

        // Kasus 8: Tampilkan keturunan (child)
        case 8:
            cout << "Masukkan data untuk menampilkan keturunan(child): ";
            cin >> data_133;
            node = findNode(root, data_133);
            displayDescendants(node);
            break;

        // Kasus 9: Sifat
        case 9:
            characteristic();
            break;

        // Kasus 10: PreOrder Traversal
        case 10:
            cout << "PreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;

        // Kasus 11: InOrder Traversal
        case 11:
            cout << "InOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;

        // Kasus 12: PostOrder Traversal
        case 12:
            cout << "PostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;

        // Kasus 13: Hapus pohon
        case 13:
            clear();
            break;

        // Kasus 14: Keluar
        case 14:
            cout << "Keluar program" << endl;
            break;

        // Default: Pilihan tidak tersedia
        default:
            cout << "Pilihan tidak tersedia" << endl;
        }
    } while (pilih_133 != 14); // Ulangi sampai pengguna memilih untuk keluar

    return 0;
}
