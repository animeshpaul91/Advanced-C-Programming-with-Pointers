#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{ int coeff,expo;
 struct node *next;
}*start1=NULL,*start2=NULL,*start3=NULL;
struct node *insert(struct node *);
struct node *print(struct node *);
struct node *add(struct node *,struct node *,struct node *); 
struct node *diff(struct node *,struct node *,struct node *); 
struct node *new1(struct node*,int,int);
int main()
{ int i,c,n;
//clrscr();
while(1)
{ printf("\n\n\n\n....MENU.......");
printf("\n1.Insert poly1\n2.Print poly1\n3.Insert Poly 2\n4.Print poly2\n5.Add\n6.Display result\n7Subtract\n8.EXIT");
printf("\nEnter choice");
scanf("%d",&c);
switch(c)
{ case 1:
	 printf("\nEnter the number of terms");
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
	  start1=insert(start1);
	  break;
  case 2:
	 printf("\n\n\n");
	 start1=print(start1);
	 break;
  case 3:
	 printf("\nEnter the Number of terms");
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
	  start2=insert(start2);
	  break;
  case 4:
	 printf("\n\n\n");
	start2=print(start2);
	 break;
  case 5:
	 start3=add(start1,start2,start3);
	 break;
  case 6:
	 printf("\n\n\n");
	 start3=print(start3);
	 break;
 case 7:
        start3=diff(start1,start2,start3);
        break;
 case 8:
         exit(0);
  default:
	       printf("\n\nWrong Option Entered\n\n\n");
}
}
//return 0;
}

struct node *insert(struct node *start)
{ struct node *temp,*p;
  int e,c;
   printf("\nEnter the coefficient and exponent");
   scanf("%d%d",&c,&e);
   temp=(struct node *)malloc(sizeof(struct node));
   temp->coeff=c;
   temp->expo=e;
   temp->next=NULL;
   if(start==NULL)
   start=temp;
   else
   { p=start;
     while(p->next!=NULL)
     p=p->next;
     p->next=temp;
     }
   return start;
}

struct node *print(struct node *start)
{ struct node *p;
  p=start;
  while(p!=NULL)
  { printf("\t%dx^%d",p->coeff,p->expo);
    p=p->next;
  }
  return start;
}

struct node *add(struct node *start1,struct node *start2,struct node *start3)
{ struct node *p1,*p2;
  int sum,c;
  p1=start1;
  p2=start2;
  while(p1->next!=NULL||p2->next!=NULL)
  { if(p1->expo==p2->expo)
    { sum=p1->coeff+p2->coeff;
      start3=new1(start3,sum,p1->expo);
      p1=p1->next;
      p2=p2->next;
    }
    else if(p1->expo>p2->expo)
    { start3=new1(start3,p1->coeff,p1->expo);
      p1=p1->next;
    }
    else if(p2->expo>p1->expo)
    { start3=new1(start3,p2->coeff,p2->expo);
      p2=p2->next;
    }
  }
  if(p1->next==NULL)
  { while(p2->next!=NULL)
     { start3=new1(start3,p2->coeff,p2->expo);
        p2=p2->next;
     }
  }
  
  if(p2->next==NULL)
  { while(p1->next!=NULL)
     { start3=new1(start3,p1->coeff,p1->expo);
       p1=p1->next;
       }
  }
  
return start3;
}

struct node *diff(struct node *start1,struct node *start2,struct node *start3)
{ struct node *p1,*p2;
  int dif,c;
  p1=start1;
  p2=start2;
  while(p1->next!=NULL||p2->next!=NULL)
  { if(p1->expo==p2->expo)
    { if(p1->coeff>p2->coeff)
      dif=p1->coeff-p2->coeff;
      else
      dif=p2->coeff-p1->coeff;
      start3=new1(start3,dif,p1->expo);
      p1=p1->next;
      p2=p2->next;
    }
    else if(p1->expo>p2->expo)
    { start3=new1(start3,p1->coeff,p1->expo);
      p1=p1->next;
    }
    else if(p2->expo>p1->expo)
    { start3=new1(start3,p2->coeff,p2->expo);
      p2=p2->next;
    }
  }
  if(p1->next==NULL)
  { while(p2->next!=NULL)
     { start3=new1(start3,p2->coeff,p2->expo);
       p2=p2->next;
       }
  }
  
  if(p2->next==NULL)
  { while(p1->next!=NULL)
     { start3=new1(start3,p1->coeff,p1->expo);
       p1=p1->next;
       }
  }
  
return start3;
}

struct node *new1(struct node *start,int n,int c)
{ struct node *temp,*p;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->coeff=n;
 temp->expo=c;
 temp->next=NULL;
 if(start==NULL)
 start=temp;
 else
 {p=start;
  while(p->next!=NULL)
  p=p->next;
  p->next=temp;
}
return start;
}
       

    

    
  
         
         
          
         
 
 
