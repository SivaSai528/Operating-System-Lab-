#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	// Stores block id of the
	// block allocated to a process
	int allocation[n],already_allocated[n];

	// Initially no block is assigned to any process
	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;/*To store allocated block of particular process*/
		already_allocated[i]=-1;/*to indicate whether a particular block is 
		                        already allocated or not*/
	}

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (i = 0; i < n; i++)	 //here, n -> number of processes
	{
		for (j = 0; j < m; j++)	 //here, m -> number of blocks
		{
			if ((blockSize[j] >= processSize[i]) && already_allocated[j]==-1)
			{
				// allocating block j to the ith process
				allocation[i] = j;
				already_allocated[j]=0;
				// Reduce available memory in this block.
				blockSize[j] -= processSize[i];

				break; //go to the next process in the queue
			}
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (i=0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

// Driver code
int main()
{
	int i;
	int m; //number of blocks in the memory
	printf("enter no of blocks in memory:\n");
	scanf("%d",&m);
	int n; //number of processes in the input queue
	printf("enter no of processes in input queue:\n");
	scanf("%d",&n);
	int blockSize[m];
	int processSize[n];
	for(i=0;i<m;i++){
		printf("\nenter %d block size:",i+1);
		scanf("%d",&blockSize[i]);
	}
	
	for(i=0;i<n;i++){
		printf("\nenter %d process size:",i+1);
		scanf("%d",&processSize[i]);
	}

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}

