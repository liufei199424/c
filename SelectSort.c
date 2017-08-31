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
输出数组
*/
void showList (SqList *L) {
	int i;
	for(i = 1; i < L->length; i++){
		printf("%d ", L->r[i]);
	}
	printf("\n");
}

int selectSort(SqList *L) {
    int i,j,min;
    int count = 0;

    for (i = 1; i < L->length; i++) {
        min = i;
        for (j = i + 1; j < L->length; j++) {
            if (L->r[i] > L->r[j]) {
                min = j;
            }
        }

        if (min != i) {
            count ++;
            swap(L, min, i);
        }
    }

    return count;
}

int main(int argc, char const *argv[]) {
    SqList L1 = {{0,1,3,4,2,5,6,7,8,9}, 10};

	showList(&L1);
	int count = selectSort(&L1);
	showList(&L1);
    printf("交换次数:%d\n\n", count);

    return 0;
}
