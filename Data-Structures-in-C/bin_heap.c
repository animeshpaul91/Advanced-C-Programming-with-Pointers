#include<stdio.h>
#include<stdlib.h>
#define infinite 9999
#define max 100
int dispaly(int a[],int );
void insert_heap(int a[],int *);
void delete_heap(int a[],int *);
void create_heap(int a[],int *);
void restore_up(int a[],int );
void restore_down(int a[],int,int);
int main()
{
    int heap[max],h_size=0;
    int n,item,i,choice,p;
    while(1)
    {
    printf("waht you want to do \n enter 1 for creation of heap. \n 2 for insertion in heap.\n 3 for deletion from heap. \n 4 for display.\n 5 for exit from this operation. \n enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        create_heap(heap,&h_size);
        break;
    case 2:
        insert_heap(heap,&h_size);
        break;
    case 3:
        delete_heap(heap,&h_size);
        break;
    case 4:
        p=display(heap,h_size);
        break;
    case 5:
        exit(1);
        break;
    default:
        printf("wrong choice .\n");
        break;
    }// end of switch
}//end of while
return 0;
}//end of main

void restore_up(int a[],int n)
{
    int i=n,par=i/2,k=a[i];
    while(k>a[par])
          {
              a[i]=a[par];
                i=par;
                par=i/2;
          }
          a[i]=k;
}// end of restore_up function
void restore_down(int a[],int n,int h_size)
{
    int i=n,lchild=2*i,rchild=2*i+1,k=a[i];
    while(rchild<=h_size)
    {
        if(k>a[lchild]&&k>a[rchild])
           {
               a[i]=k;
               return;
            }
        else if(a[lchild]>a[rchild])
        {
          a[i]=a[lchild];
          i=lchild;
        }
        else
        {
            a[i]=a[rchild];
            i=rchild;
        }
        lchild=2*i;
        rchild=2*i+1;
    }
    if(lchild==k<a[lchild])
    {
        a[i]=a[lchild];
        i=lchild;
    }
    a[i]=k;
}// end of restore down
void create_heap(int a[],int *ph_size)
{
    int n,i,k;
    printf("\nhow many item you want to store in your heap : ");
     scanf("%d",&n);
     *ph_size=n;
     a[0]=infinite;
     for(i=1;i<=n;i++)
     scanf("%d",&a[i]);
     for(i=2;i<=n;i++)
        restore_up(a,i);
}// end of create_heap function
void insert_heap(int a[],int *ph_size)
{
    int item,k;
    if(*ph_size==max)
    {
        printf("enter is not possible.\n");
        return;
    }
    (*ph_size)++;
    printf("enter the item you want to insert : ");
    scanf("%d",&item);
    a[*ph_size]=item;
    restore_up(a,*ph_size);
}// end of insert_heap function
void delete_heap(int a[],int *ph_size)
{
    int item,i;
    if(*ph_size==0)
    {
        printf("deletion is not possible because heap is empty.\n");
        return ;
    }
    printf("enter the item you wanty to delete : ");
    scanf("%d",&item);
    i=1;
    while(a[i]!=item)
        i++;
    if(i>*ph_size)
    {
        printf("the item you have entered is not found in the heap.\n");
        return;
    }
    a[i]=a[*ph_size];
    (*ph_size)--;
    if(a[i]>a[i/2])
        restore_up(a,i);
    else
        restore_down(a,i,*ph_size);
}// end of delete_heap function

int display(int a[],int h_size)
{
    int i;
    if(h_size==0)
    {
        printf("heap is empty.\n");
        return 0;
    }
    for(i=1;i<=h_size;i++)
        printf("%d\n",a[i]);
        return 0;
}// end of display











