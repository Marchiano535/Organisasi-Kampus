#include "OrganisasiKampus.h"
#include <iostream>
#include <limits>
using namespace std;

//--------------------------------------------------------------------------------------------------------

// Organisasi CSLL
void createListORG(ListORG &L) { firstORG(L) = NULL; }

adrORG createElmtORG(infotypeORG X) {
  adrORG P = new ElmtORG;
  infoORG(P) = X;
  nextORG(P) = P;
  return P;
}

void insertLastORG(ListORG &L, adrORG P) {
  if (firstORG(L) == NULL) {
    firstORG(L) = P;
  } else {
    adrORG X = firstORG(L);
    do {
      X = nextORG(X);
    } while (nextORG(X) != firstORG(L));
    nextORG(X) = P;
    nextORG(P) = firstORG(L);
  }
}

void deleteFirstORG(ListORG &L, adrORG &P) {
  if (firstORG(L) == NULL) {
    cout << "List Organisasi Kosong" << endl;
  } else if (nextORG(firstORG(L)) == firstORG(L)) {
    P = firstORG(L);
    firstORG(L) = NULL;

  } else {
    P = firstORG(L);
    adrORG X = firstORG(L);
    while (nextORG(X) != firstORG(L)) {
      X = nextORG(X);
    }
    firstORG(L) = nextORG(P);
    nextORG(X) = firstORG(L);
    nextORG(P) = NULL;
  }
}

void deleteLastORG(ListORG &L, adrORG &P) {
  adrORG X;
  if (firstORG(L) == NULL) {
    cout << "List Organisasi Kosong" << endl;
  } else if (nextORG(firstORG(L)) == firstORG(L)) {
    P = firstORG(L);
    firstORG(L) = NULL;
  } else {
    X = firstORG(L);
    while (nextORG(nextORG(X)) != firstORG(L)) {
      X = nextORG(X);
    }
    P = nextORG(X);
    nextORG(X) = firstORG(L);
    nextORG(P) = NULL;
  }
}

void deleteAfterORG(ListORG &L, adrORG prec, adrORG &P) {
  if (firstORG(L) == NULL) {
    cout << "List Organisasi Kosong" << endl;
  } else if (nextORG(prec) == NULL) {
    cout << " tidak ada elemen setelah prec" << endl;
  } else if (nextORG(nextORG(prec)) == firstORG(L)) {
    deleteLastORG(L, P);
  } else {
    P = nextORG(prec);
    nextORG(prec) = nextORG(P);
    nextORG(P) = NULL;
  }
}

void deleteOrg(ListORG &L) {
  string NamaOrganisasi;
  cin >> NamaOrganisasi;
  adrORG N = findORG(L, NamaOrganisasi);

  adrORG Z = firstORG(L);
  adrORG prec;
  while (Z != NULL) {
    if (Z == N) {

      if (Z == firstORG(L)) {
        deleteFirstORG(L, Z);
      } else if (Z == lastORG(L)) {
        deleteLastORG(L, Z);
      } else {
        deleteAfterORG(L, prec, Z);
      };

      cout << "Mahasiswa Successfully Deleted." << endl;
      return;
    };
    prec = Z;
    Z = nextORG(Z);
  };
  cout << "Mahasiswa Unsucsessfully Deleted." << endl;
};

adrORG findORG(ListORG L, string NamaOrganisasi) {
  adrORG X = firstORG(L);
  do {
    if (infoORG(X).NamaOrganisasi == NamaOrganisasi) {
      return X;
    }
    X = nextORG(X);
  } while (X != firstORG(L));

  return NULL;
}
void showORG(ListORG L) {
  adrORG X = firstORG(L);
  cout << "-- Organisasi --" << endl;
  do {
    cout << "Nama Organisasi " << infoORG(X).NamaOrganisasi << endl;
    cout << "Jumlah Anggota " << infoORG(X).Jumlah_Anggota << endl;
    cout << "Tahun Berdiri  " << infoORG(X).Tahun_Berdiri << endl;
    cout << endl;
    X = nextORG(X);
  } while (X != firstORG(L));
}
int countORG(ListORG L) {
  int count = 0;
  if (firstORG(L) == NULL) {
    cout << "Banyak element list Organisasi " << count << endl;
  } else {
    adrORG X = firstORG(L);
    do {
      count++;
      X = nextORG(X);
    } while (X != firstORG(L));
    cout << "Banyak element list Organisasi " << count << endl;
  }
  return count;
}
void editOrg(ListORG &L, string id) {
  adrORG X = firstORG(L);
  if (X == NULL) {
    cout << "List Kosong" << endl;
    return;
  }
  do {
    if (infoORG(X).NamaOrganisasi == id) {
      cout << "No id: " << infoORG(X).id << endl;
      cout << "Nama: " << infoORG(X).NamaOrganisasi << endl;
      cout << "Jumlah Anggotan: " << infoORG(X).Jumlah_Anggota << endl;
      cout << "------------------------------------" << endl;
      cout << "Masukkan Nama Organisasi: ";
      cin >> infoORG(X).NamaOrganisasi;
      // Validasi input untuk memastikan input adalah integer
      while (true) {
        cout << "Masukkan Jumlah Anggota: ";
        cin >> infoORG(X).Jumlah_Anggota;
        if (cin.fail()) {
          // Handle kesalahan input yang bukan integer
          cin.clear(); // Membersihkan status error pada cin
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Input harus berupa angka. Silakan coba lagi." << endl;
        } else {
          // input valid, keluar dari loop
          break;
        }
      }
      cout << "data berhasil di edit" << endl;
      return;
    }
    X = nextORG(X);
  } while (X != firstORG(L));
  cout << "Organisasi tidak ditemukan" << endl;
};

//--------------------------------------------------------------------------------------------------------

// Mahasiswa DLL

void createListMHS(ListMHS &L) {
  firstMHS(L) = NULL;
  lastMHS(L) = NULL;
}

adrMHS createElmtMHS(infotypeMHS X) {
  adrMHS P = new ElmtMHS;
  infoMHS(P) = X;
  nextMHS(P) = NULL;
  prevMHS(P) = NULL;
  return P;
}

void insertLastMHS(ListMHS &L, adrMHS P) {
  if (firstMHS(L) == NULL) {
    firstMHS(L) = P;
    lastMHS(L) = P;
  } else {
    nextMHS(lastMHS(L)) = P;
    prevMHS(P) = lastMHS(L);
    lastMHS(L) = P;
  }
}

void deleteFirstMHS(ListMHS &L, adrMHS &P) {
  if (firstMHS(L) == NULL) {
    cout << "List Mahasiswa Kosong" << endl;
  } else if (nextMHS(firstMHS(L)) == NULL) {
    P = firstMHS(L);
    firstMHS(L) = NULL;
  } else {
    P = firstMHS(L);
    firstMHS(L) = nextMHS(firstMHS(L));
    nextMHS(P) = NULL;
  }
}

void deleteLastMHS(ListMHS &L, adrMHS &P) {
  if (firstMHS(L) == NULL) {
    cout << "List Mahasiswa Kosong" << endl;
  } else if (firstMHS(L) == lastMHS(L)) {
    P = firstMHS(L);
    firstMHS(L) = NULL;
    lastMHS(L) = NULL;
  } else {
    P = lastMHS(L);
    lastMHS(L) = prevMHS(P);
    nextMHS(lastMHS(L)) = NULL;
    prevMHS(P) = NULL;
  }
}

void deleteAfterMHS(ListMHS &L, adrMHS prec, adrMHS &P) {
  if (firstMHS(L) == NULL) {
    cout << "List Kosong Mahasiswa" << endl;
  } else if (nextMHS(prec) == NULL) {
    cout << "Tidak ada oganisasi setelah prec" << endl;
  } else if (nextMHS(nextMHS(prec)) == NULL) {
    deleteLastMHS(L, P);
  } else {
    P = nextMHS(prec);
    nextMHS(prec) = nextMHS(P);
    prevMHS(nextMHS(P)) = prec;
    prevMHS(P) = NULL;
    nextMHS(P) = NULL;
  }
}

void deleteMahasiswa(ListMHS &L) {
  string NamaMahasiswa;
  cout << "input nama mahasiswa: ";
  cin >> NamaMahasiswa;
  adrMHS M = findMHS(L, NamaMahasiswa);

  adrMHS O = firstMHS(L);
  adrMHS prec;
  while (O != NULL) {
    if (O == M) {

      if (O == firstMHS(L)) {
        deleteFirstMHS(L, O);
      } else if (O == lastMHS(L)) {
        deleteLastMHS(L, O);
      } else {
        deleteAfterMHS(L, prec, O);
      };

      cout << "Mahasiswa Successfully Deleted." << endl;
      return;
    };
    prec = O;
    O = nextMHS(O);
  };
  cout << "Mahasiswa Unsucsessfully Deleted." << endl;
};

adrMHS findMHS(ListMHS L, string NamaMahasiswa) {
  adrMHS P = firstMHS(L);
  while (P != NULL) {
    if (infoMHS(P).Nama == NamaMahasiswa) {
      return P;
    }
    P = nextMHS(P);
  }
  return NULL;
}
void showMHS(ListMHS L) {
  adrMHS X = firstMHS(L);
  cout << "-- Mahasiswa --" << endl;
  while (X != NULL) {
    cout << "Nama      :   " << infoMHS(X).Nama << endl;
    cout << "Nim       :   " << infoMHS(X).Nim << endl;
    cout << "Jurusan   :   " << infoMHS(X).Jurusan << endl;
    cout << "Angkatan  :   " << infoMHS(X).Angkatan << endl;
    cout << endl;
    X = nextMHS(X);
  }
}
void countMHS(ListMHS L) {
  int count = 0;
  if (firstMHS(L) == NULL) {
    cout << "Banyak element list mhs" << count << endl;
  } else {
    adrMHS X = firstMHS(L);
    while (X != NULL) {
      count++;
      X = nextMHS(X);
    }
    cout << "Banyak element list mhs" << count << endl;
  }
}
