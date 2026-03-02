#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* awal = arr;
    int* akhir = arr + (n - 1);

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

void tampilArrayDanAlamat(int* arr, int n) {
    int* p = arr;
    while (p < arr + n) {
        cout << "Nilai: " << *p << "  |  Alamat: " << p << endl;
        p++;
    }
}

int main() {
    cout << "==========================================" << endl;
    cout << "         SOAL 3 - Array dan Pointer       " << endl;
    cout << "==========================================" << endl;

    int prima[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "\nArray sebelum dibalik:" << endl;
    tampilArrayDanAlamat(prima, 7);

    reverseArray(prima, 7);

    cout << "\nArray sesudah dibalik:" << endl;
    tampilArrayDanAlamat(prima, 7);

    return 0;
}