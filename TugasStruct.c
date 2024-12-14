#include <stdio.h>
#include <stdlib.h>
struct Mahasiswa{
    int npm;
    char nama[30];
    int umur;
    float ipk;
};
typedef struct Mahasiswa Mahasiswa;
void cariData(Mahasiswa* mhs, int jumlah, int cari);
void tampilkanData(Mahasiswa* mhs, int jumlah);
void tambahData(Mahasiswa** mhs, int* jumlah);
void program(Mahasiswa* mahasiswa, int jumlah);
int main(){
    int jumlah = 0;
    Mahasiswa* mahasiswa = NULL;
    program(mahasiswa, jumlah);
    return 0;
}

void program(Mahasiswa* mahasiswa, int jumlah){
    int pilihan, cari;
    while (1){
    printf("=== Program Struct Mahasiswa ===\n");
    printf("1. Menambah Data Mahasiswa\n");
    printf("2. Menampilkan Data Mahasiswa\n");
    printf("3. Mencari Mahasiswa dengan NPM\n");
    printf("4. Keluar Program\n");
    printf("Pilih nomor program: ");
    scanf("%d", &pilihan);
    switch (pilihan){
        case 1:
            tambahData(&mahasiswa, &jumlah);
            break;
        case 2:
            if( mahasiswa != NULL && jumlah > 0){
                tampilkanData(mahasiswa, jumlah);
            }else {
                printf("Data belum ada!!\n");
            }
            break;
        case 3:
            if( mahasiswa != NULL && jumlah > 0){
                printf("Masukkan npm dari mahasiswa: ");
                scanf("%d", &cari);
                cariData(mahasiswa, jumlah, cari);
            }else {
                printf("Data belum ada!!\n");
            }
            break;
        case 4:
            printf("Program berhenti...");
            return;
        default:
            printf("Masukkan nomor dari programnya!!");
            break;
    }
}
}

void tambahData(Mahasiswa** mhs, int* jumlah) {
    int tambah;
    printf("Masukkan jumlah data mahasiswa yang ingin ditambah: ");
    scanf("%d", &tambah);

    *mhs = (Mahasiswa*) realloc(*mhs, (*jumlah + tambah) * sizeof(Mahasiswa));

    for (int i = 0; i < tambah; i++) {
        printf("Mahasiswa %d\n", *jumlah + 1);
        printf("Masukkan NPM mahasiswa: ");
        scanf("%d", &(*mhs)[*jumlah].npm);
        printf("Masukkan nama mahasiswa: ");
        scanf("%s", (*mhs)[*jumlah].nama);
        printf("Masukkan umur mahasiswa: ");
        scanf("%d", &(*mhs)[*jumlah].umur);
        printf("Masukkan IPK mahasiswa: ");
        scanf("%f", &(*mhs)[*jumlah].ipk);
        printf("\n");
        (*jumlah)++;
    }
}

void tampilkanData(Mahasiswa* mhs, int jumlah){
    for (int i = 0; i < jumlah; i++){
        printf("\nMahasiswa %d\n", i+1);
        printf("=== NPM: %d\n", mhs[i].npm);
        printf("=== Nama: %s\n", mhs[i].nama);
        printf("=== Umur: %d\n", mhs[i].umur);
        printf("=== IPK: %.2f\n", mhs[i].ipk);
        printf("\n");
    }
}

void cariData(Mahasiswa* mhs, int jumlah, int cari){
    for(int i = 0; i < jumlah; i++){
        if(mhs[i].npm == cari){
            printf("Mahasiswa dengan NPM %d ada pada data\n", cari);
            printf("=== NPM: %d\n", mhs[i].npm);
            printf("=== Nama: %s\n", mhs[i].nama);
            printf("=== Umur: %d\n", mhs[i].umur);
            printf("=== IPK: %.2f\n", mhs[i].ipk);
            printf("\n");
            return;
        }
    }
    printf("Mahasiswa dengan NPM %d tidak ada pada data!\n", cari);
}