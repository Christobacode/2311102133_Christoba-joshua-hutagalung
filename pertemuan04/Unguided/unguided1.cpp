#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_133;
    string NIM_133;
    node *next;
};
node *head;
node *tail;

//Inisialisasi node head & tail
void Inisialisasi_133(){
    head = NULL;
    tail = NULL;
}

//fungsi pengecekan
bool isEmpty_133(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//prosedur hitung node
int HitungNode_133(){
    node *hitung = head;
    int jumlah_133 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_133++;
    }
    return jumlah_133;
}

//prosedur tambah depan
void TambahDepan_133(string Name_133, string NIM_133){
    node *baru = new node;
    baru->Nama_133 = Name_133;
    baru->NIM_133 = NIM_133;
    baru->next = NULL;
    if(isEmpty_133() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//prosedur tambah tengah
void TambahTengah_133(string Name_133, string NIM_133, int Position_133){
    if(Position_133 < 1 || Position_133 > HitungNode_133() + 1){ 
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_133 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_133 = Name_133;
        baru->NIM_133 = NIM_133;
        int hitung_133 = 1;
        while(hitung_133 < Position_133 - 1){
            bantu = bantu->next;
            hitung_133++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//prosedur hapus depan
void HapusDepan_133(){
    node *hapus;
    if(isEmpty_133() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data depan
string TampilDepan_133(){
    string NamaYangDihapus_133 = "";
    if(isEmpty_133() == false){
        NamaYangDihapus_133 = head->Nama_133;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_133;
}

//prosedur hapus belakang
void HapusBelakang_133(){
    node *hapus, *bantu;
    if(isEmpty_133() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

// prosedur tambah belakang
void TambahBelakang_133(string Name_133, string NIM_133) {
    node *baru = new node;
    baru->Nama_133 = Name_133;
    baru->NIM_133 = NIM_133;
    baru->next = NULL; // inisialisasi next pointer ke NULL
    if (isEmpty_133() == true) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru; // Mengubah pointer tail untuk menunjuk pada elemen terakhir yang baru
    }
}

//prosedur hapus tengah
void HapusTengah_133(int posisi_133){
    if(posisi_133 < 1 || posisi_133 > HitungNode_133()){ 
        cout << "Posisi node yang akan dihapus offside" << endl;
    } else if(posisi_133 == 1){
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_133 = 1;
        while(nomor_133 <= posisi_133){
            if(nomor_133 == posisi_133 - 1){
                bantu2 = bantu;
            } else if(nomor_133 == posisi_133){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_133++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//fungsi tampil data tengah
string TampilTengah_133(int Position_133){
    string NamaYangDihapus_133 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_133() == false){
        int nomor_133 = 1;
        while (nomor_133 <= Position_133 - 1){
            if(nomor_133 == Position_133 - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_133++;
        }
        bantu->next = tampil;
        NamaYangDihapus_133 = tampil->Nama_133;       
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_133;
}

//prosedur Ubah depan
void UbahDepan_133(string NewName_133, string NewNIM_133){
    if(isEmpty_133() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_133 = NewName_133;
        head->NIM_133 = NewNIM_133;
    }
}

//prosedur ubah belakang
void UbahBelakang_133(string NewName_133, string NewNIM_133){
    if(isEmpty_133() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_133 = NewName_133;
        tail->NIM_133 = NewNIM_133;
    }
}

//prosedur ubah tengah
void UbahTengah_133(string NewName_133, string NewNIM_133, int Position_133){
    if(isEmpty_133() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(Position_133 < 1 || Position_133 > HitungNode_133()){
            cout << "Node yang ingin diubah diluar jangkauan!" << endl;
        } else if(Position_133 == 1){
            cout << "Node yang ingin diubah bukan ditengah!" << endl;
        } else {
            node *bantu;
            bantu = head;
            int nomor_133 = 1;
            while(nomor_133 < Position_133){
                bantu = bantu->next;
                nomor_133++;
            }
           bantu->Nama_133 = NewName_133;
           bantu->NIM_133 = NewNIM_133;
        }
    }
}

//prosedur hapus list
void HapusList_133(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_133() == true){
        cout << "List masih kosong!" << endl;
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

// fungsi tampil list
void TampilList_133() {
    if (isEmpty_133()) {
        cout << "List masih kosong!" << endl;
    } else {
        node *bantu = head;
        cout << "------------------------------------------" << endl;
        cout << "|         NAMA         |       NIM       |" << endl;
        cout << "------------------------------------------" << endl;
        while (bantu != NULL) {
            cout << "|" << setw(22) << left << bantu->Nama_133 << "|" << setw(17) << left << bantu->NIM_133 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------" << endl;
    }
}

int main(){
    int Position_133, Choose_133;
    string Nama_133, Namalama_133, NIM_133, Nimlama_133;
    char Yakin_133;
    Inisialisasi_133();
    Menu:
    //Menu Program linked list
    cout << "------- PROGRAM SINGLE LINKED LIST -------" << endl;
    cout << "-------------- NON-CIRCULAR --------------" << endl; 
    cout << "| 1. TAMBAH DEPAN                        |" << endl;
    cout << "| Menambahkan data pada awal list        |" << endl;
    cout << "| 2. TAMBAH BELAKANG                     |" << endl;
    cout << "| Menambahkan data pada akhir list       |" << endl;
    cout << "| 3. TAMBAH TENGAH                       |" << endl;
    cout << "| Menambahkan data pada urutan tertentu  |" << endl;
    cout << "| 4. UBAH DEPAN                          |" << endl;
    cout << "| Mengubah data pada urutan pertama      |" << endl;
    cout << "| 5. UBAH BELAKANG                       |" << endl;
    cout << "| Mengubah data pada urutan terakhir     |" << endl;
    cout << "| 6. UBAH TENGAH                         |" << endl;
    cout << "| Mengubah data pada urutan tertentu     |" << endl;
    cout << "| 7. HAPUS DEPAN                         |" << endl;
    cout << "| Menghapus data urutan pertama          |" << endl;
    cout << "| 8. HAPUS BELAKANG                      |" << endl;
    cout << "| Menghapus data urutan terakhir         |" << endl;
    cout << "| 9. HAPUS TENGAH                        |" << endl;
    cout << "| Menghapus data urutan tertentu         |" << endl;
    cout << "| 10. HAPUS LIST                         |" << endl;
    cout << "| Menghapus seluruh data                 |" << endl;
    cout << "| 11. TAMPILKAN                          |" << endl;
    cout << "| Menampilkan list data yang tersimpan   |" << endl;
    cout << "| 0. KELUAR                              |" << endl;
    cout << "| Keluar dari program                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> Choose_133;
    cout << endl;
    switch(Choose_133){
        case 1:
            //Tambah depan pada list
            cout << "-------------- TAMBAH DEPAN --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Nama_133;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_133;
            TambahDepan_133(Nama_133, NIM_133);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto Menu;
            break;
        case 2:
            //Tambah belakang pada list
            cout << "------------ TAMBAH BELAKANG -------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Nama_133;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_133;
            TambahBelakang_133(Nama_133, NIM_133);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto Menu;
            break;
        case 3:
            //Tambah tengah pada list
            cout << "------------- TAMBAH TENGAH --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Nama_133;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_133;
            cout << "Posisi data = ";
            cin >> Position_133;
            TambahTengah_133(Nama_133, NIM_133, Position_133);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto Menu;
            break;
        case 4:
            //Ubah depan pada list
            cout << "----------------- UBAH DEPAN -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> Namalama_133;
            cout << "NIM Mahasiswa lama = ";
            cin >> Nimlama_133;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama Mahasiswa baru = ";
            cin >> Nama_133;
            cout << "NIM Mahasiswa baru = ";
            cin >> NIM_133;
            UbahDepan_133(Nama_133, NIM_133);
            cout << "Data berhasil diubah" << endl;
            cout << endl;
            goto Menu;
            break;
        case 5:
            //Ubah belakang pada list
            cout << "---------------- UBAH BELAKANG ----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> Namalama_133;
            cout << "NIM Mahasiswa lama = ";
            cin >> Nimlama_133;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama Mahasiswa baru = ";
            cin >> Nama_133;
            cout << "NIM Mahasiswa baru = ";
            cin >> NIM_133;
            UbahBelakang_133(Nama_133, NIM_133);
            cout << "Data berhasil diubah" << endl;
            cout << endl;
            goto Menu;
            break;
        case 6:
            //Ubah tengah pada list
            cout << "----------------- UBAH TENGAH -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> Namalama_133;
            cout << "NIM Mahasiswa lama = ";
            cin >> Nimlama_133;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama Mahasiswa baru = ";
            cin >> Nama_133;
            cout << "NIM Mahasiswa baru = ";
            cin >> NIM_133;
            cout << "Posisi data = ";
            cin >> Position_133;
            UbahTengah_133(Nama_133, NIM_133, Position_133);
            cout << "Data berhasil diubah" << endl;
            cout << endl;
            goto Menu;
            break;
        case 7:
            //Hapus depan pada list
            cout << "-------------- HAPUS DEPAN --------------" << endl;
            cout << "Apakah anda yakin ingin menghapus data pertama (Y/N)? ";
            cin >> Yakin_133;
            if(Yakin_133 == 'Y' || Yakin_133 == 'y'){
                HapusDepan_133();
                cout << "Data berhasil dihapus" << endl;
            }
            cout << endl;
            goto Menu;
            break;
        case 8:
            //Hapus belakang pada list
            cout << "------------- HAPUS BELAKANG -------------" << endl;
            cout << "Apakah anda yakin ingin menghapus data terakhir (Y/N)? ";
            cin >> Yakin_133;
            if(Yakin_133 == 'Y' || Yakin_133 == 'y'){
                HapusBelakang_133();
                cout << "Data berhasil dihapus" << endl;
            }
            cout << endl;
            goto Menu;
            break;
        case 9:
            //Hapus tengah pada list
            cout << "------------- HAPUS TENGAH -------------" << endl;
            cout << "Apakah anda yakin ingin menghapus data tertentu (Y/N)? ";
            cin >> Yakin_133;
            if(Yakin_133 == 'Y' || Yakin_133 == 'y'){
                cout << "Posisi data yang akan dihapus = ";
                cin >> Position_133;
                HapusTengah_133(Position_133);
                cout << "Data berhasil dihapus" << endl;
            }
            cout << endl;
            goto Menu;
            break;
        case 10:
            //Hapus semua data pada list
            cout << "------------- HAPUS LIST -------------" << endl;
            cout << "Apakah anda yakin ingin menghapus semua data (Y/N)? ";
            cin >> Yakin_133;
            if(Yakin_133 == 'Y' || Yakin_133 == 'y'){
                HapusList_133();
                cout << "Seluruh data berhasil dihapus" << endl;
            }
            cout << endl;
            goto Menu;
            break;
        case 11:
            //Menampilkan semua data pada list
            cout << "------------- TAMPIL LIST ------------" << endl;
            TampilList_133();
            cout << endl;
            goto Menu;
            break;
        case 0:
            //Keluar dari program
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            cout << endl;
            goto Menu;
            break;
    }
    return 0;
}