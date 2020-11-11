#include <stdio.h>
#define size 3
int pq[size],front=0,rear=-1;

void insertionsort(int n)
{
	int j=rear;
	while(pq[j]>n&&j>=0)
	{
	  pq[j+1]=pq[j];
	  j--;
	}
	pq[++j]=n;
}
	  
void insertpq(int n)
{
	if(rear==size-1)
	{
		printf("\nQueue overflow\n");
		return;
	}
	if(rear<front)
	{
		rear=0;
		front=0;
		pq[rear]=n;
		return;
	}
	insertionsort(n);
	rear++;
	
}	
void deletepq()
{
	if(front>rear)
	{
		printf("\nQueue underflow\n");
		front=0;
		rear=-1;
		return;
	}
	printf("\nElement deleted is %d\n",pq[front++]);
}
void displaypq()
{
	if(front>rear)
	{
		printf("\nQueue empty\n");
		front=0;
		rear=-1;
		return;
	}
	printf("\nQueue: \n");
	for(int i=front;i<=rear;i++)
	printf("%d ",pq[i]);
	
	printf("\n");
}
int main()
{
	int ch,n;
	for(;;)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter element to be inserted ");
					scanf("%d",&n);
					insertpq(n);
			break;
			
			case 2: deletepq();
			break;
			case 3: displaypq();
			break;
			case 4: return 0;
		}
	}
}	
	