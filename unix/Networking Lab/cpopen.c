#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 80

FILE *mypopen(const char *cmdstring, char *type)
{
	int i;
	int pfd[2];
	pid_t pid;
	FILE *fp;
	pipe(pfd);
	pid=fork();
	if (pid == 0) 
	{ 
		if(*type=='r') 
		{
			close(pfd[0]);
			dup2(pfd[1], STDOUT_FILENO);
			close(pfd[1]);

		} 
		else if(*type=='w') 
		{
			close(pfd[1]);
			dup2(pfd[0], STDIN_FILENO);
			close(pfd[0]);
		}
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		_exit(127);
	}
	if(*type=='r') 
		close(pfd[1]); 
	else if(*type=='w') 
		close(pfd[0]);
	fp=fdopen(pfd[0], type);
	return fp;
}


int main(int argc, char **argv)
{	
	char buff [MAXLINE] , command [MAXLINE] ;
	FILE *fp;
	printf("Enter command: ");	
	fgets (command, MAXLINE, stdin);	
	fp=mypopen(command, "r");
	while(fgets(buff, MAXLINE, fp) != NULL)
		fputs(buff , stdout);
	pclose(fp);
	exit(0);
}
