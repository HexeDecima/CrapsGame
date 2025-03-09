#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> // For rand()

/*
2025-02-19

RULES

Come-Out Roll:
You roll two dice.
 - If the sum is 7 or 11, you win right away.
 - If the sum is 2, 3, or 12 (called “craps”), you lose immediately.
 - If the sum is 4, 5, 6, 8, 9, or 10, that number becomes your point.

Point Phase:
Once a point is set, you keep rolling the dice.
 - If you roll the point number again before rolling a 7, you win.
 - If you roll a 7 before the point, you lose.

*/

int roll_dice(void);
bool play_game(void);

int main() {
    int roll = 0;
    int user_choice;
    bool is_valid = false;
    // Game loop
    printf("Play a game? (Y/N): ");
    while (!is_valid) { 
        user_choice = getchar();
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {} // clear the buffer

        if (user_choice == 'y' || user_choice == 'Y') {
            is_valid = true;
            play_game();
        }
        else if (user_choice == 'n' || user_choice == 'N') break;
        else {
            printf("Invalid input. Try again.\n");
        }
    } 
    
    return 0;
}

int roll_dice(void) {
    // Generate the equivalent of a sum of 2 random numbers 1-6
    int dices = (rand() % 12 + 1);
    return dices;
}

bool play_game(void) {
    bool result = false;
    bool is_valid = false;
    bool game_has_ended = false;
    int first_roll;
    int user_choice;
    int roll_result;
    
    // One dice roll
    printf("Roll dice ('R')\n");
    while (!is_valid) { 
        first_roll = getchar();     
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {} // clear the buffer
        if (first_roll == 'r' || first_roll == 'R') {
            is_valid = true;
        }
        else {
            printf("Invalid input. Try again.\n");
        }
    } 

    roll_result = roll_dice();

    int roll = 1;
    int point = 0;

    // Evaluate roll
    if (roll == 1)
    {
        switch (roll_result) {
            // Immediate win
            case 7: {
                        result = true;
                        point = 0;
                        break;
                    };
            case 11: {
                        result = true;
                        point = 0;
                        break;
                     };
            // Immediate lose
            case 2: {
                        result = false;
                        break;
                    };
            case 3: {
                        result = false;
                        break;
                    };
            case 12: {
                        result = false;
                        break;
                     };
            // Point
            case 4: {
                        roll = 2;
                        point = 4;
                        result = true;
                        break;
                    };
            case 5: {
                        roll = 2;
                        point = 5;
                        result = true;
                        break;
                    };
            case 6: {
                        roll = 2;
                        point = 6;
                        result = true;
                        break;
                    };
            case 8: {
                        roll = 2;
                        point = 8;
                        result = true;
                        break;
                    };
            case 9: {
                        roll = 2;
                        point = 9;
                        result = true;
                        break;
                    };
            case 10: {
                        roll = 2;
                        point = 10;
                        result = true;
                        break;
                     };
        }
    }
    // Roll 1 results
    if (result == false) {
        printf("Roll 1: %d\n", roll_result);
        printf("You lose!\n");
        game_has_ended = true;
    }
    else if (result == true && roll == 1 && point == 0) {
        printf("Roll 1: %d\n", roll_result);
        printf("You win!\n");
        game_has_ended = true;
    }
    else {
        // Roll 2
        if (roll == 2 && point > 0) {
            printf("Point: %d\n", roll_result);
            int roll_2;
            bool is_valid = false;

            while (!is_valid) { 
                printf("Press 'R' to roll again.\n");
                roll_2 = getchar();     
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {} 

                if (roll_2 == 'r' || roll_2 == 'R') {
                    is_valid = true;
                }
                else {
                    printf("Invalid input. Try again.\n");
                }
            } 
                        
            // Roll 2 results
            switch (roll_dice()) {
                case 7: {
                    result = false;
                    printf("Roll 2: %d\n", roll_dice());
                    printf("You lose!\n");
                    game_has_ended = true;
                    break;
                }
                default: {
                    result = true;
                    printf("Roll 2: %d\n", roll_dice());
                    printf("You win!\n");
                    game_has_ended = true;
                    break;
                }
            }
        }
    }

    // Recursion
    is_valid = false;
    printf("Play another game? (Y/N): ");
    while (!is_valid) { 
        user_choice = getchar();
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {} 
        if (user_choice == 'y' || user_choice == 'Y') {
            is_valid = true;
            play_game();
        }
        else if (user_choice == 'n' || user_choice == 'N') return game_has_ended;
        else {
            printf("Invalid input. Try again.\n");
        }
    }
    return game_has_ended;
}
