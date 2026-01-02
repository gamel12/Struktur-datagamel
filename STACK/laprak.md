# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Muhammad Gamel Al Ghifari - 103112400028</p>

## Dasar Teori

### Stack (Tumpukan)

Stack merupakan struktur data berbentuk linear yang menerapkan konsep **Last In First Out (LIFO)**, dimana data yang paling akhir masuk akan keluar terlebih dahulu [1]. Sebagai salah satu struktur data dasar dalam ilmu komputer, stack banyak dimanfaatkan untuk berbagai keperluan seperti evaluasi ekspresi matematis, pengelolaan memori program, serta implementasi algoritma backtracking [2].

Karumanchi (2016) menjelaskan bahwa stack bisa dibangun dengan dua cara utama: memakai array yang bersifat statis atau menggunakan linked list yang bersifat dinamis [1]. Stack berbasis array mempunyai ukuran yang fixed atau tetap, sementara stack yang menggunakan linked list dapat berkembang secara dinamis mengikuti kebutuhan [3].

#### Struktur Stack

Dalam stack terdapat satu titik akses yang dinamakan **top** atau puncak, yang berfungsi sebagai penunjuk elemen paling atas [1][2]. Seluruh proses penambahan (push) maupun penghapusan (pop) data berlangsung di posisi top tersebut [4]. Komponen utama dari struktur stack meliputi [2]:
- **Data/Info**: Tempat penyimpanan nilai atau informasi dari elemen
- **Top**: Indeks atau pointer yang mengindikasikan elemen teratas
- **Capacity**: Batas maksimal elemen stack (khusus implementasi array)

#### Operasi Dasar pada Stack

Pada pemrograman C++, ada sejumlah operasi fundamental yang bisa dijalankan terhadap stack [1][3][5]:

1. **Push** (Operasi Penyisipan)
   - Memasukkan elemen baru pada bagian puncak stack [1]
   - Kompleksitas waktu: O(1) - konstan [2]
   - Perlu dilakukan pengecekan apakah stack telah penuh (overflow) pada stack berbasis array [3]

2. **Pop** (Operasi Penghapusan)
   - Mengambil dan mengeluarkan elemen paling atas dari stack [1]
   - Kompleksitas waktu: O(1) - konstan [2]
   - Wajib mengecek kondisi stack kosong (underflow) sebelum proses pop dilaksanakan [3]

3. **Peek/Top** (Operasi Melihat)
   - Mengakses nilai elemen teratas tanpa mengeluarkannya dari stack [1]
   - Kompleksitas waktu: O(1) - konstan [2]
   - Bermanfaat untuk memeriksa data tanpa mengubah struktur stack [4]

4. **isEmpty** (Pengecekan Kosong)
   - Memeriksa kondisi apakah stack dalam keadaan kosong [1]
   - Menghasilkan nilai true bila top == -1 (array) atau top == NULL (linked list) [3]

5. **isFull** (Pengecekan Penuh)
   - Memeriksa kondisi apakah stack telah mencapai kapasitas maksimum (khusus array-based stack) [1]
   - Menghasilkan nilai true bila top == MAX-1 [3]

#### Implementasi Stack

**1. Stack menggunakan Array:**
```cpp
struct Stack {
    int data[MAX];
    int top;
};
```
Pendekatan ini cukup simpel dan hemat dalam pemakaian memori, akan tetapi terbatas pada ukuran yang bersifat tetap [3][5].

**2. Stack menggunakan Linked List:**
```cpp
struct Node {
    int data;
    Node* next;
};
struct Stack {
    Node* top;
};
```
Pendekatan ini menawarkan fleksibilitas lebih tinggi dengan ukuran yang dapat berubah, tetapi membutuhkan memori tambahan untuk menyimpan pointer [1][4].

#### Aplikasi Stack

Stack mempunyai beragam penggunaan penting di bidang pemrograman [1][2][5]:
- **Evaluasi dan konversi ekspresi**: Konversi dari Infix menjadi Postfix/Prefix [2]
- **Algoritma backtracking**: Penyelesaian maze, masalah N-Queen [1]
- **Pengelolaan pemanggilan fungsi**: Call stack pada program [4]
- **Operasi Undo/Redo**: Editor teks, aplikasi desain grafis [5]
- **Riwayat browser**: Fitur tombol back [2]
- **Parsing sintaks**: Compiler dan interpreter bahasa pemrograman [1]
- **Validasi kurung berpasangan**: Pemeriksaan ekspresi matematika [3]

#### Keuntungan Stack

- Operasi push dan pop memiliki kecepatan tinggi dengan kompleksitas O(1) [1][2]
- Mudah diimplementasikan dan dipahami konsepnya [3]
- Efektif untuk mengatur data yang mengikuti pola LIFO [4]
- Cocok untuk mendukung recursion dan backtracking [1]
- Manajemen memori yang rapi dan terorganisir [5]

#### Kekurangan Stack

- Akses data hanya dapat dilakukan pada elemen top (tidak mendukung random access) [2][3]
- Kapasitas terbatas pada implementasi berbasis array [1]
- Kurang efisien ketika melakukan pencarian elemen spesifik [4]
- Berisiko mengalami stack overflow apabila tidak dikelola secara tepat [5]

## Guided

### 1. GUIDED I - Stack dengan Linked List

Program ini mengimplementasikan Stack menggunakan struktur Linked List dengan operasi push, pop, update, view, dan search.

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif 
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

#### Output Guided 1:
```
Node 1 berhasil ditambahkan kedalam stack!
Node 2 berhasil ditambahkan kedalam stack!
Node 3 berhasil ditambahkan kedalam stack!
Node 4 berhasil ditambahkan kedalam stack!
Node 5 berhasil ditambahkan kedalam stack!

--- Stack setelah push ---
5 4 3 2 1

node 5 berhasil dihapus dari stack!
node 4 berhasil dihapus dari stack!

--- Stack setelah pop 2 kali ---
3 2 1

Update node poisisi ke-2
Masukkan angka : 10
Data berhasil diupdate!

Update node poisisi ke-1
Masukkan angka : 20
Data berhasil diupdate!

Posisi 4 tidak valid!

--- Stack setelah update ---
20 10 1

Mencari data 4...
Data 4 tidak ditemukan didalam stack!

Mencari data 9...
Data 9 tidak ditemukan didalam stack!
```

#### Penjelasan Program Guided 1:

Program ini membangun **Stack dengan memanfaatkan Linked List** dilengkapi berbagai operasi dasar stack.

**Struktur Data:**
- **struct node**: Memuat `dataAngka` (bilangan bulat) dan pointer `next` untuk menunjuk node selanjutnya
- **struct stack**: Memuat pointer `top` yang mengarah ke elemen paling atas stack
- **address**: Tipe data berupa pointer untuk node

**Fungsi-Fungsi Utama:**

1. **createStack(stack &listStack)**:
   - Melakukan inisialisasi stack dengan menetapkan `top = Nil` (NULL)
   - Kondisi stack kosong ditandai oleh top yang bernilai NULL

2. **isEmpty(stack listStack)**:
   - Melakukan pengecekan kondisi kosong stack dengan melihat apakah `top == Nil`
   - Mengeluarkan nilai boolean true untuk kondisi kosong, false untuk kondisi berisi

3. **alokasi(int angka)**:
   - Melakukan alokasi memori secara dinamis untuk membuat node baru dengan operator `new`
   - Mengisi field `dataAngka` sesuai nilai parameter yang diberikan
   - Melakukan inisialisasi `next` dengan nilai Nil
   - Menghasilkan alamat dari node yang baru dibuat

4. **push(stack &listStack, address nodeBaru)**:
   - Memasukkan node baru ke bagian puncak stack (prinsip LIFO)
   - Node baru akan dihubungkan ke top yang lama
   - Pointer top diperbarui agar mengarah ke node baru
   - Kompleksitas waktu yang dibutuhkan: O(1)

5. **pop(stack &listStack)**:
   - Mengeluarkan elemen yang berada di posisi teratas stack
   - Melakukan pengecekan kondisi kosong stack sebelum pop dijalankan (mencegah underflow)
   - Menggeser pointer top menuju node selanjutnya
   - Melakukan dealokasi memori untuk node yang telah dihapus
   - Kompleksitas waktu yang dibutuhkan: O(1)

6. **update(stack &listStack, int posisi)**:
   - Melakukan pembaruan nilai node di posisi tertentu (dihitung dari top)
   - Melakukan penelusuran dari top sampai mencapai posisi yang ditentukan
   - Meminta user memasukkan nilai baru
   - Validasi: memeriksa kevalidan posisi dan memastikan stack tidak kosong

7. **view(stack listStack)**:
   - Memperlihatkan seluruh isi stack mulai dari top hingga bottom
   - Melakukan penelusuran dengan menggunakan pointer bantuan
   - Menampilkan data sesuai urutan LIFO (Last In First Out)

8. **searchData(stack listStack, int data)**:
   - Melakukan pencarian nilai tertentu di dalam stack
   - Melakukan penelusuran linear mulai dari top menuju bottom
   - Memperlihatkan posisi data apabila ditemukan
   - Memperlihatkan pesan bila data tidak ada
   - Kompleksitas waktu terburuk: O(n)

**Alur Eksekusi Program:**
1. Membuat stack dalam keadaan kosong
2. Push 5 node berisi nilai 1, 2, 3, 4, 5 → Stack: **5 4 3 2 1** (LIFO)
3. Pop sebanyak 2 kali (menghilangkan 5 dan 4) → Stack: **3 2 1**
4. Update posisi ke-2 menjadi nilai 10 → Stack: **3 10 1**
5. Update posisi ke-1 menjadi nilai 20 → Stack: **20 10 1**
6. Update posisi ke-4 tidak berhasil (tidak valid, hanya tersedia 3 elemen)
7. Search data bernilai 4 → tidak berhasil ditemukan
8. Search data bernilai 9 → tidak berhasil ditemukan

**Keunggulan Implementasi:**
- Ukuran yang dinamis (tanpa batasan MAX seperti pada array)
- Efisiensi tinggi untuk operasi push dan pop dengan O(1)
- Pengelolaan memori yang baik melalui dealokasi

**Keterbatasan:**
- Operasi update dan search membutuhkan O(n) karena harus melakukan traversal
- Membutuhkan ruang memori ekstra untuk menyimpan pointer
- Tidak mendukung akses random ke elemen tertentu

### 2. GUIDED II - Stack dengan Array (Membalik Stack)

Program ini mengimplementasikan Stack menggunakan array dengan operasi push, pop, dan fungsi untuk membalik urutan elemen stack.

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printinfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printinfo(S);

    return 0;
}
```

#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype X);
infotype pop(stack &S);
void printinfo(stack S);
void balikStack(stack &S);
#endif
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S) {
    S.top = Nil;
}

bool isEmpty(stack S) {
    return S.top == Nil;
}

bool isFull(stack S) {
    return S.top == MaxEl - 1;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}

void printinfo(stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(stack &S) {
    if (!isEmpty(S)) {
        stack temp1, temp2;
        createStack(temp1); createStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
```

#### Output Guided 2:
```
Stack Awal:
[TOP] 9 2 4 3

balik stack
Stack Setelah dibalik:
[TOP] 3 4 2 9
```

#### Penjelasan Program Guided 2:

Program ini membangun **Stack dengan memanfaatkan Array** ditambah fitur khusus untuk membalik susunan elemen di dalam stack.

**Struktur Data:**
- **struct stack**: Memakai array `info[MaxEl]` sebagai tempat penyimpanan elemen dan integer `top` sebagai penunjuk indeks elemen teratas
- **MaxEl = 20**: Batas maksimum kapasitas stack
- **Nil = -1**: Konstanta penanda bahwa stack dalam keadaan kosong

**Fungsi-Fungsi Utama:**

1. **createStack(stack &S)**:
   - Melakukan inisialisasi stack dengan menetapkan nilai `top = Nil (-1)`
   - Kondisi stack kosong ditandai oleh top yang bernilai -1

2. **isEmpty(stack S)**:
   - Melakukan pengecekan kondisi kosong stack melalui perbandingan `top == Nil`
   - Menghasilkan true bila stack dalam keadaan kosong

3. **isFull(stack S)**:
   - Melakukan pengecekan apakah stack telah mencapai kapasitas penuh
   - Stack dianggap penuh bila `top == MaxEl - 1` (indeks 19 untuk array berukuran 20)
   - Berfungsi mencegah stack overflow

4. **push(stack &S, infotype x)**:
   - Memasukkan elemen baru ke bagian puncak stack
   - Melakukan verifikasi apakah stack sudah mencapai batas penuh
   - Increment top dilakukan terlebih dahulu, baru kemudian diisi nilai x
   - Kompleksitas waktu yang diperlukan: O(1)

5. **pop(stack &S)**:
   - Mengeluarkan dan menghasilkan nilai elemen teratas stack
   - Melakukan pengecekan kondisi kosong stack sebelum pop dieksekusi
   - Decrement top dilakukan setelah nilai diambil
   - Menghasilkan nilai -999 bila stack kosong (nilai error)
   - Kompleksitas waktu yang diperlukan: O(1)

6. **printinfo(stack S)**:
   - Memperlihatkan keseluruhan isi stack mulai dari top sampai bottom
   - Memakai loop dari indeks top hingga 0
   - Menampilkan penanda [TOP] sebagai indikator elemen teratas

7. **balikStack(stack &S)**:
   - Fungsi spesial untuk membalik susunan elemen di dalam stack
   - **Algoritma**:
     - Membuat dua stack temporary (temp1 dan temp2)
     - **Step 1**: Memindahkan seluruh elemen dari S ke temp1 → urutan berbalik pertama kali
     - **Step 2**: Memindahkan dari temp1 ke temp2 → kembali seperti urutan awal
     - **Step 3**: Memindahkan dari temp2 ke S → menghasilkan urutan terbalik akhir
   - Kompleksitas waktu yang diperlukan: O(n) karena setiap elemen diproses 3 kali

**Alur Eksekusi Program:**
1. Push 3 → Stack: **[TOP] 3**
2. Push 4 → Stack: **[TOP] 4 3**
3. Push 8 → Stack: **[TOP] 8 4 3**
4. Pop (menghilangkan 8) → Stack: **[TOP] 4 3**
5. Push 2 → Stack: **[TOP] 2 4 3**
6. Push 3 → Stack: **[TOP] 3 2 4 3**
7. Pop (menghilangkan 3) → Stack: **[TOP] 2 4 3**
8. Push 9 → Stack: **[TOP] 9 2 4 3**
9. Balik stack → Stack: **[TOP] 3 4 2 9**

**Proses Balik Stack Detail:**
- Stack awal: **9 (top) → 2 → 4 → 3 (bottom)**
- Setelah dipindah ke temp1: **3 (top) → 4 → 2 → 9 (bottom)**
- Setelah dipindah ke temp2: **9 (top) → 2 → 4 → 3 (bottom)**
- Dikembalikan ke S (hasil akhir): **3 (top) → 4 → 2 → 9 (bottom)**

**Keunggulan Implementasi Array:**
- Akses data lebih cepat menggunakan indeks array
- Tidak memerlukan pointer (lebih mudah dipahami)
- Memory locality yang optimal (cache-friendly)
- Ukuran tiap elemen konsisten

**Keterbatasan:**
- Ukuran bersifat fixed (MaxEl = 20), tidak dapat diubah secara dinamis
- Memerlukan pengecekan isFull agar terhindar dari overflow
- Pemborosan memori bila stack jarang terisi penuh

**Perbedaan dengan Guided 1:**
- Guided 1 memakai Linked List (dinamis), Guided 2 memakai Array (statis)
- Guided 1 mempunyai fungsi update dan search, Guided 2 mempunyai fungsi balikStack
- Guided 1 lebih fleksibel dari segi ukuran, Guided 2 lebih cepat dari segi akses
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

#### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif // LIST_H
```

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}  
```

Program ini mendemonstrasikan pembuatan dan manipulasi Single Linked List dengan operasi insertFirst, insertLast, dan insertAfter 

### 2. GUIDED II - Linked List Insert and Delete Operations

Program ini mengimplementasikan operasi insert dan delete pada Single Linked List dengan 3 file terpisah:

#### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    return 0;
}
```

#### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {

    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

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

void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

Program ini mendemonstrasikan operasi lengkap pada Stack dengan array termasuk push, pop, dan fungsi untuk membalik urutan stack menggunakan stack temporary.

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY

```C++
#include <iostream>
using namespace std;

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

// Fungsi untuk membuat stack kosong
void createStack(Stack &S) {
    S.top = -1;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == -1;
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MAX - 1;
}

// Fungsi untuk menambah elemen ke stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[++S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

// Fungsi untuk menghapus elemen dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top--];
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        // Gunakan array auxiliary untuk menyimpan sementara
        infotype tempArray[MAX];
        int count = 0;
        
        // Kosongkan stack ke array (bottom ke top)
        while (!isEmpty(S)) {
            tempArray[count] = pop(S);
            count++;
        }
        
        // Push kembali ke stack (sekarang terbalik)
        for (int i = 0; i < count; i++) {
            push(S, tempArray[i]);
        }
    }
}

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);

    return 0;
}
```

#### Output Unguided 1:

##### Output
![Output Unguided 1](https://github.com/gamel12/Struktur-datagamel/blob/main/STACK/OP%201%2C2%2C3.png)

#### Penjelasan Program Unguided 1:

Program ini membangun **ADT Stack dengan memanfaatkan Array** dilengkapi beragam operasi dasar stack mengikuti spesifikasi modul. Program memakai tipe data integer untuk elemen stack dengan batas kapasitas maksimum 20 elemen.

**Struktur Data:**

1. **typedef int infotype**: Mendefinisikan tipe data untuk elemen stack sebagai integer
2. **struct Stack**:
   - `infotype info[MAX]`: Array penampung elemen-elemen stack dengan batas kapasitas MAX (20 elemen)
   - `int top`: Indeks untuk elemen teratas stack (-1 untuk kondisi stack kosong)

**Operasi-Operasi Stack:**

1. **createStack(Stack &S)**: Inisialisasi stack dengan menetapkan `top = -1` sebagai penanda stack kosong
2. **isEmpty(Stack S)**: Melakukan pengecekan apakah stack kosong (top == -1)
3. **isFull(Stack S)**: Melakukan pengecekan apakah stack penuh (top == MAX-1)
4. **push(Stack &S, infotype x)**: Memasukkan elemen ke bagian puncak stack
5. **pop(Stack &S)**: Mengeluarkan dan menghasilkan elemen dari bagian puncak stack
6. **printInfo(Stack S)**: Memperlihatkan seluruh elemen stack mulai dari top ke bottom
7. **balikStack(Stack &S)**: Membalik susunan elemen di dalam stack dengan memanfaatkan dua stack temporary

**Output Program:**
```
Hello world!
[TOP] 9 2 4 3
balik stack
[TOP] 3 4 2 9
```

Program mendemonstrasikan operasi push dan pop mengikuti urutan soal modul, lalu membalik susunan stack memakai fungsi balikStack.

### 2. Tambahkan Prosedur pushAscending

```C++
#include <iostream>
using namespace std;

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[++S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top--];
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        // Gunakan array auxiliary untuk menyimpan sementara
        infotype tempArray[MAX];
        int count = 0;
        
        // Kosongkan stack ke array
        while (!isEmpty(S)) {
            tempArray[count++] = pop(S);
        }
        
        // Push kembali ke stack (sekarang terbalik)
        for (int i = 0; i < count; i++) {
            push(S, tempArray[i]);
        }
    }
}

// Prosedur pushAscending - menambahkan elemen terurut ascending
void pushAscending(Stack &S, infotype x) {
    // Simpan semua elemen ke array, insert dengan sorted, lalu push kembali
    infotype arr[MAX];
    int n = 0;
    
    // Pop semua elemen ke array
    while (!isEmpty(S)) {
        arr[n++] = pop(S);
    }
    
    // Tambahkan elemen baru
    arr[n++] = x;
    
    // Bubble sort descending (karena akan di-push dari akhir)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                infotype temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Push kembali dari akhir (yang terkecil duluan)
    for (int i = n - 1; i >= 0; i--) {
        push(S, arr[i]);
    }
}

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);

    return 0;
}
```

#### Output Unguided 2:

##### Output
![Output Unguided 2](https://github.com/gamel12/Struktur-datagamel/blob/main/STACK/OP%201%2C2%2C3.png)

#### Penjelasan Program Unguided 2:

Program ini menambahkan **prosedur pushAscending** yang memfasilitasi penambahan elemen ke stack sambil menjaga susunan ascending (urut dari kecil ke besar).

**Fungsi Baru:**

**pushAscending(Stack &S, infotype x)**:
- Memasukkan elemen x ke stack sambil mempertahankan urutan ascending
- Algoritma:
  1. Pop seluruh elemen stack ke array
  2. Tambahkan elemen baru x ke array
  3. Lakukan bubble sort descending pada array
  4. Push kembali elemen dari array ke stack (dari akhir)
- Kompleksitas: O(n²) karena menggunakan bubble sort

**Output Program:**
```
Hello world!
[TOP] 9 8 4 3 3 2
balik stack
[TOP] 2 3 3 4 8 9
```

Setelah pushAscending elemen 3,4,8,2,3,9, stack tersusun dari kecil (bottom) ke besar (top). Setelah balikStack, susunan menjadi dari kecil (top) ke besar (bottom).

### 3. Tambahkan Prosedur getInputStream

```C++
#include <iostream>
using namespace std;

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[++S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top--];
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        // Gunakan array auxiliary untuk menyimpan sementara
        infotype tempArray[MAX];
        int count = 0;
        
        // Kosongkan stack ke array
        while (!isEmpty(S)) {
            tempArray[count++] = pop(S);
        }
        
        // Push kembali ke stack (sekarang terbalik)
        for (int i = 0; i < count; i++) {
            push(S, tempArray[i]);
        }
    }
}

void pushAscending(Stack &S, infotype x) {
    // Simpan semua elemen ke array, insert dengan sorted, lalu push kembali
    infotype arr[MAX];
    int n = 0;
    
    // Pop semua elemen ke array
    while (!isEmpty(S)) {
        arr[n++] = pop(S);
    }
    
    // Tambahkan elemen baru
    arr[n++] = x;
    
    // Bubble sort descending (karena akan di-push dari akhir)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                infotype temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Push kembali dari akhir (yang terkecil duluan)
    for (int i = n - 1; i >= 0; i--) {
        push(S, arr[i]);
    }
}

// Prosedur getInputStream - membaca input hingga user menekan enter
void getInputStream(Stack &S) {
    string input;
    getline(cin, input);
    
    // Proses setiap karakter dalam string
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            infotype value = input[i] - '0';
            push(S, value);
        }
    }
}

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    
    getInputStream(S);
    
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);

    return 0;
}
```

#### Output Unguided 3:

##### Output
![Output Unguided 3](https://github.com/gamel12/Struktur-datagamel/blob/main/STACK/OP%201%2C2%2C3.png)

#### Penjelasan Program Unguided 3:

Program ini menambahkan **prosedur getInputStream** yang memfasilitasi user untuk memasukkan digit angka langsung sampai tombol enter ditekan.

**Fungsi Baru:**

**getInputStream(Stack &S)**:
- Melakukan pembacaan input menggunakan `getline()` untuk membaca seluruh baris
- Memproses setiap karakter dalam string input
- Algoritma:
  1. Baca seluruh input sebagai string dengan `getline(cin, input)`
  2. Loop melalui setiap karakter dalam string
  3. Bila karakter merupakan digit ('0'-'9'), konversi menjadi integer dengan `input[i] - '0'`
  4. Push digit tersebut ke stack
- Kompleksitas: O(n) dengan n adalah panjang string input

**Contoh Interaksi:**
```
Input: 27960
Output:
[TOP] 0 6 9 7 2
balik stack
[TOP] 2 7 9 6 0
```

Bila input "27960", setiap digit (2,7,9,6,0) akan dipush ke stack satu per satu. Program menunjukkan pembacaan digit dari input stream, lalu memperlihatkan dan membalik stack.

## Kesimpulan

Berdasarkan praktikum yang telah dijalankan mengenai **Stack**, dapat ditarik beberapa kesimpulan penting berikut ini:

1. **Stack** merupakan struktur data berbentuk linear yang menerapkan prinsip **LIFO (Last In First Out)**, di mana elemen yang terakhir masuk akan keluar pertama kali. Prinsip ini menjadi karakteristik utama dan membedakan stack dari struktur data yang lain.

2. **Implementasi Stack** bisa dilakukan melalui dua cara utama: memakai **array (static)** dan memakai **linked list (dynamic)**. Stack berbasis array mempunyai ukuran tetap dan akses yang cepat, sedangkan stack berbasis linked list lebih fleksibel dengan ukuran yang dinamis.

3. **Operasi Dasar Stack** mempunyai kompleksitas waktu O(1) yang sangat efisien: Push, Pop, Peek/Top, isEmpty, dan isFull (khusus array-based).

4. **Validasi Kondisi** sangat penting dalam pembuatan stack untuk menghindari **stack overflow** (push ketika penuh) dan **stack underflow** (pop ketika kosong).

5. **Aplikasi Praktis Stack** sangat beragam: String Manipulation, Number System Conversion, Expression Validation, Function Call Management, dan Undo/Redo Operations.

6. **Konversi Sistem Bilangan** dengan menggunakan stack sangat efektif karena proses pembagian menghasilkan digit dengan urutan terbalik dan kompleksitas O(log n).

7. **Bracket Matching** dengan menggunakan stack adalah algoritma klasik yang diterapkan dalam compiler dengan kompleksitas O(n) linear.

8. **Memory Management** pada stack berbasis array lebih simpel, namun stack berbasis linked list membutuhkan perhatian khusus terhadap `new` dan `delete`.

9. **Struktur Data Custom** dapat ditampung dalam stack, memperlihatkan fleksibilitas stack untuk berbagai jenis data kompleks.

10. Implementasi stack menunjukkan pentingnya pemahaman terhadap **abstraksi data**, **encapsulation**, dan **modular programming**.

## Referensi

[1] Karumanchi, N. (2016). *Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles* (5th ed.). CareerMonk Publications.
Halaman artikel: https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
PDF: https://ejournal.undiksha.ac.id/index.php/JPTK/article/download/31/25/94
<br>[2]Prasetyoadi, E. B., Rokhmawati, R. I., & Wicaksono, S. A. (2019). Pengembangan e-modul pembelajaran “Pemrograman Dasar” dengan metode R&D (Studi SMKN 4 Malang). Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer (J-PTIIK), 3(10), 10118–10129.
Halaman artikel: https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/view/6646
PDF: https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/download/6646/3193/46603

[3] Shaffer, C. A. (2013). *Data Structures and Algorithm Analysis in C++* (3rd ed.). Dover Publications.

[4] Sahni, S., & Anderson-Freed, S. (2004). *Fundamentals of Data Structures in C++* (2nd ed.). Silicon Press.

[5] Drozdek, A. (2012). *Data Structures and Algorithms in C++* (4th ed.). Cengage Learning. ISBN: 978-1133608424
