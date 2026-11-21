#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib> // for atoi

using namespace std;

// Fungsi untuk mengubah string oktet menjadi integer
int octetToInt(const string& octet) {
    return atoi(octet.c_str()); 
}

// Fungsi untuk mengubah integer menjadi string oktet
string intToOctet(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Fungsi untuk melakukan operasi bitwise AND pada dua oktet
string bitwiseAnd(const string& octet1, const string& octet2) {
    int num1 = octetToInt(octet1);
    int num2 = octetToInt(octet2);
    return intToOctet(num1 & num2);
}

// Fungsi untuk melakukan operasi bitwise OR pada dua oktet
string bitwiseOr(const string& octet1, const string& octet2) {
    int num1 = octetToInt(octet1);
    int num2 = octetToInt(octet2);
    return intToOctet(num1 | num2);
}

// Fungsi untuk membalikkan bit pada suatu oktet
string bitwiseNot(const string& octet) {
    int num = octetToInt(octet);
    return intToOctet(~num & 0xFF); // 0xFF digunakan untuk memastikan hasilnya tetap dalam rentang 0-255
}

// Fungsi untuk memvalidasi alamat IP (tanpa regex)
bool isValidIpAddress(const string& ipAddress) {
    int countDots = 0;
    for (unsigned int i = 0; i < ipAddress.length(); i++) { 
        if (ipAddress[i] == '.') {
            countDots++;
        } else if (!isdigit(ipAddress[i])) {
            return false;
        }
    }
    if (countDots != 3) { 
        return false;
    }

    stringstream ss(ipAddress);
    string octet;
    while (getline(ss, octet, '.')) {
        int num = octetToInt(octet);
        if (num < 0 || num > 255) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk memvalidasi subnet mask
bool isValidSubnetMask(const string& subnetMask) {
    return isValidIpAddress(subnetMask); //  You might want to add more specific validation for subnet masks
}

// Fungsi untuk menghitung network address
string getNetworkAddress(const string& ipAddress, const string& subnetMask) {
    vector<string> ipOctets, maskOctets;
    stringstream ssIp(ipAddress), ssMask(subnetMask);
    string octet;

    while (getline(ssIp, octet, '.')) {
        ipOctets.push_back(octet);
    }
    while (getline(ssMask, octet, '.')) {
        maskOctets.push_back(octet);
    }

    string networkAddress = "";
    for (int i = 0; i < 4; i++) {
        networkAddress += bitwiseAnd(ipOctets[i], maskOctets[i]);
        if (i < 3) {
            networkAddress += ".";
        }
    }

    return networkAddress;
}

// Fungsi untuk menghitung broadcast address
string getBroadcastAddress(const string& ipAddress, const string& subnetMask) {
    vector<string> ipOctets, maskOctets;
    stringstream ssIp(ipAddress), ssMask(subnetMask);
    string octet;

    while (getline(ssIp, octet, '.')) {
        ipOctets.push_back(octet);
    }
    while (getline(ssMask, octet, '.')) {
        maskOctets.push_back(octet);
    }

    string broadcastAddress = "";
    for (int i = 0; i < 4; i++) {
        broadcastAddress += bitwiseOr(ipOctets[i], bitwiseNot(maskOctets[i]));
        if (i < 3) {
            broadcastAddress += ".";
        }
    }

    return broadcastAddress;
}

// Fungsi untuk menghitung jumlah host yang tersedia
int getNumberOfHosts(const string& subnetMask) {
    int numBits = 0;
    vector<string> maskOctets;
    stringstream ssMask(subnetMask);
    string octet;

    while (getline(ssMask, octet, '.')) {
        maskOctets.push_back(octet);
    }

    // Mengubah range-based for loop menjadi traditional for loop
    for (vector<string>::size_type i = 0; i < maskOctets.size(); i++) {
        int num = octetToInt(maskOctets[i]);
        for (int j = 7; j >= 0; j--) {
            if ((num >> j) & 1) {
                numBits++;
            }
        }
    }

    return (1 << (32 - numBits)) - 2; // Kurangi 2 untuk network address dan broadcast address
}

// Fungsi untuk menampilkan informasi subnet
void printSubnetInfo(const string& ipAddress, const string& subnetMask) {
    string networkAddress = getNetworkAddress(ipAddress, subnetMask);
    string broadcastAddress = getBroadcastAddress(ipAddress, subnetMask);
    int numHosts = getNumberOfHosts(subnetMask);

    cout << "\nInformasi Subnet:\n";
    cout << "IP Address: " << ipAddress << endl;
    cout << "Subnet Mask: " << subnetMask << endl;
    cout << "Network Address: " << networkAddress << endl;
    cout << "Broadcast Address: " << broadcastAddress << endl;
    cout << "Jumlah Host: " << numHosts << endl;
}

int main() {
    string ipAddress, subnetMask;

    cout << "Masukkan IP address: ";
    cin >> ipAddress;

    cout << "Masukkan subnet mask: ";
    cin >> subnetMask;

    if (isValidIpAddress(ipAddress) && isValidSubnetMask(subnetMask)) {
        cout << "IP address dan subnet mask valid!\n";
        printSubnetInfo(ipAddress, subnetMask);
    } else {
        cout << "IP address atau subnet mask tidak valid!\n";
    }

    return 0;
}
