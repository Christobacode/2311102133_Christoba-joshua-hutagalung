# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE</h1>
<p align="center">Christoba Joshua Hutagalung - 2311102133</p>

## Dasar Teori
Queue disebut juga antrian dimana data masuk di satu sisi dan keluar di sisi yang lain. Karena itu, queue bersifat FIFO (First In First Out). Antrian (Queue) merupakan suatu kumpulan data yang penambahan elemennya (masuk antrian) hanya bisa dilakukan pada suatu ujung (disebut dengan sisi belakang/rear) atau disebut juga enqueue yaitu apabila seseorang masuk ke dalam sebuah antrian. Jika seseorang keluar dari antrian/penghapusan (pengambilan elemen) dilakukan lewat ujung yang lain (disebut dengan sisi depan/front) atau disebut juga dequeue yaitu apabila seseorang keluar dari antrian.Antrian menggunakan prinsip “masuk pertama keluar pertama” atau disebut juga dengan prinsip FIFO (first in first out). Dengan kata lain, urutan keluar akan sama dengan urutan masuknya. Contoh: antrian mobil saat membeli karcis di pintu jalan tol, antrian di bioskop, dan sebagainya.

## Operasi / Prosedur Standar pada Queue / Antrian

QUEUE merupakan struktur data dinamis, ketika program dijalankan, jumlah elemennya dapat berubah secara dinamis sesuai keperluan. Berikut ini operasi-operasi standar pada queue:

- a. **Inisialisasi**: Proses untuk membuat queue pada kondisi awal, yaitu queue yang masih kosong (belum mempunyai elemen).

- b. **InQueue** (Insert Queue): Prosedur untuk memasukkan sebuah elemen baru pada queue. Jumlah elemen Queue akan bertambah satu dan elemen tersebut merupakan elemen belakang.

- c. **DeQueue** (Delete Queue): Prosedur untuk menghapus/mengambil sebuah elemen dari queue. Elemen yang diambil adalah elemen depan dan jumlah elemen queue akan berkurang satu.

Operasi-operasi yang berhubungan dengan jumlah elemen suatu queue adalah:

1. **Size**: Operasi untuk mendapatkan banyaknya elemen queue.

2. **Empty**: Prosedur untuk mengetahui apakah queue dalam keadaan kosong atau tidak. Dengan status ini maka dapat dicegah dilakukannya operasi Dequeue dari suatu queue yang kosong.

3. **Full**: Prosedur untuk mengetahui apakah Queue penuh atau tidak. Prosedur ini hanya berlaku untuk queue yang jumlahnya terbatas.

## Pendeklarasian queue
```c
//deklarasi queue dengan struct dan array
struct QUEUE
{
 int data[5];
 int head;
 int tail;
};
//deklarasi variabel antrian dari struct
QUEUE antrian;
```

## Guided 

### 1. Guided 1
```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;  // Maksimal antrian
int front = 0;                // Penanda antrian
int back = 0;                 // Penanda
string queueTeller[5];        // Fungsi pengecekan

bool isFull() {               // Pengecekan antrian penuh atau tidak
  if (back == maksimalQueue) {
    return true;  // =1
  } else {
    return false;
  }
}

bool isEmpty() {  // Antriannya kosong atau tidak
  if (back == 0) {
    return true;
  } else {
    return false;
  }
}

void enqueueAntrian(string data) {  // Fungsi menambahkan antrian
  if (isFull()) {
    cout << "Antrian penuh" << endl;
  } else {
    if (isEmpty()) {  // Kondisi ketika queue kosong
      queueTeller[0] = data;
      front++;
      back++;
    } else {  // Antrianya ada isi
      queueTeller[back] = data;
      back++;
    }
  }
}

void dequeueAntrian() {  // Fungsi mengurangi antrian
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    for (int i = 0; i < back; i++) {
      queueTeller[i] = queueTeller[i + 1];
    }
    back--;
  }
}

int countQueue() {  // Fungsi menghitung banyak antrian
  return back;
}

void clearQueue() {  // Fungsi menghapus semua antrian
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    for (int i = 0; i < back; i++) {
      queueTeller[i] = "";
    }
    back = 0;
    front = 0;
  }
}

void viewQueue() {  // Fungsi melihat antrian
  cout << "Data antrian teller:" << endl;
  for (int i = 0; i < maksimalQueue; i++) {
    if (queueTeller[i] != "") {
      cout << i + 1 << ". " << queueTeller[i] << endl;
    } else {
      cout << i + 1 << ". (kosong)" << endl;
    }
  }
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  return 0;
}
```
Program ini adalah contoh dari struktur data antrian atau queue di c++.queue ini dibuat untuk simulasi antrian seperti loket teller yang dimana pelanggan ditambahkan ke dalam antrian dan kemudian dilayani berdasarkan nomor urut antrian mereka.berikut ini adalah fungsi fungsi dan penjelasan pada fungsi pada program diatas:
- 'isFull()': Fungsi ini memeriksa apakah antrian sudah penuh atau belum dengan cara membandingkan setiap nilai variabel back dengan maksimalQueue. Jika nilai back sama dengan maksimalQueue maka antrian dianggap penuh.
- 'isEmpty()': Fungsi ini memeriksa apakah antrian kosong atau tidak dengan cara memeriksa apakah nilai back sama dengan 0.
- 'enqueueAntrian(string data)': Fungsi ini digunakan untuk menambahkan data pelanggan ke dalam antrian. Jika antrian nya sudah penuh, program akan menampilkan pesan kepada pelanggan "Antrian penuh". Jika antrian masih ada ruang maka data pelanggan akan ditambahkan ke posisi belakang antrian (queueTeller[back]) dan nilai back akan dinaikkan.
- 'dequeueAntrian()': Fungsi ini menghapus data pelanggan dari depan antrian. Jika antrian kosong maka program akan menampilkan pesan "Antrian kosong". Jika tidak, data pada setiap elemen antrian akan digeser ke depan dan nilai back akan dikurangi.
- 'countQueue()': Fungsi ini mengembalikan jumlah pelanggan dalam antrian dengan cara mengembalikan nilai variabel back.
- 'clearQueue()': Fungsi ini menghapus semua data yang ada di dalam antrian. Semua elemen dalam array queueTeller akan diubah menjadi string kosong dan nilai back serta front akan diatur kembali menjadi 0.
- 'viewQueue()': Fungsi ini menampilkan data pelanggan dalam antrian. Jika suatu posisi dalam antrian kosong maka akan ditampilkan "(kosong)".

berikutnya,didalam fungsi main() beberapa operasi antrian dijalankan untuk menguji fungsionalitas dari program. Pertama, dua pelanggan ditambahkan ke dalam antrian menggunakan fungsi enqueueAntrian(), lalu antrian ditampilkan dengan menggunakan viewQueue() dan jumlah antrian dicetak menggunakan countQueue(). Selanjutnya, satu pelanggan dihapus dari depan antrian menggunakan dequeueAntrian(), dan operasi yang sama diulang untuk melihat hasilnya. Terakhir, semua data dalam antrian dihapus menggunakan clearQueue() dan antrian ditampilkan kembali.

## Unguided 

### 1.  Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list.
```C++
```
#### Output:

### 2.  Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa.
```C++
```
#### Output:

## Kesimpulan


## Referensi
[1] A. S. R. St. MTi, STRUKTUR DATA DAN ALGORITMA DENGAN C++. CV. AA. RIZKY, 2019. [Online]. Available: http://books.google.ie/books?id=GP_ADwAAQBAJ&pg=PR4&dq=978-623-7411-56-7&hl=&cd=1&source=gbs_api<br>
[2] Triase, Triase. "Struktur Data: Diktat Edisi Revisi." (2020). [Online]. Available: http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf
