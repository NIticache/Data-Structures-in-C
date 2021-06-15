
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
printf("Values");
for(i=1;i<=num;i++)
{
    n=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&n->info);
    n->next=NULL;
    old->next=n;
    old=n;
}
}
void print()
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
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}
int main()
{
    int Hmany;
    printf("Enter the number of nodes to be created : ");
    scanf("%d",&Hmany);
    addnode(Hmany);
    print();
}






