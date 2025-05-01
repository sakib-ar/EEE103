#include <stdio.h>

int main() {
    printf("*Find out the Grade of the Steel*\n\n");

    float hardness, carbon_content, tensile_strength ;
    int grade ;
    printf("Enter Hardness: "); scanf("%f", &hardness);
    printf("Enter Carbon Content: "); scanf("%f", &carbon_content);
    printf("Enter Tensile Strength: "); scanf("%f", &tensile_strength);
    printf("\n");

    if(hardness > 50 && carbon_content < 0.7 && tensile_strength > 5600){
        grade = 10;
    }
    else if(hardness > 50 && carbon_content < 0.7){
        grade = 9;
    }
    else if(carbon_content < 0.7 && tensile_strength > 5600){
        grade = 8;
    }
    else if(hardness > 50 && tensile_strength > 5600){
        grade = 7;
    }
    else if(hardness > 50 || carbon_content < 0.7 || tensile_strength > 5600){
        grade = 6;
    }
    else{
        grade = 5;
    }
    printf("The grade of the steel is: %d\n", grade);

    return 0;
}
