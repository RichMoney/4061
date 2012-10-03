//
//  myLittleShellScript.c
//
//
//  Created by Brian Salter on 9/15/12.
//  Rich Jeffery, Chris Arcand
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv, char **envp)
{
    printf("Welcome to My Little Shell!  Try not to disturb the ponies.\n\n");

    int maxSize = 100;
    char cmd[maxSize];
    char myLittleProgram[maxSize];
    char myLittleArguments[maxSize];
    char *myLittleEnv[maxSize];
    pid_t pid;
    char **env = envp;
    int isBackground = 0;

    while (69)
    {
        printf("Command: ");
        fgets(cmd, maxSize, stdin);
        char myLittlePath[] = "/bin/";
        strcpy(myLittleArguments, "");
//      printf("%c%s%c\n%c%s%c\n%c%s%c\n", '|', myLittlePath, '|', '|', myLittleProgram, '|', '|', myLittleArguments, '|');

        // Replaces the newline with a null character for printf
        char *newline = strchr(cmd, '\n');
        if (newline != NULL)
            *newline = '\0';

        printf("%s%s\n", "Executing command: ", cmd);
        
        int i = 0;
        int j = 0;

        while (i < maxSize && cmd[i] != ' ' && cmd[i] != '\0')
        {
            myLittleProgram[i] = cmd[i];
            i++;
        }
        myLittleProgram[i] = '\0';
        i++;
        while (i < maxSize && cmd[i] != '\0')
        {
            myLittleArguments[j] = cmd[i];
            i++;
            j++;
        }
        
        if (myLittleArguments[j-1] == '&')
        {
         printf("%s", "in the background.");
         isBackground = 1;
         myLittleArguments[j-1] = '\0';
        }
        if (strcmp(myLittleArguments, ""))
           myLittleArguments[j] = '\0';

                   
        if (!strcmp(myLittleProgram, "exit") || (!strcmp(myLittleProgram, "quit")))
           return 0;

        else if (!strcmp(myLittleProgram, "mylittleenv"))
        {
            i = 0;
            while (env[i] != 0)
            {
                printf("%s\n%d\n", env[i], i);
                i++;
            }
            continue;
        }

        else if (!strcmp(myLittleProgram, "mylittlesetenv"))
        {
            printf("%s\n", myLittleArguments);
            i = 0;
            while (env[i] != 0)
                i++;
            char *myLittleArg = (char *)malloc(maxSize);
            strcpy(myLittleArg, myLittleArguments);
            env[i] = myLittleArg;
            printf("%s\n%d\n", env[i], i);
            env[i + 1] = 0;
            continue;
        }
        
        

        else
        {
            pid = fork(); //create child
            if (pid == 0) //if child
            {
                strcat(myLittlePath, myLittleProgram);
//              printf("%c%s%c\n%c%s%c\n%c%s%c\n", '|', myLittlePath, '|', '|', myLittleProgram, '|', '|', myLittleArguments, '|');
                if (!strcmp(myLittleArguments, ""))
                {
                   int successcode = execlp(myLittlePath, myLittleProgram, NULL);
                   if (successcode == -1) {
                        printf("%s%s%s\n", "Command '", myLittleProgram, "' not found!");
                   }
                }
                else {
                   int successcode = execlp(myLittlePath, myLittleProgram, myLittleArguments, NULL);
                   if (successcode == -1) {
                        printf("%s%s%s\n", "Command '", myLittleProgram, "' not found!");
                   }
                }
                return 0;
            }
            else //if parent
            {
                if (!isBackground) //if our command isn't supposed to be in the background
                    waitpid(pid); //wait for child
                if (isBackground)
                    printf("%s","\n");
            }
        }
    }

    return 0;
}