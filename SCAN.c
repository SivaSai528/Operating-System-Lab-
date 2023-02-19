#include<stdio.h>
int main(){
	int n,header_moves,first,last,cur_pos,direction;
	printf("enter first cylinder number:");
	scanf("%d",&first);
	printf("enter last cylinder number");
	scanf("%d",&last);
	printf("Enter current position of header");
	scanf("%d",&cur_pos);
	printf("Enter direction 0->left 1->right"); 
	                           /* current direction of header*/
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
	
	/* if header is headed toward left go to first cylinder and after that 
	check whether all requests are serviced or not 
	ex: if the sequence is 5 7 8 23 70 
	                    header at 80 & direction is left
			if it reaches first cylinder now it means it serviced all the requests
	
	    if the sequence is 5 7 8 23 70
		                header is at 50 & direction is left
			now if it reaches first cylinder from 50 still it need to cover other requests
	
	If it unable to cover any one request it will start from that first cylinder and 
	reaches last cylinder in the request[] array.
	*/

	if(direction==0){          
		header_moves+=(cur_pos-first);// moving toward first cylinder 
		if(request[n-1]>cur_pos){  // check if there are any un covered cylinders in the request
			header_moves+=(request[n-1]-first);
		}
	}
	
	/* same as above but header is headed toward right
	header first reaches last cylinder and check whether all the requests are
	serviced or not*/
	
	else{
		header_moves+=(last-cur_pos);
		if(request[0]<cur_pos){
			header_moves+=(last-request[0]);
		}
	}
		
	printf("\n no of head movements is:\t %d",header_moves);
}
