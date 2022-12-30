#include<stdio.h>
#include<stdlib.h>

struct node{
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

NODE insert_at_front(int item, NODE first)
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

NODE insert_at_end(int item, NODE first)
{
   NODE new, last;
   new=getnode();
   new->value=item;
   new->next=NULL;
   if(first->next ==NULL)
   {
   	first->next =new;
   	return new;
   }
   last=first;
   while(last->next!= NULL)
   {
      last=last->next;
  }
  last->next=new;
  return first;
}

NODE insert_at_pos(int item,NODE first,int pos)
{
	int count=1;
	int val=item;
	NODE new,prev,curr;
	new=getnode();
	new->value=item;
	new->next=NULL;
	curr=first;
	if(first==NULL && pos==1)
	{
		return new;
	}
	while(count!=pos && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
		count++;
	}
	if(count==pos)
	{
		prev->next=new;
		new->next=curr;
		return first;
	}
	if(curr==NULL)
	{
		printf("Position not found\n");
		return first;
	}
	if(first!=NULL && pos==1)
	{
		first=insert_at_front(val,first);
		return first;
	}
	
}
NODE del_beg(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	temp=first;
	temp=temp->next;
	printf("Item deleted =%d",first->value);
	free(first);
	return temp;
	
}
NODE del_end(NODE first)
{
	NODE curr,prev;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	prev=NULL;
	curr=first;
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	printf("%d",curr->value);
	free(curr);
	return first;
}
NODE del_value(NODE first,int key)
{
	NODE prev,curr;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	curr=first;
	if(curr->value==key)
	{
		printf("Item deleted =%d",curr->value);
		first=first->next;
		free(curr);
		return first;
	}
	prev=NULL;
	curr=first;
	while(curr->value!=key && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr->value==key)
	{
		prev->next=curr->next;
		printf("Item deleted=%d",curr->value);
		free(curr);
		return first;
	}
	if(curr==NULL)
	{
		printf("End of list reached and item not found\n");
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
		printf("value stored in the node=%d \n",temp-> value);
		temp= temp->next;
	}
	}

int main()
{
	int pos,item,ch;
	NODE first=NULL;
	while(1)
	{
		printf("1.Insert at the beginning \n 2.Insert at the end \n 3.Insert at a given position \n 4.Delete at the beginning \n 5.Delete at the end \n 6.Delete at a given position\n 7.Display \n");
		printf("Enter your choice \n");
		scanf("%d",&ch);
		switch(ch)
        {
			case 1:printf("Enter the item to be inserted \n");
			        scanf("%d",&item);
			        first= insert_at_front(item,first);
			        break;
			case 2:printf("Enter the item to be inserted \n");
			       scanf("%d",&item);
				   first=insert_at_end(item,first);
				   break;
			case 3:printf("Enter the item to be inserted");
			       scanf("%d",&item);
			       printf("Enter the position");
			       scanf("%d",&pos);
				   first=insert_at_pos(item,first,pos);
				   break;
            case 4:first=del_beg(first);
					break;
			case 5:first=del_end(first);
					break;
			case 6:printf("Enter the item to be deleted :");
				  scanf("%d",&item);
				  first=del_value(first,item);
				  break;             
		    case 7:display(first);
		         	break;
			default:printf("Invalid choice \n");
			        exit(0);	

		}
	}
}
