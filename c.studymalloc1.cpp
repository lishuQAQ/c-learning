#include<stdio.h>
#include<malloc.h>
int main(){
	int *a=(int *)malloc(5*sizeof(int));
	if(a==NULL){
		printf("ÄÚ´æÉêÇëÊ§°Ü\n");
		return 1;
	}
	a[0]=1;
	a[1]=2;
	a[2]=3;
	a[3]=4;
	a[4]=5;
	for(int i=0;i<5;i++){
		printf("a[%d]=%d\n",i,a[i]);
	}
	free(a);
	a=NULL;
	return 0;
}
