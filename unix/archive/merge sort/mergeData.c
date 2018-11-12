#include<stdio.h>
#include<stdlib.h>
#define NUM 500000
#define MAX 1000

int main()
{
	int i, temp;
	FILE *fp;
	printf("NUM= %d\nMAX= %d\n", NUM, MAX);
	fp = fopen("mergeData.txt", "w+");
	for(i=0; i<NUM; ++i)
	{
		temp=MAX*((float)rand())/RAND_MAX;
		printf("\rGenerating Data... %3d%%", i*100/NUM);
		fprintf(fp,"%d ", temp);
	}
	printf("\rGenerating Data... 100%%");
	fclose(fp);
	printf("\nDone!");
	//getch();
	return 0;
}
