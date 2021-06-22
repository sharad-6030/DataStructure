//implementation of singly linear linked list operations:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma pack(1)
#define SIZE 20
typedef struct node
{
	char data[20];//20 bytes
	struct node *next;//self referential pointer – 4 bytes
}node_t;

void add_node_at_last_position(char *data);
void add_node_at_first_position(char *data);
node_t *create_node(char *data);
void display_list(void);


//create an empty linked list
node_t *head = NULL;


int main(void)
{
    char data[20];  
    FILE *fpRead=NULL;
    if( (fpRead=fopen("file1.txt","r"))==NULL)
        printf("\n unable to read file");
    else
    {
        while(fscanf(fpRead,"%s", data)!=EOF)
        {
           // add_node_at_first_position(data);
             add_node_at_last_position(data);
        }
        fclose(fpRead);
        printf("\n list is created");
        display_list();
        
    }
  
    return 0;
}

void display_list(void)
{
    //if list is not empty
    if( head != NULL ){
        //start traversal from first node
        node_t *trav = head;
        printf("list is: head -> ");
        //traverse the list till last node including it
        while( trav != NULL )
        {
            printf("%s -> ", trav->data);//visit data part of each node
            trav = trav->next;
        }
        printf("null\n");
    }
    else
        printf("list is empty !!!\n");
}


node_t *create_node(char* data)
{
    //1. allocate memory dynamically for node
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    /* malloc() functions allocates requested bytes of memory from heap section and on success
    it returns starting addr of dynamically allocated block and on failure it returns
    NULL */
    if( temp == NULL )
    {
        printf("malloc() failed !!! insufficient heap memory !!!\n");
        exit(1);
    }

    //2. initialize members of the node
    strcpy(temp->data , data);
    temp->next = NULL;
    //3. return starting of dynamically allocated node to the calling function
    return temp;
}

void add_node_at_last_position(char *data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;    
    }
    else//step-3: if list is not empty
    {
        //start traversal from first node
        node_t *trav = head;
        //traverse list till last node
        while( trav->next != NULL ){
            trav = trav->next;//move trav pointer towards its next node
        }

        //attach newly created node to the last node
        //i.e. store an addr of newly created node into the next part last node
        trav->next = newnode;

    }
}

void add_node_at_first_position(char *data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;    
    }
    else//step-3: if list is not empty
    {
        //store an addr of cur first node into the next part of newly created node
        newnode->next = head;
        //attach newly created node to the head
        head = newnode;
    }
}





