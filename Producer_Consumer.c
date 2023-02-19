#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty,n, x=0;
int in=0,out=0;
int p[100];
void producer(int produce)
{
	--mutex;
	++full;
	--empty;
    p[in]=produce;
	in=(in+1)% n;
	printf("\nProducer produces item %d",produce);
	++mutex;
}
void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumes item %d",p[out]);
	out=(out+1)%n;
	++mutex;
}

int main()
{
	int z, i,produce;
    printf("Enter Buffer size: ");
    scanf("%d",&n);
    int p[n];
    empty=n;
	printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit");
	for (i = 1; i > 0; i++) {

		printf("\nEnter your choice:");
		scanf("%d", &z);
		switch (z) {
		case 1:
			if ((mutex == 1) && (empty != 0)) {
                printf("enter the value=");
				scanf ("%d",&produce);
				producer(produce);
			}
			else {
				printf("Buffer is full!");
			}
			break;
		case 2:
			if ((mutex == 1) && (full != 0)) {
				consumer();
			}
			else {
				printf("Buffer is empty!");
			}
			break;
		case 3:
			exit(0);
			break;
		}
	}
}
