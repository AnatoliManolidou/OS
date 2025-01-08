#include <stdio.h>

void sum(int *a, int *b, int *c, int *summ){

	*summ = *a + *b + *c;
}

int main(){

	int a, b, c, summ;
	int *ptra = &a;
	int *ptrb = &b;
	int *ptrc = &c;
	int *ptrsum = &summ;
	
	//Getting the values from the keyboard
	printf("Enter 3 integers\n");
	scanf("%d %d %d", ptra, ptrb, ptrc); 

	sum(&a, &b, &c, &summ); //Calling function sum

	printf("The sum of %d, %d and %d is equal to:%d\n", a, b, c, summ);

	return(0);
}

