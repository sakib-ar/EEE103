#include <stdio.h>

int main() {
    printf("*Check whether a year is a leap year or not*\n\n");
    int year ;
    printf("Enter Year: ");
    scanf("%d", &year);

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        printf("%d is a leap year\n", year);
    }
    else{
        printf("%d is Not a leap year\n",year);
    }

    return 0;
}
