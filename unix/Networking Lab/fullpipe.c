#include<stdio.h>
#include<stdlib.h>

int main()
{
	int fd[2], s;
	char c;
	pid_t pid;	
	pipe(fd);
	if(fork()==0)
	{
		sleep(1);
		read(fd[0], &c, 1);
		printf("child= %c\n", c);
		s=write(fd[0], "c", 1);
		printf("wtf=%d\n", s);		
		exit(0);
	}
	write(fd[1],"p", 1);
	sleep(1);
	read(fd[1], &c, 1);
	printf("parent= %c\n", c);
	exit(0);
}
	
