#include<stdio.h>
/* C SCAN is same as scan but after reaching first or last cylinder based 
upon direction of header it will moves from current end (first or last cylinder)
to opposite end(last or first cylinder).
now service the remaining requests*/
int main(){
	int n,header_moves,first,last,cur_pos,direction,last_visit;
	printf("enter first cylinder number:");
	scanf("%d",&first);
	printf("enter last cylinder number");
	scanf("%d",&last);
	printf("Enter current position of header");
	scanf("%d",&cur_pos);
	printf("Enter direction 0->left 1->right");
	scanf("%d",&direction);
	printf("enter no of requests:");
	scanf("%d",&n);
	int request[n];
	int i;
	header_moves=0;
	int count=0;
	for(i=0;i<n;i++){
		printf("enter request %d :",i+1);
		scanf("%d",&request[i]);
	}
	
	/* sorting the requests */
	int min_pos,j,temp;
	for(i=0;i<n;i++){
		min_pos=i;
		for(j=i+1;j<n;j++){
			if(request[min_pos]>request[j]){
				min_pos=j;
			}	
		}
		temp=request[i];
		request[i]=request[min_pos];
		request[min_pos]=temp;
		}
	printf("\n");
	
	/* print sorted requests*/
	for(i=0;i<n;i++){
		printf("%d,",request[i]);
	}
	printf("\n");
	
	if(direction==0){          //for left direction
		header_moves+=(cur_pos-first);// moving toward first cylinder 
		if(request[n-1]>cur_pos){
			/*check if there are any un covered cylinders in the request
			if yes go to last cylinder  to service the remaining requests
				
			if last number in request array is grater than current position
			 means we will not service it while moving toward left end*/
			header_moves+=(last-first)
			for(i=0;i<n;i++){      /* findout highest cylinder number among 
			cylinders left to be serviced (we are directly finding it since 
			we stop our header at that postion)*/
				if(request[i]>cur_pos){
				last_visit=request[i];
				break;
			}	    
			}
			header_moves+=(last-last_visit);
		}
	}
	/* same scenario but header is headed toward right*/
	else{
		header_moves+=(last-cur_pos);
		if(request[0]<cur_pos){
			header_moves+=(last-first);
			for(i=0;i<n;i++){
				if(request[i]>cur_pos){
				last_visit=request[i-1];
				break;
			}	    
			}
			header_moves+=(last_visit-first);
		}
	}
		
	printf("\n no of head movements is:\t %d",header_moves);
}
