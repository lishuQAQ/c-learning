#include<stdio.h>//利用指针使指针指向的变量加10
void addTen(int *x){
	*x+=10;
}
int main(){
	int n=10;
	printf("传入函数前：%d\n",n);
	addTen(&n);	
	printf("传入函数后：%d",n);
	return 0;
}
