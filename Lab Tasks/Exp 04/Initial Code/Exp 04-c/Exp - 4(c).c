#include <stdio.h>

int digit_sum(int n){
    if(n<0){
        n = -n ; // Sorting out negative numbers in order to sum only digits...
    }
    if(n==0){
        return 0;
    }
    else{
        return (n % 10 + digit_sum(n/10));
    }
}

int main() {
    printf("*Find the sum of digits of a given number using recursion*\n\n");

    int n;
    printf("Enter number: "); scanf("%d", &n);
    printf("\nThe Sum of Digits in %d is %d", n, digit_sum(n));

    return 0;
}
