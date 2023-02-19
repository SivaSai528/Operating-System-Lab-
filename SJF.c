#include<stdio.h> 
struct process 
{ 
      char pn; 
      int at, bt, ct, wt, tat; 
      int status; 
}P[1000]; 
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
      int i, time = 0, largest; 
      char c; 
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit); 

      for(i = 0, c = 'A'; i < limit; i++, c++) 
      { 
            P[i].pn = c; 
            printf("\nEnter Details For Process[%C]:\n", 
            P[i].pn); 
            printf("Enter Arrival Time:\t"); 
            scanf("%d", &P[i].at ); 
            printf("Enter Burst Time:\t"); 
            scanf("%d", &P[i].bt);
            P[i].status = 0; 
      } 
      Arrival_Time_Sorting();
      printf("PID   AT   BT   CT   TAT  WT");
      P[99].bt = 9999; 
      time = P[0].at;
      int cct[limit];
      for(int j=0;j<limit;j++) 
      { 
            if(time<P[j].at)
            {
                  time= P[j].at;
            }
            largest = 99; 
            for(i = 0; i < limit; i++) 
            {
                  if(P[i].at <= time && P[i].status != 1 && P[i].bt<P[largest].bt) 
                  { 
                        largest = i;
                  } 
            }
            if(j==0){
                P[largest].ct=(P[largest].bt+P[largest].at);
                cct[j] = P[largest].ct;
            }
            else{
                  if(cct[j-1]<P[largest].at){
                       P[largest].ct=(P[largest].bt+P[largest].at);
                       cct[j] = P[largest].ct; 
                  }
                  else{
                  P[largest].ct=(P[largest].bt+cct[j-1]);
                  cct[j] = P[largest].ct;
                  }
            }
            time=P[largest].ct;
            P[largest].status = 1; 
            P[largest].tat = P[largest].ct-P[largest].at; 
            P[largest].wt = P[largest].tat-P[largest].bt;
            printf("\n%c     %d    %d    %d    %d    %d\n",P[largest].pn,P[largest].at,P[largest].bt,P[largest].ct,P[largest].tat,P[largest].wt); 
        }
}
