#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int rollDice();

void decideScore(int sum);

void longGame(int savedSum);

int main() {
    int sum;
    char decide, lastDecide = 'e';

    while (lastDecide != 'k') {
        sum = rollDice();
        decideScore(sum);

        scanf("%c", decide);
        lastDecide = tolower(decide);

        if (decide == 'a') longGame(sum);
    }

    system("pause");
    return 0;
}

int rollDice() {
    srand(time(NULL));
    int x = rand() % 6 + 1;
    int y = rand() % 6 + 1;
    return x + y;
}

void decideScore(int sum) {

    if (sum == 7 || sum == 11) {
        printf("Zarlar atiliyor... %d kazandiniz\nYeni oyun oynansin mi ? (e/E - h/H) ?", sum);
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("Zarlar atiliyor... %d kaybettiniz\nYeni oyun oynansin mi ? (e/E - h/H) ?", sum);
    } else {
        printf("Zarlar atiliyor... %d Sonuc Belirsiz, tekrar zar atilacak. At(a/A) ?", sum);
    }

}

void longGame(int savedSum) {

    int currentSum;

    while (savedSum != currentSum) {
        currentSum = rollDice();
        printf("Zarlar atiliyor... %d Sonuc Belirsiz, tekrar zar atilacak. At(a/A) ?", currentSum);
    }

    if (savedSum == currentSum)
        printf("Zarlar atiliyor... %d Kazandiniz");
    else
        printf("CRAPS sona erdi.");
}
