#include <stdio.h>
#include <process.h>
#include <dxtmpl.h>
#include <time.h>

void continueOrStop(char decide);
char getDecide();
int secondChance , counter = 0;

int rollDice(){
     srand(time(NULL));
     int x = rand() % 6 + 1;
     int y = rand() % 6 + 1;
     return x+y;
}

void theGame(){
    int a = rollDice();
    char decide2;

    if(a == 11 || a == 7){
        printf("Zarlar atiliyor... %d Kazandiniz\n",a);
        char decide = getDecide();
        continueOrStop(decide);
    }
    else if( a == 2 || a == 3 || a == 12){
        printf("Zarlar atiliyor... %d Kaybettiniz\n",a);
        char decide = getDecide();
        continueOrStop(decide);
    }
    else{
        printf("Zarlar atiliyor... %d Sonuc belirsiz , tekrar zar atilacak. At (a/A) ?\n",a);
        scanf("%c",&decide2);
        if(decide2 == 'a' ||decide2 == 'A'){

            if(counter == 0){
                secondChance = a;
                counter++;
            }



        }

    }
}

void continueOrStop(char decide) {

    if(decide == 'e' || decide == 'E'){
        theGame();
    }
    else if (decide == 'h' || decide == 'H'){
        printf("CRAPS sona erdi\n");
    }
}

char getDecide(){
    char decide;
    printf("Yeni oyun oynansin mi (e/E - h/H) ?\n");
    scanf("%c",&decide);
    return decide;
}


int main() {


    system("pause");
    return 0;
}
