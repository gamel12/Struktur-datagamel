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

Simpul* pencarianLinear(Simpul* kepala, int kunci) {
    Simpul* sekarang = kepala;
    int posisi = 1;
    
    cout << "\nProses Pencarian:" << endl;
    
    while (sekarang != nullptr) {
        cout << "Memeriksa node " << posisi << ": " << sekarang->data;
        
        if (sekarang->data == kunci) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return sekarang;
        }
        
        cout << " (tidak sama)" << endl;
        sekarang = sekarang->berikutnya;
        posisi++;
    }
    
    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

int main() {
    Simpul* kepala = nullptr;
    int n, nilai, cari;
    
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    cout << "Masukkan jumlah elemen (minimal 3): ";
    cin >> n;
    
    cout << "Masukkan " << n << " elemen:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << (i+1) << ": ";
        cin >> nilai;
        tambah(kepala, nilai);
    }
    
    tampilkanList(kepala);
    
    cout << "Mencari nilai: ";
    cin >> cari;
    
    Simpul* hasil = pencarianLinear(kepala, cari);
    
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
    
    hasil = pencarianLinear(kepala, cari);
    
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
