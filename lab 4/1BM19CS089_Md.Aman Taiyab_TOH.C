#include<stdio.h>
void towers(int n,char src,char temp,char dest)
{

    if(n==1)
    {
        printf("Move disk 1 from %c to %c",src,dest);
        return ;
    }
    towers(n-1,src,dest,temp);
    printf("\nMove disk %d from %c to %c\n",n,src,dest);
    towers(n-1,temp,src,dest);
}
void main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    towers(n,'S','T','D');
}
