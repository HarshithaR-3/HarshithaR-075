#include <stdio.h>
#include <stdlib.h>
#define stack_size 5
int st[10],top=-1,item;


void push()
{
 if(top==stack_size)
   printf("Stack overflow \n");
 else
 {
   top++;
   st[top]=item;
 }
}

int pop()
{
  int del_item;
  if(top==-1)
    printf("Stack Underflow \n");
  else
  {
   del_item=st[top];
   top--;
   return del_item;
  }
}

void display()
{
 int i;
 if(top==-1)
   printf("Stack is empty\n");
 for(i=0;i<=top;i++)
   printf("%d \n",st[i]);
 }

 int main()
 {
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
              push();
              break;
        case 2:printf("The element deleted is %d:\n",pop());
              break;
        case 3:display();
              break;
        case 4:exit(0);
               break;
        default:printf("Enter the correct value\n");
     }       
     }
 }
 