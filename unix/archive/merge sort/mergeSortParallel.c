#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#define NUM 500000
void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for (i=0; i<n1; i++)
        L[i]=arr[l+i];
    for (j=0; j<n2; j++)
        R[j]=arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if (L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
	if (l<r)
    {
    	int m = l+(r-l)/2;
      	#pragma omp parallel sections
        {
			#pragma omp section
			mergeSort(arr, l, m);
			#pragma omp section
      		mergeSort(arr, m+1, r);
      	}
      	merge(arr, l, m, r);
   }
}
 
int main()
{
	int i, temp, *data;
	float time_spent;
	FILE *fp;
	clock_t begin, end;
	data= (int*)malloc(NUM*sizeof(int));
	printf("NUM= %d\n", NUM);
	fp = fopen("mergeData.txt", "r");
	for(i=0; i<NUM; ++i)
	{
		printf("\rReading Data... %3d%%", i*100/NUM);
		fscanf(fp,"%d ", &data[i]);
	}
	printf("\rReading Data... 100%%");
	fclose(fp);
	
	begin = clock();
	mergeSort(data, 0, NUM-1);
	end = clock();
	time_spent = (float)(end-begin)/CLOCKS_PER_SEC;	
	printf("\nTime spent sorting= %f s\n", time_spent);

	fp = fopen("mergeDataSortedParallel.txt", "w+");
	fprintf(fp,"Time spent sorting= %f s\n", time_spent);
	for(i=0; i<NUM; ++i)
	{
		printf("\rWriting Sorted Data... %3d%%", i*100/NUM);
		fprintf(fp,"%d ", data[i]);
	}
	printf("\rWriting Sorted Data... 100%%\n");

	fclose(fp);
	//getch();
	return 0;
}
