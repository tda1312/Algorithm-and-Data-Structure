#include <stdio.h>

int multiplication(int x, int y){
	if (x == 0||y == 0){
		return 0;
	}
	
	if(x > 0 && y > 0||x < 0 && y < 0){
		if (y > 0){
			return (x + multiplication(x, y-1));
		}
	}
	
	if(x > 0 && y < 0){
		return -(multiplication(x, -y));
	}
	
	if(x < 0 && y > 0){
		return -(multiplication (-x, y));
	}
}

void print_menu(){
	printf("-------------------------------------MENU-------------------------------------\n");
	printf("0. Exit the program.\n");
	printf("1. Enter 2 numbers and calculate the product.\n");
	
}

int main(){
	int choice, x, y, result;
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
	
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter the 1st number: ");
				scanf("%d", &x);
				printf("Enter the 2nd number: ");
				scanf("%d", &y);
				result = multiplication(x, y);
				printf("The product of 2 input numbers: %d\n", result);
				break;
		}
	} while (choice != 0);
	
	return 0;
}
