#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MYNAME "Olivia Zurek"

int main(){
  printf("Welcome to Hangman!\n");
  printf("Try to guess the secret word one letter at a time.\n\n");

  char givenWord[] = "STRENGTHEN";
  char numGuesses[] = "**********";
  hangmanGame(givenWord, numGuesses);
  getch();
  return 0;
}

void hangmanGame(char correctAnswer[], char yourGuess[]){
  int numTries = 8;
  char yourLetter;
  printf("# misses left: %d        word = %s", numTries, yourGuess);

  while (numTries >= 0)
  {
    --numTries;
    printf("\nEnter a letter: ");
    scanf(" %c", &yourLetter);
    bool isDuplicate = false;

    for (int i = 0; i < strlen(correctAnswer); i++){
      if (yourLetter == correctAnswer[i]){
        yourGuess[i] = yourLetter;
        isDuplicate = true;
      }
    }

    if (isDuplicate == true){
      printf("# misses left: %d        word = %s", numTries, yourGuess);
    }

    if (strchr(correctAnswer, yourLetter) == NULL)
    {
      printf("# misses left: %d        word = %s ", numTries, yourGuess);
    }

    if(numTries > 0 && strcmp(correctAnswer, yourGuess) == 0){
      printf("\nYOU WON!");
      break;
    }

    if(numTries == 0){
      if(strcmp(correctAnswer, yourGuess) == 0){
        printf("\nYOU WON!");
        break;
      }
      printf("\nYOU LOSE! The word was %s", correctAnswer);
      break;
    }
  }
}
