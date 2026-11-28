#include <iostream>
#include <string>
using namespace std;

struct Laporan {
    int id;
    int jenis;
    int kategori;
    int status;
    string kontak;
    string namaBarang;
    string lokasi;
    string tanggal;
    string deskripsi;
    string namaPelapor;
};

Laporan lapor[100];
int jumlahLaporan = 0;
int nomorID = 1;
//Prototype
void bersihkanInput();
int inputAngka(string pesan);
int inputRentang(string pesan, int min, int max);
string inputTeks(string pesan);
string jenisLaporan(int jenis);
string kategoriBarang(int kategori);
string statusLaporan(int jenis, int status);
int cariID(int id);
void tampilSatuLaporan(int i);
void tambahLaporan();
void tampilkanLaporan();
void cariLaporan();
void updateStatus();
void hapusLaporan();

int main() {
    int pilihan;
    do {
        system("cls");

        cout << "\n====================================\n";
        cout << "           LOST AND FOUND\n";
        cout << "====================================\n";
        cout << "1. TAMBAH LAPORAN\n";
        cout << "2. TAMPILKAN SEMUA LAPORAN\n";
        cout << "3. CARI LAPORAN\n";
        cout << "4. UPDATE STATUS LAPORAN\n";
        cout << "5. HAPUS LAPORAN\n";
        cout << "6. KELUAR\n";
        cout << "====================================\n";

        pilihan = inputRentang(
            "PILIH MENU[1-6]: ", 1, 6
        );
        system("cls");

        switch (pilihan) {
            case 1:
                tambahLaporan();
                break;
            case 2:
                tampilkanLaporan();
                break;
            case 3:
                cariLaporan();
                break;
            case 4:
                updateStatus();
                break;
            case 5:
                hapusLaporan();
                break;
            case 6:
                cout << "\n\t  PROGRAM KELUAR\n";
                cout << "----------------------------------\n";
                cout << "======= SEMUA DATA DIHAPUS =======\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}

void bersihkanInput() {
    char karakter;
    while (cin.get(karakter) && karakter != '\n') {
    }
}
int inputAngka(string pesan) {
    int angka;

    while (true) {
        cout << pesan;
        if (cin >> angka) {
            bersihkanInput();
            return angka;
        }

        cout << "Input harus berupa angka!\n";
        cin.clear();
        bersihkanInput();
    }
}
int inputRentang(string pesan, int min, int max) {
    int angka;
    do {
        angka = inputAngka(pesan);
        if (angka < min || angka > max) {
            cout << "Pilihan harus antara " << min << " sampai " << max << "!\n";
        }
    } while (angka < min || angka > max);
    system("cls");
    return angka;
}
string inputTeks(string pesan) {
    string teks;
    do {
        cout << pesan;
        getline(cin, teks);

        if (teks.empty()) {
            cout << "Data tidak boleh kosong!\n";
        }

    } while (teks.empty());

    return teks;
}
string jenisLaporan(int jenis) {
    if (jenis == 1) {
        return "Barang Hilang";
    }
    return "Barang Temuan";
}
string kategoriBarang(int kategori) {
    switch (kategori) {
        case 1:
            return "Elektronik";
        case 2:
            return "Dokumen";
        case 3:
            return "Aksesori";
        case 4:
            return "Pakaian";
        case 5:
            return "Kunci";
        case 6:
            return "Lainnya";
        default:
            return "Tidak diketahui";
    }
}
string statusLaporan(int jenis, int status) {

    if (jenis == 1) {
        if (status == 1) {
            return "Belum Ditemukan";
        }
        else if (status == 2) {
            return "Sudah Ditemukan";
        }
        else {
            return "Sudah Dikembalikan";
        }
    }
    else {
        if (status == 1) {
            return "Belum Diklaim";
        }
        else if (status == 2) {
            return "Pemilik Ditemukan";
        }
        else {
            return "Sudah Diambil";
        }
    }
}
int cariID(int id) {
    for (int i = 0; i < jumlahLaporan; i++) {
        if (lapor[i].id == id) {
            return i;
        }
    }
    return -1;
}
void tampilSatuLaporan(int i) {

    cout << "\n====================================\n";
    cout << "          DETAIL LAPORAN\n";
    cout << "====================================\n";
    cout << "ID LAPORAN       : " << lapor[i].id << endl;
    cout << "JENIS LAPORAN    : " << jenisLaporan(lapor[i].jenis) << endl;
    cout << "KATEGORI         : " << kategoriBarang(lapor[i].kategori) << endl;
    cout << "NAMA PELAPOR     : " << lapor[i].namaPelapor << endl;
    cout << "KONTAK PELAPOR   : " << lapor[i].kontak << endl;
    cout << "NAMA BARANG      : " << lapor[i].namaBarang << endl;
    cout << "LOKASI TERAKHIR  : " << lapor[i].lokasi << endl;
    cout << "TANGGAL          : " << lapor[i].tanggal << endl;
    cout << "DESKRIPSI BARANG : " << lapor[i].deskripsi << endl;
    cout << "STATUS           : " << statusLaporan(lapor[i].jenis, lapor[i].status) << endl;
    cout << "====================================\n";
}
void tambahLaporan() {
    system("cls");
    if (jumlahLaporan >= 100) {
        cout << "\n\tLAPORAN SUDAH PENUH\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "          TAMBAH LAPORAN\n";
    cout << "====================================\n";
    cout << "1. BARANG HILANG\n";
    cout << "2. BARANG TEMUAN\n";
    lapor[jumlahLaporan].jenis = inputRentang("PILIH JENIS LAPORAN[1-2]: ", 1, 2);

    cout << "\nPILIH KATEGORI BARANG\n";
    cout << "1. ELEKTRONIK\n";
    cout << "2. DOKUMEN\n";
    cout << "3. AKSESORI\n";
    cout << "4. PAKAIAN\n";
    cout << "5. KUNCI\n";
    cout << "6. LAINNYA\n";
    lapor[jumlahLaporan].kategori = inputRentang("PILIH KATEGORI[1-6]: ", 1, 6);

    cout << "\tMASUKKAN DETAIL LAPORAN\n\n";
    lapor[jumlahLaporan].id = nomorID;
    lapor[jumlahLaporan].namaBarang = inputTeks("NAMA BARANG      : ");
    lapor[jumlahLaporan].lokasi = inputTeks("LOKASI TERAKHIR  : ");
    lapor[jumlahLaporan].tanggal = inputTeks("TANGGAL          : ");
    lapor[jumlahLaporan].deskripsi = inputTeks("DESKRIPSI BARANG : ");
    lapor[jumlahLaporan].namaPelapor = inputTeks("NAMA PELAPOR     : ");
    lapor[jumlahLaporan].kontak = inputTeks("KONTAK PELAPOR   : ");
    lapor[jumlahLaporan].status = 1;
    cout << "\n=== LAPORAN BERHASIL DITAMBAHKAN! ===\n";
    cout << "ID: " << nomorID << endl;
    cout << "Tekan ENTER untuk kembali";

    jumlahLaporan++;
    nomorID++;
    cin.get();
}
void tampilkanLaporan() {
    system("cls");
    if (jumlahLaporan == 0) {
        cout << "BELUM ADA LAPORAN\n";
        return;
    }

    for (int i = 0; i < jumlahLaporan; i++) {
        tampilSatuLaporan(i);
    }

    cout << "LAPORAN TERDAFTAR: " << jumlahLaporan << endl;
    cin.get();
}
void cariLaporan() {
    system("cls");

    if (jumlahLaporan == 0) {
        cout << "\n=== BELUM ADA LAPORAN ===\n";
        return;
    }

    cout << "\n========== CARI LAPORAN ==========\n";
    cout << "1. CARI BERDASARKAN NAMA BARANG\n";
    cout << "2. CARI BERDASARKAN KATEGORI\n";

    int pilihan = inputRentang(
        "PILIH PENCARIAN[1-2]: ", 1, 2
    );

    if (pilihan == 1) {

        string nama = inputTeks(
            "MASUKKAN NAMA BARANG: "
        );

        bool ditemukan = false;

        for (int i = 0; i < jumlahLaporan; i++) {
            if (lapor[i].namaBarang.find(nama) != string::npos) {
                tampilSatuLaporan(i);
                ditemukan = true;
            }
        }

        if (!ditemukan) {
            cout << "\n=== BARANG TIDAK DITEMUKAN! ===\n";
        }
    }else {

        cout << "\nPILIH KATEGORI BARANG\n";
        cout << "1. ELEKTRONIK\n";
        cout << "2. DOKUMEN\n";
        cout << "3. AKSESORI\n";
        cout << "4. PAKAIAN\n";
        cout << "5. KUNCI\n";
        cout << "6. LAINNYA\n";

        int kategori = inputRentang(
            "PILIH KATEGORI[1-6]: ", 1, 6
        );

        bool ditemukan = false;

        for (int i = 0; i < jumlahLaporan; i++) {
            if (lapor[i].kategori == kategori) {
                tampilSatuLaporan(i);
                ditemukan = true;
            }
        }

        if (!ditemukan) {
            cout << "\n--- TIDAK ADA LAPORAN PADA KATEGORI TERSEBUT! ---\n";
        }
    }
    cin.get();
}
void updateStatus() {

    system("cls");
    if (jumlahLaporan == 0) {
        cout << "\nBELUM ADA LAPORAN\n";
        return;
    }

    cout << "\n======= UPDATE STATUS LAPORAN =======\n";

    int id = inputAngka("MASUKKAN ID: ");
    int index = cariID(id);

    if (index == -1) {
        cout << "LAPORAN TIDAK VALID!\n";
        return;
    }

    tampilSatuLaporan(index);

    cout << "\nPILIH STATUS: \n";

    if (lapor[index].jenis == 1) {
        cout << "1. SUDAH DITEMUKAN\n";
        cout << "2. SUDAH DIKEMBALIKAN\n";
    }
    else {
        cout << "1. PEMILIK DITEMUKAN\n";
        cout << "2. SUDAH DIAMBIL\n";
    }

    int status = inputRentang(
        "PILIH STATUS[1-2]: ", 1, 2
    );

    lapor[index].status = status;

    cout << "\n=== STATUS BERHASIL DIPERBARUI! ===\n";
    cout << "STATUS TERBARU: " << statusLaporan(lapor[index].jenis, lapor[index].status) << endl;

    cin.get();
}
void hapusLaporan() {
    system("cls");
    if (jumlahLaporan == 0) {
        cout << "\nBELUM ADA LAPORAN UNTUK DIHAPUS.\n";
        return;
    }

    cout << "\n========== HAPUS LAPORAN ==========\n";

    int id = inputAngka("MASUKKAN ID: ");
    int index = cariID(id);

    if (index == -1) {
        cout << "LAPORAN TIDAK VALID!\n";
        return;
    }

    tampilSatuLaporan(index);

    cout << "\nApakah Anda yakin ingin menghapus?\n";
    cout << "1. Ya\n";
    cout << "2. Tidak\n";

    int konfirmasi = inputRentang(
        "Pilihan: ", 1, 2
    );

    if (konfirmasi == 1) {
        for (int i = index; i < jumlahLaporan - 1; i++) {
            lapor[i] = lapor[i + 1];
        }

        jumlahLaporan--;

        cout << "\nLaporan berhasil dihapus!\n";
    }
    else {
        cout << "\nPenghapusan dibatalkan.\n";
    }
    cin.get();
}