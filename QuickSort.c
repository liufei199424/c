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
	for(i = 0; i < L->length; i++){
		printf("%d ", L->r[i]);
	}
	printf("\n");
}

void qSort (SqList *L, int low, int high) {
    int pivot;
    if (low < high) {
        pivot = partition(L, low, high);

        qSort(L, low, pivot - 1);
        qSort(L, pivot + 1, high);
    }
}

int partition (SqList *L, int low, int high) {
    int pivotkey = L->r[low];
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey) {
            high--;
        }
        swap(L, low, high);     // 将比枢轴记录小的记录交换到低端

        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        swap(L, low, high);
    }

    return low;
}

/*
快速排序
*/
void quickInsert (SqList *L) {
    qSort(L, 0, L->length - 1);
}

int main(int argc, char const *argv[]) {
    SqList L1 = {{50,10,90,30,70,40,80,60,20}, 9};

	showList(&L1);
	quickInsert(&L1);
	showList(&L1);
    // printf("moveCnt:%d\n\n", count);

    SqList L2 = {{50,10,90,30,70,40,80,60,20}, 9};

    return 0;
}
