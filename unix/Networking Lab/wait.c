#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int status, val;
	pid = fork();
	if (pid == 0)
		exit(0);
	val=wait(&status);
	printf("val %d\t code %x\n", val, status);	
	
	pid = fork();
	if (pid == 0)
		abort();
	val=wait(&status);
	printf("val %d\t code %x\n", val, status);
	
	pid = fork();
	if (pid == 0)
		status /= 0;
	val=wait(&status);
	printf("val %d\t code %x\n", val, status);
	
	pid = fork();
	if (pid != 0)
	{
	kill(pid, SIGABRT);
	val=wait(&status);
	printf("val %d\t code %x\n", val, status);
	}
	
	exit(0);
}
