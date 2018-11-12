#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int i, val,code, status;
/*
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
*/

/*
	printf("process= %d\n", getpid());	
	for(i=1; i<=3; ++i)
	fork();
	printf("process= %d\n", getpid());

	for(i=0; i<5; ++i)
	if(fork()>0) break;
	else
	{
		printf("ppid= %d\n", getppid());
	}	

	for(;;);
*/

for(i=0;i<4;++i)
if(fork()>0)
{
printf("%d\n",getpid());
exit(i);
}
else
{
val=waitpid(pid,&code,0);
printf("val %d\t code %x\n",val,code);
}
}
