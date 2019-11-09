#include<stdio.h>

int checkdigit();

int main(){
	int isbn[10], i;
	
	printf("Enter the first 9 ISBN digits:\n");
	for (i=0;i<9;i++){
		printf("Digit no.%d: ",i+1);
		scanf("%d",&isbn[i]);
	}
	isbn[9]=checkdigit(isbn);
	
	printf("Complete ISBN: ");
	for (i=0;i<9;i++) 
   		printf("%d", isbn[i]);
   	printf("%d",isbn[9]);
	return 0;
};

int checkdigit(int isbn[]){
	int controlnumber, checkdigit, i, order;
	order=1;
	controlnumber=0;
	for (i=0;i<9;i++){
		controlnumber+=isbn[i]*order;
		order++;
	}
	checkdigit=controlnumber%11;
	return checkdigit;
}
