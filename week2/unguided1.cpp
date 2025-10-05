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
