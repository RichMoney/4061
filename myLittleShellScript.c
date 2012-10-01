//
//  Blue Shell.c
//
//
//  Created by Brian Salter on 9/15/12.
//
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    printf("Welcome to My Little Shell!  Try not to disturb the ponies.\n\n");

    int maxSize = 100;
    char cmd[maxSize];
    char myLittleProgram[maxSize];
    char myLittleArguments[maxSize];
    char *myLittleEnv[maxSize];
    pid_t pid;

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
        while (i < maxSize && cmd[i] != '\0')
        {
            myLittleArguments[j] = cmd[i];
            i++;
            j++;
        }
        
        if (strcmp(myLittleArguments, ""))
           myLittleArguments[j] = '\0';
           
        if (!strcmp(myLittleProgram, "exit"))
           return 0;

        else if (!strcmp(myLittleProgram, "mylittleenv"))
        {
             char * env = getenv("PATH");
             printf(env);
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
                   execlp(myLittlePath, myLittleProgram, NULL);
                }
                else
                    execlp(myLittlePath, myLittleProgram, myLittleArguments, NULL);
                return 0;
            }
            else //if parent
            {
                waitpid(pid); //wait for child
            }
        }
    }

    return 0;
}
