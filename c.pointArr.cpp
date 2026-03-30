#include<stdio.h>//利用指针遍历数组，通过函数处理一维数组，掌握指针和数组下标的关系
void f(int *pArr,int len){
	int i;
	for(int i=0;i<len;++i){
		printf("%d ",pArr[i]);//*(pArr+i)等价于pArr[i] 也等价于a[i],等价于*(a+i)
		/*
		可以写为printf("%d",*(pArr+i));
		*/}
	printf("\n");
}
int main(){
	int a[4]={1,2,3,4};	
	int b[5]={3,4,5,8,9};
	int c[100]={2,6,7};
	f(a,4);
	f(b,5);
	f(c,100);
	return 0;
}
