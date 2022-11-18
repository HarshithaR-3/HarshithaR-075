
#include <stdio.h>
#include <stdlib.h>
#define stack_size 10



int push(int st[], int *top, int item)
{
 if(*top==stack_size-1)
   printf("Stack overflow \n");
 else
 {
   (*top)++;
   st[*top]=item;
 }
}

int pop(int st[], int *top)
{
    int del_item;
   if(*top==-1)
    printf("Stack Underflow \n");
  else
  {
   del_item=st[*top];
   (*top)--;
   return del_item;
  } 
}

void display(int st[],int *top)
{
 int i;
 if(*top==-1)
   printf("Stack is empty\n");
 for(i=0;i<=*top;i++)
   printf("%d \n",st[i]);
 }

 int main()
 {
     int st[stack_size],top=-1,item,del_item;
     int n;
     while(1)
     {
     printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
     printf("Enter your choice:\n");
     scanf("%d",&n);
     switch(n)
     {
        case 1:printf("Enter the element to be inserted\n");
              scanf("%d",&item);
              push(st, &top, item);
              break;
        case 2:del_item=pop(st,&top);
               printf("The element deleted is %d:\n",del_item);
              break;
        case 3:display(st, &top);
              break;
        case 4:exit(0);
               break;
        default:printf("Enter the correct value\n");
     }       
     }
 }
