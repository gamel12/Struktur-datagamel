# <h1 align="center">Laporan Praktikum Modul 3 - ADT (Abstract Data Type)</h1>
<p align="center">Muhammad Gamel Al Ghifari - 103112400028</p>

## Dasar Teori

### Abstract Data Type (ADT)

Abstract Data Type (ADT) adalah sebuah konsep teoretis dalam ilmu komputer yang merupakan cara untuk melihat perilaku sebuah struktur data dari sudut pandang pengguna [1][2]. ADT dapat dianggap sebagai sebuah cetak biru yang mendefinisikan jenis informasi yang disimpan (data) dan operasi-operasi apa saja yang dapat dilakukan terhadap data tersebut [4].

Ide utama dari ADT adalah abstraksi—pengguna tidak perlu tahu bagaimana cara kerjanya secara internal, cukup tahu apa yang bisa dilakukannya [4][7].

#### Definisi ADT

Sebuah ADT didefinisikan oleh tipe datanya dan sekumpulan operasi dasar, yang disebut primitif, yang dapat dilakukan pada tipe tersebut [1][2]. Ini adalah definisi statis, yang berarti ia didefinisikan sebelum program dijalankan [2]. ADT bahkan dapat terdiri dari ADT lain, seperti ADT 'waktu' yang mencakup ADT 'jam' dan ADT 'tanggal' [2].

#### Operasi Primitif ADT

Primitif adalah operasi-operasi fundamental untuk berinteraksi dengan data ADT [1][2]. Umumnya, primitif dikelompokkan sebagai berikut [1][2][7]:

1. **Konstruktor/Kreator**: Digunakan untuk membuat instance baru dari ADT [1][2].

2. **Selektor**: Memungkinkan akses ke data di dalam ADT [1][7].

3. **Mutator (Pengubah)**: Prosedur untuk mengubah nilai komponen data ADT [2][6].

4. **Validator**: Memeriksa apakah data berada dalam keadaan yang valid [2][7].

5. **Destruktor/Dealokator**: Membersihkan dan melepaskan memori yang digunakan oleh instance ADT [1][7].

6. **Operasi Baca/Tulis**: Menangani interaksi dengan perangkat input/output [2][6].

7. **Operator Relasional**: Mendefinisikan perbandingan seperti sama dengan, lebih besar dari, atau lebih kecil dari [1][7].

8. **Operator Aritmetika**: Mendefinisikan operasi matematis pada data ADT [2][7].

9. **Fungsi Konversi**: Mengubah ADT ke dan dari tipe data lain [1][6].

#### Implementasi ADT dalam C++

Dalam pemrograman praktis, khususnya dalam bahasa seperti C++, ADT biasanya diimplementasikan dengan memisahkan antarmuka (interface) dari implementasinya [3][6]. Pendekatan modular ini meningkatkan keteraturan dan keterbacaan kode [5][6].

- **File Header (.h)**: File ini berisi definisi tipe data (sering kali menggunakan struct atau class) dan deklarasi fungsi-fungsi primitif [3][5]. File ini berfungsi sebagai antarmuka publik dari ADT.

- **File Implementasi (.cpp)**: File ini berisi kode C++ yang sebenarnya, atau "badan" program, untuk fungsi-fungsi primitif yang telah dideklarasikan di file header [3][6].

Pemisahan ini diilustrasikan dalam contoh mahasiswa, di mana mahasiswa.h mendefinisikan struct dan prototipe fungsi, sementara mahasiswa.cpp berisi logika untuk fungsi-fungsi tersebut [3][5]. Program utama (main.cpp) kemudian menyertakan file header untuk dapat menggunakan ADT tersebut [6].


## Guided 

### 1. Guided gabungan

```C++
#include <iostream>
#include <cstdlib>

using namespace std;

// Definisi struct mahasiswa (dari guided1.cpp)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

// Deklarasi fungsi
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

// Implementasi fungsi (dari guided2.cpp)
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float) (m.nilai1 + m.nilai2) / 2;
}

// Fungsi main (dari main.cpp)
int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "nilai rata Rata-rata adalah : " << rata2(mhs) << endl;
    system("pause");    
    return 0;
}
```

#### Penjelasan:
Program ini mendemonstrasikan penggunaan ADT dengan struct mahasiswa yang memiliki field NIM, nilai1, dan nilai2. Terdapat fungsi `inputMhs()` untuk menginput data mahasiswa dan fungsi `rata2()` untuk menghitung rata-rata dari dua nilai. Program utama membuat objek mahasiswa, menginput data, lalu menampilkan hasil perhitungan rata-rata.


## Unguided 

### 1. Unguided 1 dan 2

```C++
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

```
### Output Unguided 1 & 2 :

![Screenshot Output Unguided 1](https://github.com/gamel12/Struktur-datagamel/blob/main/week3/OP1.png)

#### Penjelasan:

**Soal 1 - Data Mahasiswa:** Program menggunakan struct `Mahasiswa` dengan field nama, nim, uts, uas, tugas, dan nilaiAkhir. Array dapat menampung maksimal 10 mahasiswa. Fungsi `hitungNilaiAkhir()` menghitung nilai akhir dengan bobot 30% UTS + 40% UAS + 30% Tugas. Fungsi `tampilkanMahasiswa()` menampilkan semua data mahasiswa yang telah diinput beserta nilai akhirnya.

**Soal 2 - ADT Pelajaran:** Implementasi ADT pelajaran menggunakan struct `Pelajaran` dengan field namapel dan kodepel. Fungsi `create_pelajaran()` berfungsi sebagai konstruktor untuk membuat objek pelajaran, sedangkan `tampil_pelajaran()` menampilkan data pelajaran. Program mendemonstrasikan pembuatan ADT dengan output "Struktur Data" dan "STD".

### 3. 

```C++
#include <iostream>
using namespace std;

void tampilArray2D(int arr[][3], int baris, int kolom) {
    cout << "\nIsi Array 2D:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarIsiArray2D(int arr1[][3], int arr2[][3], int baris, int kolom) {
    cout << "\nMenukar isi array 2D pada posisi [" << baris << "][" << kolom << "]\n";
    
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
    
    cout << "Isi berhasil ditukar!\n";
}

void tukarIsiPointer(int* ptr1, int* ptr2) {
    cout << "\nMenukar isi dari 2 pointer...\n";
    cout << "Sebelum ditukar: ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;
    
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    
    cout << "Setelah ditukar: ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;
}


int main() {
    cout << "========== SOAL 3: ARRAY 2D DAN POINTER ==========\n";
    
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int array2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };
    
    cout << "\n--- Array 1 (Awal) ---";
    tampilArray2D(array1, 3, 3);
    
    cout << "\n--- Array 2 (Awal) ---";
    tampilArray2D(array2, 3, 3);
    
    tukarIsiArray2D(array1, array2, 1, 1);
    
    cout << "\n--- Array 1 (Setelah Tukar Posisi [1][1]) ---";
    tampilArray2D(array1, 3, 3);
    
    cout << "\n--- Array 2 (Setelah Tukar Posisi [1][1]) ---";
    tampilArray2D(array2, 3, 3);
    
    cout << "\n\n========== POINTER INTEGER ==========\n";
    int nilai1 = 100;
    int nilai2 = 200;
    
    int* ptr1 = &nilai1;
    int* ptr2 = &nilai2;
    
    cout << "Nilai awal:\n";
    cout << "nilai1 = " << nilai1 << ", nilai2 = " << nilai2 << endl;
    cout << "ptr1 menunjuk ke nilai1 = " << *ptr1 << endl;
    cout << "ptr2 menunjuk ke nilai2 = " << *ptr2 << endl;
    
    tukarIsiPointer(ptr1, ptr2);
    
    cout << "\nNilai setelah ditukar:\n";
    cout << "nilai1 = " << nilai1 << ", nilai2 = " << nilai2 << endl;
    
    cout << "\n\n========== CONTOH TAMBAHAN ==========\n";
    cout << "Menukar elemen array pada posisi [0][0] dan [2][2]:\n";
    
    tukarIsiArray2D(array1, array2, 0, 0);
    
    cout << "\n--- Array 1 (Setelah Tukar Posisi [0][0]) ---";
    tampilArray2D(array1, 3, 3);
    
    cout << "\n--- Array 2 (Setelah Tukar Posisi [0][0]) ---";
    tampilArray2D(array2, 3, 3);
    
    tukarIsiArray2D(array1, array2, 2, 2);
    
    cout << "\n--- Array 1 (Setelah Tukar Posisi [2][2]) ---";
    tampilArray2D(array1, 3, 3);
    
    cout << "\n--- Array 2 (Setelah Tukar Posisi [2][2]) ---";
    tampilArray2D(array2, 3, 3);
    
    return 0;
}

```
### Output Unguided 3 :

![Screenshot Output Unguided 3 Part 1](https://github.com/gamel12/Struktur-datagamel/blob/main/week3/OP2.png)

![Screenshot Output Unguided 3 Part 2](https://github.com/gamel12/Struktur-datagamel/blob/main/week3/OP2%20b.png)


#### Penjelasan:
Program ini mendemonstrasikan penggunaan array 2D dan pointer integer. Program membuat 2 array 2D berukuran 3x3 (array1 berisi 1-9, array2 berisi 10-18). Fungsi `tampilArray2D()` menampilkan isi array, fungsi `tukarIsiArray2D()` menukar nilai pada posisi tertentu antara dua array menggunakan variabel temporary. Untuk pointer, program membuat 2 pointer integer (ptr1 dan ptr2) yang menunjuk ke variabel nilai1 dan nilai2. Fungsi `tukarIsiPointer()` menukar nilai yang ditunjuk oleh kedua pointer menggunakan dereferencing operator (*). Program mendemonstrasikan konsep manipulasi data melalui pointer dan pertukaran nilai pada array multidimensi.

## Kesimpulan

Praktikum Modul 3 tentang Abstract Data Type (ADT) memberikan pemahaman tentang konsep enkapsulasi data dalam pemrograman C++. Struct digunakan sebagai implementasi ADT untuk mengelompokkan berbagai tipe data menjadi satu kesatuan. Penggunaan fungsi terpisah untuk operasi data menunjukkan prinsip modularitas dan abstraksi, memudahkan pemeliharaan kode. Implementasi array untuk menyimpan multiple data dan pointer untuk manipulasi data mendemonstrasikan fleksibilitas C++ dalam pengelolaan memori. Dengan memahami konsep ADT, programmer dapat membuat kode yang lebih terstruktur, mudah dipahami, dan reusable.

## Referensi
[1] Aho, A. V., Hopcroft, J. E., & Ullman, J. D. (1983). Data Structures and Algorithms. Addison-Wesley.

[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.

[3] Ford, W., & Topp, W. (2002). Data Structures with C++ Using STL (2nd ed.). Prentice Hall.

[4] GeeksforGeeks. (n.d.). Abstract Data Types. Diakses dari https://www.geeksforgeeks.org/abstract-data-types/

[5] Lafore, R. (2002). Object-Oriented Programming in C++ (4th ed.). Sams Publishing.

[6] Malik, D. S. (2017). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.

[7] Weiss, M. A. (2013). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.
