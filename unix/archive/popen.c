#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 80

int main(int argc, char **argv)
{	size_t n;
	char buff [MAXLINE] , command [MAXLINE] ;
	FILE *fp;
	fgets (buff, MAXLINE, stdin) ;
	n = strlen(buff);
	if (buff[n - 1] == '\n')
	n-- ; 	
	snprintf(command, sizeof(command), "cat %s", buff);
	fp = popen(command, "r");
	while (fgets(buff, MAXLINE, fp) != NULL)
	fputs (buff , stdout) ;
	pclose (fp) ;
	exit (0) ;
}
