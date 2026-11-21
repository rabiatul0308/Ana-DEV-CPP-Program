#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> encryptionKey; 

string encrypt(string plaintext) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i += 2) {
        string digram = plaintext.substr(i, 2);
        ciphertext += encryptionKey[digram]; 
    }
    return ciphertext;
}

string decrypt(string ciphertext) {
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        for (map<string, string>::iterator it = encryptionKey.begin(); it != encryptionKey.end(); ++it) {
            if (it->second == ciphertext.substr(i, 2)) {
                plaintext += it->first;
                break;
            }
        }
    }
    return plaintext;
}

int main() {
   
    encryptionKey.insert(make_pair("ab", "XY"));
    encryptionKey.insert(make_pair("cd", "ZQ"));
    encryptionKey.insert(make_pair("ef", "MN"));
    encryptionKey.insert(make_pair("gh", "OP"));


    string plaintext;
    cout << "Enter the plaintext: ";
    cin >> plaintext;

    string ciphertext = encrypt(plaintext);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
