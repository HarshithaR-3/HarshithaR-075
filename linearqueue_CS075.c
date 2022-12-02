#include <stdio.h>
#include <stdlib.h>
#define qsize 3

void insert_rear(int q[], int item, int *r)
{
    if(*r == qsize-1)
     printf("Queue overflow\n");
    else
    {
        (*r)++;
        q[*r]=item;
    }
}

int delete_front(int q[], int*f, int*r)
{
    if((*f)>(*r))
      printf("Queue underflow\n");
    else
      return q[(*f)++];
} 

void display(int q[], int *f, int *r)
{
    int i;
    if(*f>*r)
     printf("Queue is empty\n");
    else
    {
        for(i=*f; i<=*r;i++)
        printf("%d \n", q[i]);
    }
}

 int main()
 {
     int q[qsize],r=-1,f=0,item,del;
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
              insert_rear(q,item,&r);
              break;
        case 2:del=delete_front(q,&f,&r);
              printf("The deleted element is %d:\n",del);
               break;
        case 3:display(q,&f,&r);
              break;
        case 4:exit(0);
               break;
        default:printf("Enter the correct value\n");
     }       
     }
    
}
