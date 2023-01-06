#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode()
 {
 	NODE temp;
 	temp= (NODE)malloc(sizeof(struct node));
 	if(temp==NULL)
    {
    	printf("Memory not allocated");
    	return NULL;
    }
    return temp;
}


NODE concatenate(NODE first, NODE second)
{
    NODE temp=first;
    if(temp==NULL && second==NULL)
    {
        return NULL;
    }
    else if(temp==NULL)
    {
        return second;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=second;
        return first;
    }
}

NODE sort(NODE first)
{   
    int temp;
    NODE second;
    struct node*p=first;
    while(p->next !=NULL)
    {
        if(p==NULL && p->next==NULL)
        {
            return NULL;
        }
        second=p->next;
        while(second!=NULL)
        {
        if(p->value > second->value)
        {
            temp=p->value;
            p->value= second->value;
            second->value=temp;
        }
        second=second->next;
        
        }
        p=p->next;
    }
    return first;
}

NODE reverse(NODE first)
{   
    NODE prev=NULL;
    NODE curr=first;
    NODE next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    first=prev;
    return first;
}


NODE insert_at_beg(int item, NODE first)
{
   NODE new;
   new=getnode();
   new->value=item;
   new->next=NULL;
   if(first==NULL)
   {
   	return new;
   }
   else{
   

    new->next = first;
    first = new;
    return first;
}
}

void display(NODE first)
{
	NODE temp;
	temp=first;
	if(first==NULL)
	{
		printf("List is empty \n");
	}
	while(temp!=NULL)
	{
		printf("%d \n",temp-> value);
		temp= temp->next;
	}
	}

int main()
{
    int n,i,item,ch;
    NODE first=NULL;
    NODE second=NULL;
    while(1)
    {
    printf("1.Concatenate \n 2.Sorting \n 3.Reversing \n 4.Exit \n");
    printf("Enter your choice\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: printf("Enter the number of elements of first linked list");
               scanf("%d",&n);
                for(i=1;i<=n;i++)
                {
                    printf("Enter the element to be inserted \n");
                    scanf("%d",&item);
                    first=insert_at_beg(item,first);
                }
                
                printf("Enter the number of elements of second linked list");
                scanf("%d",&n);
                for(i=1;i<=n;i++)
                {
                    printf("Enter the element to be inserted \n");
                    scanf("%d",&item);
                    first=insert_at_beg(item,first);
                }
                
                first=concatenate(first,second);
                display(first);
                break;

                

        case 2:  printf("Enter the number of elements of linked list");
                scanf("%d",&n);
                for(i=1;i<=n;i++)
                {
                    printf("Enter the element to be inserted \n");
                    scanf("%d",&item);
                    first=insert_at_beg(item,first);
                }
                first=sort(first);
                display(first);       
                break;

        case 3:printf("Enter the number of elements of linked list");
                scanf("%d",&n);
                for(i=1;i<=n;i++)
                {
                    printf("Enter the element to be inserted \n");
                    scanf("%d",&item);
                    first=insert_at_beg(item,first);
                } 
                first=reverse(first); 
                display(first);
                break;

        case 4:exit(0);

        default:printf("Enter correct input value");           


}
}
}
