// Declaring Libraries:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Building a Structure to store Book info:
struct library {
    int id; // for Book ID
    char title[100]; // for Book title (max 75 characters)
    char author[100]; // for Book Author (max 75 characters)
    float price; // for Book Price
} b[100]; // Array to hold up to 100 books

int num_of_books = 0;  // Track the current number of books in the library...
char password[] = "among_us";  // This is the current password...

// Function to add books info:
void Add() {
    char pass_entry[20]; // to collect and check user given password...
    printf("Enter Password: "); scanf("%s", pass_entry);

    // Password check
    if (strcmp(pass_entry, password) != 0) {
        printf("\nIncorrect password! <ACCESS DENIED>\n");
        return; // Exiting the function if wrong...
    }

    int new_books; // number of books user wants to add...
    printf("\nHow many books' info do you want to enter? => "); scanf(" %d", &new_books);

    for (int i = num_of_books ; i < num_of_books + new_books ; i++) {
        printf("\nEnter the following information about the book no.%d:\n", i - num_of_books + 1);
        printf("ID: "); scanf("%d", &b[i].id); // Collecting book ID...
        printf("Title: ");
        getchar();  // To clear the newline character left in the input buffer...
        fgets(b[i].title, 40, stdin); // To collect the title, also it allows spaces...
        b[i].title[strcspn(b[i].title, "\n")] = 0;  // Remove the newline character from the title...
        printf("Author's name: ");
        fgets(b[i].author, 20, stdin); // To collect Author's name, and it allows spaces...
        b[i].author[strcspn(b[i].author, "\n")] = 0;  // Remove the newline character from the author name
        printf("Price (in Tk): "); scanf("%f", &b[i].price); // To Collect book price
    }

    num_of_books += new_books;  // Update the total number of books
}

// Function to display book details in the library:
void Disp() {
    // If no books are registered in the library...
    if (num_of_books == 0) {
        printf("\nSorry! No books to Display!\n");
        return;
    }

    // Printing the header with appropriate spacing...
    printf("\n%-6s\t%-40s\t%-25s\t%s\n", "ID", "Name", "Author", "Price(Tk)"); // Headlines are adjusted with spaces...

    // Printing the book details with proper alignment...
    for (int i = 0 ; i < num_of_books ; i++) {
        printf("%-6d\t%-40s\t%-25s\t%.2f\n", b[i].id, b[i].title, b[i].author, b[i].price); // Adjusted width and spaces to look it more neat & clean...
    }
}

// Function to display all books by a specific author:
void List() {
    char str[20]; // Buffer to hold the author's name
    printf("Enter the author's name: ");
    getchar();  // Clearing the newline character from the input buffer...
    fgets(str, 20, stdin); // Geting author's name from the user...
    str[strcspn(str, "\n")] = 0;  // Removing the newline character from the input...

    int found = 0; // To check if any books by the author were found...
    for (int i = 0 ; i < num_of_books ; i++) {
        if (strcmp(str, b[i].author) == 0) { // strcmp() mainly compares entered name with the stored author's name...
            printf("\n\t%d\t%s\t%s\t%.2f\n", b[i].id, b[i].title, b[i].author, b[i].price); // To Display book details...
            found = 1; // To mark at least one book by the author was found...
        }
    }
    // If no books by the author were found:
    if (!found) {
        printf("No books found by author: %s\n", str);
    }
}

// Function to display the total number of books in the library:
void Count() {
    printf("\nNo of books available in the library = %d\n", num_of_books);
}

// Main function:
int main() {
    int option = 0; // Variable to store the user's selected option...
    // To Display menu options and ask to select the corresponding actions...
    do {
        printf("\n*Welcome to the library*\nPlease Select an Option: \n");
        printf("-----------------------------------------------------------\n");
        printf("1. Add book details\n2. Display book details\n3. List all books of a given author\n4. Show total no. of books in the library\n5. Exit\n");
        printf("-----------------------------------------------------------\n");
        printf("Select an option: "); scanf("%d", &option); // Get user option...

        switch (option) {
            case 1:
                Add(); // Calling the Add function to add book details
                break;
            case 2:
                Disp(); // Calling the Disp function to display book details
                break;
            case 3:
                List(); // Calling the List function to display books by a given author
                break;
            case 4:
                Count(); // Calling the Count function to show the total number of books
                break;
            case 5:
                printf("Exiting the program...\n"); // Exit message
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5); // Keep looping until the user chooses to exit

    return 0; // That return successful execution...
}
