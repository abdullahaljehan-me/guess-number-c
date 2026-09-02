#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int choice, number, min = 1, max, attempts = 0, chances, guess;
    int won = 0;

    // Seed the random number generator so it's different every time
    srand(time(NULL));

    do
    {
        // Reset variables for a new game
        attempts = 0;
        won = 0;

        printf("\n");
        printf("  ============================================\n");
        printf("  ||         🎲 GUESS THE NUMBER 🎲         ||\n");
        printf("  ============================================\n\n");

        printf("  [1] Easy   (1 to 50  | 7 chances)\n");
        printf("  [2] Medium (1 to 100 | 6 chances)\n");
        printf("  [3] Hard   (1 to 200 | 5 chances)\n");
        printf("  [4] Exit   \n\n");

        printf("  Choose your destiny (1-4): ");

        // Prevent infinite loops if the user types letters instead of numbers
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("\n  INVALID INPUT! Let's try that again.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            max = 50;
            chances = 7;
            printf("\n  Easy mode! A nice warm-up. Let's go!\n");
            break;
        case 2:
            max = 100;
            chances = 6;
            printf("\n  Medium mode! Now we're getting serious.\n");
            break;
        case 3:
            max = 200;
            chances = 5;
            printf("\n  Hard mode! Brave choice. You'll need luck!\n");
            break;
        case 4:
            printf("\n  Exiting the game... Catch you later!\n\n");
            return 0;
        default:
            printf("\n  Oops! That's not on the menu. Pick 1, 2, 3, or 4.\n");
            continue;
        }

        printf("\n  Alright, I'm thinking of a number between %d and %d.\n", min, max);
        printf("  You have %d chances. Don't waste them!\n\n", chances);

        // Generate the secret number
        number = (rand() % (max - min + 1)) + min;

        while (attempts < chances)
        {
            printf("  [Attempt %d/%d] What's your guess? (-1 to quit): ", attempts + 1, chances);

            if (scanf("%d", &guess) != 1)
            {
                while (getchar() != '\n')
                    ;
                printf("  Nice try, but I need an actual number!\n");
                continue;
            }

            // Check for quit first
            if (guess == -1)
            {
                printf("\n  SORRY to see you quit! The magic number was %d. See ya!\n", number);
                break;
            }

            // Forgive out-of-bounds guesses so they don't lose a chance
            if (guess < min || guess > max)
            {
                printf(" INVALID INPUT! Stay within %d and %d, please! That didn't count.\n", min, max);
                continue;
            }

            if (guess == number)
            {
                won = 1;
                printf("\n  CONGRATS! You guessed it! The number was indeed %d!\n", number);

                // Dynamic win messages based on performance
                if (attempts == 0)
                {
                    printf("  EXCELLENT! On the very first try?! Are you a mind reader?\n");
                }
                else if (attempts < chances / 2)
                {
                    printf("  Superb! You crushed that in just %d tries!\n", attempts + 1);
                }
                else
                {
                    printf("  You got it in %d tries. Nice job!\n", attempts + 1);
                }
                break; // Exit the loop on a correct guess
            }
            else if (guess < number)
            {
                printf("  Too LOW! Think a bit bigger!\n");
            }
            else if (guess > number)
            {
                printf("  Too HIGH! Think a bit lower!\n");
            }

            attempts++;

            // Check if they just ran out of chances
            if (attempts == chances && !won)
            {
                printf("\n  GAME OVER! You ran out of chances.\n");
                printf("  The secret number was %d. Better luck next time!\n", number);
            }
        }

        // Prompt for the next round
        if (won)
        {
            printf("\n  Feeling lucky? Pick a difficulty to play again!\n");
        }
        else if (guess != -1)
        {
            printf("\n  Try again from the menu!\n");
        }

    } while (choice != 4);

    return 0;
}
