#include <stdio.h>
#include <stdlib.h>

struct node_type {
	int data;
	struct node_type *next;
};
typedef struct node_type list;

void showList();	//displays list contents
list *reverse();	//reverses the list
list *insert();
list *createNode();
list *delete();
list *find();

int main()
{
	list *temp, *start = NULL; //start will point to first node of the list
	char c = 'y';
	int n;

	while(c != 'n' && c != 'N')
	{
		printf("\nEnter the data: ");
		scanf("%d",&n); getchar(); fflush(stdin);
		temp = createNode();
		temp->data = n;
		temp->next = NULL;
		if(!find(start,temp->data))
			start = insert(start,temp);

		printf("\nDo you want to add new data in the list? (y/n): ");
		scanf("%c",&c); fflush(stdin);
	}
	printf("\nTHE LIST IS: "); showList(start); printf("\n\n");

	c = 'y';
	while(c != 'n' && c != 'N')
	{
		printf("\nEnter the data to be deleted: ");
		scanf("%d",&n); getchar(); fflush(stdin);
		if(find(start, n)) start = delete(start, n);

		printf("\nDo you want to delete another data from the list? (y/n):");
		scanf("%c", &c) ; fflush(stdin);
	}
	printf("\nTHE LIST AFTER DATA DELETION IS: "); showList(start); printf("\n\n");

	start = reverse(start);
	printf("\nTHE REVERSED LIST IS: "); showList(start); printf("\n\n");
}


/* Function to create a Node. Allocates memory for a new node. */
list *createNode()
{
	list *new;
	new = (list *)malloc(sizeof(list));
	return(new);
}


/* Recursive function to create and insert a new node at the end of the list */
list *insert(list *st, list *ndt)
{
	if(!st) return(ndt);
	st->next = insert(st->next, ndt);
	return(st);
}


/*
 Function to search a data item in the list and return the node address
 that matches data. In case no match found, returns NULL
*/
list *find(list *st, int dt)
{
	while(st)
		if(st->data == dt)
			return (st);
		else
			st = st->next;
	return(st);
}

void showList(list *temp)
{
	while(temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


/* Function to reverse the list */
list *reverse(list *l)
{
	list *nxt, *temp;
	if(!l) return(l);
	else
	{
		nxt = l->next;
		l->next = NULL;
		while(nxt)
		{
			temp = nxt->next;
			nxt->next = l;
			l = nxt;
			nxt = temp;
		}
		return(l);
	}
}


/* Recursive function for deleting a node from the list */
list *delete(list *st, int n)
{
	list *tmp;
	if(!st) return(st);
	if(st->data == n)
	{
		tmp = st;
		st = st->next;
		free(tmp);
		return(st);
	}
	st->next = delete(st->next,n);
	return(st);
}
