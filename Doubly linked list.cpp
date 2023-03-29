#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

void displayList(struct Node* node)
{
	struct Node* last;
	while (node != NULL) {
		cout << node->data << "<==>";
		last = node;
		node = node->next;
	}
	if (node == NULL)
		cout << "NULL";
}


void insert_front(struct Node** head, int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = (*head);
	newnode->prev = NULL;
	(*head) = newnode;
}

void delete_front(struct Node** head, int data)
{
	if (*head == NULL)
	{
		cout << "Empty List" << endl;
	}
	else
		(*head)->next->prev = NULL;
	*head = (*head)->next;
}

void insert_back(struct Node** head, int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		struct Node* temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
	}
}

void delete_back(struct Node** head, int data)
{
	if (*head == NULL)
	{
		cout << "Empty List" << endl;
	}
	else
	{
		struct Node* temp = *head;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next = NULL;
	}
}

void insert_middle(struct Node** head, int position, int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	if (*head == NULL)
	{
		*head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		if (position == 1)
			insert_front(head, data);
		else
		{
			class Node* temp = *head;
			for (int i = 2; i < position; i++)
				if (temp->next != NULL)
					temp = temp->next;
			newnode->next = temp->next;
			temp->next->prev = newnode;
			temp->next = newnode;
			newnode->prev = temp;
		}
	}
}

void delete_middle(struct Node** head, int position, int data)
{
	if (*head == NULL)
	{
		cout << "Empty List" << endl;
		exit(0);
	}
	else
	{
		class Node* temp = *head;
		for (int i = 2; i < position; i++)
			if (temp->next != NULL)
				temp = temp->next;

		temp->next = temp->next->next;
		temp->next->prev = temp;
	}
}

int main() {
	struct Node* head = NULL;
	insert_back(&head, 40);
	insert_front(&head, 20);
	insert_front(&head, 10);
	insert_back(&head, 50);
	insert_middle(&head, 2, 20);
	cout << "Doubly linked list is as follows: " << endl;
	displayList(head);
	return 0;
}

