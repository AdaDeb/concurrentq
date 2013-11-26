#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
#include <pthread.h>

/*
 * Node data srtucture
 */
struct Node
{
  int Data;
  struct Node* next;
}*tail, *head, *dummy;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function definitions
bool isEmpty(struct Node *);

/*
 * Initializing of the Queue.
 */
void initialize_queue(void){
  head=(struct Node *)malloc(sizeof(struct Node)); 
  tail=(struct Node *)malloc(sizeof(struct Node));
  dummy=(struct Node *)malloc(sizeof(struct Node));
  
  
  head->next=dummy;    	//head points to dummy
  tail->next=dummy;   	//tail points to dummy
  dummy->next=NULL;   	//dummy points to NULL
  isEmpty(dummy);      	//Makes sure isEmpty is empty (true).
}



/*
 * Adds one item to the tail of the list.
 */
void enqueue(int val)
{
  struct Node *temp;
  struct Node *temp1;
  temp=(struct Node *)malloc(sizeof(struct Node));
  temp1=(struct Node *)malloc(sizeof(struct Node));
  temp->Data=val;
  
  pthread_mutex_lock(&lock);

  if (isEmpty(dummy)) // if the list is Empty.
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
  
  pthread_mutex_unlock(&lock);

}

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
int dequeue(int *extracted_value) //SHOULD ADD *EXTRACEDVALUE HERE
{  
  if(dummy->next!=NULL)
    {      
      *extracted_value = (dummy-> next)->Data; //Extracts the value from the second item in 
      dummy = dummy->next; //Dummy becomes the next item in the list.
      return 0;	
    }else return 1;
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
  initialize_queue();	

  enqueue(5);
  enqueue(10);
  int extracted;
  int res = dequeue(&extracted);
  printf("Res is : %d\n", res);
  printf("First element is: %d\n", (dummy->next)->Data);
}
