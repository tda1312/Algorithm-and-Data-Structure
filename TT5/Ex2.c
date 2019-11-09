#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node* next;
}Node;

void add_front(Node** head, int value){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->val = value;

	if(*head == NULL){
		new_node->next = NULL;
		(*head) = new_node;
	} else {
		new_node->next = (*head);
		(*head) = new_node;
	}
	return;
}

Node* merge_subsort(Node* sub_1, Node* sub_2){
	Node* merged_head = NULL;
	
	if(sub_1 == NULL){
		return sub_2;
	} else if(sub_2 == NULL){
		return sub_1;
	}
	
	if(sub_1->val <= sub_2->val){
		merged_head = sub_1;
		merged_head->next = merge_subsort(sub_1->next, sub_2);
	}else{
        merged_head = sub_2;
        merged_head->next = merge_subsort(sub_1, sub_2->next);
    }
    
    return merged_head;
}


void divide(Node* head, Node** sub_1, Node** sub_2){
	Node* end_1;
	Node* end_2;
	
	if(head == NULL || head->next == NULL){
		*sub_1 = head;
		*sub_2 = NULL;
	} else{
		end_1 = head;
		end_2 = head->next;
		
		while(end_2 != NULL){
			end_2 = end_2->next;
			
			if(end_2 != NULL){
				end_1 = end_1->next;
				end_2 = end_2->next;
			}
		}
		
		*sub_1 = head;
		*sub_2 = end_1->next;
		end_1->next = NULL;
	}
}

void mergesort(Node** head){
	Node* sub_1 = NULL;
	Node* sub_2 = NULL;
	
	if(*head == NULL || (*head)->next == NULL){
		return;
	}
	
	divide(*head, &sub_1, &sub_2);
	mergesort(&sub_1);
	mergesort(&sub_2);
	
	*head = merge_subsort(sub_1, sub_2);
}

void display_list(Node* head){
	Node* current_node = head;

	if(head == NULL){
		return;
	}

	while(current_node){
		printf("%d ", current_node->val);
		current_node = current_node->next;
	}
}

void print_menu(){
	printf("\n--------------------------MENU------------------------\n");
	printf("0. Add a value to the list.\n");
	printf("1. Sort the list.\n");
}

int main(){
	Node* head = NULL;
	int choice, val;
	
	choice = 0;
	
	while(choice != 1){
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				printf("Enter the value: ");
				scanf("%d", &val);
				add_front(&head, val);
				break;
			case 1:
				mergesort(&head);
				printf("Sorted list: ");
				display_list(head);
				continue;
		}
	}
	
	return 0;
}

// Complexity: Best O(nLog(n)); Average O(nLog(n)); Worst O(n*log(n))
