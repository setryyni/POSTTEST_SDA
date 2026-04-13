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
    Hewan* next;
};

struct RiwayatTindakan {
    int    idHewan;
    string namaHewan;
    string tindakan;
    string dokter;
    RiwayatTindakan* next;
};

struct Queue {
    Hewan* front;
    Hewan* rear;
    int    size;
};

struct Stack {
    RiwayatTindakan* top;
    int              size;
};

Hewan dataHewan[100];
int   jumlahHewan = 0;
Queue antrianPasien;
Stack riwayatTindakan;

void garis(char c = '-', int panjang = 60) {
    for (int i = 0; i < panjang; i++) cout << c;
    cout << endl;
}

void headerProgram() {
    garis('=');
    cout << "                    PAWCARE PETSHOP" << endl;
    cout << "            Sistem Manajemen Hewan Peliharaan" << endl;
    garis('=');
}

void swapHewan(Hewan* a, Hewan* b) {
    int    tmpId     = a->id;     a->id     = b->id;     b->id     = tmpId;
    string tmpNama   = a->nama;   a->nama   = b->nama;   b->nama   = tmpNama;
    string tmpJenis  = a->jenis;  a->jenis  = b->jenis;  b->jenis  = tmpJenis;
    string tmpPemilik= a->pemilik;a->pemilik= b->pemilik;b->pemilik= tmpPemilik;
    int    tmpUmur   = a->umur;   a->umur   = b->umur;   b->umur   = tmpUmur;
    double tmpHarga  = a->harga;  a->harga  = b->harga;  b->harga  = tmpHarga;
}

void tampilSemuaData(Hewan* arr, int n) {
    if (n == 0) { cout << "\n  Belum ada data hewan hmzz.\n"; return; }
    cout << "\n"; garis('=');
    cout << "  DATA HEWAN PELIHARAAN - PAWCARE PETSHOP\n"; garis('=');
    cout << left << setw(5) << "ID" << setw(18) << "Nama Hewan" << setw(12) << "Jenis"
         << setw(16) << "Pemilik" << setw(8) << "Umur" << "Harga Perawatan" << endl;
    garis('-');
    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << (arr+i)->id << setw(18) << (arr+i)->nama
             << setw(12) << (arr+i)->jenis << setw(16) << (arr+i)->pemilik
             << setw(8) << to_string((arr+i)->umur) + " bln"
             << "Rp " << fixed << setprecision(0) << (arr+i)->harga << endl;
    }
    garis('-');
    cout << "  Total data: " << n << " hewan\n"; garis('=');
}

void tambahData() {
    if (jumlahHewan >= 100) { cout << "\n  Data penuh.\n"; return; }
    cout << "\n"; garis('='); cout << "  TAMBAH DATA HEWAN BARU\n"; garis('=');
    Hewan baru;
    baru.id   = (jumlahHewan == 0) ? 1 : dataHewan[jumlahHewan-1].id + 1;
    baru.next = nullptr;
    cout << "  ID Otomatis : " << baru.id << endl;
    cout << "  Nama Hewan  : "; cin.ignore(); getline(cin, baru.nama);
    cout << "  Jenis Hewan : "; getline(cin, baru.jenis);
    cout << "  Nama Pemilik: "; getline(cin, baru.pemilik);
    cout << "  Umur (bulan): "; cin >> baru.umur;
    cout << "  Harga (Rp)  : "; cin >> baru.harga;
    dataHewan[jumlahHewan++] = baru;
    cout << "\n  Data hewan berhasil ditambahin\n"; garis('=');
}

void linearSearch(Hewan* arr, int n) {
    if (n == 0) { cout << "\n  Blom ada data hewan.\n"; return; }
    cout << "\n"; garis('=');
    cout << "  LINEAR SEARCH - CARI BERDASARKAN NAMA HEWAN\n"; garis('=');
    cout << "  Masukkan nama hewan yang dicari: ";
    cin.ignore(); string target; getline(cin, target);
    cout << "\n  Memulai pencarian untuk nama: \"" << target << "\"\n"; garis('-');
    bool ditemukan = false; int idxKetemu = -1;
    for (int i = 0; i < n; i++) {
        cout << "  Iterasi " << setw(3) << (i+1) << " | Cek ID " << setw(4)
             << (arr+i)->id << " | Nama: " << setw(15) << (arr+i)->nama;
        if ((arr+i)->nama == target) {
            cout << " --> YEAY KETEMU!\n"; idxKetemu = i; ditemukan = true; break;
        } else cout << " --> [ga cocok, lanjut...]\n";
    }
    if (ditemukan) {
        garis('-'); cout << "\n  DATA DITEMUKAN:\n"; garis('-');
        cout << "  ID          : " << (arr+idxKetemu)->id      << endl;
        cout << "  Nama Hewan  : " << (arr+idxKetemu)->nama    << endl;
        cout << "  Jenis       : " << (arr+idxKetemu)->jenis   << endl;
        cout << "  Pemilik     : " << (arr+idxKetemu)->pemilik << endl;
        cout << "  Umur        : " << (arr+idxKetemu)->umur    << " bulan\n";
        cout << "  Harga       : Rp " << fixed << setprecision(0) << (arr+idxKetemu)->harga << endl;
        garis('-');
        if (idxKetemu != 0) {
            cout << "  Swap: \"" << (arr+idxKetemu)->nama << "\" ke posisi depan...\n";
            swapHewan(arr+idxKetemu, arr+0);
            cout << "  Swap berhasil.\n";
        } else cout << "  Data sudah di posisi depan.\n";
        garis('-');
        cout << "  Ditemukan pada iterasi ke-" << (idxKetemu+1) << "\n";
    } else {
        garis('-');
        cout << "\n  Data \"" << target << "\" ga ditemukan.\n";
        cout << "  Total iterasi: " << n << " kali\n";
    }
    garis('=');
}

void urutkanById(Hewan* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if ((arr+j)->id < (arr+minIdx)->id) minIdx = j;
        if (minIdx != i) swapHewan(arr+minIdx, arr+i);
    }
}

void fibonacciSearch(Hewan* arr, int n) {
    if (n == 0) { cout << "\n  Belum ada data hewan.\n"; return; }
    cout << "\n"; garis('=');
    cout << "  FIBONACCI SEARCH - CARI BERDASARKAN ID HEWAN\n"; garis('=');
    cout << "  Masukkan ID hewan yang dicari: "; int targetId; cin >> targetId;
    Hewan temp[100];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    urutkanById(temp, n);
    cout << "\n  Data diurutkan berdasarkan ID untuk Fibonacci Search.\n";
    cout << "  Mencari ID: " << targetId << "\n"; garis('-');
    int fib2=0, fib1=1, fib=1;
    while (fib < n) { fib2=fib1; fib1=fib; fib=fib1+fib2; }
    cout << "  Fibonacci awal: fib=" << fib << ", fib1=" << fib1 << ", fib2=" << fib2 << "\n"; garis('-');
    int offset=-1, langkah=0, hasil=-1;
    while (fib > 1) {
        langkah++;
        int i = offset + fib2;
        if (i >= n) i = n-1;
        cout << "  Langkah " << langkah << " | Periksa indeks " << setw(2) << i
             << " | ID=" << setw(4) << temp[i].id << " | Nama: " << setw(12) << temp[i].nama;
        if (temp[i].id == targetId) { cout << " --> YEAY KETEMU!\n"; hasil=i; break; }
        else if (temp[i].id < targetId) {
            cout << " --> [target lebih besar, cari ke KANAN]\n";
            fib=fib1; fib1=fib2; fib2=fib-fib1; offset=i;
        } else {
            cout << " --> [target lebih kecil, cari ke KIRI]\n";
            fib=fib2; fib1=fib1-fib2; fib2=fib-fib1;
        }
    }
    if (hasil==-1 && fib1==1 && (offset+1)<n) {
        langkah++;
        cout << "  Langkah " << langkah << " | Periksa indeks " << setw(2) << (offset+1)
             << " | ID=" << setw(4) << temp[offset+1].id << " | Nama: " << setw(12) << temp[offset+1].nama;
        if (temp[offset+1].id == targetId) { cout << " --> YEAY KETEMU!\n"; hasil=offset+1; }
        else cout << " --> [ga cocok]\n";
    }
    garis('-');
    if (hasil != -1) {
        cout << "\n  DATA DITEMUKAN:\n"; garis('-');
        cout << "  ID          : " << temp[hasil].id      << endl;
        cout << "  Nama Hewan  : " << temp[hasil].nama    << endl;
        cout << "  Jenis       : " << temp[hasil].jenis   << endl;
        cout << "  Pemilik     : " << temp[hasil].pemilik << endl;
        cout << "  Umur        : " << temp[hasil].umur    << " bulan\n";
        cout << "  Harga       : Rp " << fixed << setprecision(0) << temp[hasil].harga << endl;
        garis('-');
        if (hasil != 0) { swapHewan(temp+hasil, temp+0); cout << "  Swap berhasil!\n"; }
        else cout << "  Data sudah di posisi depan.\n";
        garis('-');
        cout << "  Ditemukan setelah " << langkah << " langkah Fibonacci\n";
    } else cout << "\n  Data dengan ID " << targetId << " tidak ditemukan.\n";
    garis('=');
}

void bubbleSort(Hewan* arr, int n) {
    if (n == 0) { cout << "\n  Blum ada data hewan.\n"; return; }
    cout << "\n"; garis('='); cout << "  BUBBLE SORT - URUTKAN BERDASARKAN NAMA (A-Z)\n"; garis('=');
    cout << "  Memproses pengurutan...\n\n";
    for (int i = 0; i < n-1; i++) {
        bool adaTukar = false;
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->nama > (arr+j+1)->nama) { swapHewan(arr+j, arr+j+1); adaTukar=true; }
        }
        if (!adaTukar) break;
    }
    cout << "  yah, Pengurutan berhasil.\n\n"; tampilSemuaData(arr, n);
}

void selectionSort(Hewan* arr, int n) {
    if (n == 0) { cout << "\n  Belum ada data hewan.\n"; return; }
    cout << "\n"; garis('=');
    cout << "  SELECTION SORT - URUTKAN BERDASARKAN HARGA\n";
    cout << "  (Termurah ke TerMUAHALL)\n"; garis('=');
    cout << "  Memproses pengurutan...\n\n";
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if ((arr+j)->harga < (arr+minIdx)->harga) minIdx = j;
        if (minIdx != i) swapHewan(arr+minIdx, arr+i);
    }
    cout << "  Pengurutan berhasil hmzzz...\n\n"; tampilSemuaData(arr, n);
}

void initQueue(Queue* q) { q->front = nullptr; q->rear = nullptr; q->size = 0; }
void initStack(Stack* s)  { s->top  = nullptr; s->size = 0; }

bool isQueueEmpty(Queue* q) { return q->front == nullptr; }
bool isStackEmpty(Stack* s) { return s->top  == nullptr; }

void enqueue(Queue* q, Hewan* h) {
    Hewan* nodeBaru = new Hewan;
    nodeBaru->id      = h->id;
    nodeBaru->nama    = h->nama;
    nodeBaru->jenis   = h->jenis;
    nodeBaru->pemilik = h->pemilik;
    nodeBaru->umur    = h->umur;
    nodeBaru->harga   = h->harga;
    nodeBaru->next    = nullptr;
    if (isQueueEmpty(q)) {
        q->front = nodeBaru;
        q->rear  = nodeBaru;
    } else {
        q->rear->next = nodeBaru;
        q->rear       = nodeBaru;
    }
    q->size++;
    cout << "\n  \"" << h->nama << "\" (ID: " << h->id << ") masuk antrian. Posisi: " << q->size << "\n";
}

void daftarAntrian(Queue* q) {
    if (jumlahHewan == 0) { cout << "\n  Belum ada data hewan.\n"; return; }
    cout << "\n"; garis('='); cout << "  DAFTAR ANTRIAN - PILIH HEWAN\n"; garis('=');
    tampilSemuaData(dataHewan, jumlahHewan);
    cout << "  Masukkan ID hewan yang mau didaftarkan: "; int idTarget; cin >> idTarget;
    Hewan* found = nullptr;
    for (int i = 0; i < jumlahHewan; i++)
        if ((dataHewan+i)->id == idTarget) { found = dataHewan+i; break; }
    if (!found) { cout << "\n  Hewan ID " << idTarget << " ga ditemukan.\n"; return; }
    enqueue(q, found);
    garis('=');
}

void dequeue(Queue* q, Stack* s) {
    if (isQueueEmpty(q)) { cout << "\n  [UNDERFLOW] Antrian kosong!\n"; return; }
    Hewan* dipanggil = q->front;
    q->front = q->front->next;
    if (q->front == nullptr) q->rear = nullptr;
    q->size--;
    cout << "\n"; garis('='); cout << "  MEMANGGIL PASIEN\n"; garis('=');
    cout << "  Nama   : " << dipanggil->nama    << endl;
    cout << "  ID     : " << dipanggil->id      << endl;
    cout << "  Jenis  : " << dipanggil->jenis   << endl;
    cout << "  Pemilik: " << dipanggil->pemilik << endl;
    garis('-');
    cout << "  Tindakan medis : "; cin.ignore(); string tindakan; getline(cin, tindakan);
    cout << "  Nama dokter    : "; string dokter; getline(cin, dokter);
    RiwayatTindakan* nodeBaru = new RiwayatTindakan;
    nodeBaru->idHewan   = dipanggil->id;
    nodeBaru->namaHewan = dipanggil->nama;
    nodeBaru->tindakan  = tindakan;
    nodeBaru->dokter    = dokter;
    nodeBaru->next      = s->top;
    s->top  = nodeBaru;
    s->size++;
    cout << "\n  Tindakan \"" << tindakan << "\" berhasil dicatat.\n";
    cout << "  Sisa antrian: " << q->size << " hewan\n"; garis('=');
    delete dipanggil;
}

void popRiwayat(Stack* s) {
    if (isStackEmpty(s)) { cout << "\n  [UNDERFLOW] Stack riwayat kosong!\n"; return; }
    RiwayatTindakan* terhapus = s->top;
    s->top = s->top->next;
    s->size--;
    cout << "\n"; garis('='); cout << "  POP - TINDAKAN TERAKHIR DIHAPUS\n"; garis('=');
    cout << "  ID Hewan  : " << terhapus->idHewan   << endl;
    cout << "  Nama      : " << terhapus->namaHewan << endl;
    cout << "  Tindakan  : " << terhapus->tindakan  << endl;
    cout << "  Dokter    : " << terhapus->dokter    << endl;
    garis('-');
    cout << "  Riwayat dihapus. Sisa: " << s->size << " tindakan\n"; garis('=');
    delete terhapus;
}

void peek(Queue* q, Stack* s) {
    cout << "\n"; garis('='); cout << "  PEEK - ANTRIAN & RIWAYAT\n"; garis('=');
    cout << "  [QUEUE] Pasien terdepan:\n"; garis('-');
    if (isQueueEmpty(q)) cout << "  Antrian kosong.\n";
    else {
        Hewan* depan = q->front;
        cout << "  ID     : " << depan->id      << endl;
        cout << "  Nama   : " << depan->nama    << endl;
        cout << "  Jenis  : " << depan->jenis   << endl;
        cout << "  Pemilik: " << depan->pemilik << endl;
    }
    garis('-'); cout << "  [STACK] Tindakan terakhir:\n"; garis('-');
    if (isStackEmpty(s)) cout << "  Riwayat kosong.\n";
    else {
        RiwayatTindakan* terakhir = s->top;
        cout << "  ID Hewan  : " << terakhir->idHewan   << endl;
        cout << "  Nama      : " << terakhir->namaHewan << endl;
        cout << "  Tindakan  : " << terakhir->tindakan  << endl;
        cout << "  Dokter    : " << terakhir->dokter    << endl;
    }
    garis('=');
}

void tampilAntrian(Queue* q) {
    cout << "\n"; garis('='); cout << "  DAFTAR ANTRIAN PEMERIKSAAN\n"; garis('=');
    if (isQueueEmpty(q)) { cout << "  Antrian kosong.\n"; garis('='); return; }
    cout << left << setw(6) << "No." << setw(5) << "ID" << setw(18) << "Nama Hewan"
         << setw(12) << "Jenis" << "Pemilik" << endl;
    garis('-');
    Hewan* temp = q->front;
    int no = 1;
    while (temp != nullptr) {
        cout << left << setw(6) << no++ << setw(5) << temp->id << setw(18) << temp->nama
             << setw(12) << temp->jenis << temp->pemilik << endl;
        temp = temp->next;
    }
    garis('-'); cout << "  Total antrian: " << q->size << " hewan\n"; garis('=');
}

void tampilRiwayat(Stack* s) {
    cout << "\n"; garis('='); cout << "  RIWAYAT TINDAKAN MEDIS\n"; garis('=');
    if (isStackEmpty(s)) { cout << "  Riwayat kosong.\n"; garis('='); return; }
    cout << left << setw(6) << "No." << setw(5) << "ID" << setw(18) << "Nama Hewan"
         << setw(22) << "Tindakan" << "Dokter" << endl;
    garis('-');
    RiwayatTindakan* temp = s->top;
    int no = 1;
    while (temp != nullptr) {
        cout << left << setw(6) << no++ << setw(5) << temp->idHewan
             << setw(18) << temp->namaHewan << setw(22) << temp->tindakan << temp->dokter << endl;
        temp = temp->next;
    }
    garis('-'); cout << "  Total riwayat: " << s->size << " tindakan\n"; garis('=');
}

void inisialisasiData(Hewan* arr, int &n) {
    Hewan dataAwal[] = {
        {1, "Mochi",   "Kucing",  "Jesnolimit",  12, 150000, nullptr},
        {2, "Bruno",   "Anjing",  "Reza Arab",   24, 200000, nullptr},
        {3, "Rusdi",   "Kelinci", "Norah Grace",  6, 100000, nullptr},
        {4, "Pikachu", "Hamster", "Setriyani",    3,  75000, nullptr},
        {5, "Nemo",    "Ikan",    "Sahroni",     18,  50000, nullptr},
    };
    n = 5;
    for (int i = 0; i < n; i++) arr[i] = dataAwal[i];
}

void tampilMenu() {
    cout << "\n"; garis('=');
    cout << "          MENU UTAMA - PAWCARE PETSHOP\n"; garis('=');
    cout << "  --- DATA HEWAN ---\n";
    cout << "  1. Tampil Semua Data Hewan\n";
    cout << "  2. Tambah Data Hewan Baru\n";
    cout << "  3. Linear Search    (cari berdasarkan Nama)\n";
    cout << "  4. Fibonacci Search (cari berdasarkan ID)\n";
    cout << "  5. Bubble Sort      (urutin berdasarkan Nama A-Z)\n";
    cout << "  6. Selection Sort   (urutkan berdasarkan Harga)\n";
    cout << "  7.  Daftar ke Antrian  (Enqueue)\n";
    cout << "  8.  Panggil Pasien     (Dequeue)\n";
    cout << "  9.  Hapus Riwayat      (Pop)\n";
    cout << "  10. Peek Antrian & Riwayat\n";
    cout << "  11. Tampil Semua Antrian\n";
    cout << "  12. Tampil Semua Riwayat\n";
    cout << "  0.  Keluar\n";
    garis('='); cout << "  Pilih menu: ";
}

int main() {
    headerProgram();
    inisialisasiData(dataHewan, jumlahHewan);
    initQueue(&antrianPasien);
    initStack(&riwayatTindakan);
    int pilihan;
    do {
        tampilMenu(); cin >> pilihan;
        switch (pilihan) {
            case 1:  tampilSemuaData(dataHewan, jumlahHewan); break;
            case 2:  tambahData(); break;
            case 3:  linearSearch(dataHewan, jumlahHewan); break;
            case 4:  fibonacciSearch(dataHewan, jumlahHewan); break;
            case 5:  bubbleSort(dataHewan, jumlahHewan); break;
            case 6:  selectionSort(dataHewan, jumlahHewan); break;
            case 7:  daftarAntrian(&antrianPasien); break;
            case 8:  dequeue(&antrianPasien, &riwayatTindakan); break;
            case 9:  popRiwayat(&riwayatTindakan); break;
            case 10: peek(&antrianPasien, &riwayatTindakan); break;
            case 11: tampilAntrian(&antrianPasien); break;
            case 12: tampilRiwayat(&riwayatTindakan); break;
            case 0:
                cout << "\n"; garis('=');
                cout << "  Maksih telah menggunakan PAWCARE PETSHOP\n";
                cout << "  Bye byee!\n"; garis('='); break;
            default: cout << "\n  Pilihan ga valid bozz. Coba lagi.\n"; break;
        }
    } while (pilihan != 0);
    return 0;
}