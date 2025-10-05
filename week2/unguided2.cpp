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
