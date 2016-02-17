#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

Status initStack(sqStack *s)
{
    s->base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!s->base)
    {
        exit(0);
    }
    s->top=s->base;
    s->stackSize=STACK_INIT_SIZE;
    return OK;
}

Status Show_Stack(sqStack *s)
{
    ElemType *p,*q;
    p=s->base;
    printf("\n");
    while(p!=s->top)
    {
        printf("%d\t",*p);
        p++;
    }
    printf("\n");
    return OK;
}

Status Push(sqStack *s,ElemType e)
{
    if(s->top-s->base >=s->stackSize)
    {
        s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
        if(!s->base)
            exit(0);

        s->top=s->base+s->stackSize;
        s->stackSize+=STACKINCREMENT;
    }

    *(s->top)=e;
    s->top++;
    return OK;
}

Status Pop(sqStack *s,ElemType *e)
{
    if(s->top==s->base)
        return 0;
    *e=*--(s->top);
    return OK;
}

Status Init_Stack_Type(sqStack *s)
{

    int flag=1,temp;
	 initStack(s);
    while(flag)
    {
        printf("输入一个数：");
        scanf("%d",&temp);
        Push(s,temp);
        printf("Are you sure to continue(1/0):");
        scanf("%d",&flag);
    }
    return OK;
}

int Getlen(sqStack *s)
{
   return (s->top-s->base);
}

Status Free_All(sqStack *s)
{
    s->base=s->top;
}

Status Destroy(sqStack *s)
{
    int len=s->stackSize,i;
    ElemType *p,*q;
    for(i=0;i<len;i++)
    {
        p=s->base++;
        free(s->base);
        s->base=p;
    }
    s->base=s->top=NULL;
    s->stackSize=0;
    return OK;
}

void main()
{
    sqStack *s;
	int *e;
	e=(int *)malloc(sizeof(int));
	 s=(sqStack *)malloc(sizeof(sqStack));
    Init_Stack_Type(s);
    Show_Stack(s);
	Push(s,9);
	Show_Stack(s);
	Pop(s,e);
	Show_Stack(s);
	printf("\nlength is %d\n",Getlen(s));
	Free_All(s);
	Show_Stack(s);
	Destroy(s);
	free(e);
}













