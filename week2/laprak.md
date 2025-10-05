# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Muhammad Gamel Al Ghifari - 103112400028</p>

## Dasar Teori
Pemrograman C++ merupakan bahasa pemrograman tingkat menengah yang dikembangkan sebagai perluasan dari bahasa C, yang menyediakan paradigma pemrograman berorientasi objek dan pemrograman prosedural [1]. Bahasa ini menjadi fondasi penting dalam pengembangan perangkat lunak modern karena kemampuannya dalam mengelola memori secara langsung dan menyediakan kontrol penuh terhadap sumber daya sistem [1].

Array dalam C++ adalah struktur data fundamental yang menyimpan sekumpulan elemen dengan tipe data yang sama dalam lokasi memori yang berurutan [2]. Menurut Universitas Komputer Indonesia, array memungkinkan programmer untuk mengelola data dalam bentuk koleksi yang terorganisir, di mana setiap elemen dapat diakses melalui indeks yang dimulai dari 0 [2]. Array dapat berupa satu dimensi (linear) maupun multidimensi, yang sangat berguna untuk merepresentasikan data dalam bentuk tabel atau matriks [2].

Pointer merupakan salah satu konsep yang paling powerful dalam C++, yaitu variabel yang menyimpan alamat memori dari variabel lain [3]. Sebagaimana dijelaskan dalam dokumentasi GitHub Pages UCL, pointer memberikan kemampuan untuk melakukan manipulasi memori secara langsung, yang memungkinkan implementasi struktur data dinamis dan manajemen memori yang efisien [3]. Penggunaan pointer memungkinkan program untuk mengakses dan memodifikasi data melalui referensi alamat memorinya, sehingga memberikan fleksibilitas tinggi dalam pemrograman [3].

Fungsi dan prosedur adalah komponen modular dalam pemrograman yang memungkinkan pengorganisasian kode menjadi blok-blok yang dapat digunakan kembali [4]. Berdasarkan laporan praktikum algoritma pemrograman, fungsi merupakan subprogram yang dapat mengembalikan nilai, sedangkan prosedur adalah subprogram yang melakukan tugas tertentu tanpa mengembalikan nilai [4]. Penggunaan fungsi dan prosedur meningkatkan modularitas program, memudahkan maintenance, dan mengurangi redundansi kode [1][4].

## Guided 1

### 1. Array1 dimensi 

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];
    for (int i = 0; i < 5; i++){
        cout << "Masukan value indeks ke-" << i << ":";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << ":" << arr[j]<< endl;
        j++;
    }
    return 0;
}
```

**Penjelasan Program:**

Program ini mendemonstrasikan penggunaan array satu dimensi dalam C++. Berikut adalah penjelasan langkah demi langkah:

1. **Deklarasi Array**: Program mendeklarasikan array integer `arr[5]` yang dapat menampung 5 elemen.

2. **Input Data menggunakan For Loop**: Program menggunakan perulangan `for` untuk meminta pengguna memasukkan 5 nilai ke dalam array. Setiap iterasi meminta input untuk indeks ke-i.

3. **Output Data menggunakan While Loop**: Program menggunakan perulangan `while` untuk menampilkan semua elemen array yang telah diinput oleh pengguna.

4. **Pengaksesan Elemen**: Elemen array diakses menggunakan notasi `arr[indeks]` dimana indeks dimulai dari 0.

### 2. Array2 dimensi 

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan :" << endl;
    tampilkanHasil(arrC);

    cout << endl;

    // perkalian matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrD[i][j] = 0; // reset biar aman
            for(int k = 0; k < 2; k++){
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian :" << endl;
    tampilkanHasil(arrD);

    return 0;
}
```

**Penjelasan Program:**

Program ini mendemonstrasikan operasi matematika pada matriks 2x2 menggunakan array dua dimensi:

1. **Fungsi tampilkanHasil()**: Fungsi untuk menampilkan isi matriks 2x2 dengan format yang rapi menggunakan nested loop.

2. **Inisialisasi Matriks**: Program mendeklarasikan empat matriks 2x2:
   - `arrA` dan `arrB`: matriks input dengan nilai yang sudah ditentukan
   - `arrC` dan `arrD`: matriks untuk menyimpan hasil operasi

3. **Penjumlahan Matriks**: Menggunakan nested loop untuk menjumlahkan elemen-elemen matriks A dan B secara element-wise.

4. **Perkalian Matriks**: Implementasi algoritma perkalian matriks menggunakan triple nested loop, dimana setiap elemen hasil merupakan dot product dari baris matriks A dengan kolom matriks B.

5. **Reset Safety**: Pada perkalian matriks, dilakukan reset `arrD[i][j] = 0` untuk memastikan tidak ada nilai sampah.

### 3. Arrnpointer

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer menunjuk ke elemen pertama

    // Cetak menggunakan pointer
    for (int i = 0; i < 5; ++i) {
        cout << "Elemen array ke-" << i + 1 
             << " menggunakan pointer: " << *(ptr + i) << endl;
    }

    // Cetak menggunakan indeks
    for (int i = 0; i < 5; ++i) {
        cout << "Elemen array ke-" << i + 1 <<"menggunakan indeks:" << arr[i] << endl;
    }

    return 0;
}
```

**Penjelasan Program:**

Program ini mendemonstrasikan hubungan antara array dan pointer dalam C++:

1. **Deklarasi Array dan Pointer**: 
   - Array `arr[]` diinisialisasi dengan 5 elemen {10, 20, 30, 40, 50}
   - Pointer `ptr` diarahkan ke alamat elemen pertama array (`arr`)

2. **Akses Menggunakan Pointer Arithmetic**: 
   - `*(ptr + i)` menggunakan aritmatika pointer untuk mengakses elemen ke-i
   - Pointer arithmetic memungkinkan navigasi melalui elemen array dengan menambahkan offset

3. **Akses Menggunakan Indeks Konvensional**: 
   - `arr[i]` menggunakan notasi subscript standar untuk mengakses elemen
   - Secara internal, `arr[i]` setara dengan `*(arr + i)`

4. **Konsep Penting**: Program menunjukkan bahwa nama array (`arr`) adalah pointer konstan yang menunjuk ke elemen pertama, sehingga `ptr = arr` valid tanpa operator `&`.

### 4. Fungsi prosedur

```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 }
```

**Penjelasan Program:**

Program ini mendemonstrasikan tiga jenis struktur perulangan dalam C++ dengan perilaku yang berbeda:

1. **Perulangan FOR**: 
   - Mencetak angka dari 0 hingga (angka1-1)
   - Kondisi: `i < angka1`
   - Akan tereksekusi jika angka1 > 0

2. **Perulangan WHILE**: 
   - Mencetak angka dari 10 menurun hingga angka yang lebih besar dari angka1
   - Kondisi: `j > angka1` 
   - Akan tereksekusi hanya jika angka1 < 10
   - Jika angka1 ≥ 10, perulangan tidak akan dieksekusi sama sekali

3. **Perulangan DO-WHILE**: 
   - Mencetak angka 10 minimal satu kali
   - Kondisi: `k < angka1`
   - Karena k = 10 dan kondisi `k < angka1`, perulangan akan berhenti setelah satu iterasi kecuali angka1 > 10
   - Karakteristik: kondisi dicek setelah eksekusi, sehingga minimal dijalankan sekali

**Perbedaan Kunci**: FOR dan WHILE mengecek kondisi sebelum eksekusi, sedangkan DO-WHILE mengecek setelah eksekusi pertama.

## Unguided 

### 1. Buatlah program untuk menampilkan nilai maksimum dari kumpulan data yang diinput menggunakan array dan fungsi.

```C++
#include <iostream>
using namespace std;
const int SIZE = 3;
void cetakMatriks(int M[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            cout << M[r][c] << " ";
        }
        cout << endl;
    }
}

void tambah(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            C[r][c] = A[r][c] + B[r][c];
        }
    }
    cout << "\n>> Hasil Penjumlahan Matriks:\n";
    cetakMatriks(C);
}

void kurang(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            C[r][c] = A[r][c] - B[r][c];
        }
    }
    cout << "\n>> Hasil Pengurangan Matriks:\n";
    cetakMatriks(C);
}

void kali(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            C[r][c] = 0;
        }
    }

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            for (int k = 0; k < SIZE; k++) {
                C[r][c] += A[r][k] * B[k][c];
            }
        }
    }
    cout << "\n>> Hasil Perkalian Matriks:\n";
    cetakMatriks(C);
}

int main() {
    int A[SIZE][SIZE] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int B[SIZE][SIZE] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int C[SIZE][SIZE];
    int pilih;

    do {
        cout << "\n==== MENU OPERASI MATRIKS ====\n";
        cout << "1. Tambah Matriks\n";
        cout << "2. Kurang Matriks\n";
        cout << "3. Kali Matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih [1-4]: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambah(A, B, C); break;
            case 2: kurang(A, B, C); break;
            case 3: kali(A, B, C); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 4);

    return 0;
}
```

**Penjelasan Program:**

Program ini merupakan kalkulator matriks 3x3 yang menggunakan konsep fungsi dan array dua dimensi:

1. **Konstanta SIZE**: Mendefinisikan ukuran matriks (3x3) menggunakan `const int SIZE = 3` untuk memudahkan maintenance.

2. **Fungsi cetakMatriks()**: 
   - Mencetak matriks dalam format yang rapi
   - Menggunakan nested loop untuk traversal baris dan kolom

3. **Fungsi tambah()**: 
   - Melakukan penjumlahan dua matriks secara element-wise
   - Formula: `C[r][c] = A[r][c] + B[r][c]`
   - Langsung menampilkan hasil setelah perhitungan

4. **Fungsi kurang()**: 
   - Melakukan pengurangan dua matriks secara element-wise
   - Formula: `C[r][c] = A[r][c] - B[r][c]`

5. **Fungsi kali()**: 
   - Implementasi algoritma perkalian matriks
   - Inisialisasi matriks hasil dengan 0
   - Triple nested loop untuk dot product baris × kolom
   - Formula: `C[r][c] += A[r][k] * B[k][c]`

6. **Menu Interaktif**: Program menyediakan menu do-while yang terus berjalan hingga user memilih keluar.

### Output Unguided 1 :

##### Output 
![Keluaran1](https://raw.githubusercontent.com/hanif-12-01/STRUKTUR_DATA_MHANIFALFAIZ/master/WEEK%202/Keluaran1.png)

Program ini menunjukkan implementasi operasi matriks menggunakan fungsi modular, dimana setiap operasi (penjumlahan, pengurangan, perkalian) dipisahkan dalam fungsi terpisah untuk meningkatkan readability dan reusability kode. 

### 2. Buatlah program mencari nilai maksimum dan minimum dari sekumpulan data menggunakan pointer.

```C++
#include <iostream>
using namespace std;
int main() {
    int pj, lb, L, K;

    cout << "--- Program Luas & Keliling Persegi Panjang ---" << endl;
    cout << "Masukkan panjang: ";
    cin >> pj;
    cout << "Masukkan lebar: ";
    cin >> lb;

    int *pPj = &pj;
    int *pLb = &lb;

    L = (*pPj) * (*pLb);
    K = 2 * ((*pPj) + (*pLb));

    cout << "\nHasil Perhitungan Awal:" << endl;
    cout << "Luas     = " << L << endl;
    cout << "Keliling = " << K << endl;

    *pPj += 2;  
    *pLb += 1;  

    L = (*pPj) * (*pLb);
    K = 2 * ((*pPj) + (*pLb));

    cout << "\nSetelah Nilai Diubah via Pointer:" << endl;
    cout << "Panjang Baru = " << pj << endl;
    cout << "Lebar Baru   = " << lb << endl;
    cout << "Luas Baru    = " << L << endl;
    cout << "Keliling Baru= " << K << endl;

    return 0;
}
```

**Penjelasan Program:**

Program ini mendemonstrasikan penggunaan pointer untuk manipulasi data dan perhitungan geometri:

1. **Input dari User**: 
   - Program meminta input panjang dan lebar dari pengguna
   - Data disimpan dalam variabel `pj` dan `lb`

2. **Deklarasi Pointer**: 
   - `int *pPj = &pj;` - pointer yang menunjuk ke alamat variabel panjang
   - `int *pLb = &lb;` - pointer yang menunjuk ke alamat variabel lebar

3. **Perhitungan Awal**: 
   - Luas: `L = (*pPj) * (*pLb)` - menggunakan dereferencing pointer
   - Keliling: `K = 2 * ((*pPj) + (*pLb))` - formula keliling persegi panjang

4. **Manipulasi via Pointer**: 
   - `*pPj += 2;` - menambah nilai panjang sebesar 2 melalui pointer
   - `*pLb += 1;` - menambah nilai lebar sebesar 1 melalui pointer

5. **Perhitungan Ulang**: 
   - Program menghitung ulang luas dan keliling dengan nilai yang telah dimodifikasi
   - Menunjukkan bahwa perubahan melalui pointer mempengaruhi variabel asli

**Konsep Penting**:
- **Dereferencing**: Operator `*` digunakan untuk mengakses nilai yang ditunjuk pointer
- **Address-of**: Operator `&` digunakan untuk mendapatkan alamat variabel
- **Pointer Modification**: Mengubah nilai melalui pointer akan mengubah variabel asli
### Output Unguided 2 :

##### Output 
![Keluaran2](https://github.com/gamel12/Struktur-datagamel/blob/main/week2/ug2.png)

Program ini mendemonstrasikan konsep pointer dalam C++ untuk perhitungan luas dan keliling persegi panjang, dimana nilai dapat dimodifikasi melalui pointer dan mempengaruhi variabel asli tanpa menggunakan fungsi terpisah.

## Kesimpulan

Berdasarkan praktikum Modul 2 "Pengenalan Bahasa C++ (Bagian Kedua)" yang telah dilaksanakan, dapat disimpulkan bahwa pemahaman mengenai array, pointer, fungsi, dan struktur perulangan merupakan fondasi esensial dalam pemrograman C++ yang harus dikuasai untuk mengembangkan aplikasi yang efisien dan terstruktur.

**Implementasi Array dan Struktur Data:**
Praktikum ini berhasil mendemonstrasikan penggunaan array satu dimensi untuk pengelolaan data sekuensial dan array dua dimensi untuk representasi matriks. Melalui guided practice, terbukti bahwa array menyediakan cara yang efisien untuk menyimpan dan mengakses kumpulan data dengan tipe yang sama. Implementasi operasi matriks (penjumlahan dan perkalian) menunjukkan kemampuan array multidimensi dalam menangani struktur data yang kompleks, yang sangat penting dalam komputasi matematis dan algoritma.

**Konsep Pointer dan Manajemen Memori:**
Pemahaman pointer sebagai variabel yang menyimpan alamat memori telah terbukti memberikan fleksibilitas tinggi dalam manipulasi data. Praktikum menunjukkan hubungan erat antara array dan pointer, dimana nama array pada dasarnya adalah pointer konstan ke elemen pertama. Kemampuan pointer arithmetic (`*(ptr + i)`) memberikan alternatif akses elemen array yang lebih fundamental dibandingkan notasi subscript konvensional. Dalam unguided practice, demonstrasi manipulasi nilai melalui pointer membuktikan bahwa perubahan nilai melalui dereferencing pointer secara langsung mempengaruhi variabel asli, konsep yang krusial untuk pass-by-reference dan alokasi memori dinamis.

**Modularitas melalui Fungsi:**
Implementasi fungsi dalam kalkulator matriks 3x3 (unguided 1) mendemonstrasikan prinsip pemrograman modular yang meningkatkan keterbacaan, maintainability, dan reusability kode. Pemisahan logika menjadi fungsi-fungsi spesifik (`tambah()`, `kurang()`, `kali()`, `cetakMatriks()`) membuktikan bahwa pendekatan modular memudahkan debugging dan pengembangan program yang lebih kompleks. Penggunaan konstanta `SIZE` juga menunjukkan praktik terbaik dalam penulisan kode yang mudah dimodifikasi.

**Struktur Kontrol dan Perulangan:**
Praktikum berhasil mengeksplorasi tiga jenis perulangan (for, while, do-while) yang masing-masing memiliki karakteristik dan kegunaan spesifik. Perbedaan mendasar antara kondisi pre-check (for, while) dan post-check (do-while) memberikan pemahaman yang solid tentang kapan menggunakan struktur perulangan tertentu berdasarkan kebutuhan logika program.

**Integrasi Konsep dan Aplikasi Praktis:**
Keseluruhan praktikum menunjukkan bagaimana konsep-konsep fundamental C++ dapat diintegrasikan untuk membangun aplikasi yang fungsional. Menu interaktif dalam program kalkulator matriks menggabungkan struktur kontrol (do-while, switch-case), fungsi modular, array multidimensi, dan input/output, menciptakan pengalaman pembelajaran yang holistik.

**Implikasi untuk Pengembangan Selanjutnya:**
Penguasaan array, pointer, dan fungsi yang telah diperoleh melalui praktikum ini membentuk fondasi solid untuk mempelajari konsep-konsep lanjutan seperti struktur data dinamis (linked list, tree), algoritma kompleks, dan pemrograman berorientasi objek. Kemampuan untuk berpikir dalam konteks alamat memori (pointer) dan strukturisasi kode (fungsi) merupakan keterampilan fundamental yang akan terus relevan dalam pengembangan software yang skalabel dan efisien.

Secara keseluruhan, praktikum ini berhasil membangun pemahaman komprehensif tentang building blocks pemrograman C++ yang akan menjadi dasar untuk eksplorasi topik-topik advanced programming selanjutnya.



## Referensi
## Daftar Pustaka

1. Universitas Logistik dan Bisnis Internasional. (2025). Modul 2_Pengenalan Bahasa C++ (Bagian Kedua).
Diakses dari: https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/85988811/1a452c49-a1e8-408f-9fd0-3e6080d407e6/Modul-2_Pengenalan-Bahasa-C-Bagian-Kedua.pdf

2. Universitas Komputer Indonesia. (2025). ARRAY DALAM C++.
Diakses dari: https://repository.unikom.ac.id/69155/1/Array%20dalam%20c++.pdf

3. GitHub Pages UCL. (2025). Pointer dalam C++.
Diakses dari: https://translate.google.com/translate?u=https%3A%2F%2Fgithub-pages.ucl.ac.uk%2Fresearch-computing-with-cpp%2F02cpp1%2Fsec05Pointers.html&hl=id&sl=en&tl=id&client=srp

4. Laporan Praktikum Algoritma Pemrograman (6) – Fungsi & Prosedur. (2025).
Diakses dari: https://id.scribd.com/document/556296944/Laporan-Praktikum-Algoritma-Pemrograman-6-Fungsi-Prosedur-docx




