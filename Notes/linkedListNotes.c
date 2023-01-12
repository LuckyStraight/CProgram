#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    int data;
    struct node_s *nextptr;

}node_t;

node_t *insert(node_t *head);
void removeList(node_t *head);
void displayList(node_t *head);


int main()
{
    node_t *head = NULL;

    head = insert(head);
    head = insert(head);
    head = insert(head);
    head = insert(head);
    head = insert(head);

    displayList(head);
    removeList(head);

    return 0;
}

node_t *insert(node_t *head)
{
    if(head == NULL)
    {
        head = (node_t *)malloc(sizeof(node_t));

        printf("Enter a number: ");
        scanf("%d", &head -> data);

        head -> nextptr = NULL;

        return head;
    }

    /*traverse to the end of the List.*/
    node_t *temp = head;

    while(temp -> nextptr != NULL)
    {
        temp = temp -> nextptr;
    }

    temp -> nextptr = (node_t *)malloc(sizeof(node_t));

    temp = temp -> nextptr;

    printf("Enter the Data: ");
    scanf("%d", &temp -> data);

    temp -> nextptr = NULL;
}

void removeList(node_t *head)
{

    while(head -> nextptr != NULL)
    {
        node_t *temp = head;
        head = head -> nextptr;

        free(temp);
        
    }

    free(head); //de-allocate the tail of the linked list.
}

void displayList(node_t *head)
{
    node_t *temp = head;

    while(head != NULL)
    {
        printf("*****************************************");
        printf("Address of current node is %p\n", &temp);
        printf("The data stored at the node is %d\n", temp -> data);
        printf("The address of nextptr points to %p\n", temp -> nextptr);
        printf("*****************************************");

        temp = temp -> nextptr;
    }
}