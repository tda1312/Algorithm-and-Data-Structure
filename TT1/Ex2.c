#include<stdio.h>

int rdarrsum(int arr[], int arrsize);

int main(){
	int i, n;
	printf("Enter a size of the array: ");
	scanf("%d", &n);
	int rdarr[n], sum;
	for (i=0; i<n; i++){
		int r= i + 1;
		printf("Enter value number %d in the array: ", r);
		scanf("%d", &rdarr[i]);
	}
	sum=rdarrsum(rdarr,n);
	printf("Sum of values in the array: %d", sum);
	return 0;
};

int rdarrsum(int arr[], int arrsize){
	int i, sum=0;
	for (i=0; i<arrsize; i++){
		sum += arr[i];
	}
	return sum;
}
