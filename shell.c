// Avani Gandhi
// A simple UNIX shell program that allows users to copy, delete, execute, and type a program.
// The program also allows a user to exit the loop and has errors if incorrect input is entered.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Function Defintions
void error(char* fullinput);
bool InputIsExit(char* fullinput);
int InputIsType(char* fullinput);
int InputIsCopy(char* fullinput);
int InputIsDelete(char* fullinput);
int InputIsExecutable(char* fullinput);
void type(char* filename);
char* FileName1(char* fullinput);
char* FileName2(char* fullinput);
void copy(char* source, char* destination);
void delete(char* filename);
void execute(char* filename);

int main(int argc, char** argv) {
  printf("This is a program to take your input and do something awesome with it!");
  char fullinput[100] = {0};
  while (true) {
    printf("\nPlease enter a command>> ");
    scanf("%s", fullinput);
    if (InputIsExit(fullinput)) {
      break;
    } else if (InputIsType(fullinput)) {
      type(FileName1(fullinput));
    } else if (InputIsCopy(fullinput)) {
      copy(FileName1(fullinput), FileName2(fullinput));
    } else if (InputIsDelete(fullinput)) {
      delete(FileName1(fullinput));
    } else if (InputIsExecutable(fullinput)) {
      execute(fullinput);
    } else {
      error(fullinput);
    }
  }
  return 0;
}

// Displays an error message if mistake
void error(char* fullinput) {
  printf("You screwed something up...try again: %s", fullinput);
}

// Returns 1 if input is "exit"
bool InputIsExit(char* fullinput) {
  // strcmp returns 0 when strings are equal
  return !strcmp(fullinput, "exit");
}

// Returns 1 if the first word in the input is "type"
int InputIsType(char* fullinput) {
  // TODO
  return 0;
}

// Returns 1 if the first word in the input is "copy"
int InputIsCopy(char* fullinput) {
  // TODO
  return 0;
}

// Returns 1 if the first word in the input is "delete"
int InputIsDelete(char* fullinput) {
  // TODO
  return 0;
}

// Returns 1 if the input is an actual file that can be executed
int InputIsExecutable(char* fullinput) {
  // TODO
  return 0;
}

// Prints the contents of the chosen file to the command prompt
void type(char* fullinput) {
  // TODO
}

// Copies one file to another file
void copy(char* source, char* destination) {
  // TODO
}

// Deletes a file
void delete(char* filename) {
  // TODO
}

// Executes a program named `filename`
void execute(char* filename) {
  // TODO
}

// Returns the first file from user's input
char* FileName1(char* fullinput) {
  // TODO
  return 0;
}

// Returns the second file from user's input
char* FileName2(char* fullinput) {
  // TODO
  return 0;
}