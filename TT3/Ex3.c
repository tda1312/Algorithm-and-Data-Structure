#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int num;
	struct Node* link;
}Node;

void push(Node** top, int num){
	Node* new_node = (Node *)(malloc(sizeof(Node)));
		
	new_node->num = num;
		
	if(*top == NULL){
		new_node->link = NULL;
		*top = new_node;
	} else {
		new_node->link = *top;
		*top = new_node;
	}
	return;
}

void pop(Node** top){
	Node* temp_node = (*top);
	
	(*top) = (*top)->link;
	free(temp_node);
	
	return;
}

int s2compare(Node** top){
	Node* temp_node = (*top);
	temp_node = temp_node->link;
	if ((*top)->num == temp_node->num){
		return 0;
	} else{
		return 1;
	}
}

int s4compare(Node** top, int guess){
	Node* temp_node = (*top);
	temp_node = temp_node->link;
	if((*top)->num < guess && guess < temp_node->num || (*top)->num > guess && guess > temp_node->num){
		return 1;
	}
	return 0;
}

void free_all_nodes(Node** top){
	Node* temp_node = NULL;
	while(*top != NULL){
		temp_node = (*top);
		(*top) = (*top)->link;
		free(temp_node);
	}
}

void print_menu(){
	printf("\n--------------------------MENU--------------------------\n");
	printf("0. Exit the program\n");
	printf("1. Play the game\n");
}

int main(){
	Node* top = NULL;
	
	srand (time(NULL));
	int iSecret;
	int i, choice, draw, guess, chance, result;
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				chance = 0;
				iSecret = rand() % 9 + 1;
				push(&top, iSecret);
				printf("You performed a draw.\n");
				do{
					i = 1;
					if(chance == 1){
						printf("You guessed the wrong number.\n");
					}
					do{
						printf("Perform the second draw? (1 = Yes; 0 = No, wait!)\n");
						scanf("%d", &draw);
					} while(draw == 0);
					do{
						if(i == 0){
							printf("You have to draw again.\n");
							pop(&top);
						}
						iSecret = rand() % 9 + 1;
						push(&top, iSecret);
						printf("You performed the second draw.\n");
						i = s2compare(&top);
					} while(i == 0);
					printf("Guess a number: ");
					scanf("%d", &guess);
					i = s4compare(&top, guess);
					if(i == 0){
						chance++;
					}
					if(chance == 2){
						printf("You lost. Better luck next time!\n");
						pop(&top);
						i = 2;
					}
				} while(i == 0);
				if(i == 1){
					printf("Congratulations! You won the game!");
				}
				break;
		}
		free_all_nodes(&top);
	} while(choice != 0);
	
	return 0;
}
