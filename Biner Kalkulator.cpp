#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

// Fungsi untuk mengkonversi desimal ke biner
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        stringstream ss;
        ss << decimal % 2;
        binary = ss.str() + binary; 
        decimal /= 2;
    }
    return binary;
}

// Fungsi untuk mengkonversi desimal ke oktal
string decimalToOctal(int decimal) {
    string octal = "";
    while (decimal > 0) {
        stringstream ss;
        ss << decimal % 8;
        octal = ss.str() + octal;
        decimal /= 8;
    }
    return octal;
}

// Fungsi untuk mengkonversi desimal ke heksadesimal
string decimalToHexadecimal(int decimal) {
    string hexadecimal = "";
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            stringstream ss;
            ss << remainder;
            hexadecimal = ss.str() + hexadecimal;
        } else {
            hexadecimal = char(remainder - 10 + 'A') + hexadecimal;
        }
        decimal /= 16;
    }
    return hexadecimal;
}

// Fungsi untuk mengkonversi biner ke desimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Fungsi untuk mengkonversi oktal ke desimal
int octalToDecimal(string octal) {
    int decimal = 0;
    int power = 0;
    for (int i = octal.length() - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * pow(8, power);
        power++;
    }
    return decimal;
}

// Fungsi untuk mengkonversi heksadesimal ke desimal
int hexadecimalToDecimal(string hexadecimal) {
    int decimal = 0;
    int power = 0;
    for (int i = hexadecimal.length() - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * pow(16, power);
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * pow(16, power);
        }
        power++;
    }
    return decimal;
}


int main() {
    int pilihan, decimal;
    string input;

    cout << "Konversi Sistem Bilangan" << endl;
    cout << "------------------------" << endl;
    cout << "1. Desimal ke Biner" << endl;
    cout << "2. Desimal ke Oktal" << endl;
    cout << "3. Desimal ke Heksadesimal" << endl;
    cout << "4. Biner ke Desimal" << endl;
    cout << "5. Oktal ke Desimal" << endl;
    cout << "6. Heksadesimal ke Desimal" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Masukkan bilangan desimal: ";
            cin >> decimal;
            cout << "Hasil biner: " << decimalToBinary(decimal) << endl;
            break;
        case 2:
            cout << "Masukkan bilangan desimal: ";
            cin >> decimal;
            cout << "Hasil oktal: " << decimalToOctal(decimal) << endl;
            break;
        case 3:
            cout << "Masukkan bilangan desimal: ";
            cin >> decimal;
            cout << "Hasil heksadesimal: " << decimalToHexadecimal(decimal) << endl;
            break;
        case 4:
            cout << "Masukkan bilangan biner: ";
            cin >> input;
            cout << "Hasil desimal: " << binaryToDecimal(input) << endl;
            break;
        case 5:
            cout << "Masukkan bilangan oktal: ";
            cin >> input;
            cout << "Hasil desimal: " << octalToDecimal(input) << endl;
            break;
        case 6:
            cout << "Masukkan bilangan heksadesimal: ";
            cin >> input;
            cout << "Hasil desimal: " << hexadecimalToDecimal(input) << endl;
            break;
        case 7:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}
