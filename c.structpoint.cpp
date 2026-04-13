#include<stdio.h>
#include<string.h>
struct Student{
	int age;
	int score;
	char sex;
	char name[100];
};
//指针传入参数，修改结构体变量的内容；
void inputstudent(struct Student *s){
	s->age=24;
	//等价于(*s).age=24;
	s->score=98;
	strcpy(s->name,"张三");
	s->sex='b';
}
//指针传参并输出；
void outputstudent(struct Student *stu){
	printf("修改后：%d,%d,%c,%s",stu->age,stu->score,stu->sex,stu->name);
}
int main(){
	struct Student st1={32,89,'b',"张三"};
	printf("原内容：%d,%d,%c,%s\n",st1.age,st1.score,st1.sex,st1.name);
	inputstudent(&st1);
	outputstudent(&st1);
	
}
