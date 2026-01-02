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
