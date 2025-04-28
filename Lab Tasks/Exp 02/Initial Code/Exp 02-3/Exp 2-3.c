#include <stdio.h>

int main() {
    int lightspeed = 186000; // speed of light in miles per second
    int days = 1000; // specify number of days here
    double seconds = days * 24 * 60 * 60; // convert to seconds using double
    double distance = lightspeed * seconds; // compute distance

    printf("In %d days light will travel about %.lf miles.\n", days, distance);

    return 0;
}
