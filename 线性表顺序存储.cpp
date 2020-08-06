#include <stdio.h>
#include <stdlib.h>
#define Maxsize 50
typedef int ElemType;
typedef struct
{
    ElemType data[Maxsize];
    int length;
} Sqlist; //线性表的建立

bool ListInsert(Sqlist &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= Maxsize)
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
    if (i < i || i > L.length)
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
    {
        if (e == L.data[i])
        {
            return i + 1;
        }
    }
    return 0;
} //顺序表的按值查找

bool LocateSelect(Sqlist L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    return true;
}//顺序表的按位查找

void Listprint(Sqlist L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}//输出

int main()
{
    Sqlist L;
    bool ret;
    ElemType del;
    /*L.length=4;
  L.data[0]=1;
  L.data[1]=2;
  L.data[2]=3;
  L.data[3]=4;*///单一输入
    
    printf("please input L.length ");
    int n;
    scanf("%d", &L.length);
    printf("please input LNode ");
    for (int i = 0; i < L.length; i++)
        scanf("%d", &L.data[i]);//连续输入

    ret = ListInsert(L, 2, 60);
    if (ret)
    {
        printf("insertlist is successful\n");
        Listprint(L);
    }
    else
    {
        printf("insertlist is fail\n");
    }

    ret = ListDelete(L, 3, del);
    if (ret)
    {
        printf("deletelist is successful\n");
        printf("delletnode is %d\n", del);
        Listprint(L);
    }
    else
    {
        printf("deletelist is fail\n");
    }

    del = LocateElem(L, 3);
    if (del)
    {
        printf("LocateElem is successful\n");
        printf("3 is located in %d\n", del);
    }
    else
    {
        printf("LocateElem is fail\n");
    }
    
    ret = LocateSelect(L, 2, del);
    if (ret)
    {
        printf("LocateSelect is successful\n");
        printf("2(L) is %d\n", del);
    }
    else
    {
        printf("LocateSelect is fail\n");
    }
    system("pause");
}