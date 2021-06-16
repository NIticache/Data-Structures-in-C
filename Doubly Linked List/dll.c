
#include <stdio.h>
#include <stdlib.h>

struct node{
	int i;
	struct node *rlink,*llink;
}*first=NULL,*n,*ptr,*tptr,*nptr;

void infront(void){
     if(first==NULL){
					first= (struct node*)malloc(sizeof(struct node));
					printf("\nEnter item : ");
					scanf("%d",&first->i);
					first->llink =first->rlink = NULL;
				}
    else{
	       ptr = (struct node*)malloc(sizeof(struct node));
	       printf("\nEnter item : ");
	       scanf("%d",&ptr->i);
	       ptr->rlink=first;
	       ptr->llink=NULL;
	       first->llink=ptr;
	       first = ptr;
        }
  }

void inrear(void){
	if(first==NULL){
					first= (struct node*)malloc(sizeof(struct node));
					printf("\nEnter item : ");
					scanf("%d",&first->i);
					first->llink =first->rlink = NULL;
				}
				else{
					n= (struct node*)malloc(sizeof(struct node));
					printf("\nEnter item : ");
					scanf("%d",&n->i);
					n->rlink = NULL;
					ptr = first;
					while(ptr->rlink!=NULL){
						ptr = ptr->rlink;
										}
					ptr->rlink = n;
					n->llink = ptr;
				}
	}			
	void disp(void){
	ptr = first;
	if(first == NULL){
		printf("\nERROR LINK IS EMPTY !\n");
	}
	else{
		while(ptr!=NULL){
			printf("%d ",ptr->i);
			ptr = ptr->rlink;
		}
	}
}

void inany(void){
	int k;
	n = (struct node*)malloc(sizeof(struct node));
	printf("\nENTER KEY : ");
	scanf("%d",&k);
	ptr = first;
	while(ptr!=NULL&&ptr->i!=k){
		ptr=ptr->rlink;
	}
	if(ptr==NULL){
		printf("\nKEY NOT FOUND ");
	}
	else{
		printf("\nEnter item : ");
		scanf("%d",&n->i);
		n->rlink = ptr->rlink;
		n->llink = ptr;
		ptr->rlink = n;		
	}	
}

void delfront(void){
	ptr = first;
	if(first == NULL){
		printf("\nERROR LINK IS EMPTY !\n");
	}
	
	else{
		first = first->rlink;
    first->llink=NULL;
    free(ptr);
		printf("\nITEM DELETD SUCCESSFULLY\n");
                   }
    }


void delrear(void){
	ptr = first;
	if(first == NULL){
           printf("\nERROR LINK IS EMPTY !\n");
	}
	else{
			while(ptr->rlink!=NULL){
				tptr = ptr;
				ptr = ptr->rlink;
			}
			if(ptr==first){
				free(first);
				first = NULL;
			}
			else{
				tptr->rlink = NULL;
				free(ptr);
				printf("\nITEM DELTED SUCCESSFULLY");
			}
   	}
}

void delany(void){
	int k;
	printf("\nENTER KEY : ");
	scanf("%d",&k);
	ptr = first;
	while(ptr!=NULL&&ptr->i!=k){
		tptr = ptr;
		ptr=ptr->rlink;
	}

	if(ptr==NULL){
		printf("\nKey NOT FOUND ");
	}
	else{
		if(ptr==first){
				free(first);
				first = NULL;
			}
			else{
        nptr = ptr->rlink;
        nptr->llink=tptr;
				tptr->rlink = ptr->rlink;
				free(ptr);
				printf("\nITEM DELTED SUCCESSFULLY");
			}		
	}
}

void sort(void){
     int tmp;
     ptr = first;
     while(ptr!=NULL){
        tptr = ptr->rlink;
        while(tptr!=NULL){
        if((ptr->i)>(tptr->i)){
          tmp = ptr->i;
          ptr->i=tptr->i;
          tptr->i=tmp;
          
                  }
                  tptr=tptr->rlink;
                               }
            ptr = ptr->rlink;
                      }
     printf("\nLIST HAS BEEN SORTED\n");
     }

void menu(void){
	int c;
	printf("\nPRESS 1 for insert at front");
	printf("\nPRESS 2 for insert at rear");
	printf("\nPRESS 3 for insert at any position");
	printf("\nPRESS 4 for delete at front");
	printf("\nPRESS 5 for delete at rear");
	printf("\nPRESS 6 for delete at any position");
	printf("\nPRESS 7 for sort");
	printf("\nPRESS 8 for display");
	printf("\nPRESS 9 for exit");
	printf("\nChoice : ");
	scanf("%d",&c);
	switch(c){

		case 1:
			infront();
			menu();
		break;
		case 2:
			inrear();
			menu();
		break;
		case 3:
		 	inany();
		 	menu();
		break;
		case 4:
			delfront();
			menu();
		break;
		case 5:
			delrear();
			menu();
		break;
		case 6:
			delany();
			menu();
		break;
		case 7:
       sort();
       menu();
			
		case 8:
			disp();
			menu();
		break;
		case 9:
			return ;
		default:
		printf("\nINVALID INPUT\n");
		menu();
	}
}


int main(){
    menu();
    return 0;
    }
