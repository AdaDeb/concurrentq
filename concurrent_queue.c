#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
//Creation of a Node
struct Node
{
	int Data;
    struct Node* next;
}*tail, *head, *dummy;

//isEmpty: Checks if the dummmy->next is NULL returning if the list is 
//empty or not
bool isEmpty(struct Node *e ){
	if(e->next==NULL)
	{	
		return true;
	}else
		return false;
}

//deque pops one item from the head of the list, returning 0 if successful pops and 
// 1 if the list is empty.
int dequeue() //SHOULD ADD *EXTRACEDVALUE HERE
{
	struct Node *temp, *var=dummy;
      
	if(dummy->next!=NULL)
    {
		dummy = dummy->next;			//Dummy becomes the next item in the list.
	    //*extractedvalue = var->Data;	//Extracts the value from the second item in 
        free(var->next);				//the list, and pops the second item.
		return 0;	
	}else
		return 1;
}	
// Initializing of the Queue.
void initialize_queue(void){
	head=(struct Node *)malloc(sizeof(struct Node)); 
    tail=(struct Node *)malloc(sizeof(struct Node));
	dummy=(struct Node *)malloc(sizeof(struct Node));

	head->next=dummy;					//head points to dummy
	tail->next=dummy;					//tail points to dummy
	dummy->next=NULL;					//dummy points to NULL
	isEmpty(dummy);						//Makes sure isEmpty is empty (true).
}
// Adds one item to the tail of the list.
void enqueue(int val)
{
     struct Node *temp;
	 struct Node *temp1;
     temp=(struct Node *)malloc(sizeof(struct Node));
     temp1=(struct Node *)malloc(sizeof(struct Node));
	 temp->Data=val;
	
	 if (isEmpty(dummy))				// if the list is Empty.
     {
		 dummy->next = temp;			
		 temp->next = NULL;	     
     }else
	     temp1=dummy;
		 while(temp1->next != NULL){
		 	temp1=temp1->next;	
		 }
		 temp->next=NULL;
		 temp1->next = temp;
}
//*Display: Displays the items in the linked list*//
//*and displays empty if there is nothing in the list*//
void display()
{
	struct Node *var=dummy;
	struct Node *temp2;
	temp2=(struct Node *)malloc(sizeof(struct Node));
     
	if(var->next!=NULL)			// Checks if list is not empty.
    {
    	printf("\nElements are as:  ");
        
		while(var->next!=NULL)
        {
			temp2 = var->next;                
			printf("\t%d",temp2->Data);
            var=var->next;			
        }
     		printf("\n");
     }else
     	printf("\nQueue is Empty");
}

int main()
{
	int i=0;
	initialize_queue();		
    printf(" \n1. Enueue");
    printf(" \n2. Dequeue");
    printf(" \n3. Display");
    printf(" \n4. Quit\n");
    
	while(1)
    {
    	printf(" \nOptions: ");
        scanf("%d",&i);
        
		switch(i)
        {
        	case 1:
            {
            	int value;	
                printf("\nEnter a value to add into the end of the Queue: ");
                scanf("%d",&value);
                enqueue(value); 
                display();
                break;
            }
            case 2:
            {
                if(dequeue()==1){
					printf("The queue is Empty");				
				}else{
				 	display();
                }
				break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
            	printf("\nWrong choice of operation");
            }
        }
	}
}
