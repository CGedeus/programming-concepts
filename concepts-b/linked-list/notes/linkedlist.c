// Carson Gedeus, 07/05/2017
// A series of linked lists operations (i.e. insert, deletion)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct node 
{
	// data of a node in the linked list
	int data;

	// pointer to the next node in the list
	struct node *next;
} NODE;

// function to create a node

NODE *createnode(int data) 
{
	NODE *create = malloc(sizeof(NODE));

	if (create == NULL) 
	{
		printf("linked list out of memory.\n");
		exit(1);
	}
	
	create->data = data;
	create->next = NULL;
	return create;
}

NODE *headInsert(NODE *head, int data) 
{
	NODE *temp = createnode(data);
	temp->next = head;
	return temp;
}

NODE *tailInsert(NODE *tail, int data) {

	NODE *temp;

	if (tail == NULL)
		return createnode(data);

	for (temp = tail; temp->next != NULL; temp = temp->next)
		;

	temp->next = createnode(data);
	return tail;
}

void printMyList(NODE *myList) 
{
	if (myList == NULL)
	{
		printf("(empty list)\n");
		return;
	}

	for ( ; myList != NULL; myList = myList->next) 
		printf("%d%c", myList->data, (myList->next == NULL) ? '\n' : ' ');
}

NODE *searchAndDelete(NODE *delete, int data) {

	NODE *temp;

	printf("Updated List: ");

	for (temp = delete; temp != NULL; temp = temp->next)
	{
		if (temp->data == data)
		{
			temp = temp->next;
			free(temp);
		}

		printf("%d ", temp->data);
	}
	
	return temp;
}

int main(void) 
{
	srand(time(NULL));

	int i, j = 0, del;
	NODE *myList = NULL, *updatedList = NULL;
	char heads_or_tails[10];
	char esc[5];
	
	printf("heads or tails?\n");
	scanf("%s", heads_or_tails);
	
	if (strcmp(heads_or_tails, "heads") == 0) {
		for (; j < 10; j++) 
		{
			i = rand()%20;
			myList = headInsert(myList, i);
		}
		printf("Head Insertion: ");
	} else if (strcmp(heads_or_tails, "tails") == 0) {
		for (; j < 10; j++) 
		{
			i = rand()%20;
			myList = tailInsert(myList, i);
		}
		printf("Tail Insertion: ");
	} else {
		printf("Invalid user input\n");
	}

	printMyList(myList);

	printf("Enter \'delete\' then enter a number to remove item from list, or press \'esc\' to end program.\n");
	scanf("%s", esc);

	if (strcmp(esc, "esc") == 0) {
		return 0;
	} else if (strcmp(esc, "delete") == 0) {
		scanf("%d", &del);
		updatedList = searchAndDelete(myList, del);
	}

	return 0;
}