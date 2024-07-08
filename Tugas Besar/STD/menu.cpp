#include "OrganisasiKampus.h"
#include <iostream>

int mainMenu() {
  cout << "=================================" << endl;
  cout << "|        nama kelompok           |" << endl;
  cout << "=================================" << endl;
  cout << "|Muahamad Rafi Raihan Akbar      |" << endl;
  cout << "|marchiano                       |" << endl;
  cout << "=================================" << endl;

  cout << "=================================" << endl;
  cout << "|  Aplikasi Organisasi Kampus    |" << endl;
  cout << "=================================" << endl;
  cout << "| [1] mahasiswa                  |" << endl;
  cout << "| [2] organisasi                 |" << endl;
  cout << "| [0] Keluar                     |" << endl;
  cout << "=================================" << endl;
  int select;
  cout << "Pilih Menu : ";
  cin >> select;
  return select;
};
//--------------------------------------------------------------------------------------------------------
// menu organisasi
int menuorganisasi() {
  cout << "=================================" << endl;
  cout << "|        Menu Organisasi         |" << endl;
  cout << "=================================" << endl;
  cout << "| [1] insert organisasi          |" << endl;
  cout << "| [2] delate organisasi          |" << endl;
  cout << "| [3] show and count             |" << endl;
  cout << "| [4] find by name               |" << endl;
  cout << "| [5] edit organisasi            |" << endl;
  cout << "| [0] Keluar                     |" << endl;
  cout << "=================================" << endl;
  int select;
  cout << "Pilih Menu : ";
  cin >> select;
  return select;
};

void menuinsertorganisasi(ListORG &L) {
  cout << "=================================" << endl;
  cout << "|       insert Organisasi       |" << endl;
  cout << "=================================" << endl;
  infotypeORG y;
  cout << "nama organisasi: ";
  cin >> y.NamaOrganisasi;
  cout << "Jumlah anggota: ";
  cin >> y.Jumlah_Anggota;
  cout << "tahun berdiri: ";
  cin >> y.Tahun_Berdiri;
  cout << "=================================" << endl;
  adrORG newy = createElmtORG(y);
  insertLastORG(L, newy);
};

void menudeleteoganisasi(ListORG &L) {
  cout << "=================================" << endl;
  cout << "|        delate Organisasi      |" << endl;
  cout << "=================================" << endl;
  deleteOrg(L);
};
void menuShowandCountorganisasi(ListORG &L) {
  cout << "=================================" << endl;
  cout << "|   Show and Count Organisasi   |" << endl;
  cout << "=================================" << endl;
  showORG(L);
  countORG(L);
  cout << "=================================" << endl;
};
void menufindorganisasi(ListORG &L) {
  string NamaOrganisasi;
  cout << "=================================" << endl;
  cout << "|          Find by name         |" << endl;
  cout << "=================================" << endl;
  cout << "Input Nama Organisasi: ";
  cin >> NamaOrganisasi;
  adrORG f = findORG(L, NamaOrganisasi);
  if (f != NULL) {
    cout << "Nama Organisasi: " << f->infoORG.NamaOrganisasi << endl;
    cout << "Jumlah Anggota: " << f->infoORG.Jumlah_Anggota << endl;
    cout << "Tahun:" << f->infoORG.Tahun_Berdiri << endl;
  } else {
    cout << "Organisasi tidak ditemukan" << endl;
  }
};
void menuEditorganisasi(ListORG &L) {
  infotypeORG kode;
  cout << "=================================" << endl;
  cout << "|       Edit Organisasi         |" << endl;
  cout << "=================================" << endl;
  editOrg(L, kode.id);
  cout << "=================================" << endl;
};
//--------------------------------------------------------------------------------------------------------
// menu mahasiswa

int menumahasiswa() {
  cout << "=================================" << endl;
  cout << "|        Menu Mahasiswa          |" << endl;
  cout << "=================================" << endl;
  cout << "| [1] insert mahasiswa           |" << endl;
  cout << "| [2] delate mahasiswa           |" << endl;
  cout << "| [3] show and count             |" << endl;
  cout << "| [4] find by name               |" << endl;
  cout << "| [0] Keluar                     |" << endl;
  cout << "=================================" << endl;
  int select;
  cout << "Pilih Menu : ";
  cin >> select;
  return select;
};

// insert mahasiswa

void menuinsertmahasiswa(ListMHS &L) {
  cout << "=================================" << endl;
  cout << "|        insert mahasiswa        |" << endl;
  cout << "=================================" << endl;
  infotypeMHS m;
  cout << "input nama: ";
  cin >> m.Nama;
  cout << "input nim: ";
  cin >> m.Nim;
  cout << "input jurusan: ";
  cin >> m.Jurusan;
  cout << "input angkatan: ";
  cin >> m.Angkatan;
  cout << "=================================" << endl;
  adrMHS newM = createElmtMHS(m);
  cout << "Data berhasil ditambahkan" << endl;
  insertLastMHS(L, newM);
};

// delate mahasiswa

void menudeletemahasiswa(ListMHS &L) {
  cout << "=================================" << endl;
  cout << "|        delete mahasiswa       |" << endl;
  cout << "=================================" << endl;
  deleteMahasiswa(L);
};

// show and count mahasiswa
void menuShowandCountmahasiswa(ListMHS &L) {
  cout << "=================================" << endl;
  cout << "|    Show and Count Mahasiswa   |" << endl;
  cout << "=================================" << endl;
  showMHS(L);
  countMHS(L);
  cout << "=================================" << endl;
};

// find by name mahasiswa

void menufindmahasiswa(ListMHS &L) {
  string NamaMahasiswa;
  cout << "=================================" << endl;
  cout << "|          Find by name         |" << endl;
  cout << "=================================" << endl;
  findMHS(L, NamaMahasiswa);
  adrMHS f = findMHS(L, NamaMahasiswa);
  if (f != NULL) {
    cout << "Nama     : " << f->infoMHS.Nama << endl;
    cout << "nim      : " << f->infoMHS.Nim<< endl;
    cout << "jurusan  :" << f->infoMHS.Jurusan << endl;
    cout << "angkatan :" << f->infoMHS.Angkatan << endl;
  } else {
    cout << "Organisasi tidak ditemukan" << endl;
  }
};
