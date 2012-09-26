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

int main (int argc, char *argv[])
{
    printf("Welcome to My Little Shell!  Try not to disturb the ponies.\n\n");
    
    int maxSize = 100;
    char cmd[maxSize];
    char myLittleProgram[maxSize];
    char myLittleArguments[maxSize];
    char myLittlePath[] = "/bin/";
    
    while (69)
    {
        printf("Command: ");
        fgets(cmd, maxSize, stdin);
        
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
        while (i < maxSize && cmd[i] != '\0')
        {
            myLittleArguments[j] = cmd[i];
            i++;
            j++;
        }
        
        if (!strcmp(myLittleProgram, "exit"))
            return 0;
        else
        {
            strcat(myLittlePath, myLittleProgram);
            execlp(myLittlePath, myLittleProgram, NULL);
        }
        
    }
    
    return 0;
}
