#include<stdio.h>
int main(){
	int i=10;
	int *p=&i;
	int **q=&p;
	int ***t=&q;
	printf("%d",***t);
	return 0;
}
