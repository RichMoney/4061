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
    pid_t pid;
    char *env[maxSize];
    int envSet = 0;
    int isBackground = 0;

    while (69)
    {
        printf("Command: ");
        fgets(cmd, maxSize, stdin);
        char myLittlePath[] = "/bin/";
        strcpy(myLittleArguments, "");

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
           printf("%s\n", "in the background.");
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
            while (envp[i] != 0)
            {
                printf("%s\n", envp[i]);
                i++;
            }
            i = 0;
            while (envSet && env[i] != 0)
            {
                printf("%s\n", env[i]);
                i++;
            }
            continue;
        }
        
        else if (!strcmp(myLittleProgram, "myglobalenv"))
        {
            i = 0;
            while (envp[i] != 0)
            {
                printf("%s\n", envp[i]);
                i++;
            }
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
            envSet = 1;
            continue;
        }
        
        else if (!strcmp(myLittleProgram, "mylittleexport"))
        {
            i = 0;
            j = 0;
            int found = 0;
            while (envSet && env[i] != 0)
            {
                  while (69)
                  {
                        if (env[i][j] == '=')
                        {
                             found = 1;
                             break;
                        }
                        else if (env[i][j] != myLittleArguments[j])
                           break;
                        j++;
                  }
                  if (found)
                  {
                     char *myLittleArg = (char *)malloc(maxSize);
                     strcpy(myLittleArg, env[i]);
                     i = 0;
                     while (envp[i] != 0)
                           i++;
                     envp[i] = myLittleArg;
                     envp[i + 1] = 0;
                     break;
                  }
                  i++;
                  j = 0;
            }
            if (!found)
                printf("%s%s%s\n", "Could not find ", myLittleArguments, " anywhere!");
            continue;
        }


        else
        {
            pid = fork(); //create child
            if (pid == 0) //if child
            {
                strcat(myLittlePath, myLittleProgram);
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
                continue;
            }
            else //if parent
            {
                if (!isBackground) //if our command isn't supposed to be in the background
                    waitpid(pid); //wait for child
                if (isBackground)
                    printf("\n");
            }
        }
    }

    return 0;
}