#include<stdio.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int i, msgid;
	for(i=0;i<5;++i)
	{
		msgid=msgget(IPC_PRIVATE, 0666|IPC_CREAT);
		printf("msgid=%d \t%x\n", msgid, msgid);
		msgctl(msgid, IPC_RMID, 0);
	}
	exit(0);
}
