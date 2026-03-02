#include <iostream>
using namespace std;

// Tabel Analisis Kompleksitas:
// ===============================================
// | Pseudocode           | Cost |  Tmin |  Tmax |
// ===============================================
// | procedure FindMin    |  C1  |   1   |   1   |
// | min <- A[0]          |  C2  |   1   |   1   |
// | for i <- 1 to n-1    |  C3  |   n   |   n   |
// | if A[i] < min        |  C4  |  n-1  |  n-1  |
// | min <- A[i]          |  C5  |   0   |  n-1  |
// | end if               |  C6  |  n-1  |  n-1  |
// | end for              |  C7  |   n   |   n   |
// | return min           |  C8  |   1   |   1   |
// | end procedure        |  C9  |   1   |   1   |
// ===============================================
//
// Best Case (array sudah urut naik, min gapernah diupdate):
// Tn = C1+C2 + C3n + C4(n-1) + 0 + C6(n-1) + C7n + C8+C9
//    = (C3+C4+C6+C7)n + (C1+C2+C8+C9-C4-C6)
//    = (1+1+1+1)n + (1+1+1+1-1-1)
//    = 4n + 4  -> fungsi linear -> Big-O: O(n)
//
// Worst Case (array urut turun, min selalu diupdate tiap iterasi):
// Tn = C1+C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8+C9
//    = (C3+C4+C5+C6+C7)n + (C1+C2+C8+C9-C4-C5-C6)
//    = (1+1+1+1+1)n + (1+1+1+1-1-1-1)
//    = 5n + 3   -> fungsi linear -> Big-O: O(n)
//
// Kesimpulan: Best case ataupun worst case = O(n)
// ============================================================

void FindMin(int A[], int n) {
    int min = A[0];
    int indexMin = 0;

    for (int i = 1; i <= n - 1; i++) {
        if (A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }

    cout << "Nilai minimum : " << min << endl;
    cout << "Index minimum : " << indexMin << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "          SOAL 1 - FindMin              " << endl;
    cout << "========================================" << endl;

    int fibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    cout << "Array Fibonacci: ";
    for (int i = 0; i < 8; i++) {
        cout << fibonacci[i];
        if (i < 7) cout << ", ";
    }
    cout << endl;

    FindMin(fibonacci, 8);

    return 0;
}