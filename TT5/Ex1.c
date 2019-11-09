#include <stdio.h>

#define MAX 1000

void swap(int* current_val, int* adjacent_val){
	int temp;
	
	temp = *current_val;
	*current_val = *adjacent_val;
	*adjacent_val = temp;
}

void reverseswap(int* current_val, int* adjacent_val){
	int temp;
	
	temp = *current_val;
	*current_val = *adjacent_val;
	*adjacent_val = temp;
}

void display(int arr[], int size){
	int i;
	
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

void print_menu(){
	printf("----------------------------------BUBBLE SORT----------------------------------\n");
}

int main(){
	print_menu();
	
	int size, i, n, check;
	
	printf("Enter a size for the array: ");
	scanf("%d", &size);
	
	int arr[size];
	
	printf("Enter elements of the array:\n");
	for(i = 0; i < size; i++){
		printf("Elements number %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	for(n = 1; n <= size / 2; n++){
		check = 0;
		
		for(i = 0; i < size-1;i++){
			if(arr[i] > arr[i+1]){
				swap(&arr[i], &arr[i+1]);
				check = 1;
			}
		}
		
		if(check == 0){
			break;
		}
		
		for(i = size - 1; i > 0; i--){
			if(arr[i] < arr[i-1]){
				reverseswap(&arr[i], &arr[i-1]);
				check = 1;
			}
		}
		
		if(check == 0){
			break;
		}
	}
	
	printf("Sorted array: ");
	display(arr, size);
}

// Best complexity: O(n); Average complexity: O(n^2); Worst complexity: O(n^2).
