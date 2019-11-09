#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

typedef struct Node{
	char name[MAXLINE];
	struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void Enqueue(char name[]){
	Node* new_node = (Node *)(malloc(sizeof(Node)));
	strcpy(new_node->name, name);
	new_node->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = new_node;
		return;
	}
	rear->next = new_node;
	rear = new_node;
}

void Dequeue(){
	Node* temp = front;
	if(front == NULL){
		printf("---No one is waiting.\n");
		return;
	}
	if(front == rear){
		front = rear = NULL;
	} else {
		front = front->next;
	}
	
	printf("---%s just entered the train.\n", temp->name);
	
	free(temp);
}

void print_menu(){
	printf("\n--------------------------MENU------------------------\n");
	printf("0. Exit the program\n");
	printf("1. New person arrive\n");
	printf("2. Let a person enter the train\n");
}

void free_all_nodes(){
	Node* temp_node = NULL;
	while(front != NULL){
		temp_node = front;
		front = front->next;
		free(temp_node);
	}
}

int main(){
	int choice;
	char name[MAXLINE];
	
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter the name of the passenger: ");
				scanf("%s", name);
				Enqueue(name);
				printf("---%s just arrived.\n", name);
				break;
			case 2:
				Dequeue();
				break;
		}
	} while (choice != 0);
	
	free_all_nodes();
	
	return 0;
}
