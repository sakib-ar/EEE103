#include <stdio.h> // Include standard  library

int main() {
    char b; // Declare a character variable
    int i = 257; // Declare an integer and initialize it to 257
    double d = 323.142; // Declare a double and initialize it to 323.142

    b = i; // Assign the value of i to b
    printf("%c\n", b); //* Print the character corresponding to the ASCII value of b (1) as 257>256 so 257%256 is taken which is 1 so it prints*

    b = (char) i; // Assign cast i to a char and assign it to b
    printf("%c\n", b); // Print the character corresponding to the ASCII value of b

    i = (int) d; // assign d to an int and assign it to i
    printf("%d\n", i); // Print the integer value of i as an integer not a double (323)

    b = (char) d; // Assign d to a char and assign it to b
    printf("%c\n", b); // Print the character corresponding to the ASCII value of b (C)

    return 0; // To complete execution
}
