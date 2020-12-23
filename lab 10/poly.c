#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
	float cf;
	float px;
	float py;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if (x==NULL)
	{
		printf("Memory full\n");
		exit(0);
	}
	return x;
}
NODE insert_rear(float cf,float x,float y,NODE first)
{
	NODE temp,cur;
	temp=getnode();
	temp->cf=cf;
	temp->px=x;
	temp->py=y;
	temp->link=NULL;
	if (first==NULL)
	{
		return temp;
	}
	cur=first;
	while (cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	return first;
}
NODE read_poly(NODE first)
{
	int i;
	float cf,px,py;
	printf("Enter -999 to end the polynomial:\n");
	for (i=1;;i++)
	{
		printf("Enter %d term:\n",i);
		printf("Coefficient:\n");
		scanf("%f",&cf);
		if (cf==-999)
		{
			break;
		}
		printf("Power of x:\n");
		scanf("%f",&px);
		printf("Power of y:\n");
		scanf("%f",&py);
		first=insert_rear(cf,px,py,first);
	}
	return first;
}
float evaluate_polynomial(NODE first)
{
	float x,y,sum=0;
	NODE polynomial;
	printf("Enter the values of x and y:\n");
	scanf("%f%f",&x,&y);
	polynomial=first;
	while (polynomial!=NULL)
	{
		sum=sum+polynomial->cf*pow(x,polynomial->px)*pow(y,polynomial->py);
		polynomial=polynomial->link;
	}
	return sum;
}
void display(NODE first)
{
	NODE temp;
	if (first==NULL)
	{
		printf("Polynomial does not exist\n");
	}
	else
	{
		temp=first;
		while (temp->link!=NULL)
		{
			printf("(%5.2fx^%3.2fy^%3.2f)\t+",temp->cf,temp->px,temp->py);
			temp=temp->link;
		}
		printf("(%5.2fx^%3.2fy^%3.2f)\n",temp->cf,temp->px,temp->py);
    }
}
int main(){
    NODE first;
    float res;
    first=NULL;
    printf("Enter the polynomial: \n");
    first = read_poly(first);
    res = evaluate_polynomial(first);
    printf("Polynomial is: \n");
    display(first);
    printf("Result is %f\n",res);
}