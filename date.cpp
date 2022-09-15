// Judul : Struct date sekarang, besok dan kemarin
// Nama  : Samuel Andrey Aji Prasetya
// NIM   : A11.2021.13716
#include <iostream>
using namespace std;

struct date
{
    int tgl,bln,thn;
};

struct date now;


void tanggalnya(struct date x) {
    switch (x.bln) {
    case 1:
        cout << x.tgl << " Januari " << x.thn;
        break;
    case 2:
        cout << x.tgl << " Februari " << x.thn;
        break;
    case 3:
        cout << x.tgl << " Maret " << x.thn;
        break;
    case 4:
        cout << x.tgl << " April " << x.thn;
        break;
    case 5:
        cout << x.tgl << " Mei " << x.thn;
        break;
    case 6:
        cout << x.tgl << " Juni " << x.thn;
        break;
    case 7:
        cout << x.tgl << " Juli " << x.thn;
        break;
    case 8:
        cout << x.tgl << " Agustus " << x.thn;
        break;
    case 9:
        cout << x.tgl << " September " << x.thn;
        break;
    case 10:
        cout << x.tgl << " Oktober " << x.thn;
        break;
    case 11:
        cout << x.tgl << " November " << x.thn;
        break;
    case 12:
        cout << x.tgl << " Desember " << x.thn;
        break;
    default:
        break;
    }
}

void besok(struct date x, int tgl_maks) {
    
    if(x.tgl < tgl_maks) {
        x.tgl += 1;
    } else if(x.bln == 12 && x.tgl == tgl_maks) {
        x.thn += 1;
        x.bln = 1;
        x.tgl = 1;
    } else {
        x.bln += 1;
        x.tgl -= tgl_maks - 1;
    }

    tanggalnya(x);
}


void kemarin(struct date x, int tgl_maks) {
    if(x.tgl <= tgl_maks && x.tgl != 1) {
        x.tgl -= 1;
    } else if(x.bln == 1 && x.tgl == 1) {
        x.tgl = 31;
        x.bln = 12;
        x.thn -= 1;

    } else {
        x.bln -= 1;
        // pengecekan hari saat tanggal 1
        if((x.bln <= 7 && x.bln % 2 == 0) || (x.bln >= 8 && x.bln % 2 != 0)) {
            x.tgl = 30;
            if(x.bln == 2) {
                if(x.thn % 4 == 0) {
                    x.tgl = 29;
                } else {
                    x.tgl = 28;
                }
            }
        } else if((x.bln <= 7 && x.bln % 2 != 0) || (x.bln >= 8 && x.bln % 2 == 0)) {
            x.tgl = 31;
        }
        
    }
    tanggalnya(x);
}

int main() {
    // system("cls");

    input_tanggal:
    cout << "Masukkan Tanggal (Format: dd mm yyy) : ";
    cin >> now.tgl;
    cin >> now.bln;
    cin >> now.thn;

    // pengecekan jumlah tanggal dalam satu bulan
    int maks_tgl;
    if((now.bln <= 7 && now.bln % 2 == 0) || (now.bln >= 8 && now.bln % 2 != 0)) {
        maks_tgl = 30;
        if(now.bln == 2) {
            if(now.thn % 4 == 0) {
                maks_tgl = 29;
            } else {
                maks_tgl = 28;
            }
        }
    } else if((now.bln <= 7 && now.bln % 2 != 0) || (now.bln >= 8 && now.bln % 2 == 0)) {
        maks_tgl = 31;
    }
    // if(now.bln % 2 == 0 && now.bln < 8) {
    //     maks_tgl = 30;
    //     if(now.bln == 2) {
    //         if(now.thn % 4 == 0) {
    //             maks_tgl = 29;
    //         } else {
    //             maks_tgl = 28;
    //         }
    //     }
    // } else {
    //     maks_tgl = 31;
    // }

    // if(now.bln % 2 == 0 && now.bln > 7) {
    //     maks_tgl = 31;
    // } else {
    //     maks_tgl = 30;
    // }

    // pengecekan tanggal yang valid
    if(now.tgl > maks_tgl || now.bln > 12) {
        cout << "Tidak ada tanggal, Coba lagi..\n";
        goto input_tanggal;
    }

    // Proses penampilan output
    cout << "\nSekarang : ";
    tanggalnya(now);
    cout << "\nBesok    : ";
    besok(now, maks_tgl);
    cout << "\nKemarin  : ";
    kemarin(now, maks_tgl);
    return 0;
}