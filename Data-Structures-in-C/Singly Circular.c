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
 struct node
 { int data;
  struct node *next;
}*start=NULL;

          
int main()
 { int c,i,n,s,p;
   //clrscr();
  while(1)
   { printf("\nMENU.....****!!!");
     printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at any position\n4.Delete at beginning\n5.Delete at end\n6.Delete at any position\n7.Search\n8.Print list\n9.Exit\n");
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
 default:
	  exit(0);
	  }
}
return 0;
}

void insertb()
 {struct node *temp,*p;
  int data;
  printf("\nEnter the data item");
  scanf("%d",&data);
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  if(start==NULL)
  { temp->next=temp;
    start=temp;
  }
  else
  { p=start;
    while(p->next!=start)
    p=p->next;
    temp->next=start;
    p->next=temp;
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
  if(start==NULL)
  { temp->next=temp;
    start=temp;
  }
  else
  { p=start;
    while(p->next!=start)
    p=p->next;
    p->next=temp;
    temp->next=start;
  }
}

void inserts()
{ struct node *temp,*p;
  int data,i,pos;
  printf("\nEnter the data item");
  scanf("%d",&data);
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  printf("\nEnter the insertion position");
  scanf("%d",&pos);
  p=start;
  for(i=1;i<pos-1;i++)
  p=p->next;
  temp->next=p->next;
  p->next=temp;
}

void delb()
{ struct node *temp,*p;
  if(start==NULL)
  printf("\nList Underflowed");
  else
  {p=start;
  while(p->next!=start)
  p=p->next;
  p->next=start->next;
  temp=start;
  printf("\nDeleted data item=%d",start->data);
  start=start->next;
  free(temp);
 }
}

void dele()
{ struct node *temp,*p;
 if(start==NULL)
  printf("\nList Underflowed");
  else
 {p=start;
 while(p->next!=start)
 { temp=p;
  p=p->next;
 }
 temp->next=start;
 printf("\nDeleted data item=%d",p->data);
 free(p);
}
}

void dels()
{ struct node *temp,*p;
  int i,pos;
  if(start==NULL)
  printf("\nList Underflowed");
  else
  {printf("\nEnter the deletion position");
  scanf("%d",&pos);
  p=start;
  for(i=1;i<pos;i++)
  { temp=p;
   p=p->next;
  }
  printf("\nDeleted data item=%d",p->data); 
  temp->next=p->next;
  free(p);
}
}

int ser(int item)
{ int i=1;
  struct node *p;
  p=start;
  while(p->next!=start)
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
  for(a=start;a->next!=start;a=a->next)
   printf("%d\t",a->data);
}


  
  
  

  
  
  


  
  

  

