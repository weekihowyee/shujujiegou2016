#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define LEN sizeof(struct Node) //NodeµÄ´óÐ¡

typedef int ElemType;
typedef int Status;

typedef  struct Node
{
    ElemType data;
    struct Node *Next;
}Node;
typedef struct Node *Linklist;

Linklist Init_Link()
{
    Linklist L,p1,p2;
    int flag=1;
    p1=(Linklist)malloc(LEN);
    printf("PLEASE INPUT A NUM:");
    scanf("%d",&(p1->data));
    printf("\nAre you sure to continue(1/0):");
    scanf("%d",&flag);
    L=p1;
    p2=L;
    while(flag)
    {
        p2->Next=p1;
        p2=p1;
        p1=(Linklist) malloc(LEN);
        printf("PLEASE INPUT A NUM:");
        scanf("%d",&(p1->data));
        printf("\nAre you sure to continue(1/0):");
        scanf("%d",&flag);
    }
		p2->Next=p1;
        p2=p1;
    p2->Next=NULL;
    return L;
}

Status Show_Link(Linklist L)
{
    Linklist p;
    p=L;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->Next;
    }
    return OK;
}

ElemType* GetElem(Linklist L,int i)
{
    int j;
	int tes;
	ElemType *e;
    Linklist p;
    p=L;
    j=1;

    while(p && j<i)
    {
        p=p->Next;
        j++;
    }

    e=&(p->data);

    return e;
}

void main()
{
	int *e;
    Linklist L=NULL;
    L=Init_Link();
    Show_Link(L);
	e=GetElem(L,2);
	printf("%d\n",*e);
}





