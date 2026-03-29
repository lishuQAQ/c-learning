#include<stdio.h>
void calculate(int a,int b,int *sum,int *product){
	*sum=a+b;
	*product=a*b;
}
int main(){
	int n,m;
	printf("请输入两个整数：");
	scanf("%d%d",&n,&m);
	int s,p;
	calculate(n,m,&s,&p);
	printf("两数之和为：%d，两数之积为：%d",s,p);
	return 0;
}
