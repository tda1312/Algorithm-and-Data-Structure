#include<stdio.h>

int addition(int *, int *);

int main(){
	int a, b, addition;
	int *ptr1, *ptr2;
	printf("Enter the 1st value: ");
	scanf("%d",&a);
	printf("\nEnter the 2nd value: ");
	scanf("%d",&b);
	ptr1= &a; ptr2= &b;
	addition= *ptr1 + *ptr2;
	printf("\nSum of the 2 added values: %d",addition);
	return 0;
}
