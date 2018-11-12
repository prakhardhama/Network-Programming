#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ITER 10000
#define DART 5000

float monteCarlo()
{
	unsigned int i, count;
	float x, y, d, pi;
	count = 0;
	for(i=0; i<DART; i++)
	{
		x=-1+2*((float)rand())/RAND_MAX;
		y=-1+2*((float)rand())/RAND_MAX;
		d=x*x+y*y;
		if(d<=1.0)
			count++;
	}
	pi=4.0*((float)count/DART);
	//printf("pi= %f\n", pi); 
	return pi; 
}

int main()
{
	unsigned int i;
	float sum, pi, time_spent;
	clock_t begin, end;
	srand(time(0));
	sum=0.0;		
	begin = clock();
	#pragma omp parallel for shared(sum) private(i, pi)			
	for (i=0; i<ITER; i++)
	{
		pi=monteCarlo();		
		sum+=pi;			
		//printf("Thread %d= %f\n", i, pi);
	}
	end = clock();
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;	
	printf("FINAL PI = %f\n", (float)sum/ITER);
	printf("Time spent= %f\n", time_spent);		
	return 0;
}

