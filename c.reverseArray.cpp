#include<stdio.h>//利用指针逆序遍历数组
int main(){
	int arr[5]={0,1,2,3,4};
	int *p;
	for(int i=4;i>=0;i--){
		p=&arr[i];
		printf("%d ",*p);
		p++;
	}
	return 0;
}
