#include "mll.h"

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent* P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    createListChild(P->childs);
    P->next = NULL;
    P->prev = NULL;
    return P;
}

NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild* P = new NodeChild;
    P->IDFilm = id;
    P->judulFilm = judul;
    P->durasiFilm = durasi;
    P->tahunTayang = tahun;
    P->ratingFilm = rating;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstParent(ListParent &L, NodeParent *P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(ListChild &L, NodeChild *P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void hapusListChild(ListChild &L) {
    NodeChild *P = L.first;
    while (P != NULL) {
        NodeChild *temp = P;
        P = P->next;
        delete temp;
    }
    L.first = NULL;
    L.last = NULL;
}

void deleteAfterParent(ListParent &L, NodeParent *prec, NodeParent *&P) {
    P = prec->next;
    if (P != NULL) {
        hapusListChild(P->childs);
        prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = prec;
        } else {
            L.last = prec;
        }
        P->next = NULL;
        P->prev = NULL;
        delete P;
    }
}

void searchFilmByRatingRange(ListParent L, float low, float high) {
    NodeParent *P = L.first;
    while (P != NULL) {
        NodeChild *C = P->childs.first;
        int posChild = 1;
        while (C != NULL) {
            if (C->ratingFilm >= low && C->ratingFilm <= high) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << endl;
                cout << "Judul Film : " << C->judulFilm << " | Rating : " << C->ratingFilm << endl;
                cout << "Genre : " << P->namaGenre << endl;
                cout << "------------------------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
    }
}

void printStrukturMLL(ListParent L) {
    NodeParent *P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->IDGenre << " | Nama : " << P->namaGenre << endl;
        NodeChild *C = P->childs.first;
        while (C != NULL) {
            cout << "  - ID Film : " << C->IDFilm << " | Judul : " << C->judulFilm << endl;
            C = C->next;
        }
        P = P->next;
        i++;
    }
}

int main() {
    ListParent LP;
    createListParent(LP);

    insertFirstParent(LP, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(LP, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(LP, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(LP, alokasiNodeParent("G001", "Action"));

    NodeParent *curr = LP.first; 
    insertLastChild(curr->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    curr = curr->next; 
    insertLastChild(curr->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(curr->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    curr = curr->next; 
    insertLastChild(curr->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    curr = curr->next; 
    insertLastChild(curr->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(curr->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    cout << "Struktur MLL Awal:" << endl;
    printStrukturMLL(LP);

    cout << "\nPencarian Rating 8.0 - 8.5:" << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);

    cout << "\nMenghapus Genre G002 (Comedy):" << endl;
    NodeParent *del;
    deleteAfterParent(LP, LP.first, del);

    cout << "\nStruktur MLL Akhir:" << endl;
    printStrukturMLL(LP);

    return 0;
}