#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int i, code, val;
	printf("main pid=%d\n", getpid());
	if((pid=fork())<0)
		printf("fork1 error");
	else if(pid>0)
	{	if((pid=fork())<0)
		printf("fork2 error");
		else if(pid>0)
		{printf("child= %d\n", getpid());exit(7);}
		printf("gchild= %d\n", getpid());
		sleep(1);
		printf("pid= %d\n", getppid());
		exit(1);
	}
	printf("child1= %d\n", getpid());
	if(waitpid(pid, NULL, 0)!=pid)
	printf("waitpid error\n");
	exit(0);

	/*for(i=0; i<4; ++i)	
	{	pid = fork();
		if(pid == 0)
		{
			printf("pid= %d\n", getpid());
			exit(i);
		}
		else
		{	
			val=waitpid(-1, &code, 0);
			printf("val %d\t code %x\n", val, code);	
		}
	}

	for(i=0; i<4; ++i)	
	{	
		if(fork() > 0)
		{
			printf("pid= %d\n", getpid());
			exit(i);
		}
		else
		{	
			val=waitpid(-1, &code, 0);
			printf("val %d\t code %x\n", val, code);	
		}
	}*/
	
	exit(0);
}
