#include<stdio.h>
void swap(int * p,int * q){
	int  t;
	t=*p;
	*p=*q;
	*q=t;
	return;
}
int main(){
	int a,b;
	printf("连续输入两个数字\n");
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("%d %d",a,b);
	return 0;
}
