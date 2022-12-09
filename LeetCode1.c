#include<stdio.h>
void main()
{
    int height[]={10,6,8,5,11,9};
    int number[10];
    int buffer[10];
    int i,j,k;
    int var;
    int a=0;
    int count;
    for(i=0;i<6;i++)
    {
        count=0;
        var=0;
        for(j=i+1;j<6;j++)
        {
           if(height[i]>var && height[j]>var)
           {
               var=height[j];
               count++;
           }
        }
        number[i]=count;
    }
    for(i=0;i<6;i++)
    {
        printf("%d ",number[i]);
    }

}
