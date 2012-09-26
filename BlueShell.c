//
//  Blue Shell.c
//  
//
//  Created by Brian Salter on 9/15/12.
//
//

#include <stdio.h>

int main (int argc, char *argv[])
{
    printf("Welcome to Blue Shell!  Try not to be in first place.\n\n");
    
    int maxSize = 100;
    char cmd[maxSize];
    char myLittleProgram[maxSize];
    char myLittleArguments[maxSize];
    
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
        
        
    }
    
    return 0;
}