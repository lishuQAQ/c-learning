#include<stdio.h>//利用指针给一个数赋新值
int main(){
	int num=50;
	int * ptr;
	ptr=&num;
	*ptr=100;
	printf("%d",num);
	return 0;
}
