#include<stdio.h>//利用指针将两个数从大到小排序
void max(int *p,int *q){
	int t;
	if(*p<*q){
		t=*p;
		*p=*q;
		*q=t;
	}
}
int main(){
	int a,b;
	printf("请输入两个整数：");
	scanf("%d%d",&a,&b);
	max(&a,&b);
	printf("按从大到小排序结果为：%d,%d",a,b);
	return 0;
}
