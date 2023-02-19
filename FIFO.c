#include<stdio.h>
int main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0;
            printf("\n ENTER THE NUMBER OF PAGES:\n");
			scanf("%d",&n);
            printf("\n ENTER THE PAGE NUMBER :\n");
            for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
            printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no);
for(i=0;i<no;i++)
        frame[i]= -1;
j=0;
printf("\tref string\t page frames\n");
for(i=1;i<=n;i++){
	printf("%d\t\t",a[i]);   /* print element which is going to be inserted to 
	                                 page table currently*/
    avail=0;                /*flag to whether page is already present or not*/  
    for(k=0;k<no;k++)         
	if(frame[k]==a[i])
            avail=1;       /* set flag to 1 if it is already present*/
    if (avail==0){         /*If page is not present in the frames insert  it*/
		frame[j]=a[i];
        j=(j+1)%no;        /* this expression helps in maintaining FIFO order*/
        count++;           /* count no of page faults */     
        for(k=0;k<no;k++)    /* prints frames data as there is alternation occured*/
        printf("%d\t",frame[k]);                                               
}
printf("\n");
}
    printf("Page Fault Is %d",count);
	return 0;
}
