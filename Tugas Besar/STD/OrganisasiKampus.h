#ifndef ORGANISASIKAMPUS_H_INCLUDED
#define ORGANISASIKAMPUS_H_INCLUDED

#include <iostream>
using namespace std;

// chill (dll) MHS
#define firstMHS(L) L.firstMHS
#define lastMHS(L) L.lastMHS
#define infoMHS(P) P->infoMHS
#define nextMHS(P) P->nextMHS
#define prevMHS(P) P->prevMHS

// Parent (csll) ORG
#define firstORG(L) L.firstORG
#define lastORG(L) L.lastORG
#define infoORG(P) P->infoORG
#define nextORG(P) P->nextORG

// organisasi
struct Organisasi {
  string NamaOrganisasi, id;
  int Jumlah_Anggota, Tahun_Berdiri;
};

typedef Organisasi infotypeORG;
typedef struct ElmtORG *adrORG;

struct ElmtORG {
  infotypeORG infoORG;
  adrORG nextORG;
};

struct ListORG {
  adrORG firstORG, lastORG;
};

// mahasiswa
struct Mahasiswa {
  string Nama, Nim, Jurusan, Angkatan;
};

typedef Mahasiswa infotypeMHS;
typedef struct ElmtMHS *adrMHS;

struct ElmtMHS {
  infotypeMHS infoMHS;
  adrMHS nextMHS, prevMHS;
};

struct ListMHS {
  adrMHS firstMHS, lastMHS;
};

//--------------------------------------------------------------------------------------------------------

// Organisasi CSLL
void createListORG(ListORG &L);
adrORG createElmtORG(infotypeORG X);
void insertLastORG(ListORG &L, adrORG P);
// percobaan
void editOrg(ListORG &L, string id);

// delete Organisasi
void deleteFirstORG(ListORG &L, adrORG &P);
void deleteLastORG(ListORG &L, adrORG &P);
void deleteAfterORG(ListORG &L, adrORG prec, adrORG &P);
void deleteOrg(ListORG &L);

// cari Organisasi
adrORG findORG(ListORG L, string NamaOrganisasi);

// show Organisasi
void showORG(ListORG L);
int countORG(ListORG L);

//--------------------------------------------------------------------------------------------------------

// Mahasiswa DLL
void createListMHS(ListMHS &L);
adrMHS createElmtMHS(infotypeMHS X);
void insertLastMHS(ListMHS &L, adrMHS P);

// delete Mahasiswa
void deleteFirstMHS(ListMHS &L, adrMHS &P);
void deleteLastMHS(ListMHS &L, adrMHS &P);
void deleteAfterMHS(ListMHS &L, adrMHS prec, adrMHS &P);
void deleteMahasiswa(ListMHS &L);

// cari Mahasiswa
adrMHS findMHS(ListMHS L, string NamaMahasiswa);

// show Mahasiswa
void showMHS(ListMHS L);
void countMHS(ListMHS L);

//--------------------------------------------------------------------------------------------------------
// Menu

int mainMenu();

// menu organisasi
int menuorganisasi();
void menuinsertorganisasi(ListORG &L);
void menudeleteoganisasi(ListORG &L);
void menuShowandCountorganisasi(ListORG &L);
void menufindorganisasi(ListORG &L);

// menu mahasiswa
int menumahasiswa();
void menuinsertmahasiswa(ListMHS &L);
void menudeletemahasiswa(ListMHS &L);
void menuShowandCountmahasiswa(ListMHS &L);
void menufindmahasiswa(ListMHS &L);
void menuEditorganisasi(ListORG &L);

#endif // ORGANISASIKAMPUS_H_INCLUDED
