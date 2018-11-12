#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>

/*
void catcher()
{
	sigset_t set;
	sigprocmask(SIG_SETMASK, NULL, &set);
	printf("catcher=%x\n", set);
}*/

int main()
{
	sigset_t set, oset, zero;
	pid_t pid;
	int val, code;
	//signal(SIGINT, catcher);
	if(sigemptyset(&set)==0)
	printf("zero");
	sigemptyset(&oset);
	sigemptyset(&zero);
	printf("set= %x\n", set);
	printf("oset= %x\n", oset);
	printf("zero= %x\n", zero);
/*
	sigaddset(&set, SIGCHLD);
	sigaddset(&set, SIGTERM);
*/
/*
	sigprocmask(SIG_SETMASK, NULL, &zero);
	printf("zero= %x\n", zero);
	oset=zero;	
	printf("set= %x\n", set);	
	printf("oset= %x\n", oset);
	sigprocmask(SIG_BLOCK, &set, &oset);
	printf("oset= %x\n", oset);
	kill(getpid(), SIGCHLD);
	sigsuspend(&zero);
	kill(getpid(), SIGCHLD);
	
	sigprocmask(SIG_SETMASK, NULL, &set);	
	printf("set= %x\n", set);
*/	
/*
	sigprocmask(SIG_BLOCK, &set, &oset);
	printf("oset= %x\n", oset);
	
	pid=fork();
	if(pid==0)
	{
		sigsuspend(&zero);
		sigprocmask(SIG_SETMASK, NULL, &set);
		printf("abc %x\n", set);
		exit(1);
	}
	
	kill(pid, SIGTERM);
	val=waitpid(pid, &code, 0);
	printf("val=%d code=%x\n", val, code);
	
	sigprocmask(SIG_SETMASK, NULL, &set);
	printf("xyz %x\n", set);
*/	
	exit(0);
}


