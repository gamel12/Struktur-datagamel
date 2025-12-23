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

void createListParent(ListParent &L);
void createListChild(ListChild &L);
NodeParent* alokasiNodeParent(string id, string nama);
NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void insertFirstParent(ListParent &L, NodeParent *P);
void insertLastChild(ListChild &L, NodeChild *P);
void hapusListChild(ListChild &L);
void deleteAfterParent(ListParent &L, NodeParent *prec, NodeParent *&P);
void searchFilmByRatingRange(ListParent L, float low, float high);
void printStrukturMLL(ListParent L);