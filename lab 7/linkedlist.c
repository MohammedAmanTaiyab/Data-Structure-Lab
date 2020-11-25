#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(NODE));//
	if(x==NULL)
	{
		printf("memory full \n");
		exit(0);
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

NODE insert_front(NODE first,int item)
{
	NODE temp = getnode();
	temp->info = item;
	temp->link = NULL;
	if(first == NULL)
	return temp;
	temp->link=first;
	return temp;
}

NODE delete_front(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("List is empty\n");
		return first;
	}
	printf("Item deleted %d",(first->info));
	temp = first;
	temp=temp->link;
	free(first);
	return temp;
}

NODE insert_rear(NODE first,int item)
{
	NODE temp = getnode(),cur;
	temp->info=item;
	temp->link = NULL;
	if(first==NULL)
	return temp;
	cur=first;
	while(cur->link!=NULL)
	cur=cur->link;
	cur->link=temp;
	return first;
}

NODE delete_rear(NODE first)
{
	NODE cur=first,prev=NULL;
	if(first==NULL)
	{
		printf("List empty\n");
		return NULL;
	}	
	if(first->link==NULL)
	{
		printf("item deleted is %d\n",first->info);
		free(first);
		return NULL;
	}
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("Item deleted is %d\n",(cur->info));
	free(cur);
	prev->link=NULL;
	return first;
}

void display(NODE first)
{
	if(first==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("Elements of the list are : \n");
	for(NODE i=first;i!=NULL;i=i->link)
	printf("%d\n",i->info);
}
int main()
{
	int item,ch;
	NODE first=NULL;
	for(;;)
	{
		printf("\n\n1.Insert front\n2.Delete front\n3.Insert rear\n4.delete rear\n5.display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted\n");
				scanf("%d",&item);
				first = insert_front(first,item);
				break;
			case 2:
				first = delete_front(first);
				break;
			case 3:
				printf("Enter element to be inserted\n");
				scanf("%d",&item);
				first = insert_rear(first,item);
				break;
			case 4:
				first = delete_rear(first);
				break;
			case 5:
				display(first);
				break;
			default:return 0;
		}
	}
}