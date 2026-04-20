#include<stdio.h>
#include<stdlib.h>
//初始化
#define MAXSIZE 100
typedef int ElemType;

typedef struct{
	ElemType *data;
	int length;
}SeqList;

SeqList* initList(){
	SeqList *L=(SeqList*)malloc(sizeof(SeqList));
	L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	L->length=0;
	return L;
}

//在尾部添加元素
int appendElem(SeqList *L,ElemType e){
	if(L->length>=MAXSIZE){
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length]=e;
	L->length++;
	return 1;
}

//遍历顺序表
void listElem(SeqList *L){
	for(int i=0;i<L->length;++i){
		printf("%d ",L->data[i]);
	}
	printf("\n");
}



//插入元素
int insertElem(SeqList *L,int pos,ElemType e){
	if(L->length>MAXSIZE){
		printf("表已经满了\n");
		return 0;
	}
	if(pos<1||pos>>L->length){
		printf("位置插入有误\n");
		return 0;
	}
	if(pos<=L->length){
		for(int i=L->length-1;i>=pos-1;i--){
			L->data[i+1]=L->data[i];
		}
		L->data[pos-1]=e;
		L->length++;
	}
	return 1;
}
//删除元素
int deleteElem(SeqList *L,int pos,ElemType *e){
	if(L->length==0){
		printf("空表\n");
		return 0;
	}
	if(pos<1||pos>L->length){
		printf("删除数据位置有误\n");
		return 0;
	}
	*e=L->data[pos-1];
	if(pos<L->length){
		for(int i=pos;i<L->length;i++){
			L->data[i-1]=L->data[i];
		}
	}
	L->length--;
	return 1;
}


//查找元素
int findElem(SeqList *L,ElemType e){
	if(L->length==0){
			printf("空表\n");
			return 0;
		}
	for(int i=0;i<L->length;i++){
		if(L->data[i]==e){
			return i+1;
		}
	}
	return 0;
}

int main(){
	SeqList *list=initList();
	printf("初始化成功，目前长度占用%d\n",list->length);
	printf("目前占用内存%zu字节\n",sizeof(list->data));
	appendElem(list,88);
	appendElem(list,33);
	appendElem(list,45);
	listElem(list);
	insertElem(list,2,18);
	listElem(list);
	ElemType delDate;
	deleteElem(list,2,&delDate);
	printf("所删除的数据为：%d\n",delDate);
	listElem(list);
	printf("45在表中位置为%d\n",findElem(list,45));
	return 0;
}
