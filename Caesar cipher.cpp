#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key) {
  string result = "";
  for (int i = 0; i < text.length(); i++) {
    if (isalpha(text[i])) {
      char base = isupper(text[i]) ? 'A' : 'a';
      result += base + (text[i] - base + key) % 26;
    } else {
      result += text[i];
    }
  }
  return result;
}

string decrypt(string text, int key) {
  return encrypt(text, 26 - key); 
}

int main() {
  string text;
  int key;
  int pilihan;

  cout << "Pilih operasi:\n";
  cout << "1. Enkripsi\n";
  cout << "2. Dekripsi\n";
  cout << "Pilihan: ";
  cin >> pilihan;

  cout << "Masukkan teks: ";
  cin.ignore();
  getline(cin, text);

  cout << "Masukkan kunci (angka): ";
  cin >> key;

  if (pilihan == 1) {
    cout << "Hasil enkripsi: " << encrypt(text, key) << endl;
  } else if (pilihan == 2) {
    cout << "Hasil dekripsi: " << decrypt(text, key) << endl;
  } else {
    cout << "Pilihan tidak valid!\n";
  }

  return 0;
}
