#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node* next;
	int value;
} Node;

void add_front(Node** head, int value){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->value = value;

	if(*head == NULL){
		new_node->next = NULL;
		(*head) = new_node;
	} else {
		new_node->next = (*head);
		(*head) = new_node;
	}
	return;
}

int elements_sum(Node** head){
	if(*head != NULL){
		return ((*head)->value + elements_sum(&(*head)->next));
	}
}

void free_all_nodes(Node** head){
	Node* temp_node = NULL;
	while(*head != NULL){
		temp_node = (*head);
		(*head) = (*head)->next;
		free(temp_node);
	}
}

void print_menu(){
	printf("\n--------------------------MENU------------------------\n");
	printf("0. Exit program.\n");
	printf("1. Add an element.\n");
	printf("2. Calculate the sum of input elements.\n");
}

int main(){
	Node* head = NULL;
	
	int choice, value, sum;
	
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter a value for the element: ");
				scanf("%d", &value);
				add_front(&head, value);
				break;
			case 2:
				sum = elements_sum(&head);
				printf("The sum of input elements: %d\n", sum);
				printf("Elements erased.");
				
				free_all_nodes(&head);
				break;
		}
	} while (choice != 0);
	
	return 0;
}
