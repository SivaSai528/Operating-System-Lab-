#include<stdio.h>
int main(){
	int n,header_moves,first,last,cur_pos;
	printf("enter first cylinder number:");
	scanf("%d",&first);
	printf("enter last cylinder number");
	scanf("%d",&last);
	printf("Enter current position of header");
	scanf("%d",&cur_pos);
	printf("enter no of requests:");
	scanf("%d",&n);
	int request[n],service_seq[n];
	int i;
	header_moves=0; /* To count no of cylinders traversed by header*/
	int count=0;    
	for(i=0;i<n;i++){
		printf("enter request %d :",i+1);
		scanf("%d",&request[i]);
		if(request[i]<=last && request[i]>=first){
			          /* validate whether requested cylinder is 
					  present or not */
			service_seq[i]=++count;  /* n th time servieced*/
			if(cur_pos>=request[i]){  /* increment header moves*/
				header_moves+=(cur_pos-request[i]);
				/*current position is grater than present request
			 so no of cylinders traversed is cur_pos-request[i] */
			}
			else{
				header_moves+=(request[i]-cur_pos);
				/*current position is less than present request
			 so no of cylinders traversed is request[i]-cur_pos */	
			}
			cur_pos=request[i];
		/*present request now becomes current position of header*/
		}
		else{
			service_seq[i]=0;
			/* request cant be serviced if it is out of range*/
		}
	}
	printf("\n no of head movements is:\t %d",header_moves);
	printf("\nrequest\tservice_sequence\n");
	for(i=0;i<n;i++){
		printf("%d      \t  %d",request[i],service_seq[i]);
		printf("\n");
	}
}
