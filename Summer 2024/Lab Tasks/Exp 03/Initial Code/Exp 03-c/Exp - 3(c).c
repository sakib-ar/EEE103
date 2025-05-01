#include <stdio.h>

int main() {
    printf("*Welcome to the 21 Matchsticks game!*\n\n");
    printf("Rules:\tPick 1, 2, 3 or 4 Matchsticks\n");
    printf("\t\tIf you pick the last Match stick you lose\n\n");
    int mst , picked , picking;

    for(mst = 21 ; mst > 0 ; ){
        printf("Pick Matchsticks between 1 to 4: ");
        scanf("%d", &picked);

        if(mst == 1){
            if(picked == 1){
                printf("\nSo You have picked the Last One!\n");
                printf("YOU LOST\nBetter Luck Next Time...\n");
                break;
            }
            else{
                printf("\nYou had only 1 Matchstick! Why you picked %d?\n",picked);
                printf("Anyways, you had to pick the last matchstick!\n");
                printf("So, YOU LOST\nBetter Luck Next Time...\n");
                break;
            }
        }
        else{
            if(picked == 1){
            picking = 4;
            mst = mst - picking - picked;
            printf("Nice Try! I will pick %d Matchsticks. (Remaining: %d)\n\n", picking, mst);
        }
        else if(picked == 2){
            picking = 3;
            mst = mst - picking - picked;
            printf("Nice Try! I will pick %d Matchsticks. (Remaining: %d)\n\n", picking, mst);
        }
        else if(picked == 3){
            picking = 2;
            mst = mst - picking - picked;
            printf("Nice Try! I will pick %d Matchsticks. (Remaining: %d)\n\n", picking, mst);
        }
        else if(picked == 4){
            picking = 1;
            mst = mst - picking - picked;
            printf("Nice Try! I will pick %d Matchsticks. (Remaining: %d)\n\n", picking, mst);
        }
        if (picked < 1 || picked > 4) {
            printf("INVALID! You have to pick between 1 to 4! TRY AGAIN!\n\n");
            continue;
        }
        }
    }

    return 0;
}
