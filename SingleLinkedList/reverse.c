
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

   
 


int main()
{
    
    int Hmany;
    printf("Enter the number of nodes to be created : ");
    scanf("%d",&Hmany);
    addnode(Hmany);
    inorder();
    revorder(head);
   
}






