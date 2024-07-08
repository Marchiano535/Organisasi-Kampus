#include "OrganisasiKampus.h"
#include <iostream>
#include <limits>

// fungsi untuk break dan melanjutkan operasi
void pressEnter() {
  string skip;
  cout << "Tekan [enter] untuk melanjutkan...";
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n');   // Membersihkan buffer sampai newline
  getline(cin, skip); // Menggunakan getline untuk menunggu tombol Enter
  cout << endl;
};

void clearScreen() {
#ifdef _WIN32 // Windows
  system("cls");
#else
  (void)system("clear"); // Mac/Linux
#endif
};

int main() {
  // deklarasi list
  ListMHS LM;
  createListMHS(LM);
  ListORG LO;
  createListORG(LO);

  // deklarasi variabel
  int input, inputan;
  bool isExit = false;

  do {
    input = mainMenu();
    clearScreen();
    switch (input) {
    case 1:
      while (!isExit) {
        clearScreen();
        inputan = menumahasiswa();
        switch (inputan) {
        case 1:
          menuinsertmahasiswa(LM);
          pressEnter();
          break;
        case 2:
          menudeletemahasiswa(LM);
          pressEnter();
          break;
        case 3:
          menuShowandCountmahasiswa(LM);
          pressEnter();
          break;
        case 4:
          menufindmahasiswa(LM);
          pressEnter();
          break;
        case 0:
          isExit = true;
          break;
        default:
          clearScreen();
          cout << "Inputan salah" << endl;
          break;
        }
      }
      isExit = false; // kembaliin ke default menu
      clearScreen();
      break;
    case 2:
      while (!isExit) {
        clearScreen();
        inputan = menuorganisasi();
        switch (inputan) {
        case 1:
          menuinsertorganisasi(LO);
          pressEnter();
          break;
        case 2:
          menudeleteoganisasi(LO);
          pressEnter();
          break;
        case 3:
          menuShowandCountorganisasi(LO);
          pressEnter();
          break;
        case 4:
          menufindorganisasi(LO);
          pressEnter();
          break;
        case 5:
          menuEditorganisasi(LO);
          pressEnter();
          break;
        case 0:
          isExit = true;
          break;
        default:
          clearScreen();
          cout << "Inputan salah" << endl;
          break;
        }
      }
      isExit = false; // kembaliin ke default menu
      clearScreen();
      break;
    case 0:
      clearScreen();
      cout << "Terima kasih <_> \ntelah menggunakan program ini" << endl;
      break;
    default:
      cout << " Inputan salah. " << endl;
      break;
    }
  } while (input != 0);

  return 0;
}
