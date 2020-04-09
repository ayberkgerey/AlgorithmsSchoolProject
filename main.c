#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void gameLoop();
int rollDice();
int ask(int currentDice);

int main() {
    char c[2];
    srand(time(NULL));
    gameLoop();
    while (1) {
        printf("\nYeni oyun oynansin mi (e/E - h/H) ? ");
        gets(c);
        if (tolower(c[0]) == 'e')
            gameLoop();
        else if (tolower(c[0]) == 'h')
            break;
        else {
            printf("Bilinmeyen komut, cikiliyor.");
            break;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}

void gameLoop() {
    int currentDice, wantedDice = 0;
    while (1) {
        currentDice = rollDice();
        if(wantedDice == 0 && (currentDice == 11 || currentDice == 7)){
            printf("Zarlar Atiliyor... %d Kazandiniz",currentDice);
            break;
        }
        if(wantedDice == 0 && (currentDice == 2 || currentDice == 3 || currentDice == 12)){
            printf("Zarlar Atiliyor... %d Kaybettiniz",currentDice);
            break;
        }
        else if (wantedDice == 0){
            wantedDice = currentDice;
            printf("Zarlar Atiliyor... %d Sonuc belirsiz, tekrar zar atilacak. At? (a/A)? ", currentDice);
            if(!ask(currentDice))
                break;
        }
        else {
            if (currentDice == wantedDice) {
                printf("Zarlar Atiliyor... %d Kazandiniz",currentDice);
                break;
            } else if (currentDice == 7) {
                printf("Zarlar Atiliyor... %d Kaybettiniz",currentDice);
                break;
            } else {
                printf("Zarlar Atiliyor... %d Sonuc belirsiz, tekrar zar atilacak. At? (a/A)? ", currentDice);
                if(!ask(currentDice))
                    break;
            }
        }
    }
}

int ask(int currentDice){
    char c[2];
    gets(c);
    if(!(tolower(c[0]) == 'a'))
        return 0;
    return 1;
}

int rollDice() {
    int x = rand() % 6 + 1;
    int y = rand() % 6 + 1;
    return x + y;
}