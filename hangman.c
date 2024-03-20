#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define WORDS_COUNT 20
#define MAX_WORD_LENGTH 13
#define ASCII_LOWERCASE_LENGTH 26

char words[WORDS_COUNT][MAX_WORD_LENGTH] = {
    "python", "java", "kotlin", "javascript", "html", "css", "ruby",
    "sql", "coffeescript", "crystal", "elixir", "go", "groovy", "php",
    "racket", "rust", "shell", "swift", "typescript", "pascal"
};

int wins = 0;
int loses = 0;

int is_ascii_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

void print_score() {
    if (wins == 1 && loses == 1) {
        printf("You won 1 time. You lost 1 time.\n");
    } else if (wins == 1) {
        printf("You won 1 time. You lost %d times.\n", loses);
    } else if (loses == 1) {
        printf("You won %d times. You lost 1 time.\n", wins);
    } else {
        printf("You won %d times. You lost %d times.\n", wins, loses);
    }
}

int main() {
    srand(time(NULL));

    printf("H A N G M A N\n\n");

    while (1) {
        printf("Type \"play\", \"score\", or \"exit\": ");
        char menu[10];
        scanf("%s", menu);

        if (strcmp(menu, "play") == 0) {
            char currentAction[MAX_WORD_LENGTH];
            strcpy(currentAction, words[rand() % WORDS_COUNT]);
            char tip[MAX_WORD_LENGTH];
            int i;
            for (i = 0; i < strlen(currentAction); i++) {
                tip[i] = '-';
            }
            tip[i] = '\0';

            int lives = 8;
            char usedLetters[MAX_WORD_LENGTH] = {0};

            while (1) {
                printf("%s\n", tip);
                printf("Input a letter: ");
                char action[2];
                scanf("%s", action);

                if (strlen(action) != 1) {
                    printf("You should input a single letter\n\n");
                    continue;
                }
                char letter = action[0];
                if (!is_ascii_lowercase(letter)) {
                    printf("It is not an ASCII lowercase letter\n\n");
                    continue;
                }
                if (strchr(usedLetters, letter) != NULL) {
                    printf("You already typed this letter\n\n");
                    continue;
                }

                int letterFound = 0;
                for (i = 0; i < strlen(currentAction); i++) {
                    if (currentAction[i] == letter) {
                        tip[i] = letter;
                        letterFound = 1;
                    }
                }

                if (!letterFound) {
                    printf("No such letter in the word\n");
                    lives--;
                    if (lives == 0)
                        break;
                    printf("Lives left: %d\n", lives);
                }

                usedLetters[strlen(usedLetters)] = letter;

                if (strcmp(tip, currentAction) == 0)
                    break;

                printf("\n");
            }

            if (lives == 0) {
                printf("You are hanged!\n");
                loses++;
            } else {
                printf("You guessed the word %s!\n", currentAction);
                printf("You survived!\n");
                wins++;
            }

        } else if (strcmp(menu, "exit") == 0) {
            break;
        } else if (strcmp(menu, "score") == 0) {
            print_score();
        } else {
            printf("Wrong input. Please, try again\n");
        }
    }

    return 0;
}
