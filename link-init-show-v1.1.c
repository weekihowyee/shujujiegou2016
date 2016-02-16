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

void main()
{
	int *e;
    Linklist L;
	e=(int *)malloc(sizeof(int));
    L=(Linklist)malloc(LEN);
	Init_Link(L);
    Show_Link(L);
	GetElem(L,2,e);
	printf("%d\n",*e);
	free(e);
}





