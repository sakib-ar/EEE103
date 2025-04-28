#include <stdio.h>

int main() {
    int population = 100000;
    float growth = 0.10;
    int years = 10;

    printf("Population of a town today is: 100000\n");

    for (int i = 1; i <= years; i++) {
        population = population / (1 + growth);
        printf("\n%d year ago, the population was approximately\t: %d", i, population);
    }

    return 0;
}
