/* Challenge: Write a UI that allows the user to perform
operations on a linked list:
-Insert node at head
-Insert node at last
-Insert node at position
-Delete node from position
-Update Node Value
-Search Element in the linked list
-Display List
-Exit
*/

#include "stdio.h"
#include "stdlib.h"

//Defining the linked list structure
typedef struct node{
    int value;
    struct node *next;
}node_t;
typedef struct node *nodeptr;

void printOptions();
void insertBeginning(nodeptr *head);
void insertEnd(nodeptr head);
void insertSpecific(nodeptr head);
void delNode(nodeptr *head);
void nodeUpdate(nodeptr head);
void searchElement(nodeptr head);
void printNodes(nodeptr head);

int main(){
    nodeptr head=NULL;
    printOptions();
    if(head==NULL){
            puts("List is empty, please select option 1 to create a new list");
        }
    int answer=0;
    scanf("%d",&answer);
    while(answer!=8){
        switch(answer){

            case 1:
            system("clear");
            insertBeginning(&head);
            break;

            case 2:
            system("clear");
            insertEnd(head);
            break;

            case 3:
            system("clear");
            insertSpecific(head);
            break;

            case 4:
            system("clear");
            delNode(&head);
            break;

            case 5:
            system("clear");
            nodeUpdate(head);
            break;

            case 6:
            system("clear");
            searchElement(head);
            break;

            case 7:
            system("clear");
            printNodes(head);
            break;

            default:
            system("clear");
            puts("Invalid option, try again");
            break;
        }
        printOptions();
        puts("Select an option: ");
        scanf("%d",&answer);
    }
}

void printOptions(){
    puts("**************************************************************");
    puts("Choose one of the following options:");
    printf("1) Insert node at the beginning.\n2) Insert node at the end.\n3) Insert node at a specific position.\n4) Delete node.\n5) Update node value.\n");
    printf("6) Search element.\n7) Display List.\n8) Exit.\n");
    puts("**************************************************************");
}

void insertBeginning(nodeptr *head){
    puts("Enter the value of the node:");
            int input=0;
            scanf("%d",&input);
            nodeptr newNode=(nodeptr)malloc(sizeof(node_t));
            newNode->value=input;
            newNode->next=*(head);
            *(head)=newNode;
}

void insertEnd(nodeptr head){
    puts("Enter the value of the node:");
            int input=0;
            scanf("%d",&input);
            nodeptr current=head;
            for(;current->next!=NULL;current=current->next);
            nodeptr newNode=(nodeptr)malloc(sizeof(node_t));
            newNode->value=input;
            current->next=newNode;
            newNode->next=NULL;
}

void insertSpecific(nodeptr head){
    puts("Enter the value of the node:");
    int input=0;
    scanf("%d",&input);

    puts("Enter the position to insert:");
    int location=0;
    scanf("%d",&location);

    nodeptr current=head;
    for(int i=1;i<=location-2;i++){
        current=current->next;
    }
    nodeptr newNode=(nodeptr)malloc(sizeof(node_t));
    newNode->value=input;
    newNode->next=current->next;
    current->next=newNode;
}

void delNode(nodeptr *head){
    puts("Enter the position of the node you want to delete:");
    int location=0;
    scanf("%d",&location);
    nodeptr current=*(head);

    if (location==1){
        current=current->next;
        free(*(head));
        *(head)=current;
        return;
    }

    for(int i=1;i<=location-2;i++){
        current=current->next;
    }
    if (current->next==NULL){
        printf("ERROR: Node at %d does not exist.\n",location);
    }

    else{
        nodeptr temp=*(head);
        nodeptr todelete=*(head);
        for(int i=1;i<=location;i++){
            temp=temp->next;
        }
        for(int i=1;i<=location-1;i++){
            todelete=todelete->next;
        }

        current->next=temp;
        free(todelete);
    }

}

void nodeUpdate(nodeptr head){
    puts("Enter the value of the node:");
    int input=0;
    scanf("%d",&input);
    puts("Enter the position to update:");
    int location=0;
    scanf("%d",&location);
    if(location==1){
        head->value=input;
        return;
    }

    
    else{
        nodeptr current=head;
        for(int i=0;i<location-1;i++){
            current=current->next;
        }
        current->value=input;
    }
}

void searchElement(nodeptr head){
    int i=1;
    puts("Enter the value of the node:");
    int input=0;
    scanf("%d",&input);
    nodeptr current=head;
    while(1){
        if(current->value==input){
            printf("The node with value %d is at position %d\n",input,i);
            return;
        }

        else if(current->next==NULL){
            puts("ERROR: Value can't be found\n");
            return;
        }

        current=current->next;
        i++;
    }
}

void printNodes(nodeptr head){
    nodeptr current=head;
    puts("\n-------------------------------------------------------------------------------------------------------------------\n");
    while(current!=NULL){
        printf("(%d)-->",current->value);
        current=current->next;
    }
    puts("NULL\n");
    puts("-------------------------------------------------------------------------------------------------------------------\n");
}