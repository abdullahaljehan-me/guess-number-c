#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int choice, number, min = 1, max, attempts = 0, chances, guess;
    int won = 0;
    int score = 0;
    int total_score = 0;
    int hint_used = 0;
    
    // High score tracking (fewest attempts per difficulty)
    int best_easy = 999, best_medium = 999, best_hard = 999;

    // Seed the random number generator
    srand(time(NULL));

    do
    {
        // Reset variables for a new game
        attempts = 0;
        won = 0;
        score = 0;
        hint_used = 0;

        printf("\n");
        printf("  ============================================\n");
        printf("  ||           GUESS THE NUMBER             ||\n");
        printf("  ============================================\n\n");

        printf("  [1] Easy   (1 to 50  | 7 chances)\n");
        printf("  [2] Medium (1 to 100 | 6 chances)\n");
        printf("  [3] Hard   (1 to 200 | 5 chances)\n");
        printf("  [4] Exit   \n\n");
        
        // Display high scores only if they have been set
        if (best_easy != 999) {
            printf("  Session Bests -> Easy: %d att. | Medium: %d att. | Hard: %d att.\n", best_easy, best_medium, best_hard);
        }
        printf("  Total Score: %d\n\n", total_score);

        printf("  Choose your difficulty (1-4): ");

        // Prevent infinite loops if the user types letters instead of numbers
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            printf("\n  INVALID INPUT! Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            max = 50;
            chances = 7;
            printf("\n  Easy mode selected.\n");
            break;
        case 2:
            max = 100;
            chances = 6;
            printf("\n  Medium mode selected.\n");
            break;
        case 3:
            max = 200;
            chances = 5;
            printf("\n  Hard mode selected.\n");
            break;
        case 4:
            printf("\n  Exiting the game. Final Total Score: %d\n\n", total_score);
            return 0;
        default:
            printf("\n  Invalid choice. Please pick 1, 2, 3, or 4.\n");
            continue;
        }

        printf("\n  I am thinking of a number between %d and %d.\n", min, max);
        printf("  You have %d chances.\n", chances);
        printf("  (Tip: Enter '0' to get a ONE-TIME hint)\n\n");

        // Generate the secret number
        number = (rand() % (max - min + 1)) + min;

        while (attempts < chances)
        {
            printf("  [Attempt %d/%d] Your guess (-1 to quit, 0 for hint): ", attempts + 1, chances);

            if (scanf("%d", &guess) != 1)
            {
                while (getchar() != '\n');
                printf("  Invalid input. Please enter a valid number.\n");
                continue;
            }

            // Check for quit first
            if (guess == -1)
            {
                printf("\n  Game quit. The secret number was %d.\n", number);
                break;
            }

            // Handle Hint Request
            if (guess == 0)
            {
                if (hint_used)
                {
                    printf("  You have already used your one hint for this game.\n");
                    continue;
                }
                hint_used = 1;
                printf("  HINT: The secret number is %s.\n", (number % 2 == 0) ? "EVEN" : "ODD");
                
                int mid = (min + max) / 2;
                if (number <= mid) {
                    printf("  HINT: It is in the lower half of the range (%d to %d).\n", min, mid);
                } else {
                    printf("  HINT: It is in the upper half of the range (%d to %d).\n", mid + 1, max);
                }
                continue; // Does not cost an attempt
            }

            // Forgive out-of-bounds guesses so they don't lose a chance
            if (guess < min || guess > max)
            {
                printf("  Out of bounds! Please stay within %d and %d. This attempt does not count.\n", min, max);
                continue;
            }

            if (guess == number)
            {
                won = 1;
                printf("\n  CONGRATULATIONS! You guessed it. The number was %d.\n", number);

                // Calculate score: multiplier based on difficulty * remaining chances
                int multiplier = (choice == 1) ? 10 : (choice == 2) ? 20 : 30;
                score = (chances - attempts) * multiplier;
                total_score += score;

                // Dynamic win messages based on performance
                if (attempts == 0)
                {
                    printf("  Incredible! You got it on the very first try.\n");
                }
                else if (attempts < chances / 2)
                {
                    printf("  Great job! You solved it in just %d tries.\n", attempts + 1);
                }
                else
                {
                    printf("  You got it in %d tries. Well done.\n", attempts + 1);
                }
                printf("  Points earned: %d (Total Score: %d)\n", score, total_score);
                
                // Update high scores (track fewest attempts)
                if (choice == 1 && attempts < best_easy) best_easy = attempts;
                if (choice == 2 && attempts < best_medium) best_medium = attempts;
                if (choice == 3 && attempts < best_hard) best_hard = attempts;

                break; // Exit the loop on a correct guess
            }
            else if (guess < number)
            {
                printf("  Too LOW. Try a higher number.\n");
            }
            else if (guess > number)
            {
                printf("  Too HIGH. Try a lower number.\n");
            }

            attempts++;

            // Check if they just ran out of chances
            if (attempts == chances && !won)
            {
                printf("\n  GAME OVER. You ran out of chances.\n");
                printf("  The secret number was %d.\n", number);
            }
        }

        // Prompt for the next round
        if (won)
        {
            printf("\n  Play again? Select a difficulty from the menu.\n");
        }
        else if (guess != -1)
        {
            printf("\n  Returning to main menu. Try again!\n");
        }

    } while (choice != 4);

    return 0;
}
