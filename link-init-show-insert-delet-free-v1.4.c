#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define LEN sizeof(struct Node) //Node的大小

typedef int ElemType;
typedef int Status;

typedef  struct Node
{
    ElemType data;
    struct Node *Next;
}Node;
typedef struct Node *Linklist;


Linklist Init_Link(Linklist L)
{
	 Linklist p1,p2;
    int flag=1;
	L->data=0;
    p2=L;
    while(flag)
    {

        p1=(Linklist) malloc(LEN);
        printf("PLEASE INPUT A NUM:");
        scanf("%d",&(p1->data));
		L->data++;
		 p2->Next=p1;
        p2=p1;
        printf("Are you sure to continue(1/0):");
        scanf("%d",&flag);
    }
		p2->Next=p1;
        p2=p1;
    p2->Next=NULL;
    return OK;
}

Status Show_Link(Linklist L)
{
    Linklist p;
    p=L->Next;
	printf("\n长度是：%d\n",L->data);
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->Next;
    }
    printf("\n\n");
    return OK;
}

Status GetElem(Linklist L,int i,ElemType *e)
{
    int j;
	int tes;
    Linklist p;
    p=L->Next;
    j=1;

    while(p && j<i)
    {
        p=p->Next;
        j++;
    }

    *e=(p->data);

    return OK;
}

Status Insert_List(Linklist L,ElemType c,int i) //将元素c插入L的第i个位置
{
    Linklist P,s,p1,p2;
    int j;
    if(i>L->data)
        return ERROR;
    P=L->Next;
    s=(Linklist)malloc(LEN);
    s->data=c;
    for(j=0;j<i-2;j++)
    {
        P=P->Next;
    }
    p1=P;
    p2=P->Next;
    p1->Next=s;
    s->Next=p2;
    L->data++;
    return OK;
}

Status Delete_List(Linklist L,int i)
{
    int j;
    Linklist P;
    P=L->Next;
    for(j=0;j<i-2;j++)
    {
        P=P->Next;
    }
    P->Next=P->Next->Next;
    L->data--;
    return OK;
}

Status Free_All(Linklist L)
{
    Linklist p,q;
    p=L->Next;
    while(p)
    {
        q=p->Next;
        free(p);
        p=q;
    }
    return OK;
}

void main()
{
	int *e;
    Linklist L;
	e=(int *)malloc(sizeof(int));
    L=(Linklist)malloc(LEN);
	Init_Link(L);
	Show_Link(L);
	Insert_List(L,17,2);
    Show_Link(L);
	GetElem(L,2,e);
	printf("%d\n",*e);
	Delete_List(L,2);
	Show_Link(L);
	free(e);
}





