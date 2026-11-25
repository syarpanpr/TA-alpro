#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAKS = 100;
const int JUMLAH_KATEGORI = 6;

const string NAMA_KATEGORI[JUMLAH_KATEGORI] = {
    "Elektronik",
    "Dokumen & Kartu",
    "Tas & Dompet",
    "Pakaian & Aksesoris",
    "Kunci",
    "Lainnya"
};

const string NAMA_JENIS[3]  = {"", "HILANG", "TEMUAN"};
const string NAMA_STATUS[4] = {"", "Belum Ditangani", "Dalam Proses", "Selesai"};

struct Lapor {
    int id;
    int jenis;      // 1 = Hilang, 2 = Temuan
    int kategori;   // 1..JUMLAH_KATEGORI
    int status;     // 1 = Belum Ditangani, 2 = Dalam Proses, 3 = Selesai
    string namaBarang;
    string deskripsi;
    string lokasi;
    string tanggal;
    string namaPelapor;
    string kontak;
};

Lapor laporan[MAKS];
int jumlahLaporan = 0;
int noid = 1;

// ---------- Fungsi bantu input ----------

int bacaAngka(const string& prompt, int minVal, int maxVal) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x && x >= minVal && x <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cout << "Input tidak valid! Masukkan angka " << minVal
             << " - " << maxVal << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string bacaTeks(const string& prompt) {
    string s;
    while (true) {
        cout << prompt;
        getline(cin, s);
        if (!s.empty()) return s;
        cout << "Input tidak boleh kosong!" << endl;
    }
}

void tampilDaftarKategori() {
    for (int i = 0; i < JUMLAH_KATEGORI; i++) {
        cout << "  " << i + 1 << ". " << NAMA_KATEGORI[i] << endl;
    }
}

int cariIndexById(int id) {
    for (int i = 0; i < jumlahLaporan; i++) {
        if (laporan[i].id == id) return i;
    }
    return -1;
}

void tampilDetail(const Lapor& l) {
    cout << " --------------------------------" << endl;
    cout << " ID            : " << l.id << endl;
    cout << " Jenis         : " << NAMA_JENIS[l.jenis] << endl;
    cout << " Status        : " << NAMA_STATUS[l.status] << endl;
    cout << " Kategori      : " << NAMA_KATEGORI[l.kategori - 1] << endl;
    cout << " Nama Barang   : " << l.namaBarang << endl;
    cout << " Deskripsi     : " << l.deskripsi << endl;
    cout << " Lokasi        : " << l.lokasi << endl;
    cout << " Tanggal       : " << l.tanggal << endl;
    cout << " Pelapor       : " << l.namaPelapor << endl;
    cout << " Kontak        : " << l.kontak << endl;
}

// ---------- Fitur utama ----------

// 1. Tambah laporan (hilang / temuan)
void tambahLaporan() {
    cout << "\n=== TAMBAH LAPORAN ===" << endl;
    if (jumlahLaporan >= MAKS) {
        cout << "Kapasitas penuh! Hapus laporan lama terlebih dahulu." << endl;
        return;
    }

    Lapor l;
    l.id = noid++;
    l.status = 1;  // status awal otomatis

    cout << "Jenis laporan:" << endl;
    cout << "  1. Barang Hilang" << endl;
    cout << "  2. Barang Temuan" << endl;
    l.jenis = bacaAngka("Pilih jenis (1-2): ", 1, 2);

    cout << "Kategori barang:" << endl;
    tampilDaftarKategori();
    l.kategori = bacaAngka("Pilih kategori: ", 1, JUMLAH_KATEGORI);

    l.namaBarang  = bacaTeks("Nama barang                : ");
    l.deskripsi   = bacaTeks("Deskripsi (warna/ciri)     : ");
    l.lokasi      = bacaTeks(l.jenis == 1 ? "Lokasi terakhir terlihat   : "
                                          : "Lokasi ditemukan           : ");
    l.tanggal     = bacaTeks("Tanggal (dd/mm/yyyy)       : ");
    l.namaPelapor = bacaTeks("Nama pelapor               : ");
    l.kontak      = bacaTeks("Kontak pelapor (HP/email)  : ");

    laporan[jumlahLaporan++] = l;
    cout << "\nLaporan berhasil ditambahkan dengan ID " << l.id << "." << endl;
}

// 2. Tampilkan semua laporan
void tampilkanLaporan() {
    cout << "\n=== SEMUA LAPORAN ===" << endl;
    if (jumlahLaporan == 0) {
        cout << "Belum ada laporan." << endl;
        return;
    }
    for (int i = 0; i < jumlahLaporan; i++) {
        tampilDetail(laporan[i]);
    }
    cout << " --------------------------------" << endl;
    cout << "Total laporan: " << jumlahLaporan << endl;
}

// 3. Update status laporan
void updateStatus() {
    cout << "\n=== UPDATE STATUS LAPORAN ===" << endl;
    if (jumlahLaporan == 0) {
        cout << "Belum ada laporan." << endl;
        return;
    }
    int id = bacaAngka("Masukkan ID laporan: ", 1, noid);
    int idx = cariIndexById(id);
    if (idx == -1) {
        cout << "Laporan dengan ID " << id << " tidak ditemukan." << endl;
        return;
    }

    tampilDetail(laporan[idx]);
    cout << "Status baru:" << endl;
    cout << "  1. Belum Ditangani" << endl;
    cout << "  2. Dalam Proses" << endl;
    cout << "  3. Selesai (barang sudah dikembalikan/ditemukan)" << endl;
    laporan[idx].status = bacaAngka("Pilih status (1-3): ", 1, 3);
    cout << "Status berhasil diperbarui menjadi: "
         << NAMA_STATUS[laporan[idx].status] << endl;
}

// 4. Tampilkan berdasarkan kategori
void tampilkanPerKategori() {
    cout << "\n=== LAPORAN PER KATEGORI ===" << endl;
    tampilDaftarKategori();
    int kat = bacaAngka("Pilih kategori: ", 1, JUMLAH_KATEGORI);

    int ditemukan = 0;
    for (int i = 0; i < jumlahLaporan; i++) {
        if (laporan[i].kategori == kat) {
            tampilDetail(laporan[i]);
            ditemukan++;
        }
    }
    if (ditemukan == 0) {
        cout << "Tidak ada laporan pada kategori "
             << NAMA_KATEGORI[kat - 1] << "." << endl;
    } else {
        cout << " --------------------------------" << endl;
        cout << "Total: " << ditemukan << " laporan." << endl;
    }
}

// 5. Hapus laporan
void hapusLaporan() {
    cout << "\n=== HAPUS LAPORAN ===" << endl;
    if (jumlahLaporan == 0) {
        cout << "Belum ada laporan." << endl;
        return;
    }
    int id = bacaAngka("Masukkan ID laporan yang dihapus: ", 1, noid);
    int idx = cariIndexById(id);
    if (idx == -1) {
        cout << "Laporan dengan ID " << id << " tidak ditemukan." << endl;
        return;
    }

    tampilDetail(laporan[idx]);
    string yakin = bacaTeks("Yakin hapus laporan ini? (y/n): ");
    if (yakin == "y" || yakin == "Y") {
        for (int i = idx; i < jumlahLaporan - 1; i++) {
            laporan[i] = laporan[i + 1];   // geser elemen ke kiri
        }
        jumlahLaporan--;
        cout << "Laporan berhasil dihapus." << endl;
    } else {
        cout << "Penghapusan dibatalkan." << endl;
    }
}

// ---------- Program utama ----------

int main() {
    int pilMenu;

    do {
        cout << "\n ================================" << endl;
        cout << "\tLOST & FOUND SYSTEM" << endl;
        cout << " ================================" << endl;
        cout << "1. Tambah Laporan (Hilang/Temuan)" << endl;
        cout << "2. Tampilkan Semua Laporan" << endl;
        cout << "3. Update Status Laporan" << endl;
        cout << "4. Tampilkan Laporan per Kategori" << endl;
        cout << "5. Hapus Laporan" << endl;
        cout << "6. Keluar" << endl;
        cout << " ================================" << endl;
        pilMenu = bacaAngka("Pilih menu: ", 1, 6);

        switch (pilMenu) {
            case 1: tambahLaporan();       break;
            case 2: tampilkanLaporan();    break;
            case 3: updateStatus();        break;
            case 4: tampilkanPerKategori(); break;
            case 5: hapusLaporan();        break;
            case 6: cout << "Keluar dari program. Terima kasih!" << endl; break;
        }
    } while (pilMenu != 6);

    return 0;
}