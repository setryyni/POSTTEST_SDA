#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Hewan {
    int    id;
    string nama;
    string jenis;
    string pemilik;
    int    umur;      
    double harga;     
};

const int MAX_DATA = 100;
Hewan   dataHewan[MAX_DATA];
int     jumlahHewan = 0;

void garis(char c = '-', int panjang = 60) {
    for (int i = 0; i < panjang; i++) cout << c;
    cout << endl;
}

void headerProgram() {
    garis('=');
    cout << setw(40) << "  PAWCARE PETSHOP" << endl;
    cout << setw(45) << "  Sistem Manajemen Hewan Peliharaan" << endl;
    garis('=');
}

void swapHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;   
    *a         = *b;   
    *b         = temp; 
}

void tampilSemuaData(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n  Belum ada data hewan hmzz.\n";
        return;
    }

    cout << "\n";
    garis('=');
    cout << "  DATA HEWAN PELIHARAAN - PAWCARE PETSHOP\n";
    garis('=');
    cout << left
         << setw(5)  << "ID"
         << setw(18) << "Nama Hewan"
         << setw(12) << "Jenis"
         << setw(16) << "Pemilik"
         << setw(8)  << "Umur"
         << "Harga Perawatan"
         << endl;
    garis('-');

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(5)  << (arr + i)->id
             << setw(18) << (arr + i)->nama
             << setw(12) << (arr + i)->jenis
             << setw(16) << (arr + i)->pemilik
             << setw(8)  << to_string((arr + i)->umur) + " bln"
             << "Rp " << fixed << setprecision(0) << (arr + i)->harga
             << endl;
    }
    garis('-');
    cout << "  Total data: " << n << " hewan\n";
    garis('=');
}

void tambahData() {
    if (jumlahHewan >= MAX_DATA) {
        cout << "\n  Data penuh. Kapasitas maksimum " << MAX_DATA << " hewan.\n";
        return;
    }

    cout << "\n";
    garis('=');
    cout << "  TAMBAH DATA HEWAN BARU\n";
    garis('=');

    Hewan baru;

    baru.id = (jumlahHewan == 0) ? 1 : dataHewan[jumlahHewan - 1].id + 1;
    cout << "  ID Otomatis : " << baru.id << endl;

    cout << "  Nama Hewan  : "; cin.ignore(); getline(cin, baru.nama);
    cout << "  Jenis Hewan : "; getline(cin, baru.jenis);
    cout << "  Nama Pemilik: "; getline(cin, baru.pemilik);
    cout << "  Umur (bulan): "; cin >> baru.umur;
    cout << "  Harga (Rp)  : "; cin >> baru.harga;

    dataHewan[jumlahHewan] = baru;
    jumlahHewan++;

    cout << "\n  Data hewan berhasil ditambahin \n";
    garis('=');
}


void linearSearch(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n  Blom ada data hewan.\n";
        return;
    }

    cout << "\n";
    garis('=');
    cout << "  LINEAR SEARCH - CARI BERDASARKAN NAMA HEWAN\n";
    garis('=');
    cout << "  Masukkan nama hewan yang dicari: ";
    cin.ignore();
    string target;
    getline(cin, target);

    cout << "\n  Memulai pencarian untuk nama: \"" << target << "\"\n";
    garis('-');

    bool ditemukan = false;
    int  idxKetemu = -1;

// cek satu-satu dari depan
// kalau ketemu langsung stop, kalau ga ya lanjut terus
// abis ketemu di-swap ke depan biar next search lebih cepet

    for (int i = 0; i < n; i++) {

        cout << "  Iterasi " << setw(3) << (i + 1)
             << " | Cek ID " << setw(4) << (arr + i)->id
             << " | Nama: " << setw(15) << (arr + i)->nama;

        if ((arr + i)->nama == target) {
            cout << " --> YEAY KETEMU!\n";
            idxKetemu = i;
            ditemukan = true;
            break; 
        } else {
            cout << " --> [ga cocok, lanjut...]\n";
        }
    }

    if (ditemukan) {
        garis('-');
        cout << "\n  DATA DITEMUKAN:\n";
        garis('-');
        cout << "  ID          : " << (arr + idxKetemu)->id      << endl;
        cout << "  Nama Hewan  : " << (arr + idxKetemu)->nama    << endl;
        cout << "  Jenis       : " << (arr + idxKetemu)->jenis   << endl;
        cout << "  Pemilik     : " << (arr + idxKetemu)->pemilik << endl;
        cout << "  Umur        : " << (arr + idxKetemu)->umur    << " bulan\n";
        cout << "  Harga       : Rp " << fixed << setprecision(0)
             << (arr + idxKetemu)->harga << endl;
        garis('-');

        if (idxKetemu != 0) {
            cout << "  Swap: \"" << (arr + idxKetemu)->nama
                 << "\" dipindahkan ke posisi depan via pointer swap...\n";
            swapHewan(arr + idxKetemu, arr + 0); 
            cout << "  Swap berhasil. Data kini di posisi indeks 0.\n";
        } else {
            cout << "  Data sudah di posisi depan, swap ga diperluhin.\n";
        }

        garis('-');
        cout << "  Ditemukan pada iterasi ke-" << (idxKetemu + 1) << "\n";
    } else {
        garis('-');
        cout << "\n  Data dengan nama \"" << target << "\" ga ditemukan.\n";
        cout << "  Total iterasi: " << n << " kali (seluruh data diperiksa)\n";
    }

    garis('=');
}

void urutkanById(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->id < (arr + minIdx)->id)
                minIdx = j;
        }
        if (minIdx != i)
            swapHewan(arr + minIdx, arr + i);
    }
}

void fibonacciSearch(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n  Belum ada data hewan.\n";
        return;
    }

    cout << "\n";
    garis('=');
    cout << "  FIBONACCI SEARCH - CARI BERDASARKAN ID HEWAN\n";
    garis('=');
    cout << "  Masukkan ID hewan yang dicari: ";
    int targetId;
    cin >> targetId;

    Hewan temp[MAX_DATA];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    urutkanById(temp, n);

    cout << "\n  Data diurutkan berdasarkan ID untuk Fibonacci Search.\n";
    cout << "  Mencari ID: " << targetId << "\n";
    garis('-');

    int fib2 = 0; 
    int fib1 = 1; 
    int fib  = 1; 

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib  = fib1 + fib2;
    }

    cout << "  Fibonacci awal: fib=" << fib
         << ", fib1=" << fib1
         << ", fib2=" << fib2 << "\n";
    garis('-');

    int offset  = -1;
    int langkah = 0;
    int hasil   = -1;

    while (fib > 1) {
        langkah++;

        int i = offset + fib2;
        if (i >= n) i = n - 1;

        cout << "  Langkah " << langkah
             << " | Periksa indeks " << setw(2) << i
             << " | ID=" << setw(4) << temp[i].id
             << " | Nama: " << setw(12) << temp[i].nama;

        if (temp[i].id == targetId) {
            cout << " --> YEAY KETEMU!\n";
            hasil = i;
            break;
        } else if (temp[i].id < targetId) {
            cout << " --> [target lebih besar, cari ke KANAN WELL]\n";
            fib    = fib1;
            fib1   = fib2;
            fib2   = fib - fib1;
            offset = i;
        } else {
            cout << " --> [target lebih kecil, cari ke KIRI WELL]\n";
            fib  = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib  - fib1;
        }
    }

    if (hasil == -1 && fib1 == 1 && (offset + 1) < n) {
        langkah++;
        cout << "  Langkah " << langkah
             << " | Periksa indeks " << setw(2) << (offset + 1)
             << " | ID=" << setw(4) << temp[offset + 1].id
             << " | Nama: " << setw(12) << temp[offset + 1].nama;

        if (temp[offset + 1].id == targetId) {
            cout << " --> YEAY KETEMU!\n";
            hasil = offset + 1;
        } else {
            cout << " --> [ga cocok]\n";
        }
    }

    garis('-');
    if (hasil != -1) {
        cout << "\n  DATA DITEMUKAN:\n";
        garis('-');
        cout << "  ID          : " << temp[hasil].id      << endl;
        cout << "  Nama Hewan  : " << temp[hasil].nama    << endl;
        cout << "  Jenis       : " << temp[hasil].jenis   << endl;
        cout << "  Pemilik     : " << temp[hasil].pemilik << endl;
        cout << "  Umur        : " << temp[hasil].umur    << " bulan\n";
        cout << "  Harga       : Rp " << fixed << setprecision(0)
             << temp[hasil].harga << endl;
        garis('-');

        if (hasil != 0) {
            cout << "  Swap: \"" << temp[hasil].nama
                 << "\" dipindahkan ke posisi depan via pointer swap...\n";
            swapHewan(temp + hasil, temp + 0);
            cout << "  Swap berhasil! Data kini di posisi indeks 0.\n";
        } else {
            cout << "  Data sudah di posisi depan, swap ga diperluhin.\n";
        }

        garis('-');
        cout << "  Ditemukan setelah " << langkah << " langkah Fibonacci\n";
    } else {
        cout << "\n  Data dengan ID " << targetId << " tidak ditemukan.\n";
    }
    garis('=');
}

void bubbleSort(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n  Blum ada data hewan.\n";
        return;
    }

    cout << "\n";
    garis('=');
    cout << "  BUBBLE SORT - URUTKAN BERDASARKAN NAMA (A-Z)\n";
    garis('=');
    cout << "  Memproses pengurutan...\n\n";

    for (int i = 0; i < n - 1; i++) {
        bool adaTukar = false;

        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swapHewan(arr + j, arr + j + 1);
                adaTukar = true;
            }
        }

        if (!adaTukar) break;
    }

    cout << "  yah, Pengurutan berhasil. \n\n";
    tampilSemuaData(arr, n);
}

void selectionSort(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n  Belum ada data hewan.\n";
        return;
    }

    cout << "\n";
    garis('=');
    cout << "  SELECTION SORT - URUTKAN BERDASARKAN HARGA\n";
    cout << "  (Termurah ke TerMUAHALL)\n";
    garis('=');
    cout << "  Memproses pengurutan...\n\n";

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga)
                minIdx = j;
        }

        if (minIdx != i)
            swapHewan(arr + minIdx, arr + i); 
    }

    cout << " Pengurutan berhasil hmzzz...\n\n";
    tampilSemuaData(arr, n);
}


void inisialisasiData(Hewan* &arr, int &n) {
    Hewan dataAwal[] = {
        {1, "Mochi",   "Kucing",  "Jesnolimit",     12, 150000},
        {2, "Bruno",   "Anjing",  "Reza Arab", 24, 200000},
        {3, "Rusdi",    "Kelinci", "Norah grace",      6, 100000},
        {4, "Pikachu", "Hamster", "Setriyani",     3,  75000},
        {5, "Nemo",    "Ikan",    "Sahroni",       18,  50000},
    };

    n = 5;
    for (int i = 0; i < n; i++)
        arr[i] = dataAwal[i];

    cout << "  Data awal berhasil dimuat (" << n << " hewan).\n";
}

void tampilMenu() {
    cout << "\n";
    garis('=');
    cout << "         MENU UTAMA - PAWCARE PETSHOP\n";
    garis('=');
    cout << "  1. Tampil Semua Data Hewan\n";
    cout << "  2. Tambah Data Hewan Baru\n";
    cout << "  3. Linear Search  (cari berdasarkan Nama Hewan)\n";
    cout << "  4. Fibonacci Search (cari berdasarkan ID)\n";
    cout << "  5. Bubble Sort    (urutin berdasarkan Nama A-Z)\n";
    cout << "  6. Selection Sort (urutkan berdasarkan Harga)\n";
    cout << "  0. Keluar\n";
    garis('=');
    cout << "  Pilih menu: ";
}

int main() {
    headerProgram();

    Hewan* ptrData = dataHewan;
    inisialisasiData(ptrData, jumlahHewan);

    int pilihan;

    do {
        tampilMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilSemuaData(dataHewan, jumlahHewan);
                break;
            case 2:
                tambahData();
                break;
            case 3:
                linearSearch(dataHewan, jumlahHewan);
                break;
            case 4:
                fibonacciSearch(dataHewan, jumlahHewan);
                break;
            case 5:
                bubbleSort(dataHewan, jumlahHewan);
                break;
            case 6:
                selectionSort(dataHewan, jumlahHewan);
                break;
            case 0:
                cout << "\n";
                garis('=');
                cout << "  Maksih telah menggunakan PAWCARE PETSHOP\n";
                cout << "  Bye byee!\n";
                garis('=');
                break;
            default:
                cout << "\n Pilihan ga valid bozz. Coba lagi.\n";
                break;
        }

    } while (pilihan != 0);

    return 0;
}