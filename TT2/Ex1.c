#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

typedef struct Node{
	struct Node* next;
	int value;
	char string[MAX_LEN];
} Node;

void add_front(Node** head, int value, char string[]){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->value = value;
	strcpy(new_node->string, string);

	if(*head == NULL){
		new_node->next = NULL;
		(*head) = new_node;
	} else {
		new_node->next = (*head);
		(*head) = new_node;
	}
	return;
}

void display_list(Node* head){
	Node* current_node = head;

	if(head == NULL){
		printf("NULL\n");
		return;
	}

	while(current_node){
		printf("%d - %s\n", current_node->value, current_node->string);
		current_node = current_node->next;
	}
}

void remove_nodes_by_value(Node** head, int value_to_remove){
	Node* temp_node = NULL;

	while((*head)->value == value_to_remove){
		temp_node = (*head);
		(*head) = (*head)->next;
		free(temp_node);
	}

	Node* current_node = (*head);

	while(current_node != NULL) {
	    if(current_node->value == value_to_remove){
	    	temp_node->next = current_node->next;
	    	free(current_node);
	    	current_node = temp_node->next;
	    } else {
		    temp_node = current_node;
		    current_node = current_node->next;
	    }
	}

	return;
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
	printf("1. Add car to front of train.\n");
	printf("2. Delete all car have no passenger.\n");
	printf("3. Print all cars.\n");
}

int main(){
	Node* head = NULL;

	int choice, i;
	char str[MAX_LEN];

	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter number of passenger: ");
				scanf("%d", &i);
				printf("Enter name of car: ");
				scanf("%s", str);
				add_front(&head, i, str);
				display_list(head);
				break;
			case 2:
				remove_nodes_by_value(&head, 0);
				break;
			case 3:
				display_list(head);
				break;
			default:
				printf("Invalid choice!\n");
				break;
		} 
	} while (choice != 0);

	free_all_nodes(&head);

	return 0;
}
