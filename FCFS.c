#include<stdio.h> 
struct process 
{ 
      char pn; 
      int at, bt, ct, wt, tat; 
}P[1000];
//Number of processes
int limit;
void Arrival_Time_Sorting() 
{ 
      struct process temp; 
      int i, j; 
      for(i = 0; i < limit - 1; i++) 
      { 
            for(j = i + 1; j < limit; j++) 
            { 
                  if(P[i].at > P[j].at) 
                  { 
                        temp = P[i]; 
                        P[i] = P[j]; 
                        P[j] = temp; 
                  } 
            } 
      } 
}
void main() 
{ 
      int i;
      char c; 
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit);
      //Taking Input from User
      for(i = 0, c = 'A'; i < limit; i++, c++) 
      { 
            P[i].pn = c; 
            printf("\nEnter Details For Process[%C]:\n",P[i].pn); 
            printf("Enter Arrival Time:\t"); 
            scanf("%d", &P[i].at );
            printf("Enter Burst Time:\t"); 
            scanf("%d", &P[i].bt); 
      }
      // Sorting Based of Arrival Time
      Arrival_Time_Sorting(); 
      // Calculating Burst Time
      for(int j=0;j<limit;j++) 
      {
            if(j==0)
                  P[j].ct=(P[j].bt+P[j].at);
            else{
                  if(P[j-1].ct<P[j].at)
                  {
                        P[j].ct=(P[j].bt+P[j].at);
                  }
                  else
                  {
                        P[j].ct=(P[j].bt+P[j-1].ct);
                  }
            }
            P[j].tat = P[j].ct-P[j].at; 
            P[j].wt = P[j].tat-P[j].bt; 
      }
      //Printing Process Data
      printf("PID  AT BT CT TAT WT");
      for(i = 0; i < limit; i++) 
      { 
            printf("\n%c    %d  %d  %d  %d  %d\n",P[i].pn,P[i].at,P[i].bt,P[i].ct,P[i].tat,P[i].wt); 
      } 
}
