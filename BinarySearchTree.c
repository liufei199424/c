#include <stdio.h>

typedef struct BiTree {
    int data;
    struct BiTree *lchild;
    struct BiTree *rchild;
}BiTree, *BiTree;

//在二叉排序树中插入查找关键字key
BiTree InsertBST(BiTree *t,int key)
{
    if (t == NULL)
    {
        t = new BiTree();
        t->lchild = t->rchild = NULL;
        t->data = key;
        return t;
    }

    if (key < t->data)
        t->lchild = InsertBST(t->lchild, key);
    else
        t->rchild = InsertBST(t->rchild, key);

    return t;
}

//n个数据在数组d中，tree为二叉排序树根
void CreateBiTree(BiTree *tree, int d[], int n)
{
    for (int i = 0; i < n; i++)
        tree = InsertBST(tree, d[i]);
}

int main(int argc, char const *argv[]) {
    int numbers = {9,1,2,8,7,3,5,6,4};

    BiTree bT = {0, NULL, NULL};
    CreateBiTree(&bT, numbers, 9);

    return 0;
}
