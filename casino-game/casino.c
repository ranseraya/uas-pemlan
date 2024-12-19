#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct profilePemain{
    char username[10];
    char password[20];
    char role[10];
    int cash;
    int gamePlayed;
    int profit;
};
typedef struct profilePemain pemain;

void gameMenu(pemain pemain);//parameter profile
void adminMenu();
void registrasi();
void loadGame();

void displayProfile(pemain pemain);

void playBlackjack();
void playHighOrLow();
void playHeadOrTail();
void playBarakat();

int main(){
    // profile* users = NULL;
    pemain pemain1;
    strcpy(pemain1.username, "Anton");
    strcpy(pemain1.password, "admin");
    strcpy(pemain1.role, "pemain");
    pemain1.cash = 5000000;
    pemain1.gamePlayed = 30;
    pemain1.profit = 3000000;
    int pilihan;
    while(1){
    system("cls");
    printf("----------------------------- PROJECT UAS CASINO GACOR -----------------------------\n");
    printf("------------------------------- TEAM TOW NEVER END ---------------------------------\n");
    printf("1. New Profile\n");
    printf("2. Load Profile\n");
    printf("0. Exit\n");
    printf("Program: ");
    scanf("%d", &pilihan);
    switch(pilihan){
        case 1:
            //New profile
            system("cls");
            gameMenu(pemain1); // parameter profile
        case 2:
            //Load game profile
            // if( role == 'admin'){
                //adminMenu();
            // }
            system("cls");
            gameMenu(pemain1);
        case 0:
            printf("Keluar game...\n");
            return 0;
        default:
    }
    }
}

void gameMenu(pemain pemain){ //parameter profile
    int pilihanGame;
    while (1) {
        displayProfile(pemain);
        printf("\n=== Daftar Game  ===\n");
        printf("0. Info game\n");
        printf("1. Blackjack\n");
        printf("2. High or Low\n");
        printf("3. Head or Tail\n");
        printf("4. Barakat\n");
        printf("5. Back to Main Menu\n");
        printf("Pilih game : ");
        scanf("%d", &pilihanGame);
        switch (pilihanGame) {
            case 0:
                break;
            case 1:
                // playBlackjack();
                break;
            case 2:
                // playHighOrLow();
                break;
            case 3:
                // playHeadOrTail();
                break;
            case 4:
                // playBarakat();
                break;
            case 5:
                printf("Kembali ke menu utama...\n");
                return;
            default:
                printf("Pilihan tidak valid! masukkan nomor program...\n");
        }
    }
}

// Menu untuk admin
void adminMenu(){

}


// Registrasi / membuat akun
void registrasi(){

}

// Load profile pemain
void loadGame(){

}

// menampilkan profil singkat pemain
void displayProfile(pemain pemain){
    printf("| Username: %-10s| Chip: %-9d| Game Played: %-4d| Profit: %-10d|\n", pemain.username, pemain.cash, pemain.gamePlayed, pemain.profit);
}


void playBlackjack(){

}
void playHighOrLow(){

}
void playHeadOrTail(){

}
void playBarakat(){

}