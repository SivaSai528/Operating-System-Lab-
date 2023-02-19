#include <stdio.h>

void BestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    // This will store the block id of the allocated block to a process
    int allocation[proccesses];
    int occupied[blocks];
    int i,j;
    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for(i = 0; i < proccesses; i++){
        allocation[i] = -1;
    }
    
    for(i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
 
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (i=0; i<proccesses; i++)
    {
        
        int indexPlaced = -1;
        for (j=0; j<blocks; j++) 
        { 
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                // place it at the first block fit to accomodate process
                if (indexPlaced == -1)
                    indexPlaced = j;
                    
                // if any future block is smaller than the current block where
                // process is placed, change the block and thus indexPlaced
                else if (blockSize[indexPlaced] >= blockSize[j])
                    indexPlaced = j;
            }
        }
 
        // If we were successfully able to find block for the process
        if (indexPlaced != -1)
        {
            // allocate this block j to process p[i]
            allocation[i] = indexPlaced;
            
            // make the status of the block as occupied
            occupied[indexPlaced] = 1;
 
            // Reduce available memory for the block
            blockSize[indexPlaced] -= processSize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
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

	BestFit(blockSize, m, processSize, n);

	return 0 ;
}
