#include<stdio.h>
#include<stdlib.h>
#define max 100
struct node
{
    struct node *l_child;
    int data;
    struct node *r_child;
};
struct node *stack[max];
int top=-1;
void initiallize_stack()
{
    top=-1;
}// end of initiallize_stack
void push(struct node *ptr)
{
    if(top==max)
    {
        printf("stack over flow. ");
        return;
    }
    stack[++top]=ptr;
}// end of push
struct node *pop()
{
    if(top==-1)
    {
        printf("stack underflow.\n");
    }
    else
        return stack[top--];
        return NULL;
}// end of pop
int is_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}// end of is empty
struct node *insert_node(struct node *root,int item)
{
    struct node *ptr=root;
    struct node *temp;
    int cnt=0;
    struct node *par=NULL;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
        {
            cnt++;
         break;
        }
         par=ptr;
        if(ptr->data<item)
         ptr=ptr->r_child;
         else
            ptr=ptr->l_child;
    }
    if(cnt!=0)
    {
        printf("duplicate item.  \n ");
        return root;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->l_child=NULL;
    temp->r_child=NULL;
    if(par==NULL)
        root=temp;
    else if(par->data<item)
        par->r_child=temp;
    else
        par->l_child=temp;
     return root;
}// end of insert_node
struct node *delete_node(struct node *root,int item)
{
   struct node *ptr=root;
   struct node *child,*succ,*par_succ;
   struct node*par=NULL;
   struct node *temp;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
         break;
         par=ptr;
          if(ptr->data<item)
         ptr=ptr->r_child;
         else
            ptr=ptr->l_child;
    }
    if(ptr==NULL)
        printf("item not found .\n");
        temp=ptr;
        //if the node ptr have two child
     if(ptr->l_child!=NULL&&ptr->r_child!=NULL)
    {
        succ=ptr->r_child;
        par_succ=ptr;
        while(succ->l_child!=NULL)
        {
            par_succ=succ;
            succ=succ->l_child;
        }
        ptr->data=succ->data;
        ptr=succ;
        par=par_succ;
    }
    /*if node ptr have only one child*/
    if((ptr->l_child!=NULL&&ptr->r_child==NULL)||(ptr->l_child==NULL&&ptr->r_child!=NULL))
    {
        if(ptr->l_child==NULL)
            child=ptr->r_child;
        else
            child=ptr->l_child;
        if(par==NULL)
            root=child;
        else if(par->l_child==ptr)
            par->l_child=child;
        else
            par->r_child=child;
    }
    //if the node ptr have no child
    else
    {
       if(par==NULL)
        root=NULL;
       else if(par->l_child==ptr)
        par->l_child=NULL;
       else
        par->r_child=NULL;
       free(ptr);
    }
     return root;
}// end of delete _ node

struct node * create_tree(struct node *root)
{
 struct node *temp;
 int item,i,n;
 printf("how many node you want to in your tree ; \n");
 scanf("%d",&n);
 if(n==0)
        return root;
 for(i=0;i<n;i++)
 {
     printf("enter next node value : ");
     scanf("%d",&item);
     if(root==NULL)
     {
         root=(struct node *)malloc(sizeof(struct node ));
         root->data=item;
         root->l_child=NULL;
         root->r_child=NULL;
     }
     else
         root=insert_node(root,item);
 }
  return root;
}//end of creation of binery tree

void pre_traversal(struct node *root)
{
    struct node *ptr=root;
    if(ptr==NULL)
    {
        printf("tree is empty.\n ");
        return ;
    }
    push(ptr);
    while(!is_empty())
    {
        ptr=pop();
        printf("%d\n",ptr->data);
        if(ptr->r_child!=NULL)
            push(ptr->r_child);
         if(ptr->l_child!=NULL)
            push(ptr->l_child);
    }
}// end of pre _traversal
void in_traversal(struct node *root)
{
    struct node *ptr=root;
    if(ptr==NULL)
    {
        printf("tree is empty .\n");
        return ;
    }
    while(1)
          {
    while(ptr->l_child!=NULL)
    {
        push(ptr);
        ptr=ptr->l_child;
    }
    while(ptr->r_child==NULL)
    {
        printf("%d\n",ptr->data);
        if(is_empty())
            return ;
        ptr=pop();
    }
    printf("%d\n",ptr->data);
    ptr=ptr->r_child;
}
}// end of in_traversal
void post_traversal(struct node *root)
{
   struct node *ptr=root;
   struct node *q=NULL;
   if(ptr==NULL)
   {
       printf("tree is empty. \n ");
       return;
   }
   while(1)
   {
       while(ptr->l_child!=NULL)
        {
        push(ptr);
        ptr=ptr->l_child;
        }
       while(ptr->r_child==NULL||ptr->r_child==q)
        {
        printf("%d \n",ptr->data);
        q=ptr;
        if(is_empty())
            return ;
        ptr=pop();
       }
       push(ptr);
       ptr=ptr->r_child;
   }
}//end of post_traversal
void main()
{
   int choice,item;
   struct node *root=NULL;
   while(1)
   {
       printf("\n what you want to do . \n enter \n 1 for create_ binery tree. \n 2 for insertion .\n 3 for deletion .\n 4 for preorder traversal .\n 5 for inorder traversal. \n 6 for post order traversal .\n 7 for exit . \n enter your chice : ");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
              root=create_tree(root);
              break;
       case 2:
           printf("enetr your item : ");
           scanf("%d",&item);
            root=insert_node(root,item);
            break;
       case 3:
            printf("enetr your item : ");
           scanf("%d",&item);
            root=delete_node(root,item);
            break;
       case 4:
             pre_traversal(root);
             break;
       case 5:
              in_traversal(root);
              break;
       case 6:
               post_traversal(root);
               break;
       case 7:
                exit(1);
                break;
       default:
                printf("wrong choice. \n");
                break;
    }//end of switch
   }//end of while
}// ende of main


