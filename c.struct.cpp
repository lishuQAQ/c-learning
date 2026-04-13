#include<stdio.h>
#include<string.h>
struct Student{
	int age;
	char sex;
	char name[100];
};
int main(){
	struct Student st;
	//赋值1.单个
	st.age=10;
	strcpy(st.name,"张三");
	st.sex='b';
	//整体赋值
	struct Student st2={21,'g',"李四"};
	struct Student st3;
	//用指针为结构体变量赋值；
	struct Student * s=&st3;
	s->age=23;
	strcpy(s->name,"王五");
	s->sex='b';
	//输出；
	printf("%d,%s,%c\n",st.age,st.name,st.sex);
	printf("%d,%s,%c\n",st2.age,st2.name,st2.sex);
	printf("%d,%s,%c\n",s->age,s->name,s->sex);
	return 0;
}
