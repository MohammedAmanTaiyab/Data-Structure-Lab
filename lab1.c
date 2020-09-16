#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct student
{
    int marks,age,flag;
    
}stu1;

void main()

{
    struct student stu1;
    printf("Enter student details\n");
    printf("Age: \n");
    scanf("%d",&stu1.age);
    printf("Marks: \n");
     scanf("%d",&stu1.marks);
    
    if(stu1.marks>=0&&stu1.age>20&&stu1.marks<=100)
    {
        printf("student details identified for admission\n");
        printf("Age: %d\n",stu1.age);
        printf("Marks: %d\n",stu1.marks);
        if(stu1.marks>=65)
        {
             printf("Student has been qualified for admission with marks: %d",stu1.marks);
        }
    }
     
}