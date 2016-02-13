#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}Sqlist;

Status Init_List(Sqlist *L)
{
    L->length=0;
    int flag1=1;
    while(flag1)
    {
        printf("please input a int number: ");
        scanf("%d",&(L->data[L->length]));
        L->length++;
        printf("are you sure to continue(1/0)? ");
        scanf("%d",&flag1);
    }
    return OK;
}

Status Show_List(Sqlist L)
{
    int i;
    if(L.length==0)
    {
        return ERROR;
    }
    for(i=0;i<L.length;i++)
    {
        printf("%d\t",L.data[i]);
    }
    printf("\n");
    printf("length=%d\n",L.length);
    return OK;
}

Status GetElem(Sqlist L,int i,ElemType *e)  //��ָ��eָ�����Ա�L�ĵ�i��Ԫ��
{
    if((i>L.length)||(i<1)||(L.length==0))
    {
        return ERROR;
    }
    *e=L.data[i-1];
    return OK;
}

Status List_Insert(Sqlist *L,int i,ElemType e)
{
    int j=0;
    if((i>L->length+1)||(i<1)||(L->length==MAXSIZE))
        return ERROR;
    if(i<=L->length)
    {
        for(j=L->length-1;j>=i-1;j--)
        {
            L->data[j+1]=L->data[j];
        }
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

void main()
{
    Sqlist L;
    Sqlist *p;
    p=&L;
    Init_List(p);  //��ʼ�����Ա�
    Show_List(L);   //��ӡ���Ա�
    if(GetElem(L,3,p))  //ȡĳ��λ�õ�Ԫ��
    {
        printf("%d",*p);
    }
    List_Insert(p,2,6); //��ĳ��λ�ò���Ԫ��
    Show_List(L);
}





