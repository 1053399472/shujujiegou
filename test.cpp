#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define Maxsize 50

typedef struct
{
    ElemType data[Maxsize];
    int length;
} sqlist;

bool Insertlist(sqlist &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= Maxsize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.length++;
    L.data[i - 1] = e;
    return true;
}
bool deleteList(sqlist &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i - 1; j < L.length; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

int select(sqlist &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (e == L.data[i])
            return i + 1;
    }
    return 0;
}

void prinflist(sqlist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf(" %d", L.data[i]);
    }
    printf("\n");
}
int main()
{
    sqlist L;
    bool ret;
    ElemType e;
    L.length = 4;
    L.data[0] = 0;
    L.data[1] = 0;
    L.data[2] = 0;
    L.data[3] = 0;
    ret = Insertlist(L, 2, 2);
    if (ret)
    {
        prinflist(L);
    }
    ret = deleteList(L, 1, e);
    if (ret)
    {
        prinflist(L);
        printf("%d", e);
    }
    printf("\n");
    e = select(L, 1);
    printf("%d", e);
    system("pause");
}