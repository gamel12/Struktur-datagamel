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
