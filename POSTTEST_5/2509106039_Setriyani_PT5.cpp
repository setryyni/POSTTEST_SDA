#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Perpustakaan
struct BukuNode {
    string judulBuku;
    BukuNode* next;

    // Constructor
    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

//kodingan yang mw dilengkapi
bool cariBuku(BukuNode* head, string judulDicari) {
    // Kalau listnya kosong, ga perlu dicari, langsung return false
    if (head == nullptr) return false;

    // Mulai penelusuran dari node head
    BukuNode* temp = head;

    // Pakai do-while biar node head ikut dicek juga di iterasi pertama
    do {
        // Kalau judul node sekarang cocok sama yang dicari, return true
        if (temp->judulBuku == judulDicari) return true;

        // Geser ke node berikutnya
        temp = temp->next;

    } while (temp != head); // Berhenti kalau udah balik lagi ke head (satu putaran penuh)

    // Udah keliling semua node, ga ketemu juga, return false
    return false;
}

int main() {
    BukuNode* head = nullptr;
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': " << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl; // Harusnya output: Ditemukan
    cout << "Mencari buku '" << buku2 << "': " << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl; // Harusnya output: Tidak Ditemukan

    return 0;
}