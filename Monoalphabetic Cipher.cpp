#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string enkripsi(string plaintext, string key) {
  string ciphertext = "";
  for (unsigned int i = 0; i < plaintext.length(); i++) { 
    char ch = plaintext[i];
    if (isalpha(ch)) {
      char base = isupper(ch) ? 'A' : 'a';
      int index = ch - base;
      ciphertext += key[index];
    } else {
      ciphertext += ch;
    }
  }
  return ciphertext;
}

string dekripsi(string ciphertext, string key) {
  string plaintext = "";
  for (unsigned int i = 0; i < ciphertext.length(); i++) {
    char ch = ciphertext[i];
    if (isalpha(ch)) {
      char base = isupper(ch) ? 'A' : 'a';
           for (unsigned int j = 0; j < key.length(); j++) {
        if (key[j] == ch) {
          plaintext += base + j;
          break;
        }
      }
    } else {
      plaintext += ch;
    }
  }
  return plaintext;
}

int main() {
  string plaintext, key;
  int pilihan;

  cout << "Kalkulator Monoalphabetic Cipher" << endl;
  cout << "-------------------------------" << endl;
  cout << "1. Enkripsi" << endl;
  cout << "2. Dekripsi" << endl;
  cout << "Pilihan: ";
  cin >> pilihan;

  cin.ignore(); 

  cout << "Masukkan teks: ";
  getline(cin, plaintext);

  cout << "Masukkan key (26 huruf alfabet unik): ";
  getline(cin, key);

  if (key.length() != 26) {
    cout << "Error: Key harus terdiri dari 26 huruf alfabet unik." << endl;
    return 1;
  }

  switch (pilihan) {
    case 1:
      cout << "Ciphertext: " << enkripsi(plaintext, key) << endl;
      break;
    case 2:
      cout << "Plaintext: " << dekripsi(plaintext, key) << endl;
      break;
    default:
      cout << "Pilihan tidak valid!" << endl;
  }

  return 0;
}
