/*
oleh Christoba Joshua Hutagalung - 2311102133
*/
// Unguided 2 program struct dan class
#include <iostream>

using namespace std;

// Struct datapribadi_2133 yang berisi data nama dan alamat string dan umur int
struct datapribadi_2133 {
    string Nama_2133;
    int Umur_2133;
};

// Class Gamefavorit_2133 yang berisi data Nama game string, Tahun rilis int, Harga game int dan Rating int dalam akses public
class Gamefavorit_2133 {
  public:
    string Namagame_2133;
    int Tahunrilis_2133;
    int Hargagame_2133;
    int Rating_2133;
};

int main() {
    cout << "Program deklarasi class dan struct" << endl;

    // Deklarasi Struct datapribadi_2133
    datapribadi_2133 data{"Christoba joshua hutagalung", 19};// inisialisasi nilai Nama_2133 dan Umur_2133
    cout << "\n- Biografi - " << endl;
    cout << "Nama: " << data.Nama_2133 << endl;/**/
    cout << "Umur: " << data.Umur_2133 << endl;
    //Kode cout Nama dan Umur diatas adalah untuk mencetak isi nilai dari variabel data yang menyimpan nama christoba joshua hutagalung dengan umur 19 tahun

    // Deklarasi Class Gamefavorit_2133
    Gamefavorit_2133 Game;
    Game.Namagame_2133 = "Helldivers 2";//inisialisasi nilai Namagame_2133
    Game.Tahunrilis_2133 = 2024;//inisialisasi nilai Tahunrilis_2133
    Game.Hargagame_2133 = 579000;//inisialisasi nilai Hargagame_2133
    Game.Rating_2133 = 9;// inisialisasi nilai Rating_2133
    cout << "\n- Game Favorit -" << endl;
    cout << "Nama game : " << Game.Namagame_2133 << endl;
    cout << "Tahun rilis : " << Game.Tahunrilis_2133 << endl;
    cout << "Harga game : " << Game.Hargagame_2133 << endl;
    cout << "Rating : " << Game.Rating_2133 << endl; 
    /*Bagian mulai dari cout << "\n- Game Favorit -" << endl; sampai cout << "Rating : " << Game.Rating_2133 << endl; adalah cetak output dari nilai
    Namagame_2133,Tahunrilis_2133,Hargagame_2133 dan Rating_2133
    */
    return 0;
}
