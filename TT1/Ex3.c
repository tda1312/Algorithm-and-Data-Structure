#include<stdio.h>
#include<math.h>

struct Point{
	float x,y;
};

float Edistance();

int main(){
	
	struct Point A, B;
	printf("Coordinate of A:\nx1= ");
	scanf("%f", &A.x);
	printf("y1= ");
	scanf("%f", &A.y);
	printf("Coordinate of B:\nx2= ");
	scanf("%f", &B.x);
	printf("y2= ");
	scanf("%f", &B.y);
	
	float distance= Edistance(A,B);
	
	printf("Euclidean distance between two points: %.2f", Edistance(A,B));
	
	return 0;
};

float Edistance(struct Point A, struct Point B){
	
	float result= sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
	
	return result;
}
