#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int balance = 1000;
int totalGames = 0, wins = 0, losses = 0;

/* Function Declarations */
void welcome();
void showMenu();
void playGame();
void showRules();
void showStats();
int getRandom(int level);

int main()
{
    int choice;
    char name[20];

    srand(time(0));

    welcome();
    printf("\nEnter your name: ");
    scanf("%s", name);

    do
    {
        showMenu();
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                playGame();
                break;
            case 2:
                showRules();
                break;
            case 3:
                showStats();
                break;
            case 4:
                printf("\nThank you for playing, %s!\n", name);
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}

/* Function Definitions */

void welcome()
{
    printf("=================================\n");
    printf("      WELCOME TO CASINO      \n");
    printf("=================================\n");
}

void showMenu()
{
    printf("\n--------- MAIN MENU ---------\n");
    printf("1. Play Game\n");
    printf("2. View Rules\n");
    printf("3. View Statistics\n");
    printf("4. Exit\n");
}

void showRules()
{
    printf("\n--- GAME RULES ---\n");
    printf("1. Initial balance is 1000\n");
    printf("2. Choose difficulty level\n");
    printf("3. Guess the correct number\n");
    printf("4. Win gives bonus money\n");
    printf("5. Lose deducts bet amount\n");
}

void playGame()
{
    int bet, guess, number, level;
    char again;

    if(balance <= 0)
    {
        printf("\nNo balance left!\n");
        return;
    }

    printf("\nChoose Difficulty Level:\n");
    printf("1. Easy (1 - 5)\n");
    printf("2. Medium (1 - 10)\n");
    printf("3. Hard (1 - 20)\n");
    printf("Enter level: ");
    scanf("%d", &level);

    printf("Enter bet amount: ");
    scanf("%d", &bet);

    if(bet <= 0 || bet > balance)
    {
        printf("Invalid bet!\n");
        return;
    }

    printf("Enter your guess: ");
    scanf("%d", &guess);

    number = getRandom(level);

    totalGames++;

    if(guess == number)
    {
        wins++;
        printf("YOU WON! Number was %d\n", number);
        balance += bet * level;
    }
    else
    {
        losses++;
        printf(" YOU LOST! Number was %d\n", number);
        balance -= bet;
    }

    /* Lucky Bonus */
    if(number == 7)
    {
        printf(" Lucky Bonus! +200 added\n");
        balance += 200;
    }

    printf("Current Balance: %d\n", balance);

    printf("Do yo want to return to the  menu? (y/n): ");
    scanf(" %s", &again);
    if(again=='n' || again=='N' )
    {
         playGame();
    }
}

void showStats()
{
    printf("\n--- GAME STATISTICS ---\n");
    printf("Total Games Played: %d\n", totalGames);
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
    printf("Current Balance: %d\n", balance);
}

int getRandom(int level)
{
    if(level == 1)
        return rand() % 5 + 1;
    else if(level == 2)
        return rand() % 10 + 1;
    else if(level == 3)
        return rand() % 20 + 1;
    else{
        printf("Invalid level! Defaulting to easy\n");
        return rand() % 5 + 1;
    }
}