#include <stdio.h>
#define STACK_SIZE 5
void push(int *item,int s[],int *top);
int pop(int s[],int *top);
void display(int *top,int s[]);

int main()
{
    int top = -1;
    int item,s[10],item_deleted,choice;
    while(1)
    {
        
        printf("\n1:push\n2:pop\n3:display\n4:exit\nenter choice :\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the item to be inserted\n");
            scanf("%d",&item);
            push(&item,s,&top);
            break;
            case 2:item_deleted=pop(s,&top);
            if(item_deleted!=-1)
            {
            printf("\nitem deleted is %d \n",item_deleted);
            top--;
			}
            break;
            case 3 : display(&top,s);
            break;
            default : return 0;
        }
		
    }
    return 0;
}
    
void push(int *item,int s[],int *top)
{
    if(*top==STACK_SIZE-1)
    {
        printf("\nStack overflow\n");
        return;
    }
    (*top)++;
    s[*top]=*item;
    
}

int pop(int s[],int *top)
{
    int item_deleted;
    if(*top==-1)
    {
        printf("\nStack underflow \n");
        return -1;
    }

    item_deleted = s[*top];
    return item_deleted;

}
void display(int *top,int s[])
{
    if(*top==-1)
    {
        printf("\nstack is empty\n");
        return;
        
    }
    printf("\nContents of the stack \n");
    for(int i=*top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
}