#include<stdio.h>
#include<math.h>

struct point{
	int x,y;
};

int geometrycheck();
int area();
int pointcheck();

int main(){
	struct point P1,P2,P3;
	int rectanglecheck;
	do{
		printf("Coordinate of P1:\nx1= ");
		scanf("%d", &P1.x);
		printf("y1= ");
		scanf("%d", &P1.y);
		printf("Coordinate of P2:\nx2= ");
		scanf("%d", &P2.x);
		printf("y2= ");
		scanf("%d", &P2.y);
		rectanglecheck=geometrycheck(P1,P2);
	} while (rectanglecheck!=0||P1.x==P2.x && P1.y==P2.y);
	
	printf("The area of the rectangle determined by P1, P2= %d", area(P1,P2));
	
	printf("\n------------------------------------------");
	
	printf("\nRandom point check:\nEnter a coordinate:\nx= ");
	scanf("%d", &P3.x);
	printf("y= ");
	scanf("%d", &P3.y);
	printf("Result: %d", pointcheck(P3,P2,P1));
	
	return 0;
};

int geometrycheck(struct point P1, struct point P2){
	int check=((P2.x-P1.x)*(P1.x-P1.x)+(P2.y-P2.y)*(P2.y-P1.y));
	
	return check;
};

int area(struct point P1, struct point P2){
	int area;

	area= sqrt(pow((P2.y-P1.y)*(P2.x-P1.x),2));

	return area;
};

int pointcheck(struct point P3, struct point P2, struct point P1){
	if ((P1.x<P3.x&&P3.x<P2.x) && (P1.y<P3.y&&P3.y<P2.y)||(P1.x<P3.x&&P3.x<P2.x) && (P2.y<P3.y&&P3.y<P1.y)||(P2.x<P3.x&&P3.x<P1.x) && (P1.y<P3.y&&P3.y<P2.y)||(P2.x<P3.x&&P3.x<P1.x) && (P2.y<P3.y&&P3.y<P1.y)){
		return 1;
	}
	else return 0;
}
