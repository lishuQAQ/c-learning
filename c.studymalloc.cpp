#include<stdio.h>
#include<malloc.h>
void f(int *q){
	*q=200;
}
int main(){
	int i=5;
	int *p=(int *)malloc(sizeof(int));
	p=&i;
	printf("%d\n",*p);
	f(p);
	printf("%d",*p);
	return 0;
}
