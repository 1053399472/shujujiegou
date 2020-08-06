#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} Sqlist; //线性表顺序存储

bool ListInsert(Sqlist &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
} //顺序表的插入

bool ListDelete(Sqlist &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
} //顺序表的删除

int LocateElem(Sqlist L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
} //顺序表的按值查找

bool locationselect(Sqlist L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    return true;
} //顺序表的按位查找

void PrintList(Sqlist L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%4d", L.data[i]);
    }
    printf("\n");
} //顺序表的输出

int main()
{
    Sqlist L;
    bool rel;
    ElemType del;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.length = 4;
    rel = ListInsert(L, 2, 60);
    if (rel)
    {
        printf("插入成功\n");
        PrintList(L);
    }
    else
    {
        printf("插入失败\n");
    }
    rel = ListDelete(L, 1, del);
    if (rel)
    {
        printf("删除成功\n");
        printf("删除元素值为%d\n", del);
        PrintList(L);
    }
    else
    {
        printf("删除失败\n");
    }
    del = LocateElem(L, 3);
    if (del)
    {
        printf("查找成功\n");
        printf("元素位置为%d\n", del);
        PrintList(L);
    }
    else
    {
        printf("查找失败\n");
    }
    rel = locationselect(L, 2, del);
    if (rel)
    {
        printf("查找成功\n");
        printf("元素值为%d\n", del);
        PrintList(L);
    }
    else
    {
        printf("查找失败\n");
    }
    system("pause");

    return 0;
}