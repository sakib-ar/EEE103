#include <stdio.h>

int main() {
    char A[100], B[100], C[200];
    int I = 0, J = 0;

    printf("Enter first string (A) ");
    gets(A);
    printf("Enter second string (B) ");
    gets(B);

    while (A[I] != '\0')

    {
        C[I] = A[I];

        I++;
    }

    while (B[J] != '\0')
    {
        C[I] = B[J];

        I++;

        J++;
    }

    C[I] = '\0';

    printf("CONNECTED  STRING (C) %s", C);

    return 0;
}
