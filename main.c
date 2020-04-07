#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void desicion(int sum);
void rollDice();

int savedDice = 13;
int counter = 0;

void rollDice(){
    srand(time(NULL));
    int x = rand() % 6 + 1;
    int y = rand() % 6 + 1;

    if(x+y == 7 || x+y == 11){
        printf("Zarlar atiliyor... %d kazandiniz\n",x+y);
        printf("Yeni oyun oynansin mi ? (e/E - h/H) ?");
        desicion(x+y);
    }
    if(x+y == 2 || x+y == 3 || x+y == 12){
        printf("Zarlar atiliyor... %d kaybettiniz\n",x+y);
        printf("Yeni oyun oynansin mi ? (e/E - h/H) ?");
        desicion(x+y);
    }
    if(x+y == 4 || x+y == 5 || x+y == 6 || x+y == 8 || x+y == 9 || x+y == 10){
        printf("Zarlar atiliyor... %d Sonuc belirsiz , tekrar zar atilacak. At (a/A) ?\n",x+y);
        desicion(x+y);
    }
}

void desicion(int sum){

    char decide;
    scanf("%c",&decide);
    decide = tolower(decide);

    switch(decide){

        case 'e':
            rollDice();
            break;

        case 'h':
            printf("CRAPS sona erdi.");
            break;

        case 'a':

            if(savedDice == sum){
                printf("Zarlar atiliyor... %d kazandiniz\n",savedDice);
                printf("Yeni oyun oynansin mi ? (e/E - h/H) ?");
                desicion(sum);
                break;
            }

            if(counter == 0){
                savedDice = sum;
                counter ++;
                rollDice();
                break;
            }
    }
}

int main() {
    rollDice();
    system("pause");
    return 0;
}
