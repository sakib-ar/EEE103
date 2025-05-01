#include <stdio.h>
int fibonacci(int n){
 if(n == 0){
 return 0 ;
 }
 else if(n == 1){
 return 1 ;
 }
 else{
 return (fibonacci(n-1) + fibonacci(n-2));
 }
}
int main() {
 printf("*Find out nth Fibonacci term using recursion*\n\n");
 int n;
 printf("Enter the nth term: "); scanf("%d", &n);
 printf("\nThe Fibonacci series upto %dth term:\n",n);
 for (int i = 0 ; i < n ; i++) {
 printf("%d ", fibonacci(i));
 }
 return 0;
}
