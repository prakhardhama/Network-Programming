#include<stdio.h>

int main()
{
	printf("%d\t%d\n", getuid(), geteuid());
	setreuid(geteuid(), getuid());
	printf("%d\t%d\n", getuid(), geteuid());
	return 0;
}
