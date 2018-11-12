#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char **argv)
{
	int fd, i, zero = 0;
	int *ptr;
	if (argc != 2)
	{	printf("usage: incr2 <pathname>");
		exit(1);
	}
	printf("argv[1]= %s\n", argv[1]);
	fd = open(argv[1], O_RDWR | O_CREAT, FILE_MODE);
	printf("fd= %d\n", fd);
	write(fd, &zero, sizeof (int) ) ;
	
	ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	close ( fd) ;
	if (fork() == 0)	
	{
		for (i = 0; i < 5; i++)
			(*ptr)++;
		exit (0) ;
	}
	
	wait(NULL);
	for (i = 0; i < 5; i++) 
		printf("parent: %d\n", (*ptr)++);

	return 0;
}
