/* ------------------- **
** Shannon Toft        **
** Net id: hg9773      **
** Toft_Prog1.c        **
** ------------------- */

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv)
{
  char line[100];
  char *args[100];
  int num_args;
  int i;
  int waitpid;
  int childpid;
  int status;

  while(1)
  {
    printf("tish>> ");
    gets(line);

    num_args = 0;
    args[num_args] = strtok(line, " ");

    if(strcmp(line, "bye") == 0)
    {
      exit(1);
    }else if (strcmp(line, "jobs") == 0)
    {
      args[0] = "ps";
    }else if (strstr(line, "kill") != NULL)
    {
      num_args++;
      args[2] = args[1];
      args[1] = "-9";
    }

    while(args[num_args] != NULL)
    {
      num_args++;
      args[num_args] = strtok(NULL, " ");
    }
    num_args--;

    for(i = 0; i <= num_args; i++)
    {
      printf(args[i]);
      printf(" ");
    }
    printf("\n");

    childpid = fork();
    if(childpid == 0)
    {
      execvp(args[0], args);
      perror("Exec failed: ");
      exit(0);
    }

    waitpid = wait(&status);
  }
  return 0;
}
