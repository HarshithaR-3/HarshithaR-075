/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
//  */

struct ListNode *sort(struct ListNode *list1)
{
    struct ListNode *p=list1;
    struct ListNode *q;
    int temp;
    if(list1==NULL)
    {
        printf("Nothing to display!\n");
        return NULL;
    }
    while(p->next!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
        if(p->val>q->val)//ascending order sorting
        {
            temp=p->val;
            p->val=q->val;
            q->val=temp;
        }
        q=q->next;
        }
        p=p->next;
    }
    return list1;
}

struct ListNode *concatanate(struct ListNode *list1,struct ListNode *list2)
{
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    else
    {
        struct ListNode*p=list1;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=list2;
        return list1;
    }
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
        list1=concatanate(list1,list2);
    list1=sort(list1);
    return list1;
}
 
