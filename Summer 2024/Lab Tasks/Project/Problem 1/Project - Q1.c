// Calling out libraries...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating a basic function to print stars...
void printStars() {
    for (int i = 0; i < 75; i++) {
        printf("*");
    }
    printf("\n");
}

// Creating a function for introduction:
void intro() {
    printStars();// calling out the printStars function which will print stars to make it look decorative...
    printf("\t\tWelcome to the Oscar Movie Rating System\n");
    printStars();
    printf("Warm Welcome Oscar Jury Members!\n");
    printf("Time to rate the best film of the year!\n");
    printf("Each judge will be rating the nominated movies on a scale of 1 to 10.\n");
    printf("Judges will provide their ratings one by one.\n");
    printf("These ratings will help decide the best films of the year.\n");
    printf("May the best movie win!\n\n");
    printf("So, waiting for what? Let's begin!\n");
    printStars(); // calling out the PrintStars function which will print stars to make it look decorative...
}

// As this particular problem has no repetition of certain tasks frequently, we can directly code in the main function using only 2D array...

int main()
{
    int num_movie = 8; // Total number of movies
    int num_judge = 5; // Total number of judges
    float tot_num[num_movie][num_judge]; // We're using 2D array to store ratings of all movies by all judges
    float movie_avg[num_movie]; // Array to store the average rating of each movie
    char movie_name[][200] = { // Movie names are given below, separated with commas within the curly braces...
        "Nayak: The Hero",
        "The Cloud-Capped Star",
        "The Music Room",
        "Pather Panchali",
        "Charulata",
        "Subarnarekha",
        "Days and Nights in the Forest",
        "The Unnamed"
        };

    intro(); // Calling the introduction function to display intro...

   // Collecting ratings from all 5 judges for each of the 8 movies:
    for (int i = 0 ; i < num_judge ; i++) {
        printf("Judge %d, rate each movie from 1-10:\n\n", i + 1);
        for (int j = 0 ; j < num_movie ; j++) {
            printf("%s: ", movie_name[j]);
            scanf("%f", &tot_num[j][i]); // scanf will take input from user, here judges...

            // Input validation to ensure the rating is between 1 and 10
            while (tot_num[j][i] < 1 || tot_num[j][i] > 10) { // Here, we used OR operation to combine the argument...
                printf("Invalid!Enter a number between 1-10!");
                printf("\n%s: ", movie_name[j]);
                scanf("%f", &tot_num[j][i]); // again, scanf will take input from user, here judges after prompting invalid range...
            }
        }
        printf("\n\n");
    }

    // Average ratings for each movie:
    for (int i = 0 ; i < num_movie ; i++) {
        float sum = 0; // here we will store total score for each judge
        for (int j = 0 ; j < num_judge ; j++) {
            sum = sum + tot_num[i][j];  // Sum the ratings from all judges with a loop
        }
        movie_avg[i] = sum / num_judge;  // Calculate the average rating
    }

    // Sorting the movies by their average rating in ascending order by Bubble Sorting:
    for (int i = 0 ; i < num_movie-1 ; i++) { // Array index starts from 0 to n-1 if element is n...
        for (int j = 0 ; j < num_movie-1 - i ; j++) { // We'll continue this process untill each combination is done...
            if (movie_avg[j] > movie_avg[j + 1]) { // We'll only swap if current is greater than next one...
                // Swapping the averages...
                float temp_avg = movie_avg[j]; // using temporary variable to store current movie rating...
                movie_avg[j] = movie_avg[j + 1]; // swapping positions of respective array...
                movie_avg[j + 1] = temp_avg; // restoring the previous value from temporary variable...

                // Swapping the movie names respectively...
                char temp_name[100]; // Temporary string to store a movie name during swapping...
                // strcpy(des,src) mainly copies string from source to destination...
                strcpy(temp_name, movie_name[j]);
                strcpy(movie_name[j], movie_name[j + 1]);
                strcpy(movie_name[j + 1], temp_name);
            }
        }
    }

    // Displaying the movies in ascending order and their average ratings:
    printf("Movies and their average rating in ascending order:");
    printf("\n----------------------------------------------------\n");
    for (int i = 0 ; i < num_movie ; i++) { // Loop to display the sorted movies with ratings...
        printf("%s: %.2f\n", movie_name[i], movie_avg[i]); // Printing 2 digits after decimal points to look it more neat & clean...
    }
    printf("----------------------------------------------------\n");
    // Finishing Part (Outro):
    printf("\nAnd the Oscar for Best Movie of the Year goes to...\n");
    printf("***** %s *****\n",movie_name[num_movie-1]); // Best Movie is in the sorted array's last index.
    printf("Congratulations to the entire cast and crew for this outstanding achievement!\n");

    return 0;
}
