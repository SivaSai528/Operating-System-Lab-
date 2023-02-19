//least number highest priority
#include<stdio.h>
int n;
struct process
{
    int WT,AT,BT,TAT,PT,p,CT;
}a[1000];
void Arrival_Time_Sorting() 
{ 
      struct process temp; 
      int i, j; 
      for(i = 0; i < n - 1; i++) 
      { 
            for(j = i + 1; j < n; j++) 
            { 
                  if(a[i].AT > a[j].AT) 
                  { 
                        temp = a[i]; 
                        a[i] = a[j]; 
                        a[j] = temp; 
                  } 
            } 
      } 
}

int main()
{
    int temp[10],t,count=0,short_p;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("AT BT PT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        temp[i]=a[i].BT;
        a[i].p=i;
    }
    Arrival_Time_Sorting();
    a[9].PT=10000;
    printf("ID  AT  BT  PT  CT  TAT  WT\n");
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
            {
                short_p=i;
            }
        }
        
        a[short_p].BT=a[short_p].BT-1;
        if(a[short_p].BT==0)
        {
            count++;
            a[short_p].CT=t+1;
            a[short_p].TAT=a[short_p].CT-a[short_p].AT;
            a[short_p].WT=a[short_p].TAT-temp[short_p];
            total_WT=total_WT+a[short_p].WT;
            total_TAT=total_TAT+a[short_p].TAT;
            printf("p%d  %d    %d   %d   %d   %d  %d\n",a[short_p].p,a[short_p].AT,temp[short_p],a[short_p].PT,a[short_p].CT,a[short_p].TAT,a[short_p].WT);
            
        }
    }
    
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
    return 0;
}