#include <stdio.h>

int palindrome(int n){
    int n1 = n;
    int rev = 0;
    int rem = 0;
    while(n1 != 0){
        rem = n1%10 ;
        rev = rev*10 + rem;
        n1/=10;
    }
    if(rev == n){
        printf("\n%d is a Palindrome!",n);
    }
    else{
        printf("\n%d is Not a Palindrome",n);
    }
}

int main() {
    printf("*Find whether a number is Palindrome or not using functions*\n\n");
    int n ;

    printf("Enter number: ");
    scanf("%d",&n);

    palindrome(n);

    return 0;
}
