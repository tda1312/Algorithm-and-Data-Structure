#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define THRESHOLD 1000

typedef struct Node{
	int number;
	struct Node* link;
}Node;

void push(Node** top, int number){
	Node* new_node = (Node *)(malloc(sizeof(Node)));
		
	new_node->number = number;
		
	if(top == NULL){
		new_node->link = NULL;
		*top = new_node;
	} else {
		new_node->link = *top;
		*top = new_node;
	}
	return;
}

int pop(Node** top){
	Node* temp_node = *top;
	if(*top == NULL){
		return THRESHOLD;
	} else {
		*top = (*top)->link;
		return temp_node->number;
		free(temp_node);
	}
}

void display(Node* top, int order){
	Node* temp_node = top;
	
	printf("\nTower number %d: ", order);
	
	if(top == NULL){
		return;
	}
	
	while(temp_node != NULL){
		printf("%d ", temp_node->number);
		temp_node = temp_node->link;
	}
}


void print_menu(){
	printf("\n--------------------------MENU------------------------\n");
	printf("0. Exit the program.\n");
	printf("1. Solve the Hanoi Tower.\n");
}

int disk_1_place(Node* top1, Node* top2, Node* top3){
	if (top1 != NULL && top1->number == 1){
		return 1;
	} else if (top2 != NULL && top2->number == 1){
		return 2;
	} else if (top3 != NULL && top3->number == 1){
		return 3;
	}
}

void solving(int disk1place, int step, Node** top1, Node** top2, Node** top3){
	Node* temp1 = *top1;
	Node* temp2 = *top2;
	Node* temp3 = *top3;
	
	int n1, n2, n3;
	
	if (step % 2 == 0){
		if(disk1place == 1){
			push(&(*top3), pop(&(*top1)));
		} else if (disk1place == 2){
			push(&(*top1), pop(&(*top2)));
		} else if (disk1place == 3){
			push(&(*top2), pop(&(*top3)));
		}
	} else{
		if (disk1place == 1){
			n2 = pop(&(*top2));
			n3 = pop(&(*top3));
			 
			if (n2 < n3 && n3 != THRESHOLD){
				push(&(*top3), n3);
				push(&(*top3), n2);
			} else if (n2 > n3 && n2 != THRESHOLD){
				push(&(*top2), n2);
				push(&(*top2), n3);
			} else if (temp3 == NULL){
				push(&(*top3), n2);
			} else if (temp2 == NULL){
				push(&(*top2), n3);
			}
		} else if (disk1place == 2){
			n1 = pop(&(*top1));
			n3 = pop(&(*top3));
			
			if (n1 < n3 && n3 != THRESHOLD){
				push(&(*top3), n3);
				push(&(*top3), n1);
			} else if (n1 > n3 && n1 != THRESHOLD){
				push(&(*top1), n1);
				push(&(*top1), n3);
			} else if (temp3 == NULL){
				push(&(*top3), n1);
			} else if (temp1 == NULL){
				push(&(*top1), n3);
			}
		} else if (disk1place == 3){
			n1 = pop(&(*top1));
			n2 = pop(&(*top2));
			
			if (n1 < n2 && n2 != THRESHOLD){
				push(&(*top2), n2);
				push(&(*top2), n1);
			} else if (n1 > n2 && n1 != THRESHOLD){
				push(&(*top1), n1);
				push(&(*top1), n2);
			} else if (temp2 == NULL){
				push(&(*top2), n1);
			} else if (temp1 == NULL){
				push(&(*top1), n2);
			}
		}
	}
}

void free_all_nodes(Node** top){
	Node* temp_node = NULL;
	while(*top != NULL){
		temp_node = (*top);
		(*top) = (*top)->link;
		free(temp_node);
	}
}

int main(){
	Node* top1 = NULL;
	Node* top2 = NULL;
	Node* top3 = NULL;
	
	int choice, i, disk1place, num;
	
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter the number of disks: ");
				scanf("%d", &num);
				
				for(i = num; i >= 1; i--){
					push(&top1, i);
				}
				
				for(i = 0; i < pow(2, num); i++){
					display(top1, 1);
					display(top2, 2);
					display(top3, 3);
					printf("\n\n");
					disk1place = disk_1_place(top1, top2, top3);
					printf("\nStep %d:", i+1);
					solving(disk1place, i, &top1, &top2, &top3);
				}
				
				free_all_nodes(&top1);
				free_all_nodes(&top2);
				free_all_nodes(&top3);
				break;
			}
	} while (choice != 0);
	
	return 0;
}
