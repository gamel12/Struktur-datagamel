# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Gamel Al Ghifari - 103112400028</p>

## Dasar Teori
Bahasa pemrograman C++ merupakan pengembangan dari bahasa C yang awalnya diciptakan oleh Bjarne Stroustrup di Bell Labs pada awal 1980-an, menambahkan paradigma pemrograman berorientasi objek sehingga semakin efektif untuk pengembangan perangkat lunak berskala besar dan kompleks [1][4]. C++ dikenal sebagai bahasa tujuan umum yang mendukung multiparadigma, baik prosedural maupun objek [4][3].

Dalam praktiknya, C++ sering digunakan sebagai dasar pembelajaran logika pemrograman dan algoritma pada pendidikan tinggi dan mata kuliah teknologi [2][1]. Salah satu kelebihannya adalah sintaksis, struktur program yang sistematis serta kemampuan manipulasi memori secara tingkat rendah [3].

Struktur program C++ terdiri atas deklarasi variabel, penggunaan tipe data, operator, kontrol program (seperti percabangan dan perulangan), serta modularisasi menggunakan fungsi [3][2]. Pada implementasinya, Dev-C++ maupun CodeBlocks adalah dua IDE populer yang membantu proses penulisan, kompilasi, debugging, dan eksekusi kode secara efisien [1][2]. IDE ini memudahkan pemula dalam pembuatan proyek, karena dilengkapi fitur-fitur pemecahan masalah modern dan tampilan yang ramah pengguna.

Contoh kasus pemanfaatan C++ dalam kehidupan nyata dapat dilihat pada pengembangan sistem informasi perpustakaan. Dengan menggunakan Codeblocks IDE, C++ memungkinkan pendataan, pemrosesan transaksi, serta pelaporan berlangsung cepat dan akurat. Pengembangan aplikasi semacam ini dapat mengurangi tingkat kesalahan data dan meningkatkan efisiensi operasional [5].

Setiap program C++ harus memperhatikan prinsip modular, pemisahan antar fungsi/prosedur, serta penggunaan tipe data dan variabel sesuai kebutuhan algoritma yang sedang dikembangkan [2][3]. Buku-buku dan jurnal terpercaya menjelaskan pentingnya fondasi yang kuat dalam memahami logika, algoritma, dan implementasi program sederhana sebelum melangkah ke konsep lanjutan seperti pemrograman berorientasi objek [6][4][3][1][6][5].


## Guided 

### 1. 

```C++
#include <iostream>
using namespace std;

int main(){
 int angka ;
 cout << "masukan angka : " << endl;
 cin >> angka ;
 cout << "angka yang dimasukan : " << angka << endl;
 return 0;
}
```
penjelasan singkat guided 1

### 2. 

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl;
    cout << "pengurangan :" << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" << angka1 / angka2 << endl;
    cout << "sisa bagi :" << angka1 % angka2 << endl;
    return 0;
}
```
penjelasan singkat guided 2

### 3.

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 :";
    cin >> angka1;
    cout << "masukkan angka 2 :";
    cin >> angka2;

    if (angka1 < angka2){
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }
    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "Masukan pilihan:" << endl;
    cin >> pilihan;

    switch(pilihan){
        case 1:
        cout << "penjumlahan : " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan :" << angka1 - angka2 << endl;
        cout << endl;
        break;
        default : 
        cout << "pilihan salah" << endl;
    }

    return 0;
}
```
penjelasan singkat guided 3

### 4.

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
penjelasan singkat guided 3

### 5.

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        char nama[5];
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
        j++;
    }

    return 0;
    
}
```
penjelasan singkat guided 3

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;
int main() {
    float angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl;
    cout << "pengurangan :" << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" << angka1 / angka2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Tampilan Output](https://raw.githubusercontent.com/gamel12/Struktur-datagamel/main/coso1/Output1.png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;
string angkaKeTeks(int x) {
    string s[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
    string belas[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas",
                      "lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};
    string puluh[] = {"", "", "dua puluh","tiga puluh","empat puluh",
                      "lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};
    if (x < 0 || x > 100) {
        return "di luar batas";
    }
    if (x < 10) {
        return s[x];
    }
    if (x < 20) {
        return belas[x - 10];
    }
    if (x < 100) {
        return puluh[x / 10] + (x % 10 == 0 ? "" : " " + s[x % 10]);
    }
    return "seratus";
}

int main() {
    int angka;
    cout << "Input angka 0-100: ";
    cin >> angka;
    cout << angka << " = " << angkaKeTeks(angka) << "\n";

    return 0;
}

```
### Output Unguided 2 :

##### Output 
![Tampilan Output 2](https://raw.githubusercontent.com/gamel12/Struktur-datagamel/main/coso1/Output2.png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1]Budi Raharjo, 2014, Pemrograman C++ Mudah dan Cepat Menjadi Master C++, menggunakan Dev-C++. Penerbit Informatika Bandung.
<br>[2]Abdul Kadir, 2012, Buku Pintar C++ untuk Pemula, Menggunakan CodeBlocks. Penerbit MediaKom. Yogyakarta.
<br>[3]Hanif Al Fatta, 2006, Dasar Pemrograman C++ Disertai dengan Pengenalan Pemrograman Berorientasi Objek. Penerbit CV Andi Offset. Yogyakarta.
<br>[4]Stroustrup, Bjarne, 2013, The C++ Programming Language, 4th Edition. Addison-Wesley.
<br>[5]Maulidia Nurul Rizayanti & Andy Prasetyo, 2018, “Sistem Informasi Pengolahan Data Perpustakaan Menggunakan Program C++ Berbasis Codeblocks,” Purbaya E-Journal.
<br>[6}Abdul Kadir, 2009, Dasar-dasar Pemrograman C++, Andi
