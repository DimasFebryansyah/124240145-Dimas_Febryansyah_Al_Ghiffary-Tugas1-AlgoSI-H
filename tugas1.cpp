#include <iostream>
#include <string>

using namespace std;

struct Batalyon
{
    int id;
    string namaJenderal;
    string tipePasukan;
    int jumlahPasukan;
    Batalyon *next;
};

Batalyon *head = NULL;
int currentID = 1;

const string tipePasukanList[] = {"Infantry", "Kavaleri", "Archer"};

bool validasiTipePasukan(const string &tipe)
{
    for (int i = 0; i < 3; ++i)
    {
        if (tipePasukanList[i] == tipe)
            return true;
    }
    return false;
}

bool batalyonExists(const string &namaJenderal)
{
    Batalyon *temp = head;
    while (temp != NULL)
    {
        if (temp->namaJenderal == namaJenderal)
            return true;
        temp = temp->next;
    }
    return false;
}

void tambahBatalyon()
{
    string namaJenderal, tipePasukan;
    int jumlahPasukan;

    cout << "Masukkan nama jenderal: ";
    cin >> namaJenderal;
    if (batalyonExists(namaJenderal))
    {
        cout << "Error: Nama jenderal sudah terdaftar!" << endl;
        return;
    }

    cout << "Masukkan tipe pasukan (Infantry, Kavaleri, Archer): ";
    cin >> tipePasukan;
    if (!validasiTipePasukan(tipePasukan))
    {
        cout << "Error: Tipe pasukan tidak valid!" << endl;
        return;
    }

    cout << "Masukkan jumlah pasukan: ";
    cin >> jumlahPasukan;
    if (jumlahPasukan < 1)
    {
        cout << "Error: Jumlah pasukan harus lebih dari 0!" << endl;
        return;
    }

    Batalyon *batalyon = new Batalyon{currentID++, namaJenderal, tipePasukan, jumlahPasukan, NULL};
    if (head == NULL)
    {
        head = batalyon;
    }
    else
    {
        Batalyon *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = batalyon;
    }
    cout << "Batalyon berhasil ditambahkan!" << endl;

    char pilihan;
    do
    {
        cout << "Apakah anda ingin kembali ke menu? (Y/N): ";
        cin >> pilihan;
        if (pilihan == 'N' || pilihan == 'n')
        {
            exit(0);
        }
        else if (pilihan != 'Y' && pilihan != 'y')
        {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 'Y' && pilihan != 'y');
}

void cariBatalyon()
{
    string namaJenderal;
    cout << "Nama General yang ingin anda cari : ";
    cin >> namaJenderal;

    Batalyon *low = head;
    while (low != NULL && low->namaJenderal < namaJenderal)
    {
        low = low->next;
    }

    if (low != NULL && low->namaJenderal == namaJenderal)
    {
        cout << "General ditemukan!" << endl;
        cout << "ID: " << low->id << endl;
        cout << "Nama: " << low->namaJenderal << endl;
        cout << "Tipe Pasukan: " << low->tipePasukan << endl;
        cout << "Jumlah Pasukan: " << low->jumlahPasukan << endl;
    }
    else
    {
        cout << "Error: Batalyon tidak ditemukan!" << endl;
    }

    // Menambahkan jeda dan pilihan kembali ke menu atau keluar
    char pilihan;
    do
    {
        cout << "Apakah anda ingin kembali ke menu? (Y/N): ";
        cin >> pilihan;
        if (pilihan == 'N' || pilihan == 'n')
        {
            exit(0);
        }
        else if (pilihan != 'Y' && pilihan != 'y')
        {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 'Y' && pilihan != 'y');
}

void tampilkanMenu()
{
    cout << "1. Tambah Batalyon" << endl;
    cout << "2. Cari Batalyon" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih opsi: ";
}

int main()
{
    while (true)
    {
        tampilkanMenu();
        int pilihan;
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambahBatalyon();
            break;
        case 2:
            cariBatalyon();
            break;
        case 3:
            return 0;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    }
    return 0;
}
