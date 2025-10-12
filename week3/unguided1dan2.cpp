#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    int uts;
    int uas;
    int tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(int uts, int uas, int tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void tampilkanMahasiswa(Mahasiswa mhs[], int jumlah) {
    cout << "\n===== DATA MAHASISWA =====\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << ":\n";
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
}

void soal1() {
    cout << "\n========== SOAL 1: DATA MAHASISWA ==========\n";
    
    Mahasiswa dataMahasiswa[10];
    int jumlahMhs;
    
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlahMhs;
    
    if (jumlahMhs > 10 || jumlahMhs < 1) {
        cout << "Jumlah mahasiswa harus antara 1-10!\n";
        return;
    }
    
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\n--- Data Mahasiswa ke-" << (i + 1) << " ---\n";
        cin.ignore();
        cout << "Nama   : ";
        getline(cin, dataMahasiswa[i].nama);
        cout << "NIM    : ";
        getline(cin, dataMahasiswa[i].nim);
        cout << "UTS    : ";
        cin >> dataMahasiswa[i].uts;
        cout << "UAS    : ";
        cin >> dataMahasiswa[i].uas;
        cout << "Tugas  : ";
        cin >> dataMahasiswa[i].tugas;
        
        dataMahasiswa[i].nilaiAkhir = hitungNilaiAkhir(
            dataMahasiswa[i].uts, 
            dataMahasiswa[i].uas, 
            dataMahasiswa[i].tugas
        );
    }
    
    tampilkanMahasiswa(dataMahasiswa, jumlahMhs);
}

struct Pelajaran {
    string namapel;
    string kodepel;
};

Pelajaran create_pelajaran(string nama, string kode) {
    Pelajaran pel;
    pel.namapel = nama;
    pel.kodepel = kode;
    return pel;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "nama pelajaran : " << pel.namapel << endl;
    cout << "nilai : " << pel.kodepel << endl;
}

void soal2() {
    cout << "\n========== SOAL 2: ADT PELAJARAN ==========\n";
    
    string namapel = "Struktur Data";
    string kodepel = "STD";
    
    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
}

int main() {
    int pilihan;
    
    do {
        cout << "\n========================================\n";
        cout << "       MENU PROGRAM UNGUIDED 1 & 2\n";
        cout << "========================================\n";
        cout << "1. Soal 1 - Data Mahasiswa (Array)\n";
        cout << "2. Soal 2 - ADT Pelajaran\n";
        cout << "0. Keluar\n";
        cout << "========================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                soal1();
                break;
            case 2:
                soal2();
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 0);
    
    return 0;
}
