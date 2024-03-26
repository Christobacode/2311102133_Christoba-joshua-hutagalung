# <h1 align="center">Laporan Praktikum Modul 3 - Linked List</h1>
<p align="center">Christoba Joshua Hutagalung - 2311102133</p>

## Dasar Teori
Linked List (Senarai Berantai) adalah jenis struktur data yang berisi kumpulan data yang disusun secara linear dengan setiap data disimpan dalam sebuah simpul dan antara satu simpul dengan simpul lain dihubungkan melalui pointer. Struktur data ini mempunyai bentuk dasar dengan sifat data disisipkan ke dalam senarai melalui salah satu ujungnya. 

Bentuk Linked list ada 3 yaitu:<br>
-Single Linked List<br>
Single linked list atau biasa disebut linked list terdiri dari elemen-elemen individu, dimana masing masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointer next<br>
-Double Linked List<br>
Elemen-elemen dihubungkan dengan dua pointer dalam satu elemen. Struktur ini menyebabkan list melintas baik ke depan maupun ke belakang. Masing-masing elemen pada double linked list terdiri dari tiga bagian, disamping data dan pointer next, masing-masing elemen dilengkapi dengan pointer prev yang menunjuk ke elemen sebelumnya.<br> 
-Circular Linked List<br>
Circular list adalah bentuk lain dari linked list yang memberikan fleksibilitas dalam melewatkan elemen. Circular list bisa berupa single linked list atau double linked list, tetapi tidak mempunyai tail. Pada circular list, pointer next dari elemen terakhir menunjuk ke elemen pertama dan bukan menunjuk NULL. Pada double linked circular list, pointer prev dari elemen pertama menunjuk ke elemen terakhir. susunan dari single linked circular list, hanya menangani link dari elemen terakhir kembali ke elemen pertama.<br>

Operasi-operasi yang ada pada linked list relatif lebihsulit jika dibandingkan dengan operasi-operasi pada struktur yang statis.

## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty()
{
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung jumlah node dalam list
int hitungList()
{
    Node *hitung = head;
    int jumlah = 0;

    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru = new Node();
        baru->data = data;

        // Traversal
        Node *bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan()
{
    if (!isEmpty())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang()
{
    if (!isEmpty())
    {
        Node *hapus = tail;
        Node *bantu = head;

        if (head != tail)
        {
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *hapus;
        Node *bantu;
        Node *bantu2;

        int nomor = 1;
        bantu = head;

        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }

            if (nomor == posisi)
            {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data)
{
    if (!isEmpty())
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi)
{
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *bantu = head;
            int nomor = 1;

            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }

            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data)
{
    if (!isEmpty())
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Seluruh Node dalam List
void clearList()
{
    Node *bantu = head;
    Node *hapus;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan Isi List
void tampil()
{
    Node *bantu = head;

    if (!isEmpty())
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }

        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    return 0;
}
```
Program tersebut merupakan implementasi sederhana dari struktur data single linked list dalam bahasa C++. Dimulai dengan inisialisasi dua pointer, yaitu `head` dan `tail`, yang menunjukkan bagian depan dan belakang dari linked list. Setelah inisialisasi, program memungkinkan user untuk menambahkan elemen ke depan atau belakang linked list, serta menambahkan elemen di tengahnya. Selain itu, program juga dapat menghapus elemen dari depan, belakang, atau di tengah linked list. user juga diberikan pilihan untuk mengubah nilai dari elemen pertama, terakhir, atau di tengah linked list. Program memiliki fungsi untuk menampilkan isi linked list dan untuk menghapus seluruh isi linked list.Dengan menggunakan fungsi yang telah didefinisikan, program ini mengimplementasikan operasi dasar pada linked list seperti penghapusan, dan pengubahan elemen, serta menunjukkan bagaimana linked list berfungsi dalam praktiknya.Fungsi main() digunakan untuk mencoba fungsi-fungsi tersebut dengan menambah, menghapus, mengubah, dan menampilkan isi linked list secara berurutan. Setiap operasi diikuti dengan pemanggilan fungsi tampil() untuk menampilkan perubahan pada linked list.

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    void pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData,
                                       newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
        {
            list.deleteAll();
            break;
        }
        case 5:
        {
            list.display();
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```
Program ini merupakan implementasi dari double linked list c++.Double linked list adalah struktur data yang dimana elemen disimpan dalam sebuah node yang memilikki dua pointer,yaitu pointer prev dan next yang dimana fungsi dari pointer prev untuk menunjuk node sebelumnya dan next untuk node selanjutnya.lalu dalam program ini ada dua kelas utama yaitu 'node' dan 'DoublyLinkedList.Kelas 'node' untuk mempresentasikan node dalam double linked list.dengan atribut yaitu prev dan next.kelas 'doublylinkedlist' merupakan implementasi dari doubly linked list dan memilikki dua atribut yaitu head dan tail.Dalam fungsi main() program terdapat beberapa pilihan untuk user seperti menambahkan data,menghapus data,mengupdate data,menghapus semua data dan keluar dari program.setiap opsi akan memanggil metode yang sesuai dari objek DoublyLinkedList sesuai dengan pilihan user. Program akan terus berjalan hingga user memilih pilihan untuk keluar.

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
![Screenshot Soal Unguided 1](soalunguided1_modul3.png)
```C++
#include <iostream>

using namespace std;

struct node
{   //Deklarasi variabel
    string nama_133;
    int umur_133;
    node *next;
};
node *head; //Pointer ke node pertama
node *tail; //Pointer ke node terakhir

//Prosedur buat inisialisasi node
void inisialisasi_133()
{
    head = NULL; //Mengosongkan nilai head sama tailnya
    tail = NULL;
}

//Prosedur buat ngecek head dan tail
bool kosong_133()
{
    if (head == NULL)
    {
        return true;//Jika null maka true
    }
    else
    {
        return false;//Jika ada isinya false
    }
}

//Prosedur buat tambah depan
void TambahDepan_133(string name_133, int age_133)
{
    node *baru = new node;//Tambah node baru
    //Isi node baru
    baru->nama_133 = name_133;
    baru->umur_133 = age_133;
    baru->next = NULL;//Node berikut nya null
    if (kosong_133() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

//Prosedur tambah belakang
void TambahBelakang_133(string name_133, int age_133)
{
    node *baru = new node;//Tambah node baru
    //Isi node baru
    baru->nama_133 = name_133;
    baru->umur_133 = age_133;
    baru->next = NULL;//Node berikut nya null
    if (kosong_133() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

//Fungsi buat hitung node
int HitungNode_133()
{
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Prosedur untuk tambah tengah
void TambahTengah_133(string name_133, int age_133, int posisi_133)
{
    if (posisi_133 < 1 || posisi_133 > HitungNode_133())
    {
        cout << "Posisi node yang akan ditambahkan offside" << endl;
    }
    else if (posisi_133 == 1)
    {
        cout << "Posisi node yang akan ditambahkan bukan di tengah" << endl;
    }
    else
    {
        //tambah node baru & node bantu
        node *baru, *bantu;
        baru = new node;//buat node baru
        //isi node baru
        baru->nama_133 = name_133;
        baru->umur_133 = age_133;
        baru->next = NULL;//next nodenya NULL
        bantu = head;
        int nomor_133 = 1;//deklarasi variabel nomor_133
        while (nomor_133 < posisi_133 - 1)
        {
            bantu = bantu->next;
            nomor_133++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Prosedur buat hapus depan
void HapusDepan_133()
{
    node *hapus;//Menambahkan node hapus
    if (kosong_133() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur buat hapus belakang
void HapusBelakang_133()
{
    node *hapus;//Menambahkan node hapus
    node *bantu;//Menambahkan node bantu
    if (kosong_133() == false)
    {
        if (head != tail)
        {
            hapus = tail;//node hapus sebagai tail
            bantu = tail; //node bantu sebagai tail
            bantu = head;//node bantu sebagai head
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur buat hapus tengah
void HapusTengah_133(int posisi_133)
{
    if (posisi_133 < 1 || posisi_133 > HitungNode_133())
    {
        cout << "Posisi node yang akan dihapus offside" << endl;
    }
    else if (posisi_133 == 1)
    {
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    }
    else
    {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_133 = 1;
        while (nomor_133 <= posisi_133)
        {
            if (nomor_133 == posisi_133 - 1)
            {
                bantu2 = bantu;
            }
            else if (nomor_133 == posisi_133)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_133++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//Prosedur buat ubah head
void UbahDepan_133(string name_133, int age_133)
{
    if (kosong_133() == false)
    {
        head->nama_133 = name_133;
        head->umur_133 = age_133;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur buat ubah tail
void UbahBelakang_133(string name_133, int age_133)
{
    if (kosong_133() == false)
    {
        tail->nama_133 = name_133;
        tail->umur_133 = age_133;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//prosedur ubah node tengah
void UbahTengah_133(string name_133, int age_133, int posisi_133)
{
    node *bantu;
    if (kosong_133() == false)
    {
        if (posisi_133 < 1 || posisi_133 > HitungNode_133())
        {
            cout << "Node yang ingin diubah isinya diluar jangkauan" << endl;
        }
        else if (posisi_133 == 1)
        {
            cout << "Node yang ingin diubah isinya bukan head" << endl;
        }
        else
        {
            bantu = head;
            int nomor_133 = 1;
            while (nomor_133 < posisi_133)
            {
                nomor_133++;
                bantu = bantu->next;
            }
            bantu->nama_133 = name_133;
            bantu->umur_133 = age_133;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur buat hapus list
void HapusList_133()
{
    node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List sudah terhapus!" << endl;
}

//Prosedur agar menampilkan list
void TampilList_133()
{
    node *bantu;
    bantu = head;
    if (kosong_133() == false)
    {
        cout << "- Nama -     - umur -" << endl;
        for (int i = 0; i <= HitungNode_133() && bantu != NULL; i++)
        {
            cout << bantu->nama_133 << '\t' << '\t' << bantu->umur_133 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Fungsi Utama
int main()
{
    int Posisi_133, umur_133;
    char Yakin_133, Pilihan_133;
    string nama_133;
    Menu://Isi menu jawaban
    cout << "--- MENU JAWABAN ---" << endl;
    cout << "a. Jawab poin a" << endl;
    cout << "b. Jawab poin b" << endl;
    cout << "c. Jawab poin c" << endl;
    cout << "d. Jawab poin d" << endl;
    cout << "e. Jawab poin e" << endl;
    cout << "f. Jawab poin f" << endl;
    cout << "g. exit" << endl;
    cout << "Pilihan anda = ";
    cin >> Pilihan_133;
    cout << endl;

    switch (Pilihan_133)
    {
    case 'a':
        // Jawaban poin a
        inisialisasi_133();
        cout << "- Masukkan Data Sesuai Urutan -" << endl;
        for (int i = 1; i <= 8; i++)
        {
            cout << "Masukkan data nama ke-" << i << " = ";
            cin >> nama_133;
            cout << "Masukkan umur data ke-" << i << " = ";
            cin >> umur_133;
            TambahBelakang_133(nama_133, umur_133);
        }
        cout << endl;
        TampilList_133();
        goto Menu;
        break;
    case 'b':
        // Jawaban poin b
        cout << "--- Menghapus data 'Akechi' ---" << endl;
        cout << "Masukkan posisi data Akechi = ";
        cin >> Posisi_133;
        cout << "Apakah anda yakin ingin menghapus data 'Akechi' yang berada di posisi ke-" << Posisi_133 << "? [y/n] = ";
        cin >> Yakin_133;
        if (Yakin_133 == 'y' || Yakin_133 == 'Y')
        {
            HapusTengah_133(6);
            cout << "Data telah dihapus" << endl;
            cout << endl;
        }
        else if (Yakin_133 == 'n' || Yakin_133 == 'N')
        {
            cout << "Aksi dibatalkan" << endl;
            cout << endl;
        }
        TampilList_133();
        goto Menu;
        break;
    case 'c':
        // Jawaban poin c
        cout << "--- Tambahkan data 'Futaba, 18' diantara John dan Jane ---" << endl;
        cout << "Masukkan data nama = ";
        cin >> nama_133;
        cout << "Masukkan umur = ";
        cin >> umur_133;
        cout << "Masukkan posisi data yang ingin ditambahkan = ";
        cin >> Posisi_133;
        TambahTengah_133(nama_133, umur_133, Posisi_133);
        cout << endl;
        TampilList_133();
        goto Menu;
        break;
    case 'd':
        // Jawaban poin d
        cout << "--- Tambahkan data 'Igor, 20' diawal ---" << endl;
        cout << "Masukkan data nama = ";
        cin >> nama_133;
        cout << "Masukkan umur = ";
        cin >> umur_133;
        TambahDepan_133(nama_133, umur_133);
        cout << endl;
        TampilList_133();
        goto Menu;
        break;
    case 'e':
        // Jawaban poin e
        cout << "--- Ubah data 'Michael' menjadi 'Reyn, 18' ---" << endl;
        cout << "Masukkan nama data baru = ";
        cin >> nama_133;
        cout << "Masukkan umur = ";
        cin >> umur_133;
        cout << "Masukkan posisi data lama yang ingin diubah = ";
        cin >> Posisi_133;
        UbahTengah_133(nama_133, umur_133, Posisi_133);
        cout << endl;
        TampilList_133();
        goto Menu;
        break;
    case 'f':
        // Jawaban poin f
        cout << "--- Tampilkan Seluruh Data ---" << endl;
        TampilList_133();
        goto Menu;
        break;
    case 'g':
        // Jawaban poin g
        cout << "Anda telah keluar dari program" << endl;
        return 0;
        break;
    default:
        cout << "Pilihan yang anda masukkan tidak ada" << endl;
        goto Menu;
        break;
    }
}
```
#### Output:

##### Output Poin a
![Screenshot Output Unguided 1](outputunguided1(1).png)

##### Output Poin b
![Screenshot Output Unguided 1](outputunguided1(2).png)

##### Output Poin c
![Screenshot Output Unguided 1](outputunguided1(3).png)

##### Output Poin d
![Screenshot Output Unguided 1](outputunguided1(4).png)

##### Output Poin e
![Screenshot Output Unguided 1](outputunguided1(5).png)

##### Output Poin f
![Screenshot Output Unguided 1](outputunguided1(6).png)

Program ini merupakan implementasi single linked list pada c++.Linked list digunakan untuk menyimpan data berupa nama dan umur dalam struktur node.node memilikki dua atribut ada nama_133 untuk simpan nama dan umur_133 untuk simpan umur dan ada pointer next yang menunjuk ke node berikut nya dalam list.lalu terdapat fungsi fungsi dalam program ini ada inisialisasi_133 untuk menginisialisasi linked list dalam mengatur head dan tail menjadi NULL,lalu ada kosong_133 untuk mengecek linked listnya kosong atau tidak,TambahDepan_133 untuk menambahkan node baru di depan linked list,TambahBelakang_133 sama aja cuman bedanya dibelakang linked list,ada UbahDepan_133 untuk mengubah data di node head,UbahTengah_133 untuk mengubah node di tengah linked list pada posisi tertentu.HapusList_133 untuk menghapus seluruh linked list,ada TampilList_133 untuk menampilkan semua linked list dan ada fungsi main yang berfungsi sebagai menu utama untuk menjalankan fungsi fungsi seperti menambahkan data pada linked list,menghapus data tertentu di linked list dan keluar dari program.

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama Produk dan Harga. </br>Case:</br> ㅤ1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific</br> ㅤ2. Hapus produk Wardah</br> ㅤ3. Update produk Hanasui menjadi Cleora dengan harga 55000</br> ㅤ4. Tampilkan menu, di mana tampilan akhirnya akan menjadi seperti dibawah ini:
![Screenshot Soal Unguided 2](soalunguided2_modul3(1).png)

```C++
1. Tambah data
2. Hapus data
3. Update data
4. Tambah data urutan tertentu
5. Hapus data urutan tertentu
6. Hapus seluruh data
7. Tampilkan data
8. Exit
```
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

![Screenshot Soal Unguided 2](soalunguided2_modul3(2).png)

```C++
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
```
#### Output:

##### Output 1
![Screenshot output Unguided 2](outputunguided2(1).png)

##### Output 2
![Screenshot output Unguided 2](outputunguided2(2).png)

##### Output 3
![Screenshot output Unguided 2](outputunguided2(3).png)

##### Output 4
![Screenshot output Unguided 2](outputunguided2(4).png)

##### Output 5
![Screenshot output Unguided 2](outputunguided2(5).png)

Program ini adalah implementasi dari double linked list dalam c++.double linked list digunakan untuk menyimpan data tentang produk skincare,yang terdiri dari nama produk dan harganya.setiap node dalam program double linked list ini memilikki dua pointer yaitu prev dan next,prev buat ke node sebelumnya dan next buat ke node berikutnya.fungsi fungsi dalam program ini ada Inisialisasi_133 untuk menginisialisasi head dan tail menjadi 'nullptr'.ada TambahNode_133 yang berfungsi sebagai prosedur untuk menambahkan node baru ke dalam linked list,node bisa ditambahkan di posisi tertentu dalam parameter 'posisi'.ada HapusNode_133 yaitu prosedur untuk menghapus node dari posisi linked list tertentu.lalu ada TampilData_133 yaitu prosedur untuk menampilkan seluruh data yang tersimpan dalam linked list dan masih banyak lagi.Fungsi main digunakan sebagai menu utama agar user dapat melakukan operasi linked list yang diinginkan yaitu Menambah data,Menghapus data,Mengupdate data,Menghapus data pada posisi tertentu,Menghapus semua produk,Menampilkan seluruh data produk skincare dan Keluar dari program,setiap operasi diimplementasikan melalui Menu switch case yang meminta input dari user sesuai dengan pilihan yang ada. Program kemudian akan memanggil fungsi yang sesuai berdasarkan pilihan user.

## Kesimpulan
Linked list adalah salah satu struktur data dalam bahasa pemrograman c++ yang memungkinkan pengelolaan data secara dinamis.Linked list memilikki keunggulan di fleksibilitasnya yang memungkinkan penambahan dan penghapusan elemen dengan cepat dan efisien.ini berarti linked list cocok digunakan dimana elemen dapat berubah secara dinamis.linked list memilikki 3 jenis ada single linked list,double linked list dan circular linked list dan masing masing dari 3 jenis itu memilikki fungsinya masing masing.linked list wajib dipelajari karena dapat memudahkan programmer dalam membuat keputusan yang tepat dalam memilih struktur data yang sesuai untuk kebutuhan aplikasi mereka.

## Referensi
[1] A. Sindar, STRUKTUR DATA Dan Algoritma DENGAN C++, 2018.
[2] Triase, Triase. "Struktur Data: Diktat Edisi Revisi." (2020).
