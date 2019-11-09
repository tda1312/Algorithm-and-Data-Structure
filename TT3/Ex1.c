#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

typedef struct Node{
	char letter;
	struct Node* link;
}Node;

void push(Node** top, char name){
	Node* new_node = (Node *)(malloc(sizeof(Node)));
		
	new_node->letter = name;
		
	if(*top == NULL){
		new_node->link = NULL;
		*top = new_node;
	} else {
		new_node->link = *top;
		*top = new_node;
	}
	return;
}

void display(Node** top, int size){
	Node* temp_node = NULL;
	int i;
	
	if(*top == NULL){
		printf("NULL\n");
		return;
	}
	
	for(i = 0; i < size; i++){
		temp_node = (*top);
		printf("%c", temp_node->letter);
		(*top) = (*top)->link;
		free(temp_node);
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

void print_menu(){
	printf("\n--------------------------Print a string in reverse order------------------------\n");
}

int main(){
	Node* top = NULL;
	
	int i, size, choice;
	char name[MAXLINE];
	
	print_menu();
	
	printf("Enter a string: ");
	gets(name);
		
	while (name[size] != '\0'){
   	  	size++;
   	}
    
	for(i = 0; i < size; i++){
		push(&top, name[i]);
	}
	
	printf("Reverse order: ");
	display(&top, size);
	
	free_all_nodes(&top);
	
	return 0;
}
