#include<stdio.h>
#include<malloc.h>
int main(){
	int len;
	int *pArr;
	int i;
	//动态构造一维数组
	printf("请输入你所要存放的元素个数：");
	scanf("%d",&len);
	pArr=(int *)malloc(4*len);
	/*动态的构造了一个一维数组，类似于 int pArr[len]
	该数组名为pArr,每个元素为int类型*/
	//对一维数组进行赋值
	for(i=0;i<len;i++){
		scanf("%d",&pArr[i]);
	}
	printf("一维数组输出的内容为:\n");
	//对一维数组进行输出
	for(i=0;i<len;i++){
		printf("%d\n",pArr[i]);
	}
	free(pArr);//释放动态分配的一维数组
	return 0;
}
