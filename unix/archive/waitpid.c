#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>


static void
sig_cld(int signo)
{
int val, code;
printf("SIGCLD received\n");
val=waitpid(-1, &code, 0);
printf("val %d\t code %x\n", val, code);
}

int main()
{
	int i, val, code;
signal(SIGCLD, sig_cld);	
for(i=0; i<4; ++i)
		if(fork()>0)
		{
			printf("%d\n", getpid());			
			exit(i);
		}	
	for(;;);
}


