#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int status;

	if((pid = fork()) < 0)
		printf("fork error\n");
	else if(pid==0)
		exit(7);
	if(wait(&status) != pid)
		printf("wait error\n");
	printf("%x\n", status);
	
	if((pid = fork())<0)
		printf("fork error\n");
	else if(pid == 0)
		abort();
	if(wait(&status) != pid)
		printf("wait error\n");
	printf("%x\n", status);

	exit(0);
}
