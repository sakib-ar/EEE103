// Declaring Libraries...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the service charge based on payment phase...
int SERVICE_CHARGE(int Bill) {
    int Phase; // Variable to store user's choice of payment phase
    float Phase_Bill; // Variable to store final bill after applying service charge

    // Prompting the user for payment phase selection
    printf("DO YOU WANT TO PAY THE BILL IN PHASES?\n");
    printf("TO PAY THE BILL IN ONE PHASE ENTER 1\n");
    printf("TO PAY THE BILL IN THREE PHASES ENTER 3\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &Phase);

    // Checking user's phase selection and calculate the service charge accordingly
    if (Phase == 1) {
        Phase_Bill = Bill + 10; // Adding a flat service charge for one-phase payment
        printf("Total bill in one phase: %.2f\n", Phase_Bill);
    } else if (Phase == 3) {
        Phase_Bill = (Bill / 3.0) + 10; // Adding service charge for three-phase payment
        printf("Total bill in three phases: %.2f per phase\n", Phase_Bill);
    } else {
        // Invalid input, return error
        printf("INVALID NUMBER OF PHASES; PLEASE RESTART THE PROGRAM\n");
        return -1;
    }

    return Phase_Bill; // Returning the calculated bill with service charge
}

int main() {
    float Bill = 0; // To store the total bill
    float Rate; // To store the rate per unit of consumption
    int SL; // To store the category (serial number) of the user
    int Cat;
    int Unit; // To store the number of units consumed
    float New_Bill;
    float Phase_Bill;
    char Type[255]; // To store the category type
    char Lifeline; // To store whether the user qualifies for a lifeline

    int student_id;
    printf("PLEASE ENTER YOUR ID: ");
    scanf("%d", &student_id);  // Input and store the student ID

    // Welcome message and instructions:
    printf("***Electricity Bill Calculation and Payment System***");
    printf("\nHELLO User, We Are Delighted to Help You\n");
    printf("Find the Serial Number from the List below according to your category\n\n\n");

     // Displaying category options:
    printf("CATEGORY A  (RESIDENTIAL)                      SERIAL NUMBER = 1 \n");
    printf("CATEGORY B  (AGRICULTURAL PUMPING)             SERIAL NUMBER = 2\n");
    printf("CATEGORY C  (SMALL INDUSTRIES)                 SERIAL NUMBER = 3\n");
    printf("CATEGORY D  (NON-RESIDENTIAL (LIGHT AND POWER)) SERIAL NUMBER = 4\n");
    printf("CATEGORY E  (COMMERCIAL AND OFFICE)            SERIAL NUMBER = 5\n\n");

    // Get the user's serial number (category)
    printf("PLEASE ENTER YOUR SERIAL NUMBER\n");
    scanf(" %d", &SL);

    // Error checking for invalid serial number...
    if ((SL > 5) || (SL < 0)){
        printf("INVALID INPUT");
    }
    // Process based on the category selected...
    if (SL == 1) {
        printf("CATEGORY A  (RESIDENTIAL)\n");
        printf("HOW MANY UNITS HAVE BEEN USED?\n");
        scanf("%d", &Unit);
        // Checking if the user belongs to a lifeline category...
        printf("DO YOU BELONG TO A LIFELINE?\nANSWER WITH Y for yes and N for no.\n");
        scanf(" %c", &Lifeline);
        // Lifeline billing rate:
        if (Lifeline == 'Y' || Lifeline == 'y') {
            Rate = 3.33;
            Bill = Unit * Rate + 50;
        } else if (Lifeline == 'N' || Lifeline == 'n') {
            // Regular billing based on consumption
            if (Unit <= 75) {
                Bill = Unit * 3.80;
            } else if (Unit <= 200) {
                Bill = (Unit - 75) * 5.14 + (75 * 3.80);
            } else if (Unit <= 300) {
                Bill = (Unit - 200) * 5.36 + (125 * 5.14) + (75 * 3.80);
            } else if (Unit <= 400) {
                Bill = (Unit - 300) * 5.63 + (100 * 5.36) + (125 * 5.14) + (75 * 3.80);
            } else if (Unit <= 600) {
                Bill = (Unit - 400) * 8.70 + (100 * 5.63) + (100 * 5.36) + (125 * 5.14) + (75 * 3.80);
            } else {
                Bill = (Unit - 600) * 9.98 + (200 * 8.70) + (100 * 5.63) + (100 * 5.36) + (125 * 5.14) + (75 * 3.80);
            }
        } else {
            // Invalid lifeline input
            printf("INVALID INPUT FOR LIFELINE; PLEASE RESTART THE PROGRAM\n");
            return -1;
        }

        Bill += 50; // Monthly Meter Charge...
        // Calling SERVICE_CHARGE function to compute final bill
        float Final_Bill = SERVICE_CHARGE(Bill);
        if (Final_Bill != -1) {
            printf("Your final bill is: %.2f\n", Final_Bill);
        }
    }
    // Repeating similar logic for other categories:
    if (SL == 2) {
        // Agricultural pumping
        snprintf(Type, sizeof(Type), "CATEGORY B  (AGRICULTURAL PUMPING)");
        printf("HOW MANY UNITS HAVE BEEN USED?\n");
        scanf("%d", &Unit);
        Rate = 3.38; // Rate for category B
        Bill = Unit * Rate;
        Bill = Bill + 50 + 30;
        printf("Your final bill is: %.2f\n", Bill);
    }

    if (SL == 3) {
        // Small industries
        snprintf(Type, sizeof(Type), "CATEGORY C  (SMALL INDUSTRIES)");
        printf("HOW MANY UNITS HAVE BEEN USED?\n");
        scanf("%d", &Unit);

        char T;
        // Ask user to select tariff type
        printf("\nInput 'A' for flat rate, 'B' for off-peak time, 'C' for peak time: ");
        scanf(" %c", &T);
        // Different rates based on time of use
        if (T == 'A') {
            Bill = Unit * 7.66;
        } else if (T == 'B') {
            Bill = Unit * 6.90;
        } else if (T == 'C') {
            Bill = Unit * 9.24;
        } else {
            printf("Invalid input, please restart\n");
        }

        Bill = Bill + 70 + 50;
        printf("Your final bill is: %.2f\n", Bill);
    }

    if (SL == 4) {
        // Non-residential (light and power)
        snprintf(Type, sizeof(Type), "CATEGORY D (NON-RESIDENTIAL (LIGHT AND POWER))");
        printf("HOW MANY UNITS HAVE BEEN USED?\n");
        scanf("%d", &Unit);

        Rate = 5.22; // Rate for category D
        Bill = Unit * Rate;

        float Final_Bill = SERVICE_CHARGE(Bill);
        if (Final_Bill != -1) {
            printf("Your final bill is: %.2f\n", Final_Bill);
        } else {
            printf("Error in bill calculation.\n");
        }
    }

    if (SL == 5) {
        // Commercial and office
        printf("CATEGORY E  (COMMERCIAL AND OFFICE)\n");
        printf("HOW MANY UNITS HAVE BEEN USED?\n");
        scanf("%d", &Unit);

        char T;
        // Ask user to select tariff type
        printf("\nInput 'A' for flat rate, 'B' for off-peak time, 'C' for peak time: ");
        scanf(" %c", &T);

        if (T == 'A') {
            Bill = Unit * 9.80;
        } else if (T == 'B') {
            Bill = Unit * 8.45;
        } else if (T == 'C') {
            Bill = Unit * 11.98;
        } else {
            printf("Invalid input, please restart\n");
            return 1;
        }

        float Final_Bill = SERVICE_CHARGE(Bill);
        if (Final_Bill != -1) {
            printf("Your final bill is: %.2f\n", Final_Bill);
        }
    }

    return 0;
}
