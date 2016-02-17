#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr Front,Rear;
}LinkQueue;

Status initQueue(LinkQueue *q)
{
    q->Front=q->Rear=(QueuePtr)malloc(sizeof(QNode));
    if(!q->Front)
        exit(0);
    q->Front->next=NULL;
    return OK;
}

Status Inser_Queue(LinkQueue *q,ElemType e)
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(p==NULL)
        exit(0);
    p->data=e;
    p->next=NULL;
    q->Rear->next=p;
    q->Rear=p;
    return OK;
}

Status DeletQueue(LinkQueue *q,ElemType *e)
{
    QueuePtr p;
    p=q->Front->next;
    *e=p->data;
    q->Front->next=p->next;
    if(q->Rear==p)
        q->Rear=q->Front;
    free(p);
    return OK;
}

Status inti_by_type(LinkQueue *q)
{
    int flag=1,tmp;
    initQueue(q);
    q->Rear->next=NULL;
    while(flag)
    {
        printf("PLEASE INPUT A NUM:");
        scanf("%d",&tmp);
        Inser_Queue(q,tmp);
        printf("Are you sure to continue(1/0):");
        scanf("%d",&flag);
    }

    return OK;
}

Status Show_Queue(LinkQueue *q)
{
    QueuePtr x,y;
    x=q->Front->next;
    printf("\n");
    while(x!=q->Rear)
    {
        printf("%d\t",x->data);
        x=x->next;
    }
	printf("%d\t",x->data);
    printf("\n");
}

void main()
{
    LinkQueue *q=(LinkQueue *)malloc(sizeof(LinkQueue));
    inti_by_type(q);
    Show_Queue(q);
}







