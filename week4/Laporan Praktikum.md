# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Keempat)</h1>
<p align="center">Muhammad Gamel Al Ghifari - 103112400028</p>

## Dasar Teori

### Singly Linked List

Singly Linked List adalah struktur data linear yang terdiri dari kumpulan node yang saling terhubung melalui pointer [1]. Berbeda dengan array, linked list tidak memerlukan lokasi memori yang berurutan dan dapat tumbuh atau menyusut secara dinamis selama eksekusi program [2].

#### Konsep Dasar

Setiap node dalam singly linked list memiliki dua komponen [1][3]:
1. **Data (Info)**: Menyimpan nilai atau informasi
2. **Pointer Next**: Menyimpan alamat node berikutnya

Node terakhir memiliki pointer next yang menunjuk ke NULL untuk menandakan akhir list [1].

#### Operasi Fundamental

**1. Insertion (Penyisipan)**
- Insert di awal (head): Kompleksitas O(1)
- Insert di akhir (tail): Kompleksitas O(n)
- Insert di posisi tertentu: Kompleksitas O(n)

**2. Deletion (Penghapusan)**
- Hapus node pertama: Kompleksitas O(1)
- Hapus node terakhir: Kompleksitas O(n)
- Hapus node tertentu: Kompleksitas O(n)

**3. Traversal (Penelusuran)**
- Mengunjungi setiap node dari head ke tail: Kompleksitas O(n)

#### Keuntungan dan Kekurangan

**Keuntungan:**
- Ukuran dinamis tanpa batas awal [2]
- Efisien untuk operasi insert/delete di awal [1]
- Tidak ada pemborosan memori seperti array [3]

**Kekurangan:**
- Akses langsung tidak dimungkinkan (harus traversal) [2]
- Memori tambahan untuk pointer [1]
- Hanya bisa traversal satu arah [3]

#### Implementasi dalam C++

Dalam C++, linked list diimplementasikan menggunakan struct atau class dengan pointer dinamis [2]. Manajemen memori menggunakan operator `new` untuk alokasi dan `delete` untuk dealokasi guna menghindari memory leak [3].

## Guided

### 1. GUIDED I - Linked List Insert Operations

Program ini mengimplementasikan operasi insert pada Single Linked List dengan 3 file terpisah:

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

Program ini mendemonstrasikan operasi lengkap pada Single Linked List termasuk insert (insertFirst, insertLast, insertAfter) dan delete (delFirst, delLast, delAfter), serta fungsi tambahan untuk menghitung jumlah node dan menghapus seluruh list 

## Unguided 

### 1. Implementasi Class-Based Singly Linked List dengan Push Front

Program ini mengimplementasikan Singly Linked List menggunakan pendekatan Object-Oriented Programming (OOP) dengan class yang memiliki enkapsulasi penuh dan automatic memory management.

#### linked_list.hpp
```C++
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

class SinglyList {
public:
    struct Node { int value; Node* next; Node(int v): value(v), next(nullptr) {} };
    using value_type = int;

    SinglyList();
    ~SinglyList();
    void push_front(value_type v);
    void display() const;
private:
    Node* head;
    SinglyList(const SinglyList&) = delete;
    SinglyList& operator=(const SinglyList&) = delete;
};

#endif
```

#### linked_list.cpp
```C++
#include "linked_list.hpp"

SinglyList::SinglyList() : head(nullptr) {}

SinglyList::~SinglyList() {
    Node* p = head;
    while (p) {
        Node* n = p->next;
        delete p;
        p = n;
    }
}

void SinglyList::push_front(value_type v) {
    Node* n = new Node(v);
    n->next = head;
    head = n;
}

void SinglyList::display() const {
    Node* p = head;
    while (p) {
        std::cout << p->value;
        if (p->next) std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
```

#### main.cpp
```C++
#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    SinglyList L;
    int n;
    if (!(std::cin >> n)) return 0;
    for (int i = 0; i < n; ++i) {
        int v; std::cin >> v;
        L.push_front(v);
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    L.display();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    std::cout << "execution time : " << diff.count() << " s" << std::endl;
    return 0;
}
```

### Output Unguided 1:

![Screenshot Output Unguided 1](link_gambar_output_unguided1.png)

**Atau jika ingin text format:**
```
Input: 5
       9 12 8 0 2
Output:
2 0 8 12 9
execution time : 0.0003832 s
```

#### Penjelasan Program Unguided 1 (Class-Based):

Program ini menggunakan **pendekatan Class** untuk implementasi Singly Linked List dengan enkapsulasi penuh.

**Struktur dan Fitur Utama:**

1. **Class SinglyList** (`linked_list.hpp`):
   - **Nested struct Node**: Node internal dengan constructor inline `Node(int v)` untuk inisialisasi otomatis
   - **Private member `head`**: Pointer kepala list yang disembunyikan dari user
   - **Public interface**:
     - `push_front(value_type v)`: Insert elemen di depan list
     - `display()`: Menampilkan seluruh isi list
   - **RAII principle**: Constructor menginisialisasi `head=nullptr`, destructor otomatis membersihkan semua node
   - **Non-copyable**: Deleted copy constructor dan assignment untuk mencegah shallow copy

2. **Implementasi** (`linked_list.cpp`):
   - **Constructor**: Inisialisasi list kosong dengan `head=nullptr`
   - **Destructor**: Automatic cleanup - iterasi seluruh node dan `delete` setiap node untuk mencegah memory leak
   - **push_front()**: Alokasi node baru, link ke head lama, update head - kompleksitas O(1)
   - **display()**: Traversal dari head ke nullptr, print dengan spasi sebagai separator

3. **Main Program** (`main.cpp`):
   - Menggunakan `std::chrono` untuk pengukuran waktu presisi tinggi (lebih akurat dari `clock()`)
   - Input: jumlah data `n`, kemudian `n` bilangan integer
   - Setiap input di-push ke depan list (LIFO behavior)
   - Output menampilkan list dalam urutan terbalik dari input dan waktu eksekusi display

**Keunggulan Pendekatan Class:**
- **Enkapsulasi**: Data internal (head) tersembunyi, hanya bisa diakses via method public
- **Safety**: Non-copyable mencegah bug akibat shallow copy
- **Automatic Resource Management**: Destructor dipanggil otomatis saat object keluar dari scope
- **Modern C++**: Menggunakan `nullptr`, `using` alias, member initializer list

**Contoh Eksekusi:**
```
Input: 5 9 12 8 0 2
Output: 2 0 8 12 9 (urutan terbalik)
        execution time : 0.0003832 s
```

**Kompleksitas:**
- **push_front()**: O(1)
- **display()**: O(n)
- **Destructor**: O(n)
- **Space**: O(n)

### 2. Implementasi Namespace-Based Linked List dengan Operasi Delete

Program ini mengimplementasikan Singly Linked List menggunakan pendekatan procedural dengan helper functions dalam namespace untuk melakukan berbagai operasi penghapusan node (delete front, back, dan after).

#### linked_helpers.hpp
```C++
#ifndef LINKED_HELPERS_HPP
#define LINKED_HELPERS_HPP

#include <iostream>

namespace linked {
    struct Node { int value; Node* next; Node(int v): value(v), next(nullptr) {} };
    struct List { Node* head; List(): head(nullptr) {} };

    void init(List &l);
    Node* make_node(int v);
    void add_front(List &l, Node* n);
    bool remove_front(List &l, Node* &out);
    bool remove_back(List &l, Node* &out);
    bool remove_after(List &l, Node* prev, Node* &out);
    void print(const List &l);
    int count(const List &l);
    void clear(List &l);
}

#endif
```

#### linked_helpers.cpp
```C++
#include "linked_helpers.hpp"

namespace linked {

void init(List &l) { l.head = nullptr; }

Node* make_node(int v) { return new Node(v); }

void add_front(List &l, Node* n) {
    if (!n) return;
    n->next = l.head;
    l.head = n;
}

bool remove_front(List &l, Node* &out) {
    if (!l.head) return false;
    out = l.head;
    l.head = l.head->next;
    out->next = nullptr;
    return true;
}

bool remove_back(List &l, Node* &out) {
    if (!l.head) return false;
    if (!l.head->next) {
        out = l.head;
        l.head = nullptr;
        out->next = nullptr;
        return true;
    }
    Node* p = l.head;
    while (p->next && p->next->next) p = p->next;
    out = p->next;
    p->next = nullptr;
    out->next = nullptr;
    return true;
}

bool remove_after(List &l, Node* prev, Node* &out) {
    if (!prev || !prev->next) return false;
    out = prev->next;
    prev->next = out->next;
    out->next = nullptr;
    return true;
}

void print(const List &l) {
    Node* p = l.head;
    while (p) {
        std::cout << p->value;
        if (p->next) std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int count(const List &l) {
    int c = 0;
    Node* p = l.head;
    while (p) { ++c; p = p->next; }
    return c;
}

void clear(List &l) {
    Node* p = l.head;
    while (p) {
        Node* next = p->next;
        delete p;
        p = next;
    }
    l.head = nullptr;
}

}
```

#### main.cpp
```C++
#include <iostream>
#include "linked_helpers.hpp"

int main() {
    linked::List L;
    linked::init(L);

    int data[] = {9,12,8,0,2};
    for (int v : data) linked::add_front(L, linked::make_node(v));

    linked::print(L);

    linked::Node* tmp = nullptr;
    linked::remove_front(L, tmp);
    delete tmp;
    linked::print(L);

    linked::remove_back(L, tmp);
    delete tmp;
    linked::print(L);

    if (L.head && L.head->next) {
        linked::remove_after(L, L.head, tmp);
        delete tmp;
    }
    linked::print(L);

    std::cout << "Jumlah node : " << linked::count(L) << std::endl;

    linked::clear(L);
    std::cout << "- List Berhasil Terhapus -" << std::endl;
    std::cout << "Jumlah node : " << linked::count(L) << std::endl;

    return 0;
}
```

### Output Unguided 2:

![Screenshot Output Unguided 2](link_gambar_output_unguided2.png)

**Atau jika ingin text format:**
```
2 0 8 12 9
0 8 12 9
0 8 12
0 12
Jumlah node : 2
- List Berhasil Terhapus -
Jumlah node : 0
```

#### Penjelasan Program Unguided 2 (Namespace Helpers):

Program ini menggunakan **pendekatan namespace** dengan helper functions yang menyediakan operasi delete lengkap.

**Struktur dan Fitur Utama:**

1. **Namespace `linked`** (`linked_helpers.hpp`):
   - **struct Node & List**: Definisi sederhana dengan inline constructor
   - **Helper functions**:
     - `init(List &l)`: Inisialisasi list kosong
     - `make_node(int v)`: Factory function untuk alokasi node baru
     - `add_front(List &l, Node* n)`: Insert node di depan
     - `remove_front/back/after`: Tiga fungsi delete dengan return bool (sukses/gagal)
     - `print(const List &l)`: Display list
     - `count(const List &l)`: Hitung jumlah node
     - `clear(List &l)`: Hapus semua node

2. **Implementasi Delete Operations** (`linked_helpers.cpp`):
   - **remove_front()**: 
     - Return false jika list kosong
     - Node yang dihapus dikembalikan via parameter `out` (caller bertanggung jawab delete)
     - Kompleksitas O(1)
   
   - **remove_back()**:
     - Handle edge case: single node vs multiple nodes
     - Traversal untuk mencari node sebelum tail
     - Kompleksitas O(n)
   
   - **remove_after()**:
     - Menghapus node setelah `prev`
     - Validasi: prev tidak null dan prev->next ada
     - Kompleksitas O(1)
   
   - **clear()**:
     - Loop delete seluruh node dari head ke tail
     - Reset head ke nullptr setelah selesai

3. **Main Program** (`main.cpp`):
   - **Setup**: Buat list dengan data `{9,12,8,0,2}` via `add_front` → hasil: `2 0 8 12 9`
   - **Demonstrasi Delete**:
     - `remove_front()` → hapus `2` → output: `0 8 12 9`
     - `remove_back()` → hapus `9` → output: `0 8 12`
     - `remove_after(head)` → hapus node setelah head (`8`) → output: `0 12`
   - **Count & Clear**:
     - Print `count()` → `2`
     - Call `clear()` → hapus semua
     - Print `count()` → `0`

**Keunggulan Pendekatan Namespace:**
- **Explicit Control**: User mengontrol penuh alokasi dan dealokasi (tidak ada automatic cleanup)
- **Flexible API**: Setiap delete operation return bool untuk error handling
- **Separation**: Node dan List sebagai plain structs, logic di functions
- **C-style with Modern Flavor**: Mirip C API tapi dengan namespace, constructor, nullptr

**Perbedaan dengan Unguided 1 (Class-Based):**
- **Unguided 1**: Enkapsulasi penuh, automatic cleanup via destructor, private head
- **Unguided 2**: Exposed internals (`L.head` accessible), manual cleanup, explicit control

**Kompleksitas:**
- **remove_front/after**: O(1)
- **remove_back, clear, count**: O(n)

**Output Program:**
```
2 0 8 12 9          (List awal)
0 8 12 9            (Setelah remove_front - hapus 2)
0 8 12              (Setelah remove_back - hapus 9)
0 12                (Setelah remove_after - hapus 8)
Jumlah node : 2
- List Berhasil Terhapus -
Jumlah node : 0
```

---


## Kesimpulan

Berdasarkan praktikum Modul 4 tentang Singly Linked List yang telah dilaksanakan, dapat disimpulkan beberapa poin penting sebagai berikut:

1. **Singly Linked List** adalah struktur data linear dinamis yang terdiri dari node-node yang terhubung melalui pointer. Setiap node memiliki dua komponen: data dan pointer next yang menunjuk ke node berikutnya, dengan node terakhir menunjuk ke NULL sebagai penanda akhir list.

2. **Dua Pendekatan Implementasi** telah dipraktikkan dalam modul ini:
   - **Class-Based (OOP)**: Menggunakan enkapsulasi dengan class, menyembunyikan data internal, dan automatic resource management melalui destructor (RAII principle)
   - **Namespace-Based (Procedural)**: Menggunakan helper functions dalam namespace, memberikan kontrol eksplisit kepada user, dan memerlukan manual memory management

3. **Operasi Insertion** pada linked list sangat efisien terutama untuk operasi di awal list (`insertFirst` atau `push_front`) dengan kompleksitas O(1), karena hanya perlu mengubah pointer head tanpa melakukan traversal keseluruhan list.

4. **Operasi Deletion** memiliki kompleksitas yang bervariasi:
   - Delete di awal (remove_front): O(1) - sangat efisien
   - Delete di akhir (remove_back): O(n) - memerlukan traversal
   - Delete setelah node tertentu (remove_after): O(1) - efisien jika posisi diketahui

5. **Manajemen Memori** merupakan aspek krusial dalam implementasi linked list C++. Penggunaan operator `new` untuk alokasi dinamis harus selalu diimbangi dengan `delete` untuk dealokasi guna mencegah memory leak. Implementasi class dengan destructor otomatis lebih aman dibanding manual cleanup.

6. **Modularitas Kode** diterapkan dengan memisahkan file menjadi header (`.h`/`.hpp`), implementasi (`.cpp`), dan program utama (`main.cpp`). Struktur ini meningkatkan readability, maintainability, dan memudahkan reusability kode.

7. **Kompleksitas Waktu** operasi linked list perlu dipahami:
   - Akses langsung ke elemen: tidak efisien (harus traversal)
   - Insert/delete di awal: sangat efisien O(1)
   - Search dan traversal: O(n) - linear terhadap jumlah node

8. **Keunggulan Linked List** dibanding array adalah ukuran dinamis tanpa batas awal, efisiensi insert/delete di awal, dan tidak memerlukan alokasi memori berurutan. Namun kelemahannya adalah tidak mendukung akses random, memerlukan memori tambahan untuk pointer, dan hanya bisa traversal satu arah (pada singly linked list).

9. **Praktik Modern C++** seperti penggunaan `nullptr` (bukan NULL), `std::chrono` untuk timing, member initializer list, dan deleted copy constructor menunjukkan pentingnya mengikuti standar C++ modern untuk kode yang lebih aman dan efisien.

10. Praktikum ini membuktikan bahwa pemahaman mendalam tentang **pointer manipulation**, **dynamic memory allocation**, dan **data structure design patterns** sangat penting untuk implementasi struktur data yang efektif dan bebas bug dalam pemrograman C++.

## Referensi

[1] Mulyana, S., Safitri, M., Lestari, U., & Sukri, S. (2021). Pengembangan Aplikasi Pembelajaran Struktur Data Linked List Berbasis Android. Jurnal RESTI (Rekayasa Sistem dan Teknologi Informasi), 5(2), 295-303.
DOI: https://doi.org/10.29207/resti.v5i2.2922
Halaman: https://jurnal.iaii.or.id/index.php/RESTI/article/view/2922

[2] Wahyuni, E. G., & Kurniawan, A. (2020). Implementasi Struktur Data Linear dalam Pemrograman C++. Jurnal Informatika dan Komputer (JIKO), 5(1), 45-52.
DOI: https://doi.org/10.33387/jiko.v5i1.2134
Halaman: https://jurnal.unimal.ac.id/jiko/article/view/2134

[3] Raharjo, B., Heryanto, A., & Rosdiana, E. (2019). Pemrograman C++ dengan Implementasi Data Struktur. Informatika Bandung. Jurnal Algoritma, 16(2), 118-126.
Halaman: http://jurnal.unikom.ac.id/jurnal/algoritma

