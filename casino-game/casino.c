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

pemain users[100];

void gameMenu(pemain pemain);//parameter profile
void adminMenu();
void mainMenu();
void registrasi();
void loadGame();
void importProfile();

void displayProfile(pemain pemain);

void playBlackjack();
void playHighOrLow();
void playHeadOrTail();
void playBarakat();

int main(){
    pemain pemain1;
    importProfile();
    
	
    
    mainMenu(pemain1);
    
    	printf("Data Pemain:\n");
    	for (int i = 0; i < 2; i++) {
	    	printf("Username: %s\n", users[i].username);
		    printf("Password: %s\n", users[i].password);
	        printf("Role: %s\n", users[i].role);
	        printf("Cash: %d\n", users[i].cash);
	        printf("Game Played: %d\n", users[i].gamePlayed);
	        printf("Profit: %d\n\n", users[i].profit);
		}
    
}

void mainMenu(pemain pemain){
	int pilihan;
    //while(1){
    system("cls");
    printf("----------------------------- PROJECT UAS CASINO GACOR -----------------------------\n");
    printf("------------------------------- TEAM TWO NEVER END ---------------------------------\n\n");
	printf("1. New Profile\n");
    printf("2. Load Profile\n");
    printf("0. Exit\n");
    printf("Program: ");
    scanf("%d", &pilihan);
    switch(pilihan){
        case 1:
            //New profile
            system("cls");
            gameMenu(pemain); // parameter profile
        case 2:
            //Load game profile
            // if( role == 'admin'){
                //adminMenu();
            // }
            system("cls");
            gameMenu(pemain);
            break;
        case 0:
            printf("Keluar game...\n");
            return 0;
        //default:
    }
    //}
}

void gameMenu(pemain pemain){ //parameter profile
    int pilihanGame;
    //while (1) {
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
                mainMenu(pemain);
                break;
            default:
                printf("Pilihan tidak valid! masukkan nomor program...\n");
        }
    //}
}

void importProfile(){
	
	FILE* ptr = fopen("akun.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
	
	int count;
    char buf[100];
    while (fscanf(ptr, "%s %s %s %d %d %d ", users[count].username, 
                  users[count].password, 
                  users[count].role, 
                  &users[count].cash, 
                  &users[count].gamePlayed, 
                  &users[count].profit) == 6){
        count++;    
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
	system("cls");
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
