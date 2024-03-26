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
