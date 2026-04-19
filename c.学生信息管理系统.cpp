#include<stdio.h>
#include<stdlib.h>
#define NAME_LEN 100

//定义结构体
struct Student{
	int id;
	char name[NAME_LEN];
	float CHscores;
	float MAscores;
	float total;
};

//输入学生个人信息
void inputStudent(struct Student *st,int numm){
	for(int i=0;i<numm;++i){
		printf("请输入第%d个学生信息:\n",i+1);
		printf("id=");
		scanf("%d",&st[i].id);
		printf("name=");
		scanf("%s",st[i].name);
		printf("CHscores=");
		scanf("%f",&st[i].CHscores);
		printf("MAscores=");
		scanf("%f",&st[i].MAscores);
		st[i].total=st[i].CHscores+st[i].MAscores;
		printf("total=%f\n",st[i].total);
		
	}
}

//删除学生个人信息
void deleteStudentbyid(struct Student *st,int *dnum){
	int deid;
	printf("请输入要删除的学生学号：");
	scanf("%d",&deid);
	int i;
	int found=0;
	for(int i=0;i<*dnum;++i){
		if(deid==st[i].id){
			found=1;
			break;
		}
	}
	if(found==0){
		printf("该学号不存在\n");
		return;
	}
	for(int j=i;j<*dnum-1;++j){
		st[j]=st[j+1];
	}
	
	*dnum=*dnum-1;
	printf("删除成功\n");
}

//修改个人信息
void modifyStudentbyid(struct Student *st,int *mnum){
	int modid,choice;
	printf("请输入要修改信息学生的学号：");
	scanf("%d",&modid);
	int i,found=0;
	for(i=0;i<*mnum;++i){
		if(modid==st[i].id){
			found=1;
			break;
		}
	}
	if(found==0){
		printf("该学生不存在\n");
		return;
	}
	
	printf("请选择要修改的信息：\n");
	printf("1.修改学号\n");
	printf("2.修改姓名\n");
	printf("3.修改语文成绩\n");
	printf("4.修改数学成绩\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("新学号：id=");
			scanf("%d",&st[i].id);
			break;
		case 2:
			printf("新姓名：name=");
			scanf("%s",st[i].name);
			break;
		case 3:
			printf("新语文成绩：CHscores=");
			scanf("%f",&st[i].CHscores);
			break;
		case 4:
			printf("新数学成绩：MAscores=");
			scanf("%f",&st[i].MAscores);
			break;
	}
	st[i].total=st[i].MAscores+st[i].CHscores;
}

//查询学生
void searchStudentbyid(struct Student *st,int snum){
	int seid;
	printf("请输入要查询的学生的学号：");
	scanf("%d",&seid);
	int i,found=0;
	for(int i=0;i<snum;++i){
		if(seid==st[i].id){
			found=1;
			break;
		}
	}
	if(found==0){
		printf("该学生不存在\n");
		return;
	}
	printf("该学生个人信息如下：\n");
	printf("id=%d",st[i].id);
	printf("name=%s",st[i].name);
	printf("CHscores=%f",st[i].CHscores);
	printf("MAscores=%f",st[i].MAscores);
	printf("total=%f",st[i].total);
}

//显示所有学生
void showStudentbyid(struct Student *st,int shnum){
	struct Student t;
	for(int i=0;i<shnum-1;i++){
			for(int j=0;j<shnum-1-i;++j){
				if(st[j].total>st[j+1].total){
					t=st[j];
					st[j]=st[j+1];
					st[j+1]=t;	
				}
			}
		}
	printf("所有学生对成绩进行升序排序的结果为：\n");
	for(int i=0;i<shnum;++i){
		printf("第%d个学生的个人信息为：\n",i+1);
		printf("id=%d\n",st[i].id);
		printf("name=%s\n",st[i].name);
		printf("CHscores=%f\n",st[i].CHscores);
		printf("MAscores=%f\n",st[i].MAscores);
		printf("total=%f\n",st[i].total);
		printf("\n");
		}				
}

//保存到文件中
void saveToFile(struct Student *st,int num){
	FILE *fp=fopen("student.txt","w");
	if(fp==NULL){
		printf("保存失败！\n");
		return;
	}
	for(int i=0;i<num;i++){
		fprintf(fp,"%d %s %f %f %f\n",
	    	st[i].id,
		    st[i].name,
			st[i].CHscores,
			st[i].MAscores,
			st[i].total);
	}
			fclose(fp);
			printf("保存成功！共保存 %d 个学生\n", num);
}

//文件读取学生信息
void loadFromFile(struct Student **st,int *num){
	FILE *fp = fopen("student.txt", "r");
		if(fp == NULL){
			printf("暂无文件数据！\n");
			return;
		}
		free(*st);
		*st = NULL;
		*num = 0;
		struct Student temp;
		while(fscanf(fp, "%d %s %f %f %f",
			&temp.id,
			temp.name,
			&temp.CHscores,
			&temp.MAscores,
			&temp.total) != EOF){
	
			*st = (struct Student*)realloc(*st, (*num+1)*sizeof(struct Student));
			(*st)[*num] = temp;
			(*num)++;
		}
	
		fclose(fp);
		printf("读取成功！共读取 %d 个学生\n", *num);
}


int main(){
	int n,num=0;
	struct Student *pArr=NULL;
	while(1){ 
		printf("\n=======================\n");
		printf("学生信息管理系统\n");
		printf("请选择所需操作，输入对应数字选项\n");
		printf("1.添加学生\n");
		printf("2.删除学生\n");
		printf("3.修改学生信息\n");
		printf("4.查询学生\n");
		printf("5.显示所有学生\n");
		printf("6.保存到文件\n");
		printf("7.从文件读取\n");     
		printf("8.退出系统\n");
		printf("=======================\n");
		scanf("%d",&n);  

		switch(n){
			case 1: {
				int addNum;  
				printf("请输入需要添加的学生人数：");
				scanf("%d",&addNum);

				pArr = (struct Student*)realloc(pArr, (num+addNum)*sizeof(struct Student));
				if(pArr==NULL){
					printf("内存分配失败!\n");
					return 1;
				}
				inputStudent(pArr + num, addNum);
				num += addNum;  
				break;
			}
			case 2:
				if(num==0){
					printf("还没有学生信息\n");
					break;
				}
				deleteStudentbyid(pArr,&num);
				break;
			case 3:
				if(num==0){
					printf("还没有学生信息\n");
					break;
				}
				modifyStudentbyid(pArr,&num);
				break;
			case 4:
				if(num==0){
					printf("还没有学生信息\n");
					break;
				}
				searchStudentbyid(pArr,num);
				break;
			case 5:
				if(num==0){
					printf("还没有学生信息\n");
					break;
				}
				showStudentbyid(pArr,num);
				break;
			case 6:
				saveToFile(pArr, num); 
				break;
			case 7:
				loadFromFile(&pArr, &num); 
				break;
			case 8:
				printf("感谢使用!\n");
				free(pArr);
				return 0;
			default:
				printf("输入错误，请重新选择\n");
		}
	}
	return 0;
}
