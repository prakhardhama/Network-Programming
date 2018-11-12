#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 80

int main(int argc, char **argv)
{	
	char buff [MAXLINE] , command [MAXLINE];
	FILE *fp;
	printf("Enter command: ");	
	fgets(command, MAXLINE, stdin);	
	fp=popen(command, "r");
	while (fgets(buff, MAXLINE, fp) != NULL)
		fputs (buff , stdout);
	pclose(fp) ;
	exit (0) ;
}
