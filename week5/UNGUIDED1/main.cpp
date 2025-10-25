#include <iostream>
using namespace std;

struct Simpul {
    int data;
    Simpul* berikutnya;
};

void tambah(Simpul*& kepala, int nilai) {
    Simpul* simpulBaru = new Simpul();
    simpulBaru->data = nilai;
    simpulBaru->berikutnya = nullptr;
    
    if (kepala == nullptr) {
        kepala = simpulBaru;
        return;
    }
    
    Simpul* temp = kepala;
    while (temp->berikutnya != nullptr) {
        temp = temp->berikutnya;
    }
    temp->berikutnya = simpulBaru;
}

void tampilkanList(Simpul* kepala) {
    Simpul* temp = kepala;
    cout << "Linked List yang dibuat: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->berikutnya != nullptr) {
            cout << " -> ";
        }
        temp = temp->berikutnya;
    }
    cout << " -> NULL" << endl;
}

int dapatkanPanjang(Simpul* kepala) {
    int hitung = 0;
    Simpul* temp = kepala;
    while (temp != nullptr) {
        hitung++;
        temp = temp->berikutnya;
    }
    return hitung;
}

Simpul* dapatkanSimpulPada(Simpul* kepala, int indeks) {
    Simpul* temp = kepala;
    for (int i = 0; i < indeks && temp != nullptr; i++) {
        temp = temp->berikutnya;
    }
    return temp;
}

Simpul* pencarianBiner(Simpul* kepala, int kunci) {
    int kiri = 0;
    int kanan = dapatkanPanjang(kepala) - 1;
    int iterasi = 1;
    
    cout << "\nProses Pencarian:" << endl;
    
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        Simpul* simpulTengah = dapatkanSimpulPada(kepala, tengah);
        
        cout << "Iterasi " << iterasi << ": Mid = " << simpulTengah->data 
             << " (indeks tengah)";
        
        if (simpulTengah->data == kunci) {
            cout << " - DITEMUKAN!" << endl;
            return simpulTengah;
        }
        else if (simpulTengah->data < kunci) {
            cout << " -> Cari di bagian kanan" << endl;
            kiri = tengah + 1;
        }
        else {
            cout << " -> Cari di bagian kiri" << endl;
            kanan = tengah - 1;
        }
        
        iterasi++;
    }
    
    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}

int main() {
    Simpul* kepala = nullptr;
    int n, nilai, cari;
    
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    cout << "Masukkan jumlah elemen (minimal 5): ";
    cin >> n;
    
    cout << "Masukkan " << n << " elemen (harus terurut/ascending):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << (i+1) << ": ";
        cin >> nilai;
        tambah(kepala, nilai);
    }
    
    tampilkanList(kepala);
    
    cout << "Mencari nilai: ";
    cin >> cari;
    
    Simpul* hasil = pencarianBiner(kepala, cari);
    
    cout << endl;
    if (hasil != nullptr) {
        cout << "Hasil: Nilai " << cari << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node: " << hasil->data << endl;
        cout << "Node berikutnya: " << hasil->berikutnya << endl;
    } else {
        cout << "Hasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
    
    cout << "\nMencari nilai: ";
    cin >> cari;
    
    hasil = pencarianBiner(kepala, cari);
    
    cout << endl;
    if (hasil != nullptr) {
        cout << "Hasil: Nilai " << cari << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node: " << hasil->data << endl;
        cout << "Node berikutnya: " << hasil->berikutnya << endl;
    } else {
        cout << "Hasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
    
    return 0;
}
