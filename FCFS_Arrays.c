#include<stdio.h>
void quicksort(int number[25],int first,int last){
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(number[i]<=number[pivot]&&i<last)
            i++;
            while(number[j]>number[pivot])
            j--;
            if(i<j)
            {
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}
int main(){
    int i,j,count, AT[999],BT[999],AT1[999],BT1[999];
    printf("Enter No.of PID: ");
    scanf("%d",&count);
    printf("\nEnter %d AT: ", count);
    for(i=0;i<count;i++)
    scanf("%d",&AT[i]);
    printf("\nEnter %d BT : ", count);
    for(i=0;i<count;i++)
    scanf("%d",&BT[i]);
    //for sorting purpose taking extra AT1
    for(i=0;i<count;i++)
    AT1[i] = AT[i];
    //sort AT1
    quicksort(AT1,0,count-1);
    // sorting BT for AT1
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if(AT1[i]==AT[j]){
                BT1[i]=BT[j];
            }
        }
    }
    int CT[999],CT1[999];
    // Finding CT values for sorted AT,BT
    for (i=0;i<count;i++){
    if(i==0)
        CT1[i]=(BT1[i]+AT1[i]);
    else{
        if(CT1[i-1]>=AT1[i])
            CT1[i]=(CT1[i-1]+BT1[i]);
        else
            CT1[i]=(BT1[i]+AT1[i]);
    }
    }
    //Converting Sorted CT into Original Order CT
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if(AT[i]==AT1[j]){
                CT[i]=CT1[j];
            }
        }
    }
    // Finding TAT and WT
    int TAT[999],WT[999];
    for (int i=0;i<count;i++){
        TAT[i]=CT[i]-AT[i];
    }
    for (int i=0;i<count;i++){
        WT[i]=TAT[i]-BT[i];
    }

    //Prinitng in Colur Full
    for (int i=0; i<=count; i++){
        if(i==0){
            printf("|\033[0;31mPID | \033[0;32mAT | \033[0;33mAT | \033[0;34mAT | \033[0;35mTAT | \033[0;36mWT|",i);
            printf("\n\033[0;37m-----------------------------------");
        }
        else{
            printf("\n|\033[0;31mP%d  |  \033[0;32m%d |  \033[0;33m%d |   \033[0;34m%d |  \033[0;35m%d |  \033[0;36m%d|",i,AT[i-1],BT[i-1],CT[i-1],TAT[i-1],WT[i-1]);
            printf("\n\033[0;37m-----------------------------------");
        }
    }
}