#include <stdio.h>

int GetLength(char STR[]) {
    int LENGTH = 0;
    while (STR[LENGTH] != '\0') {


        LENGTH++;
    }
    return LENGTH;
}

int PalindromeChecker(char STR[]) {


    int LEFT = 0;


    int RIGHT = GetLength(STR) - 1;

    while (LEFT < RIGHT) {


        if (STR[LEFT] != STR[RIGHT])

        {

            return 0;
        }
        LEFT=LEFT+1;
        RIGHT--;
    }
    return 1;
}

int main() {
    char WORD[100];
    int I = 0;
    char CH;

    printf("Enter a word ");
    while ((CH = getchar()) != '\n' && I < 99) {
        WORD[I++] = CH;
    }
    WORD[I] = '\0';

    if (PalindromeChecker(WORD)) {


        printf("'%s' is a palindrome\n", WORD);


    }



    else {


        printf("'%s' is not a palindrome\n", WORD);
    }

    return 0;
}
