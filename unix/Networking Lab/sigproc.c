#include<stdio.h>
#include<signal.h>

int main()
{
	sigset_t set;
	sigemptyset(&set);
	printf("set= %x\n",set);
}
