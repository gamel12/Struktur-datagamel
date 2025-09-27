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
