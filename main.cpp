#include <iostream>
#include <string>
using namespace std;

struct Laporan {
    int id;
    int jenis;
    int kategori;
    string kontak;
    string namaBarang;
    string lokasi;
    string tanggal;
    string deskripsi;
    string namaPelapor;
    int status;
};

Laporan laporan[100];
int jumlahLaporan = 0;
int nomorID = 1;

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
        if (laporan[i].id == id) {
            return i;
        }
    }
    return -1;
}

void tampilSatuLaporan(int i) {

    cout << "\n====================================\n";
    cout << "          DETAIL LAPORAN\n";
    cout << "====================================\n";
    cout << "ID Laporan    : " << laporan[i].id << endl;
    cout << "Jenis Laporan : " << jenisLaporan(laporan[i].jenis) << endl;
    cout << "Kategori      : " << kategoriBarang(laporan[i].kategori) << endl;
    cout << "Nama Barang   : " << laporan[i].namaBarang << endl;
    cout << "Lokasi        : " << laporan[i].lokasi << endl;
    cout << "Tanggal       : " << laporan[i].tanggal << endl;
    cout << "Deskripsi     : " << laporan[i].deskripsi << endl;
    cout << "Nama Pelapor  : " << laporan[i].namaPelapor << endl;
    cout << "Status        : " << statusLaporan(laporan[i].jenis, laporan[i].status) << endl;
    cout << "====================================\n";
}

void tambahLaporan() {
    system("cls");
    if (jumlahLaporan >= 100) {
        cout << "\nKapasitas laporan sudah penuh!\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "          TAMBAH LAPORAN\n";
    cout << "====================================\n";
    cout << "1. Barang Hilang\n";
    cout << "2. Barang Temuan\n";
    laporan[jumlahLaporan].jenis = inputRentang("Pilih jenis laporan: ", 1, 2);

    cout << "\nPILIH KATEGORI BARANG\n";
    cout << "1. Elektronik\n";
    cout << "2. Dokumen\n";
    cout << "3. Aksesori\n";
    cout << "4. Pakaian\n";
    cout << "5. Kunci\n";
    cout << "6. Lainnya\n";
    laporan[jumlahLaporan].kategori = inputRentang("Pilih kategori: ", 1, 6);

    cout << "\tMASUKKAN DETAIL LAPORAN\n\n";
    laporan[jumlahLaporan].id = nomorID;
    laporan[jumlahLaporan].namaBarang = inputTeks("Nama Barang  : ");
    laporan[jumlahLaporan].lokasi = inputTeks("Lokasi       : ");
    laporan[jumlahLaporan].tanggal = inputTeks("Tanggal      : ");
    laporan[jumlahLaporan].deskripsi = inputTeks("Deskripsi    : ");
    laporan[jumlahLaporan].namaPelapor = inputTeks("Nama Pelapor : ");
    laporan[jumlahLaporan].kontak = inputTeks("Kontak       : ");
    laporan[jumlahLaporan].status = 1;
    cout << "\nLaporan berhasil ditambahkan!\n";
    cout << "ID Laporan: " << nomorID << endl;

    jumlahLaporan++;
    nomorID++;
    cin.get();
}

void tampilkanLaporan() {
    system("cls");
    if (jumlahLaporan == 0) {
        cout << "Belum ada laporan.\n";
        return;
    }

    for (int i = 0; i < jumlahLaporan; i++) {
        tampilSatuLaporan(i);
    }

    cout << "Total laporan: " << jumlahLaporan << endl;
    cin.get();
}

void cariLaporan() {
    system("cls");

    if (jumlahLaporan == 0) {
        cout << "\nBelum ada laporan untuk dicari.\n";
        return;
    }

    cout << "\n========== CARI LAPORAN ==========\n";
    cout << "1. Cari berdasarkan nama barang\n";
    cout << "2. Cari berdasarkan kategori\n";

    int pilihan = inputRentang(
        "Pilih pencarian: ", 1, 2
    );

    if (pilihan == 1) {

        string nama = inputTeks(
            "Masukkan nama barang: "
        );

        bool ditemukan = false;

        for (int i = 0; i < jumlahLaporan; i++) {
            if (laporan[i].namaBarang.find(nama) != string::npos) {
                tampilSatuLaporan(i);
                ditemukan = true;
            }
        }

        if (!ditemukan) {
            cout << "\nBarang tidak ditemukan!\n";
        }
    }else {

        cout << "\nPILIH KATEGORI BARANG\n";
        cout << "1. Elektronik\n";
        cout << "2. Dokumen\n";
        cout << "3. Aksesori\n";
        cout << "4. Pakaian\n";
        cout << "5. Kunci\n";
        cout << "6. Lainnya\n";

        int kategori = inputRentang(
            "Pilih kategori: ", 1, 6
        );

        bool ditemukan = false;

        for (int i = 0; i < jumlahLaporan; i++) {
            if (laporan[i].kategori == kategori) {
                tampilSatuLaporan(i);
                ditemukan = true;
            }
        }

        if (!ditemukan) {
            cout << "\nTidak ada laporan pada kategori tersebut!\n";
        }
    }
    cin.get();
}

void updateStatus() {

    system("cls");
    if (jumlahLaporan == 0) {
        cout << "\nBelum ada laporan.\n";
        return;
    }

    cout << "\n========== UPDATE STATUS ==========\n";

    int id = inputAngka("Masukkan ID laporan: ");
    int index = cariID(id);

    if (index == -1) {
        cout << "Laporan tidak ditemukan!\n";
        return;
    }

    tampilSatuLaporan(index);

    cout << "\nPilih status baru:\n";

    if (laporan[index].jenis == 1) {

        cout << "1. Belum Ditemukan\n";
        cout << "2. Sudah Ditemukan\n";
        cout << "3. Sudah Dikembalikan\n";
    }
    else {
        cout << "1. Belum Diklaim\n";
        cout << "2. Pemilik Ditemukan\n";
        cout << "3. Sudah Diambil\n";
    }

    int status = inputRentang(
        "Pilih status: ", 1, 3
    );

    laporan[index].status = status;

    cout << "\nStatus berhasil diperbarui!\n";
    cout << "Status sekarang: " << statusLaporan(laporan[index].jenis, laporan[index].status) << endl;

    cin.get();
}

void hapusLaporan() {
    system("cls");
    if (jumlahLaporan == 0) {
        cout << "\nBelum ada laporan untuk dihapus.\n";
        return;
    }

    cout << "\n========== HAPUS LAPORAN ==========\n";

    int id = inputAngka("Masukkan ID laporan: ");
    int index = cariID(id);

    if (index == -1) {
        cout << "Laporan tidak ditemukan!\n";
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
            laporan[i] = laporan[i + 1];
        }

        jumlahLaporan--;

        cout << "\nLaporan berhasil dihapus!\n";
    }
    else {
        cout << "\nPenghapusan dibatalkan.\n";
    }
    cin.get();
}

int main() {

    int pilihan;

    do {
        system("cls");

        cout << "\n====================================\n";
        cout << "       CAMPUS LOST AND FOUND\n";
        cout << "====================================\n";
        cout << "1. Tambah Laporan\n";
        cout << "2. Tampilkan Semua Laporan\n";
        cout << "3. Cari Laporan\n";
        cout << "4. Update Status Laporan\n";
        cout << "5. Hapus Laporan\n";
        cout << "6. Keluar\n";

        cout << "====================================\n";

        pilihan = inputRentang(
            "Pilih menu: ", 1, 6
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
                cout << "\nProgram selesai.\n";
                cout << "Seluruh data sementara akan hilang.\n";
                break;
        }

    } while (pilihan != 6);
    return 0;
}
