/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    
} *old,*n,*head;


void addnode(int num)
{
    int i;
head=(struct node*)malloc(sizeof(struct node));

head->next=NULL;
old=head;
for(i=1;i<=num;i++)
{
    n=(struct node*)malloc(sizeof(struct node));
    printf("Value of node %d : ",i);
    scanf("%d",&n->info);
    n->next=NULL;
    old->next=n;
    old=n;
}
printf("\n\n\n");
printf("INSERTED SUCEESFULLY\n\n");
}

void inorder()
{
    if(head==NULL)    //condition to check whether list is empty
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur=head;            
    int count;
    count=0;
    while(cur!=NULL)                  //the loop traverse until it gets any NULL node
    {
        printf("%d->",cur->info);    
        count++;                      //counts the number of nodes or elements present in list
        cur=cur->next;                //moves cur pointer to next node to check and get value
    }
    printf("NULL\n\n");
    printf("\n\n");
    printf("NUMBER OF NODES : %d\n\n\n\n",count);
}

void revorder(struct node *temp)
{
    int arr[100],i=0;
    temp=head;
    printf("REVERSE ORDER \n\n");            // Reversing Using Array
    while(temp!=NULL)
    {
        arr[i]=temp->info;
        i++;
        temp=temp->next;
    }
    
    while(i>0)                         // Printing Reversing Order 
    {
         i--;
        printf("%d  ",arr[i]);
       
    }
    
    
    
}

   void inanypos(int ele,int pos)
 {
     struct node *new;
     new=(struct node*) malloc(sizeof(struct node));
     new->info=ele;
     new->next=NULL;
     struct node *prev=head;
     while(prev->info!=pos )
     {
         prev=prev->next;
         
     }
     new->next=prev->next;
     prev->next=new;
     
 }
 
void deleteitem(int ele)
{
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->info!=ele)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
        prev->next=cur->next;       //the address of next node after the node containing element to be deleted is assigned to the previous node of the node containing the element to be deleted
    free(cur);                      //memory of the structure cur is deallocated
    printf("DELETED SUCCESSFULLY");

}




// int main()
// {
    
//     int Hmany,element,position;
//     printf("Enter the number of nodes to be created : ");
//     scanf("%d",&Hmany);
//     addnode(Hmany);
//     inorder();
//     revorder(head);
//     printf("Enter the position where to be inserted\n : ");
//     scanf("%d",&position);
//     printf("Enter the element value to be inserted\n : ");
//     scanf("%d", &element);
//     inanypos(element,position);
//     inorder();
   
// }


int main()
{
    

int Hmany,element,position,ch,del;

while(1)
    {
        printf("\n 1. Create  2.Display Linked List  3.Print Linked List in Reverse way. 4.Insert at any position 5.Delete a element  .6.Exit\n\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
        printf("Enter the number of nodes to be created : ");
        scanf("%d",&Hmany);
        addnode(Hmany);
        
        }
        else if(ch==2)
        {
          inorder();
        }
        else if(ch==3)
        {
            
          revorder(head);
        }
        
        else if(ch==4)
        {
          printf("Enter after which  position  to be inserted\n : ");
         scanf("%d",&position);
         printf("Enter the element value to be inserted\n : ");
         scanf("%d", &element);
          inanypos(element,position);
          printf("Inserted the element in the Position %d",position+1);
        }
       
       else if(ch==5)
       {
         printf("Enter the element to be deleted\n : ");
         scanf("%d",&del);
         deleteitem(del);
         
       
       }
        else if(ch>=6 || ch==0)
            return 0;
        ;
    }
    return 0;
}



