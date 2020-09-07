//Program of Binary Search Tree
#include<stdio.h>
#include<conio.h>
struct node
{
       int data;
       struct node *leftchild,*rightchild;
}*root=NULL,*p,*q,*temp,*par,*loc=NULL;
void Create()
{
     temp=(struct node *)malloc(sizeof(struct node));
     printf("\n Enter the data:");
     scanf("%d",&temp->data);
     temp->leftchild=NULL;
     temp->rightchild=NULL;
     if(root==NULL)
     {
                   root=temp;
                   return;
     }
     p=root;
     while(p!=NULL)
     {
                   q=p;
                   if(temp->data==p->data)
                   {
                                          printf("\n Data Already Present");
                                          return;
                   }
                   if(temp->data<p->data)
                   p=p->leftchild;
                   else
                   p=p->rightchild;
     }
     if(temp->data<q->data)
     q->leftchild=temp;
     else
     q->rightchild=temp;     
}
void Inorder()
{
     struct node *stack[20],*ptr;
     int top=-1;
     ptr=root;
     label: while(ptr!=NULL)
     {
                stack[++top]=ptr;
                ptr=ptr->leftchild;     
     }
     while(ptr==NULL && top!=-1)
     {
                     ptr=stack[top--];
                     printf("%d ",ptr->data);
                     ptr=ptr->rightchild;
                     goto label;
     }
}
void Preorder()
{
     struct node *ptr,*stack[20];
     int top=-1;
     ptr=root;
     stack[++top]=ptr;
     while(top!=-1)
     {
                   ptr=stack[top--];
                   if(ptr!=NULL)
                   {
                                printf("%d ",ptr->data);
                                stack[++top]=ptr->rightchild;
                                stack[++top]=ptr->leftchild;
                   }
     }
}
void Postorder()
{
     struct node *stackchild[20],*stackparent[20],*ptr;
     int top=-1,top1=-1;
     ptr=root;
     stackchild[++top]=ptr;
     while(top!=-1)
     {
                     ptr=stackchild[top--];
                     stackparent[++top1]=ptr;
                     if(ptr->leftchild!=NULL)
                     stackchild[++top]=ptr->leftchild;
                     if(ptr->rightchild!=NULL)
                     stackchild[++top]=ptr->rightchild;
     }  
     while(top1!=-1)
	{
		ptr=stackparent[top1--];
		printf("%d ",ptr->data);
	}
}
struct node *Search(int item)
{
       struct node *ptr,*save;
       if(root==NULL)
       {
                     par=NULL;
                     loc=NULL;
                     return(loc);
       }
       else if(item==root->data)
       {
            par=NULL;
            loc=root;
            return(loc);
       }
       if(item<root->data)
       {
                          save=root;
                          ptr=root->leftchild;
       }
       else if(item>root->data)
       {
            save=root;
            ptr=root->rightchild;
       }
       while(ptr!=NULL)
       {
                       if(item==ptr->data)
                       {
                                  par=save;
                                  loc=ptr; 
                                  return(loc);       
                       }
                       if(item<ptr->data)
                       {
                                         save=ptr;
                                         ptr=ptr->leftchild;
                       }
                       else
                       {
                           save=ptr;
                           ptr=ptr->rightchild;
                       }
       }
       loc=NULL;
       par=save;
       return(loc);
}
void Delete_firstcase(struct node *loc,struct node *par)
{
     struct node *child;
     if(loc->leftchild==NULL && loc->rightchild==NULL)
     child=NULL;
     else if(loc->leftchild!=NULL)
     child=loc->leftchild;
     else
     child=loc->rightchild;
     if(par!=NULL)
     {
                  if(loc==par->leftchild)
                  par->leftchild=child;
                  else
                  par->rightchild=child;
     }
     else
     root=child;
}
void Delete_bothchild(struct node *loc,struct node *par)
{
     struct node *ptr,*suc,*parsuc;
     ptr=loc->rightchild;
     parsuc=loc;
     while(ptr->leftchild!=NULL)
     {
                                parsuc=ptr;
                                ptr=ptr->leftchild;
     }
     suc=ptr;
     Delete_firstcase(suc,parsuc);
     if(par!=NULL)
     {
                  if(par==loc->rightchild)
                  par->rightchild=suc;
                  else
                  par->leftchild=suc;
     }
     else
     root=suc;
     suc->leftchild=loc->leftchild;
     suc->rightchild=loc->rightchild;
}
void Level_order()
{
     struct node *queue[20],*ptr;
     int front=-1,rear=-1;
     ptr=root;
     while(front<=rear)
     {
                       if(front==-1)
                       {
                                    queue[++rear]=root;
                                    ++front;           
                       }
                       else
                       {
                           ptr=queue[front++];
                           printf("%d ",ptr->data);
                           if(ptr->leftchild!=NULL)
                           queue[++rear]=ptr->leftchild;
                           if(ptr->rightchild!=NULL)
                           queue[++rear]=ptr->rightchild;
                       }
     }
}
int main()
{
    int choice,i,n;
    int del,val;
    do
    {
    printf("\n Enter");
    printf("\n 1.Create Tree");
    printf("\n 2.Inorder Traversal");
    printf("\n 3.Preorder Traversal");
    printf("\n 4.Postorder Traversal");
    printf("\n 5.Level order Traversal");
    printf("\n 6.Searching");
    printf("\n 7.Deletion");
    printf("\n 8.Exit");
    printf("\n Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
                  case 1:
                       printf("\nEnter how many nos you want to enter in tree:");
                       scanf("%d",&n);
                       for(i=0;i<n;i++)
                       Create();
                       break;
                  case 2:
                       Inorder();
                       break;
                  case 3:
                       Preorder();
                       break;
                  case 4:
                       Postorder();
                       break;
                  case 5:
                       Level_order();
                       break;
                  case 6:
                       printf("\n Enter the data which you want to search:");
                       scanf("%d",&val);
                       loc=Search(val);
                       if(loc==NULL)
                       {
                                    printf("\n Data NOT found\n");
                       }
                       else
                       printf("\n Data is present in the tree\n");
                       break;
                  case 7:
                       printf("\n Enter the data which you want to delete:");
                       scanf("%d",&del);
                       loc=Search(del);
                       if(loc==NULL)
                       {
                                  printf("\n Data NOT found\n");
                       }
                       else
                       {
                       if(loc->rightchild!=NULL && loc->leftchild!=NULL)
                       Delete_bothchild(loc,par);
                       else
                       Delete_firstcase(loc,par);
                       }
                       break;
                  case 8:
                       break;
                  default:
                          printf("\n Invalid choice:");
                          break;
    }
    }while(choice!=8);
    getch();
    return 0;
}
