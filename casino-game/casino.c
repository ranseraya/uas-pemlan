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
pemain currPlayer;
int playerIndex;
int totalUsers = 0;

void gameMenu(pemain currPlayer);//parameter profile
void adminMenu();
void mainMenu();
void registrasi();
void loadGame();
void importProfile();

void displayProfile(pemain currPlayer);

void playBlackjack();
void playHighOrLow();
void playHeadOrTail();
void playBarakat();

int searching(const char* cariUsername, const char* cariPassword);

int main(){
    // pemain pemain1;
    importProfile();
    // loadGame();
    
	
    
    mainMenu();
    
    	// printf("Data Pemain:\n");
    	// for (int i = 0; i < 2; i++) {
	    // 	printf("Username: %s\n", users[i].username);
		//     printf("Password: %s\n", users[i].password);
	    //     printf("Role: %s\n", users[i].role);
	    //     printf("Cash: %d\n", users[i].cash);
	    //     printf("Game Played: %d\n", users[i].gamePlayed);
	    //     printf("Profit: %d\n\n", users[i].profit);
		// }
    
}

void mainMenu(){
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
            gameMenu(currPlayer); // parameter profile
        case 2:
            //Load game profile
            // if( role == 'admin'){
                //adminMenu();
            // }
            loadGame();
            gameMenu(currPlayer);
            break;
        case 0:
            printf("Keluar game...\n");
            return;
        //default:
    }
    //}
}

void gameMenu(pemain currPlayer){ //parameter profile
    int pilihanGame;
    //while (1) {
        displayProfile(currPlayer);
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
                mainMenu();
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
        return;
    }
	
    char buf[100];
    while (fscanf(ptr, "%s %s %s %d %d %d ", users[totalUsers].username, 
                  users[totalUsers].password, 
                  users[totalUsers].role, 
                  &users[totalUsers].cash, 
                  &users[totalUsers].gamePlayed, 
                  &users[totalUsers].profit) == 6){
        totalUsers++;    
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
    char curUsername[10];
    char curPassword[20];
    
    printf("Masukkan username: ");
    scanf("%10s", curUsername); 
    printf("Masukkan password: ");
    scanf("%20s", curPassword); 

    if (searching(curUsername, curPassword)) {
        printf("Profil ditemukan. Selamat datang, %s!\n", curUsername);
        currPlayer = users[playerIndex];
    } else {
        printf("Username atau password salah.\n");
        loadGame();
    }
}

// menampilkan profil singkat pemain
void displayProfile(pemain currPlayer){
	system("cls");
    printf("| Username: %-10s| Chip: %-9d| Game Played: %-4d| Profit: %-10d|\n", currPlayer.username, currPlayer.cash, currPlayer.gamePlayed, currPlayer.profit);
}


void playBlackjack(){

}
void playHighOrLow(){

}
void playHeadOrTail(){

}
void playBarakat(){

}



int searching(const char* cariUsername, const char* cariPassword) {
    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(cariUsername, users[i].username) == 0 && 
            strcmp(cariPassword, users[i].password) == 0) {
            playerIndex = i;
            return 1; 
        }
    }
    return 0; 
}