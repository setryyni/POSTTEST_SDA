#include <iostream>
using namespace std;

void tukarNilai(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    cout << "========================================" << endl;
    cout << "     SOAL 4 - Pointer pada Fungsi       " << endl;
    cout << "========================================" << endl;

    int x = 45, y = 90;

    cout << "Sebelum ditukar -> x: " << x << ", y: " << y << endl;

    tukarNilai(&x, &y);

    cout << "Sesudah ditukar -> x: " << x << ", y: " << y << endl;

    return 0;
}