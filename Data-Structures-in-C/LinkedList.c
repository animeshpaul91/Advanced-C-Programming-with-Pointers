
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//#include<alloc.h>
#include<string.h>
 void insertb();
 void inserte();
 void insertsb(int);
 void insertsa(int);
 void delb();
 void dele();
 int ser(int);
 void dels(int);
 void print();

struct NODE
 { char name[20];
   float wt;
   float r;
   struct NODE *link;
}*start=NULL;

int main()
 { int c,n,p,pos,i,m;
   //clrscr();
    while(1)
    { printf("\n----------------------MENU----------------------\n");
      printf("\n1.Insertion at beginning\n2.Insertion at end");
      printf("\n3.Insertion of a new node before a specified value of the first field of the structure");
      printf("\n4.Insertion of a new node after a specified value of the first field of the structure");
      printf("\n5.Deletion from the begining\n6.Deletion from End\n7.Deletion of a node with specified value of the first field");
      printf("\n8.Searching value\n9.Display of entire list\n10.Exit");
      printf("\n----------------------X--------------------------");
      printf("\nEnter your choice\n");
      scanf("%d",&c);
      switch(c)
      { case 1:
	       printf("\nEnter The Number of nodes to Insert");
	       scanf("%d",&m);
	       for(i=1;i<=m;i++)
	       insertb();
		   break;
       case 2:
	       printf("\nEnter The Number of nodes to Insert");
	       scanf("%d",&m);
	       for(i=1;i<=m;i++)
		   inserte();
		   break;
       case 3:
		  printf("\nEnter the specified weight of the first field before which to insert");
		  scanf("%d",&pos);
		  insertsb(pos);
		  break;
       case 4:
		  printf("\nEnter the specified weight of the first field after which to insert");
		  scanf("%d",&pos);
		  insertsa(pos);
		  break;
       case 5:
		printf("\nEnter The Number of nodes to Delete from beginning");
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		delb();
		   break;
       case 6:
	       printf("\nEnter The Number of nodes to Delete at the end");
	       scanf("%d",&m);
	       for(i=1;i<=m;i++)
	       dele();
	       break;
       case 7:
	       printf("\nEnter the specified weight");
	       scanf("%d",&pos);
	       dels(pos);
	       break;
       case 8:
	       printf("\nEnter wt Number to be searched");
	       scanf("%d",&n);
	       p=ser(n);
	       if(p==-1)
	       printf("\nThe value is not found");
	       else
	       printf("\nThe value is found at=%d position",p);
	       break;
       case 9:
		  printf("\nPrinting..........\n");
	      print();
		  break;
       default:
		   exit(0);
       }
  }
}

void insertb()
 {  struct NODE *temp;
    char name[20];
    float wt,r;
    temp=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\nEnter Material name");
    fflush(stdin);
    gets(name);
    printf("\nEnter weight and Radius");
    scanf("%f%f",&wt,&r);
    strcpy(temp->name,name);
    temp->wt=wt;
    temp->r=r;
    temp->link=start;
    start=temp;
}

void inserte()
{   struct NODE *temp,*p;
    char name[20];
    float wt,r;
    temp=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\nEnter Material name");
    fflush(stdin);
    gets(name);
    printf("\nEnter weight and Radius");
    scanf("%f%f",&wt,&r);
    strcpy(temp->name,name);
    temp->wt=wt;
    temp->r=r;
    p=start;
    while(p->link!=NULL)
    p=p->link;
    p->link=temp;
    temp->link=NULL;
}

void insertsb(int pos)
 {  struct NODE *temp,*p;
    char name[20];
    float r,wt;
    temp=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\nEnter Material name");
    fflush(stdin);
    gets(name);
    printf("\nEnter Weight and Radius");
    scanf("%f%f",&wt,&r);
    strcpy(temp->name,name);
    temp->wt=wt;
    temp->r=r;
    p=start;
    if(p->wt==pos)
    { temp->link=start;
      start=temp;
    }
    else
   {
    while(p->link!=NULL)
    { if(p->link->wt==pos)
      { temp->link=p->link;
	    p->link=temp;
 	    break;
      }
      else
      p=p->link;
    }
    if(p->link==NULL)
    printf("\nInsertion failed. . .Value not present");
}
}

void insertsa(int pos)
{   struct NODE *temp,*p;
    char name[20];
    float r,wt;
    temp=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\nEnter Material name");
    fflush(stdin);
    gets(name);
    printf("\nEnter weight and Radius");
    scanf("%f%f",&wt,&r);
    strcpy(temp->name,name);
    temp->wt=wt;
    temp->r=r;
    p=start;
    while(p!=NULL)
    { if(p->wt==pos)
      { temp->link=p->link;
	   p->link=temp;
	   break;
      }
      else
      p=p->link;
    }
    if(p==NULL)
    printf("\nInsertion failed. . .Value not present");
}

void delb()
{ struct NODE *p;
  p=start;
  start=start->link;
  free(p);
}

void dele()
{ struct NODE *temp,*p;
  temp=start;
  while(temp!=NULL)
  { p=temp;
    temp=temp->link;
    if(temp->link==NULL)
    { p->link=NULL;
      free(temp);
      break;
    }
  }
}

void dels(int pos)
{ struct NODE *temp,*p;
  temp=start;
  if(temp->wt==pos)
  { start=start->link;
    free(temp);
    return;
  }
  else
{
  while(temp!=NULL)
  { p=temp;
    temp=temp->link;
    if(temp->wt==pos)
    { p->link=temp->link;
      free(temp);
      break;
    }
    
  }
  if(temp==NULL)
  printf("\nDeletion Failed. . .Value not present\n");
}
}

int ser(int item)
{ int i=1;
  struct NODE *p;
  p=start;
  while(p!=NULL)
  { if(item==p->wt)
   return(i);
   else
   { p=p->link;
     i++;
   }
  }
  return(-1);
}

void print()
{ struct NODE *a;
  if(start==NULL)
    printf("\nLinked list is Empty");
  else
  { a=start;
    printf("\nNAME\tWEIGHT\tRADIUS");
    while(a!=NULL)
    {  printf("\n%s\t%f\t%f\t",a->name,a->wt,a->r);
     a=a->link;
    }
  }

}

