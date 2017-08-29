#include<stdio.h>

#define MAXSIZE 10

typedef struct {
	int r[MAXSIZE + 1];
	int length;
}SqList;

/*
交换L中数组r的下标为i和j的值
*/
void swap (SqList *L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
} 

/*
冒泡排序初级版
*/
void BubbleSort_one (SqList *L) {
	int i,j;
	for(i = 1; i < L->length; i++){
		for(j = i + 1; j < L->length; j++){
			if (L->r[i] > L->r[j]) {
				swap(L, i, j);
			}
		}
	}
}

/*
输出数组
*/
void showList (SqList *L) {
	int i;
	for(i = 1; i < L->length; i++){
		printf("%d ", L->r[i]);
	}
	printf("\n");
}

int main () {
	SqList L = {{0,9,1,5,8,3,7,4,6,2}, 10};
	
	showList(&L);
	BubbleSort_one(&L);
	showList(&L);
}
	
