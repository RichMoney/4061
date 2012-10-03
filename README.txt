    __  ___         __    _ __  __  __        _____ __         ____
   /  |/  /_  __   / /   (_) /_/ /_/ /__     / ___// /_  ___  / / /
  / /|_/ / / / /  / /   / / __/ __/ / _ \    \__ \/ __ \/ _ \/ / / 
 / /  / / /_/ /  / /___/ / /_/ /_/ /  __/   ___/ / / / /  __/ / /  
/_/  /_/\__, /  /_____/_/\__/\__/_/\___/   /____/_/ /_/\___/_/_/   
       /____/                                                     

Brian Salter, Rich Jeffery, Chris Arcand
CSCI 4061, Fall 2012

My Little Shell has various custom commands (listed here) as well
as standard Bash commands for simple operations (ls, cd, mkdir, etc).
It supports background processes with '&' and is interactive with 
common user errors (example: prompts for invalid commands and invalid
syntax in things such as setting environment variables).
Many of the custom commands involve the creation of new environments
and environment variables.

MY LITTLE SHELL COMMANDS:

mylittleenv
Displays the environment of the shell

myglobalenv
Displays the global environment

mylittlesetenv [key]=[value]
Sets an environment variable (must be in key=value format)

mylittleexport [key]
Exports the given key with it's value for use in a new instance
of My Little Shell

mylittleshell
Starts a new instance of My Little Shell as a child process


Thanks for using My Little Shell! And always try your best not to
disturb the ponies.


TECHNICAL NOTE(S):
If you are for some reason recompiling the source of My Little Shell,
please remember to name the binary 'mylittleshell'. My Little Shell
will recognize and tell you if you've made a mistake, however. 

