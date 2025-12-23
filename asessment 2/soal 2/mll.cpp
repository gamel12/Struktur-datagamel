#include <iostream>
#include <string>

using namespace std;

struct NodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild *next, *prev;
};

struct ListChild {
    NodeChild *first, *last;
};

struct NodeParent {
    string IDGenre;
    string namaGenre;
    ListChild childs;
    NodeParent *next, *prev;
};

struct ListParent {
    NodeParent *first, *last;
};

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
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

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent* P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    createListChild(P->childs);
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
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << posChild << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posChild << endl;
                cout << "ID Film : " << C->IDFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "-------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->IDGenre << endl;
                NodeParent *temp = L.first;
                int posParent = 1;
                while (temp != P) { temp = temp->next; posParent++; }
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "==========================================" << endl;
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
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        NodeChild *C = P->childs.first;
        int j = 1;
        while (C != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "    ID Film : " << C->IDFilm << endl;
            cout << "    Judul Film : " << C->judulFilm << endl;
            cout << "    Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << C->tahunTayang << endl;
            cout << "    Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "-------------------------" << endl;
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

    NodeParent *pG001 = LP.first;
    insertLastChild(pG001->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    NodeParent *pG002 = LP.first->next;
    insertLastChild(pG002->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(pG002->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    NodeParent *pG003 = LP.first->next->next;
    insertLastChild(pG003->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    NodeParent *pG004 = LP.last;
    insertLastChild(pG004->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(pG004->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(LP);

    cout << "\n--- Search Film Rating 8.0 - 8.5 ---" << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);

    cout << "\n--- Deleting G002 (After G001) ---" << endl;
    NodeParent *del;
    deleteAfterParent(LP, pG001, del);

    printStrukturMLL(LP);

    return 0;
}