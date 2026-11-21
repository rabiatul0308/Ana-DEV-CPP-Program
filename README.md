# Ana-DEV-CPP-Program

Kumpulan program berbasis **C++** untuk implementasi algoritma kriptografi klasik, perhitungan jaringan komputer (*subnetting*), dan konversi sistem bilangan.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

## Daftar Program

### 1. Kriptografi Klasik (*Classical Ciphers*)
* **`Caesar cipher.cpp`**: Implementasi enkripsi dan dekripsi pergeseran karakter berbasis kunci numerik (*shift cipher*).
* **`Monoalphabetic Cipher.cpp`**: Implementasi substitusi karakter satu-ke-satu menggunakan pemetaan alfabet acak.
* **`Polyalphabetic substitution cipher.cpp`**: Implementasi enkripsi substitusi berganda menggunakan kata kunci berulang (seperti Vigenère).
* **`Polygram substitution cipher.cpp`**: Implementasi enkripsi berbasis blok kelompok huruf (*polygram*) untuk menyamarkan frekuensi huruf tunggal.

### 2. Jaringan Komputer & Sistem Bilangan
* **`SOJ Subnetting.cpp`**: Kalkulator perhitungan *subnetting* IPv4 (Network ID, Broadcast Address, Subnet Mask, dan rentang host valid).
* **`Biner Kalkulator.cpp`**: Utilitas konversi dan operasi aritmatika pada sistem bilangan biner.

## Cara Menjalankan (*Compile & Run*)

Pastikan kompiler C++ (seperti `g++` / MinGW) sudah terpasang di perangkat Anda. Buka terminal pada direktori repositori ini, lalu kompilasi file yang diinginkan:

```bash
# Contoh kompilasi dan eksekusi menggunakan g++
g++ "Biner Kalkulator.cpp" -o BinerKalkulator
./BinerKalkulator
