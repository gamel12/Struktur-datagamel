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
