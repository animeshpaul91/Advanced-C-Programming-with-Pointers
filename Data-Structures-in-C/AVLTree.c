#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//#include<alloc.h>
 typedef enum{FALSE,TRUE}bool;
 struct node
 { int val,balance;
   struct node *left,*right;
};
struct node *search(struct node *ptr,int data)
{ if(ptr!=NULL)
   if(data<ptr->val)
    ptr=search(ptr->left,data);
   else if(data>ptr->val)
   ptr=search(ptr->right,data);
  return(ptr);
}
struct node *insert(int data,struct node *ptr,int *hc)
{ struct node *aptr,*bptr;
    if(ptr==NULL)
      { ptr=(struct node *)malloc(sizeof(struct node));
        ptr->val=data;
        ptr->left=NULL;
        ptr->right=NULL;
        ptr->balance=0;
        *hc=TRUE;
        return(ptr);
      }
    if(data<ptr->val)
    { ptr->left=insert(data,ptr->left,hc);
      if(*hc==TRUE)
      { switch(ptr->balance)
        { case -1:
                  /* Right heavy */
                  ptr->balance=0;
                  *hc=FALSE;
                  break;
          case 0:
                  /* Balanced tree */
                  ptr->balance=1;
                  break;
          case 1:
                  /* Left heavy */
                  aptr=ptr->left;
                  if(aptr->balance==1)
                  { printf("\nLeft to Left Rotation Performed\n\n");
                    ptr->left=aptr->right;
                    aptr->right=ptr;
                    ptr->balance=0;
                    aptr->balance=0;
                    ptr=aptr;
                  }
                  else
                  { printf("\nLeft to Right Rotation Performed\n\n");
                    bptr=aptr->right;
                    aptr->right=bptr->left;
                    bptr->left=aptr;
                    ptr->left=bptr->right;
                    bptr->right=ptr;
                    if(bptr->balance==1)
                    ptr->balance=-1;
                    else
                    ptr->balance=0;
                    if(bptr->balance==-1)
                    aptr->balance=1;
                    else
                     aptr->balance=0;
                    bptr->balance=0;
                    ptr=bptr;
                  }
                  *hc=FALSE;
               }
             }
          }
     
      if(data>ptr->val)
      { ptr->right=insert(data,ptr->right,hc);
        if(*hc==TRUE)
        { switch(ptr->balance)
          { case 1:
                   /* Left Heavy */
                   ptr->balance=0;
                   *hc=FALSE;
                   break;
            case 0:
                   /* Balanced tree */
                   ptr->balance=-1;
                   break;
            case -1:
                     /* Right Heavy */
                     aptr=ptr->right;
                     if(aptr->balance==-1)
                     { printf("\nRight to Right Rotation Performed\n\n");
                       ptr->right=aptr->left;
                       aptr->left=ptr;
                       ptr->balance=0;
                       aptr->balance=0;
                       ptr=aptr;
                     }
                     else
                     { printf("\nRight to Left Rotation Performed\n\n");
                       bptr=aptr->left;
                       aptr->left=bptr->right;
                       bptr->right=aptr;
                       ptr->right=bptr->left;
                       bptr->left=ptr;
                       if(bptr->balance==-1)
                        ptr->balance=1;
                       else
                        ptr->balance=0;
                       if(bptr->balance==1)
                        aptr->balance=-1;
                       else
                        aptr->balance=0;
                       bptr->balance=0;
                       ptr=bptr;
                     } /* End of else */
                    *hc=FALSE;
                 }
              }
          }
    return(ptr);
    
}

void display(struct node *ptr,int level)
{ int i;
  if(ptr!=NULL)
  { display(ptr->right,level+1);
    printf("\n");
    for(i=0;i<level;i++)
      printf(" ");
     printf("%d\t",ptr->val);
    display(ptr->left,level+1);
  }
  
}

void inorder(struct node *ptr)
{ if(ptr!=NULL)
  { inorder(ptr->left);
    printf("%d\t",ptr->val);
    inorder(ptr->right);
  }
}
  
void pre(struct node *tree)
{
  if(tree!=NULL)
  { printf("%d\t",tree->val);
    pre(tree->left);
    pre(tree->right);
  }
}

void post(struct node *tree)
{
 if(tree!=NULL)
  { post(tree->left);
    post(tree->right);
    printf("%d\t",tree->val);
  }
}

void lev(struct node *tree)
{ struct node *queue[100],*ptr;
  int r=0,f=0;
  if(tree==NULL)
  printf("\nThe Entire tree is Empty\n");
  else
  { queue[r]=tree;
    while(f<=r)
    { ptr=queue[f++];
      if(ptr!=NULL)
      { printf("%d\t",ptr->val);
	queue[++r]=ptr->left;
	queue[++r]=ptr->right;
      }
    }
  }
}

struct node *del(struct node *root,int item)
{
   struct node *ptr=root;
   struct node *child,*succ,*par_succ;
   struct node*par=NULL;
   struct node *temp;
    while(ptr!=NULL)
    {
        if(ptr->val==item)
         break;
         par=ptr;
          if(ptr->val<item)
         ptr=ptr->right;
         else
            ptr=ptr->left;
    }
    if(ptr==NULL)
        printf("item not found .\n");
        temp=ptr;
        //if the node ptr have two child
     if(ptr->left!=NULL&&ptr->right!=NULL)
    {
        succ=ptr->right;
        par_succ=ptr;
        while(succ->left!=NULL)
        {
            par_succ=succ;
            succ=succ->left;
        }
        ptr->val=succ->val;
        ptr=succ;
        par=par_succ;
    }
    /*if node ptr have only one child*/
    if((ptr->left!=NULL&&ptr->right==NULL)||(ptr->left==NULL&&ptr->right!=NULL))
    {
        if(ptr->left==NULL)
            child=ptr->right;
        else
            child=ptr->left;
        if(par==NULL)
            root=child;
        else if(par->left==ptr)
            par->left=child;
        else
            par->right=child;
    }
    //if the node ptr have no child
    else
    {
       if(par==NULL)
        root=NULL;
       else if(par->left==ptr)
        par->left=NULL;
       else
        par->right=NULL;
       free(ptr);
    }
     return root;
}// end of delete _ node


int main()
 { bool ht;
   int data,c,i,n;
   struct node *root=(struct node *)malloc(sizeof(struct node));
   struct node *p;
   root=NULL;
   while(1)
   { printf("\n\n\n*************MENU****************\n\n");
     printf("\n\t1.Insert\n\t2.Display\n\t3.Search an Element\n\t4.Delete an Element\n\t5.Quit\n");
     printf("\n***********************************\n");
     printf("\nEnter your choice");
     scanf("%d",&c);
     switch(c)
     { case 1: 
              printf("\nEnter the Number of Nodes you want to insert");
              scanf("%d",&n);
              for(i=1;i<=n;i++)
              {printf("\nEnter the Item Number:-%d\t",i);
               scanf("%d",&data);
               if(search(root,data)==NULL)
               root=insert(data,root,&ht);
               else
                printf("\nDuplicate Value Ignored\n");
              }
              break;
       case 2:
              if(root==NULL)
              { printf("\nTree is Empty\n");
                continue;
              }
              printf("\n\nTree in the Descending Order is:\n");
              display(root,1);
              printf("\n\nAfter Performing All the Required Rotations\n\n\n");
              printf("\nIn Order Traversal is:\n\n");
              inorder(root);
              printf("\n\n\nPre Order Traversal is:\n\n");
              pre(root);
              printf("\n\n\nPost Order Traversal is:\n\n");
              post(root);
              printf("\n\n\nLevel Order Traversal is:\n\n");
              lev(root);
              break;
       case 3:
              printf("\nEnter the value to be searched");
	          scanf("%d",&n);
	          p=search(root,n);
	          if(p==NULL)
	          printf("\nThe Requested Element is not found");
	          else
	          printf("\nThe Requested Element is found");
	          break;
       case 4:
              printf("\nEnter the Element to be deleted");
	          scanf("%d",&n);
              root=del(root,n);
              break;
       case 5:
               exit(0);
               
     default:
              printf("\n\nWrong Option Entered\n");
     }
  }
}

               
               
     
     
                     
                       
                      
                  
                    
                    
                      
                  
      
      













 
   
 
