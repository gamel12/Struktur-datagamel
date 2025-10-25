# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Muhammad Gamel Al Ghifari - 103112400028</p>

## Dasar Teori

### Singly Linked List

Singly Linked List adalah struktur data linear dinamis yang terdiri dari node-node yang saling terhubung melalui pointer. Setiap node memiliki dua komponen: data dan pointer next yang menunjuk ke node berikutnya. Node terakhir menunjuk ke NULL sebagai penanda akhir list. Keunggulan utamanya adalah alokasi memori dinamis dan efisiensi operasi insert/delete di awal list.

Singly Linked List adalah struktur data linear dinamis yang terdiri dari node-node yang saling terhubung melalui pointer. Setiap node memiliki dua komponen: data dan pointer next yang menunjuk ke node berikutnya. Node terakhir menunjuk ke NULL sebagai penanda akhir list. Keunggulan utamanya adalah alokasi memori dinamis dan efisiensi operasi insert/delete di awal list.

#### Operasi Dasar

**1. Insert Operations**
- insertFirst(): Menambahkan node di awal list
- insertLast(): Menambahkan node di akhir list  
- insertAfter(): Menambahkan node setelah node tertentu

**2. Delete Operations**
- delFirst(): Menghapus node pertama
- delLast(): Menghapus node terakhir
- delAfter(): Menghapus node setelah node tertentu

**3. Update Operations**
- updateFirst(): Mengubah data node pertama
- updateLast(): Mengubah data node terakhir
- updateAfter(): Mengubah data node setelah node tertentu

**4. Search Operations**
- Linear Search: Pencarian sekuensial O(n)
- Binary Search: Pencarian divide-and-conquer, memerlukan data terurut

#### Algoritma Pencarian

**Linear Search**
- Memeriksa setiap elemen secara berurutan dari awal hingga akhir
- Tidak memerlukan data terurut
- Kompleksitas: O(n)
- Cocok untuk data kecil atau tidak terurut

**Binary Search**  
- Membagi list menjadi dua bagian dan mencari di bagian yang sesuai
- Memerlukan data terurut (sorted)
- Kompleksitas pada array: O(log n)
- Kompleksitas pada linked list: O(n log n) karena akses node memerlukan traversal

#### Manajemen Memori

Linked list menggunakan alokasi memori dinamis dengan operator `new` untuk membuat node dan `delete` untuk menghapus node. Manajemen memori yang baik penting untuk mencegah memory leak.

---

## Guided

### 1. Linked List Buah dengan Operasi Insert dan Update

Program ini mengimplementasikan Single Linked List untuk data buah dengan operasi insert (insertFirst, insertLast, insertAfter) dan update (updateFirst, updateLast, updateAfter).

#### main.cpp
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC,nodeD,nodeE;   
    createList(List);

    nodeA=alokasi("jeruk",100,3000);
    nodeB=alokasi("apel",75,4000);
    nodeC=alokasi("pir",87,5000);
    nodeD=alokasi("semangka",43,11500); 
    nodeE=alokasi("durian",15,31450);

    insertFirst(List,nodeA);
    insertLast(List,nodeB);
    insertAfter(List,nodeC,nodeA);
    insertAfter(List,nodeD,nodeC);
    insertLast(List,nodeE);

    cout<<" isi list buat dilakukan insert"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List,nodeD);

    cout<<" isi list buah setelah dilakukan update"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    return 0;
}   
```

#### listbuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
typedef buah dataBuah;
typedef struct node *address;
struct node{
    dataBuah isidata;
    address next;
};

struct linkedList{
    address first;
};

bool listEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(linkedList &List, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void delLast(linkedList &List);
void deleteAfter(address &List, address &nodehapus, address nodeprev);
int nbList(linkedList List);
void deletelist(linkedList &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif
```

#### listbuah.cpp
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " 
                 << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//Materi Modul 5 - Update Operations
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

**Penjelasan Program:**

Program mengimplementasikan Single Linked List untuk data buah dengan operasi insert dan update.

**Komponen:**
- Struct buah: nama (string), jumlah (int), harga (float)
- Operasi Insert: insertFirst(), insertLast(), insertAfter()
- Operasi Update: updateFirst(), updateLast(), updateAfter()

**Alur:** Membuat 5 node buah, melakukan insert dengan berbagai posisi, kemudian update pada node pertama, terakhir, dan setelah node tertentu.

---

### 2. Linear Search pada Linked List

Program ini mengimplementasikan algoritma Linear Search untuk mencari elemen dalam Single Linked List:

#### linear.cpp
```C++
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

Node *linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```

**Penjelasan Program:**

Program mengimplementasikan Linear Search pada Linked List untuk mencari elemen secara sekuensial.

**Fungsi Utama:**
- linearSearch(): Mencari elemen dengan memeriksa setiap node dari awal hingga akhir
- append(): Menambahkan node di akhir list
- Kompleksitas: O(n)

**Karakteristik:** Tidak memerlukan data terurut, sederhana, cocok untuk data kecil.

---

## Unguided 

### 1. Binary Search pada Linked List

Program ini mengimplementasikan algoritma **Binary Search** pada struktur data **Linked List** untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list terurut
3. Menampilkan detail proses pencarian dan hasil akhir

#### main.cpp
```C++
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
```

#### Penjelasan Program:

Program mengimplementasikan Binary Search pada Linked List untuk mencari elemen dengan metode divide and conquer.

**Fungsi Utama:**
- append(): Menambahkan node di akhir list
- displayList(): Menampilkan isi linked list
- getLength(): Menghitung jumlah node
- getNodeAt(): Mengambil node pada indeks tertentu
- binarySearch(): Mencari elemen dengan membagi list menjadi dua bagian

**Algoritma Binary Search:**
- Inisialisasi left = 0, right = panjang - 1
- Loop: hitung mid, ambil node tengah
- Jika nilai sama dengan key: return node
- Jika nilai < key: cari di kanan (left = mid + 1)
- Jika nilai > key: cari di kiri (right = mid - 1)

**Karakteristik:** Memerlukan data terurut, kompleksitas O(n log n) pada linked list karena akses node memerlukan traversal.
**Karakteristik:** Memerlukan data terurut, kompleksitas O(n log n) pada linked list karena akses node memerlukan traversal.

#### Output:
![Output Program 1](https://github.com/hanif-12-01/STRUKTUR_DATA_MHANIFALFAIZ/blob/master/WEEK%205/op1.png)

---

### 2. Linear Search pada Linked List

Program ini mengimplementasikan algoritma **Linear Search** pada struktur data **Linked List** untuk mencari elemen tertentu secara sekuensial. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

#### main.cpp
```C++
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
```

#### Penjelasan Program:

Program mengimplementasikan Linear Search pada Linked List untuk mencari elemen secara sekuensial.

**Fungsi Utama:**
- tambah(): Menambahkan node di akhir list
- tampilkanList(): Menampilkan isi linked list  
- pencarianLinear(): Mencari dengan memeriksa setiap node dari awal hingga akhir

**Algoritma:** Traverse dari kepala, periksa setiap node sampai ditemukan atau sampai akhir list.

**Karakteristik:** Tidak perlu data terurut, kompleksitas O(n), cocok untuk dataset kecil.

#### Output:
![Output Program 2](https://github.com/hanif-12-01/STRUKTUR_DATA_MHANIFALFAIZ/blob/master/WEEK%205/op2.png)

---

## Kesimpulan

Praktikum ini membahas implementasi Singly Linked List dengan fokus pada operasi pencarian. Berikut poin-poin penting:

1. **Singly Linked List** adalah struktur data dinamis dengan node yang terhubung melalui pointer, memberikan fleksibilitas dalam alokasi memori.

2. **Operasi Insert dan Update** (insertFirst, insertLast, insertAfter, updateFirst, updateLast, updateAfter) memungkinkan manipulasi data di berbagai posisi linked list.

3. **Binary Search** pada linked list memiliki kompleksitas O(n log n) karena akses node memerlukan traversal. Memerlukan data terurut untuk bekerja dengan benar.

4. **Linear Search** memiliki kompleksitas O(n), tidak memerlukan data terurut, dan lebih sederhana untuk diimplementasikan. Cocok untuk dataset kecil.

5. **Trade-off** antara kedua algoritma: Binary search lebih efisien pada array terurut, namun pada linked list linear search bisa lebih praktis karena tidak perlu sorting dan overhead akses node.

6. **Manajemen memori** dengan operator `new` dan `delete` sangat penting untuk mencegah memory leak dalam implementasi linked list di C++.

7. **Modularitas kode** dengan pemisahan file header, implementation, dan main program meningkatkan maintainability dan reusability.

---

## Referensi

[1] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.

[2] Drozdek, A. (2012). *Data Structures and Algorithms in C++* (4th ed.). Cengage Learning.

[3] Malik, D. S. (2017). *C++ Programming: From Problem Analysis to Program Design* (8th ed.). Cengage Learning.

[4] Weiss, M. A. (2013). *Data Structures and Algorithm Analysis in C++* (4th ed.). Pearson Education.
