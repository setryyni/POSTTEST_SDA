#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

void inputMahasiswa(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }
}

void tampilIPKTertinggi(Mahasiswa mhs[], int n) {
    Mahasiswa terbaik = mhs[0];

    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > terbaik.ipk) {
            terbaik = mhs[i];
        }
    }

    cout << "\n--- Mahasiswa dengan IPK Tertinggi ---" << endl;
    cout << "Nama : " << terbaik.nama << endl;
    cout << "NIM  : " << terbaik.nim << endl;
    cout << "IPK  : " << terbaik.ipk << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "       SOAL 2 - Struct Mahasiswa        " << endl;
    cout << "========================================" << endl;

    int jumlahMhs = 5;
    Mahasiswa dataMhs[5];

    inputMahasiswa(dataMhs, jumlahMhs);
    tampilIPKTertinggi(dataMhs, jumlahMhs);

    return 0;
}