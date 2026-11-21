#include <iostream>
#include <string>

using namespace std;


string encrypt(string plaintext, string keyword) {
    string ciphertext = "";
    int keywordLength = keyword.length();

    for (int i = 0, j = 0; i < plaintext.length(); ++i) {
        char p = plaintext[i];

  
        if (isalpha(p)) {
            char k = toupper(keyword[j % keywordLength]);
            char base = isupper(p) ? 'A' : 'a';
            char c = base + (p - base + k - 'A') % 26; 
            ciphertext += c;
            j++;
        } else {
            ciphertext += p;
        }
    }

    return ciphertext;
}


string decrypt(string ciphertext, string keyword) {
    string plaintext = "";
    int keywordLength = keyword.length();

    for (int i = 0, j = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];

        if (isalpha(c)) {
            char k = toupper(keyword[j % keywordLength]);
            char base = isupper(c) ? 'A' : 'a';
            char p = base + (c - base - (k - 'A') + 26) % 26;
            plaintext += p;
            j++;
        } else {
            plaintext += c;
        }
    }

    return plaintext;
}

int main() {
    string plaintext, keyword;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext); 

    cout << "Enter the keyword: ";
    getline(cin, keyword);

    string ciphertext = encrypt(plaintext, keyword);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, keyword);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
