#include<stdio.h>

int main()
{
    double r , area ;

    printf("Enter Radius: ");
    scanf("%lf",&r);

    area = 3.1416 * r * r ;

    printf("Area of the circle is ---> %.4lf", area);

    return 0;
}
