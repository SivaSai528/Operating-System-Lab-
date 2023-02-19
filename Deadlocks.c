#include<stdio.h>
struct process
{
int allocation[3];
int max[3];
int need[3];
int finish;
}p[10];
int main()
{
int n,i,I,j,avail[3],work[3],flag,count=0,sequence[10],k=0;
printf("\nEnter the number of process:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter the %dth process allocated resources:",i); // allocated resourecse for processess
scanf("%d%d%d",&p[i].allocation[0],&p[i].allocation[1],&p[i].allocation[2]);
printf("\nEnter the %dth process maximum resources:",i); // maximum resources
scanf("%d%d%d",&p[i].max[0],&p[i].max[1],&p[i].max[2]);
p[i].finish=0;
p[i].need[0]=p[i].max[0]-p[i].allocation[0]; // we get need by subtracting allocation resourcres from maximum resources
p[i].need[1]=p[i].max[1]-p[i].allocation[1];
p[i].need[2]=p[i].max[2]-p[i].allocation[2];
}
printf("\nEnter the available vector:");   // enter the available resources
scanf("%d%d%d",&avail[0],&avail[1],&avail[2]);
for(i=0;i<3;i++)
work[i]=avail[i]; // initialize work=available
while(count!=n)
{
count=0;
for(i=0;i<n;i++)
{
flag=1; // it indicates the process doesnot executed 
if(p[i].finish==0)
if(p[i].need[0]<=work[0])
if(p[i].need[1]<=work[1])
if(p[i].need[2]<=work[2])
{
for(j=0;j<3;j++)
work[j]+=p[i].allocation[j]; // work =work+allocation
p[i].finish=1;// finish[i]=true then go to step intialize work=available
sequence[k++]=i;
flag=0;
}
if(flag==1)
count++;
}
}
count=0;
for(i=0;i<n;i++)
if(p[i].finish==1)
count++;
printf("\n The safe sequence is:\t");
if(count++==n)
for(i=0;i<k;i++)
printf("%d\n",sequence[i]);
else
printf("SYSTEM IS NOT IN A SAFE STATE \n\n");
return 0;
}
