#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 5

float randomx()
{
	float x;
	x=-1+2*((float)rand())/RAND_MAX;
	return x; 
}

int main()
{
	unsigned int i;
	float sum, x, time_spent;
	clock_t begin, end;
	srand(time(0));
	sum=0.0;		
	begin = clock();
	#pragma omp parallel for shared(sum) private(i, x)		
	for (i=0; i<N; i++)
	{
		x=randomx();				
		sum+=x;		
		printf("Thread %d= %f\n", i, x);
	}
	end = clock();
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;	
	printf("Sum = %f\n", sum);
	printf("Time spent= %f\n", time_spent);		
	return 0;
}

