#include <stdio.h>

int main() {
    char CAT[100];
    int I = 0;
    char CH;

    printf("ENTER A WORD(STRING) ");

    while (I < sizeof(CAT) - 1) {
        if (scanf("%c", &CH) != 1 || CH == '\n') {


            break;
        }
        CAT[I++] = CH;
    }

    CAT[I] = '\0';

    int LENGTH = I;

    printf("THE REVERSED VERSION IS ");

    for (int J = LENGTH - 1; J >= 0; J--) {


        printf("%c", CAT[J]);
    }
    printf("\n");

    return 0;
}
