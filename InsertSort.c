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

int insertSort (SqList *L) {
    int i,j;
    int count = 0;

    for (i = 2; i < L->length; i++) {
        if (L->r[i] < L->r[i - 1]) {
            L->r[0] = L->r[i];
            count++;
            for (j = i - 1; L->r[j] > L->r[0]; j--) {
                L->r[j + 1] = L->r[j];
                count++;
            }
            L->r[j + 1] = L->r[0];
            count++;
        }
    }

    return count;
}

int main(int argc, char const *argv[]) {
    SqList L1 = {{0,5,3,4,6,2}, 6};

	showList(&L1);
	int count = insertSort(&L1);
	showList(&L1);
    printf("moveCnt:%d\n\n", count);

    return 0;
}
