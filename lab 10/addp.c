#include <stdio.h>
#include <stdlib.h>
struct node{
	int coeff;
	int px;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(NODE));
if(x==NULL)
{
printf("out of memory\n");
exit(0);
}
return x;
}
NODE insert(NODE first,int c,int px)
{
	NODE temp=getnode(),cur,prev;
	temp->coeff=c;
	temp->px=px;
	if(first==NULL)
	{
		first=temp;
		return first;
	}
	if(px>first->px)
	{
		temp->link=first;
		return temp;
	}
	cur=first;
	prev=NULL;
	while(cur!=NULL&&px<cur->px)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=temp;
	temp->link=cur;
	return first;
}

NODE addp(NODE first1,NODE first2,NODE first3)
{
	
	NODE temp1=first1,temp2=first2;
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->px==temp2->px)
		{
			first3 = insert(first3,(temp1->coeff+temp2->coeff),temp1->px);
			temp1=temp1->link;
			temp2=temp2->link;
		}
		else
		{
			if(temp1->px>temp2->px)
			{
				first3 = insert(first3,temp1->coeff,temp1->px);
				temp1=temp1->link;
			}
			else
			{
				first3 = insert(first3,temp2->coeff,temp2->px);
				temp2=temp2->link;
			}
		}
	}
	while(temp1!=NULL)
	{
		first3=insert(first3,temp1->coeff,temp1->px);
		temp1=temp1->link;
	}
	while(temp2!=NULL)
	{
		first3=insert(first3,temp2->coeff,temp2->px);
		temp2=temp2->link;
	}
	return first3;
}

void display(NODE first)
{
	NODE temp=first;
	while(temp!=NULL)
	{
		printf("%dx^%d + ",temp->coeff,temp->px);
		temp=temp->link;
	}
}
		
int main()
{
	NODE first1=NULL;
	NODE first2=NULL;
	NODE first3=NULL;
	printf("Enter first polynomial \n");
	int ch,c,px;
	while(ch!=2)
	{
		printf("1.Enter term\n2.Stop\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter coefficient\n");
			scanf("%d",&c);
			printf("Enter power\n");
			scanf("%d",&px);
			first1=insert(first1,c,px);
		}
	}
	ch=0;
	printf("Enter second polynomial \n");
	while(ch!=2)
	{
		printf("1.Enter term\n2.Stop\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter coefficient\n");
			scanf("%d",&c);
			printf("Enter power\n");
			scanf("%d",&px);
			first2=insert(first2,c,px);
		}
	}
	printf("\nFirst polynomial\n");
	display(first1);
	printf("\nSecond polynomial\n");
	display(first2);
	printf("\nResult:\n");
	first3=addp(first1,first2,first3);
	display(first3);
	return 0;
}