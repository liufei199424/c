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
int BubbleSort_one (SqList *L) {
	int count = 0;
	int i,j;
	for(i = 1; i < L->length; i++){
		for(j = i + 1; j < L->length; j++){
			count ++;
			if (L->r[i] > L->r[j]) {
				swap(L, i, j);
			}
		}
	}

	return count;
}

/*
冒泡排序中级版
*/
int BubbleSort_two (SqList *L) {
	int count = 0;
	int i,j;
	for(i = 1; i < L->length; i++){
		for(j = L->length - 1; j > i; j--) {
			count ++;
			if (L->r[j] < L->r[j - 1]) {
				swap(L, j, j - 1);
			}
		}
	}

	return count;
}

/*
冒泡排序高级版
*/
int BubbleSort_three (SqList *L) {
	int count = 0;
	int i,j;
	int flag = 1;
	for(i = 1; i < L->length && flag == 1; i++){
		flag = 0;
		for(j = L->length - 1; j > i; j--) {
			count ++;
			if (L->r[j] < L->r[j - 1]) {
				swap(L, j, j - 1);
				flag = 1;
			}
		}
	}

	return count;
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
	SqList L1 = {{0,1,3,4,2,5,6,7,8,9}, 10};
	SqList L2 = {{0,1,3,4,2,5,6,7,8,9}, 10};
	SqList L3 = {{0,1,3,4,2,5,6,7,8,9}, 10};

	// 初级冒泡
	showList(&L1);
	int count = BubbleSort_one(&L1);
	showList(&L1);
	printf("count:%d\n\n", count);

	// 中级冒泡
	showList(&L2);
	count = BubbleSort_two(&L2);
	showList(&L2);
	printf("count:%d\n\n", count);

	// 高级冒泡
	showList(&L3);
	count = BubbleSort_three(&L3);
	showList(&L3);
	printf("count:%d\n\n", count);
}
