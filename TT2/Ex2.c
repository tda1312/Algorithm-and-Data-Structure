#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Node{
	struct Node* next;
	int value;
	int degree;
} Node;

void add_front(Node** head, int value, int degree){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->degree = degree;
	
	Node* temp_node = NULL;
	Node* current_node = (*head);
	int check=0;
	
	if(*head == NULL){
		new_node->next = NULL;
		(*head) = new_node;
	} else {
		new_node->next = (*head);
		(*head) = new_node;
	}
	
	while(current_node != NULL){
		if(current_node->degree == degree){
			new_node->value = current_node->value + value;
		   	current_node = current_node->next;
		   	check = 1;
		} else{
		   		current_node = current_node->next;
			}
	}
	
	if(check == 0){
		new_node->value = value;
	}
	
	return;
}

void display_list(Node* head){
	Node* current_node = head;
	
	while(current_node){
		printf("%d*x^%d + ", current_node->value, current_node->degree);
		current_node = current_node->next;
	}
}

void remove_nodes_by_value(Node** head, int value_to_remove, int degree_to_remove){
	Node* temp_node = NULL;

	while((*head)->value == value_to_remove && (*head)->degree == degree_to_remove){
		temp_node = (*head);
		(*head) = (*head)->next;
		free(temp_node);
	}

	Node* current_node = (*head);

	while(current_node != NULL) {
	    if(current_node->value == value_to_remove && current_node->degree == degree_to_remove){
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

void enter_value_and_calculate(Node** head){
	int result, x;
	Node* temp_node = NULL;
	Node* current_node = (*head);
	
	while(current_node != NULL){
		printf("Enter value for x of degree %d: ", current_node->degree);
		scanf("%d", &x);
		result += current_node->value * pow(x, current_node->degree);
		temp_node = current_node;
		current_node = current_node->next;
	}
	
	printf("Result: %d", result);
	
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
	printf("1. Add a new term.\n");
	printf("2. Remove a term.\n");
	printf("3. Enter value for x and calculate the function.\n");
	printf("4. Print function.\n");
}

int main(){
	Node* head = NULL;
	int choice, val, degree;
	do{
		print_menu();
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter constant value: ");
				scanf("%d", &val);
				printf("Enter degree: ");
				scanf("%d", &degree);
				add_front(&head, val, degree);
				break;
			case 2:
				printf("Enter constant value: ");
				scanf("%d", &val);
				printf("Enter degree: ");
				scanf("%s", &degree);
				remove_nodes_by_value(&head, val, degree);
				break;
			case 3:
				enter_value_and_calculate(&head);
				break;
			case 4:
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
