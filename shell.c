// Avani Gandhi
// A simple UNIX shell program that allows users to copy, delete, execute, and type a program.
// The program also allows a user to exit the loop and has errors if incorrect input is entered.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv)
  {
    printf("This is a program to take your input and do something awesome with it!");
    char fullinput[100];
    bool whilebreak = true;
//while loop to continue the program until exit is called.
    while (whilebreak)
      {
        fullinput[100] = '\0';
        printf("\nPlease enter a command>> ");
//inputs text string from the user.
        fgets(fullinput, 100, stdin);
//checks input for "exit" and breaks the loop.  Created a whilebreak function to make sure the loop breaks.
        if (!strncmp(fullinput, "exit", 4))
          {
            break;
            whilebreak = false;
          }
//checks input for "type" and types the contents of the inputted file on the screen.
        else if (!strncmp(fullinput, "type", 4))
          {
            int num = 0;
            char *firstnull = (char *) malloc(100);
            int length1 = 0;
            int length2 = 0;
            char *parse = (char *) malloc(100);
            char *eachword[100];
            parse = strtok(fullinput, " ");
            while (parse != NULL)
              {
                eachword[num] = (char *) malloc(100);
                firstnull = strchr (parse, 0);
                length1 = strlen(firstnull);
                length2 = strlen(parse);
                strncpy(eachword[num],parse,length2-length1-1);
                parse = strtok(NULL, " ");
                num++;
              }
            printf("Here are the contents of %s\n", eachword[1]);
            FILE *fp = fopen(eachword[1], "r");
            char ch;
            ch = getc(fp);
            while (ch != EOF)
              {
                printf("%c", ch);
                ch = getc(fp);
              }
            fclose(fp);
          }
//checks input for "copy" and copies the contents of the first inputted file to the second inputted file.
        else if (!strncmp(fullinput, "copy", 4))
          {
            int num = 0;
            char *firstnull = (char *) malloc(100);
            int length1 = 0;
            int length2 = 0;
            char *parse = (char *) malloc(100);
            char *eachword[100];
            parse = strtok(fullinput, " ");
            while (parse != NULL)
              {
                eachword[num] = (char *) malloc(100);
                firstnull = strchr (parse, 0);
                length1 = strlen(firstnull);
                length2 = strlen(parse);
                strncpy(eachword[num],parse,length2-length1-num+1);
                parse = strtok(NULL, " ");
                num++;
              }
            printf("The contents of %s ", eachword[1]);
            printf("will be transferred to %s.\nBelow are the contents that will be moved.\n", eachword[2]);
            FILE *fp1 = fopen(eachword[1], "r");
            FILE *fp2 = fopen(eachword[2], "w");
            char ch=getc(fp1);
            while (ch != EOF)
              {
                putc(ch, fp2);
                printf("%c", ch);
                ch=getc(fp1);
              }
            fclose(fp1);
            fclose(fp2);
          }
//checks input for "delete" and removes the file entirely.
        else if (!strncmp(fullinput, "delete", 6))
          {
            int num = 0;
            char *firstnull = (char *) malloc(100);
            int length1 = 0;
            int length2 = 0;
            char *parse = (char *) malloc(100);
            char *eachword[100];
            parse = strtok(fullinput, " ");
            while (parse != NULL)
              {
                eachword[num] = (char *) malloc(100);
                firstnull = strchr (parse, 0);
                length1 = strlen(firstnull);
                length2 = strlen(parse);
                strncpy(eachword[num],parse,length2-length1-1);
                parse = strtok(NULL, " ");
                num++;
              }
            printf("%s will be deleted.  I hope it was nothing important.\n", eachword[1]);
            FILE *fp = fopen(eachword[1], "r");
            int removal = 0;
            removal = remove(eachword[1]);
            if (removal == 0)
              {
                printf("%s has been deleted.\n", eachword[1]);
              }
            else
              { 
                printf("Something went wrong.  %s has not been deleted.\n", eachword[1]);
              }
          }
//assumes the call is an executible program and attempts to run the program.
        else
          {
            int num = 0;
            char *firstnull = (char *) malloc(100);
            int length1 = 0;
            int length2 = 0;
            char *parse = (char *) malloc(100);
            char *eachword[100];
            bool fileexist = false;
            parse = strtok(fullinput, " ");
            while (parse != NULL)
              {
                eachword[num] = (char *) malloc(100);
                firstnull = strchr (parse, 0);
                length1 = strlen(firstnull);
                length2 = strlen(parse);
                strncpy(eachword[num],parse,length2-length1-1);
                parse = strtok(NULL, " ");
                num++;
              }
            FILE *fp = fopen(eachword[0], "r");
            if (fp)
              {
                fclose(fp);
                fileexist = true;
              }
            if (fileexist == true)
              {
                printf("The program %s will execute now.\n", eachword[0]);
                pid_t pid = fork();
                int parentwait;
//prints an error if something goes wrong with the fork.
                if (pid < 0)
                  {
                    printf("There was an error with the fork process.  The program is ending now.\n");
                    return;
                  }
//completes the child function of the fork.
                else if (pid == 0)
                  {
                    execvp (eachword[0], eachword);
                    exit(0);
                  }
//makes the parent wait for the child to complete.
                else
                  {
                    waitpid(-1, NULL, 0);
                  }
              }
            else
              {
                printf("You screwed something up...try again: %s", fullinput);
              }
          }
      }
  return 0;
}