#include <stdio.h>

int main() {
    int N, I;
    int LARGEST, SMALLEST;

    printf("ENTER THE NUMBER OF ELEMENTS (DO NOT USE COMMAS,please) ");
    scanf("%d", &N);

    int ARR[N];

    printf("ENTER %d NUMBERS (DO NOT USE COMMAS,please) \n", N);
    for(I = 0; I < N; I++) {


        scanf("%d", &ARR[I]);
    }

    LARGEST = ARR[0];
    SMALLEST = ARR[0];

    for(I = 1; I < N; I++) {

        if(ARR[I] > LARGEST) {

            LARGEST = ARR[I];
        }
        if(ARR[I] < SMALLEST) {

            SMALLEST = ARR[I];
        }
    }

    printf("LARGEST NUMBER IS %d\n", LARGEST);
    printf("SMALLEST NUMBER IS %d\n", SMALLEST);

    return 0;
}
