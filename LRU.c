#include<stdio.h>
 
int findLRU(int time[], int n){/* function to find least recently used frame position*/
int i, minimum = time[0], pos = 0;
for(i = 1; i < n; ++i){
if(time[i] < minimum){
minimum = time[i];
pos = i;
}
}
return pos;
}

int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
printf("Enter number of frames: ");
scanf("%d", &no_of_frames);
printf("Enter number of pages: ");
scanf("%d", &no_of_pages);
printf("Enter reference string: ");  /* sequence of pages to be accessed */
    for(i = 0; i < no_of_pages; ++i){
     scanf("%d", &pages[i]);
    }
    
for(i = 0; i < no_of_frames; ++i){// intially load all frames with -1
     frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){ // set flags to 0
     flag1 = flag2 = 0;
    
     for(j = 0; j < no_of_frames; ++j){  /* check whether particular page is 
     already available, if founds increment its hit*/ 
	 if(frames[j] == pages[i]){
     counter++;
     time[j] = counter;
   flag1 = flag2 = 1;   // forbids execution of next 2 loops
    break;
   }
     }
    
     if(flag1 == 0){   // take page to the frame if any frame is free
for(j = 0; j < no_of_frames; ++j){
     if(frames[j] == -1){
     counter++;
     faults++;
     frames[j] = pages[i];
     time[j] = counter;
     flag2 = 1; // forbids execution of next loop
     break;
     }
     }
     }
    
     if(flag2 == 0){ // finds least recently used page and replaces it 
     pos = findLRU(time, no_of_frames); // function returns position of LRU page 
     counter++;
     faults++;
     frames[pos] = pages[i];
     time[pos] = counter;
     }
    
     printf("\n");

     for(j = 0; j < no_of_frames; ++j){
     printf("%d\t", frames[j]);
     }
}
printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}
