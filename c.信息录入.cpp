#include<stdio.h>
#include<malloc.h>
struct Student{
	int age;
	int score;
	char name[100];
};
int main(){
	printf("这是一个学生个人信息录入系统\n");
	printf("输入需要录入系统的学生人数：\n");
	int num;
	struct Student t;
	printf("num=");
	scanf("%d",&num);
	struct Student *parr;
	parr=(struct Student*)malloc(num*sizeof(struct Student));
	
	//输入
	for(int i=0;i<num;++i){
		printf("请输入第%d个学生的个人信息\n",i+1);
		printf("age=");
		scanf("%d",&parr[i].age);
		printf("score=");
		scanf("%d",&parr[i].score);
		printf("name=");
		scanf("%s",parr[i].name);
		printf("\n");
	}
	
	//对成绩进行升序排序
	for(int i=0;i<num-1;i++){
		for(int j=0;j<=num-1-i;++j){
			if(parr[j].score>parr[j+1].score){
				t=parr[j];
				parr[j]=parr[j+1];
				parr[j+1]=t;	
			}
		}
	}
	
	
	//输出
	printf("对成绩进行升序排序的结果为：\n");
	for(int i=0;i<num;++i){
			printf("第%d个学生的个人信息为：\n",i+1);
			printf("age=%d\n",parr[i].age);
			printf("score=%d\n",parr[i].score);
			printf("name=%s\n",parr[i].name);
			printf("\n");
		}
		return 0;
		
}
