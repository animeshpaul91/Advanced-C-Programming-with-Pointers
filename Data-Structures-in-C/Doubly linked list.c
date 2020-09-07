#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
#include<stdlib.h>
 void insertb();
 void inserte();
 void inserts();
 void delb();
 void dele();
 void dels();
 int ser(int);
 void print();
 void rev();
 struct node
 { struct node *pre;
   int data;
   struct node *next;
 }*start=NULL;
 void rev1();
 int main()
 { int c,i,n,s,p;
   //clrscr();
  while(1)
   { printf("\n\n.......MENU.....!!!");
     printf("\n\n\n\n1.Insert at Beginning\n2.Insert at End\n3.Insert at any position\n4.Delete at beginning\n5.Delete at end\n6.Delete at any position\n7.Search\n8.Print list\n9.Revert Print list\n10.Revert Nodes\n11.Exit\n\n");
     scanf("%d",&c);
     switch(c)
     { case 1:
	      printf("\nEnter the Number of Nodes");
	      scanf("%d",&n);
	      for(i=1;i<=n;i++)
	      insertb();
	      break;
      case 2:
	      printf("\nEnter the Number of Nodes");
	      scanf("%d",&n);
	      for(i=1;i<=n;i++)
	      inserte();
	      break;
      case 3:
	         inserts();
	          break;
      case 4:
	      printf("\nEnter the Number of Nodes");
	      scanf("%d",&n);
	      for(i=1;i<=n;i++)
	      delb();
	      break;
      case 5:
	      printf("\nEnter the Number of Nodes");
	      scanf("%d",&n);
	      for(i=1;i<=n;i++)
	      dele();
	      break;
      case 6:
	          dels();
	          break;
  case 7:
	  printf("\nEnter the element to be searched");
	  scanf("%d",&s);
	  p=ser(s);
	  if(p==-1)
	  printf("\nThe Element is not found");
	  else
	  printf("\nThe Element is found at=%dth position",p);
	  break;
 case 8:
	  printf("\nPrinting list.......\n");
	  print();
	  break;
 case 9:
        printf("\nReverting List....\n");
        rev();
        break;
 case 10:
      printf("\nReverting Node links....\n");
        rev1();
        break;
         
 default:
	  exit(0);
	  }
}
return 0;
}

void insertb()
{ struct node *temp;
  int data;
  printf("\nEnter the data item");
  scanf("%d",&data);
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  if(start==NULL)
  { temp->pre=NULL;
    temp->next=NULL;
    start=temp;
  }
 else
 { temp->next=start;
   start->pre=temp;
   temp->pre=NULL;
   start=temp;
 }
}

void inserte()
{ struct node *temp,*p;
  int data;
  printf("\nEnter the data item");
  scanf("%d",&data);
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=NULL;
  if(start==NULL)
  { temp->pre=NULL;
    temp->next=NULL;
    start=temp;
  }
  else
  { p=start;
    while(p->next!=NULL)
    p=p->next;
    p->next=temp;
    temp->pre=p;
  }
}


void inserts()
{ struct node *temp,*p;
  int data,pos,i;
  printf("\nEnter the data item");
  scanf("%d",&data);
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  printf("\nEnter The insertion position");
  scanf("%d",&pos);
  p=start;
  for(i=1;i<pos-1;i++)
  p=p->next;
  temp->next=p->next;
  p->next->pre=temp;
  temp->pre=p;
  p->next=temp;
}

void delb()
{ struct node *p;
 if(start==NULL)
  printf("\nLIST UNDERFLOWED");
  else
  { p=start;
    printf("\nDeleted data item=%d",p->data);
      start=start->next;
      start->pre=NULL;
      free(p);
  }
}

void dele()
{ struct node *p;
  if(start==NULL)
  printf("\nLIST UNDERFLOWED");
  else
  { p=start;
    while(p->next!=NULL)
    p=p->next;
    printf("\nDeleted data item=%d",p->data);
    p->pre->next=NULL;
    free(p);
  }
}

void dels()
{ struct node *p,*temp;
  int i,pos;
  if(start==NULL)
  printf("\nLIST UNDERFLOWED");
  else
  { p=start;
    printf("\nEnter the deletion position");
    scanf("%d",&pos);
    for(i=1;i<pos;i++)
    p=p->next;
    temp=p;
    printf("\nDeleted Data item=%d",temp->data);
    p->next->pre=p->pre;
    p->pre=p->next;
    free(temp);
  }
}

int ser(int item)
{ int i=1;
  struct node *p;
  p=start;
  while(p!=NULL)
  { if(item==p->data)
   return(i);
   else
   { p=p->next;
     i++;
   }
  }
  return(-1);
}

void print()
{ struct node *a;
 if(start==NULL)
 printf("\nLIST UNDERFLOWED...\n");
 else
  for(a=start;a!=NULL;a=a->next)
   printf("%d\t",a->data);
}

void rev()
{ struct node *p;
  if(start==NULL)
 printf("\nLIST UNDERFLOWED...\n");
 else
  { for(p=start;p->next!=NULL;p=p->next);
    for(;p!=start;p=p->pre)
    printf("%d\t",p->data);
    printf("%d\t",p->data);
  }
}

void rev1()
{ struct node *p1,*p2,*temp,*p;
  if(start==NULL)
 printf("\nLIST UNDERFLOWED...\n");
 else
 { p1=start;
   p2=p1->next;
   p1->pre=p2;
   p1->next=NULL;
   while(p2!=NULL)
   { temp=p2;
    p2=p2->next;
    temp->pre=p2;
    temp->next=p1;
    p1=temp;
   }
   start=temp;
}
}





    
  

















