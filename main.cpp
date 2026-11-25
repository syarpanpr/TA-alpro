#include <iostream>
#include <string>
using namespace std;

struct Lapor
{
    int id;
    int kategori;
    string namaBarang;
    string deskripsi;
    string lokasi;
    string tanggal;
    string namaPelapor;
};

Lapor laporan[10];

int jumlahLaporan = 0;
int noid = 1;

int main()
{

    int pilMenu;

    cout << "halo";

    do
    {
        cout << " ================================" << endl;
        cout << "\tLOST & FOUND SYSTEM" << endl;
        cout << " ================================" << endl;
        cout << "1. Tambah Laporan Barang Hilang" << endl;
        cout << "2. Tampilkan Semua Laporan" << endl;
        cout << "3. Update Laporan Barang Hilang" << endl;
        cout << "4. Hapus Laporan Barang Hilang" << endl;
        cout << "5. Keluar" << endl;
        cout << " ================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilMenu;

        switch (pilMenu)
        {
        case 1:
            cout << "Tambah Laporan Barang Hilang" << endl;
            break;
        case 2:
            cout << "Tampilkan Semua Laporan" << endl;
            break;
        case 3:
            cout << "Update Laporan Barang Hilang" << endl;
            break;
        case 4:
            cout << "Hapus Laporan Barang Hilang" << endl;
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        }
    } while (pilMenu != 5);

    cin.get();
    return 0;
}