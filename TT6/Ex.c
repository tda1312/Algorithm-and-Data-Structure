// Abstract Data Type : linked list

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
	int val;
	int largest;
	struct Node* left_node;
	struct Node* right_node;
}Node;

Node* insert_lackednode(Node* root, int value)
{
    if (root == NULL){
    	Node* new_node = (Node *)malloc(sizeof(Node));
    	
    	new_node->val = value;
    	new_node->left_node = new_node->right_node = NULL;
    	
    	root = new_node;
	} else {
    	root->right_node = insert_lackednode(root->right_node, value);
	}
	return root;
}

Node* build_tree(int arr[], int first, int last, int* size){
	if(first > last){
		return NULL;
	}
	
	Node* sub_root = NULL;
	int half = (first + last)/2;
	
	if((*size) != 0){
		sub_root = (Node *)malloc(sizeof(Node));
		sub_root->val = arr[half];
		sub_root->left_node = sub_root->right_node = NULL;
		
		(*size)--;
		sub_root->left_node = build_tree(arr, first, half-1, size);
		sub_root->right_node =  build_tree(arr, half+1, last, size );
	}
	return sub_root;
}

unsigned int count_leaf(Node* root)
{
	if(root == NULL){
		return 0;
	}
    
	if(root->left_node == NULL && root->right_node == NULL){
		return 1;
	} else{
		return count_leaf(root->left_node) + count_leaf(root->right_node);
	}
}

void check_max(int* max, Node* root){
	if(root->val > *max){
		*max = root->val;
	} else{
		return;
	}
}

void add_last_level(Node** root, int* middle_val, int lack){
	static int max = 0;
	
	if((*root)->val != *middle_val){
		check_max(&max, *root);
	}
	
	if(*root == NULL){
		return;
	}
	
	if((*root)->left_node == NULL && (*root)->right_node == NULL && lack > 0){
		Node* new_node1 = (Node *)malloc(sizeof(Node));
    	Node* new_node2 = (Node *)malloc(sizeof(Node));
    	
    	new_node1->val = (*root)->val;
		new_node2->val = max;
    	new_node1->left_node = new_node1->right_node = new_node2->left_node = new_node2->right_node = NULL;
    	
    	(*root)->left_node = new_node1;
    	(*root)->right_node = new_node2;
	} else{
		(*root)->largest = max;
		if(lack > 0){
			add_last_level(&(*root)->left_node, &(*middle_val), lack);
			add_last_level(&(*root)->right_node, &(*middle_val), lack);
		}
	}
}

void display(Node* root){
    if(root == NULL){
    	return;
    }
    printf("%d ", root->val);
    display(root->left_node);
    display(root->right_node);
}

void print_menu(){
	printf("\n---------------------MENU---------------------\n");
	printf("0. Exit the program.\n");
	printf("1. Add an ascending array and build tree.\n");
}

int main(){
	Node* root = NULL;
	int choice, size, h, n, lack, leaves, i;
	
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter array size: ");
				scanf("%d", &size);
				h = round(log(size) / log(2)); //height
				n = pow(2, h); //total leaf nodes required
				int arr[size], subsize;
				subsize = size;
				
				int* size_ptr = &subsize;
				
				for(i = 0; i < size; i++){
					printf("Enter element number %d: ", i+1);
					scanf("%d", &arr[i]);
				}
				
				root = build_tree(arr, 0, size, size_ptr);
				
				leaves = count_leaf(root);
				lack = (n - (leaves * 2)) / 2;
				
				if(lack > 0){
					int sub_arr[lack];
					
					for(i = 0; i < lack; i++){
						sub_arr[i] = arr[size-1];
						root = insert_lackednode(root, sub_arr[i]);
					}
				}
				
				leaves = count_leaf(root);
				printf("Leaves: %d\n", leaves);
				
				int* middle_val = &root->val;
				
				add_last_level(&root, &(*middle_val), lack);
				
				printf("Tree built: ");
				display(root);
				
				continue;
		}
	} while(choice != 0);
	
	return 0;
}
