//Queue is kind of data structure that FIFO
//
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int Status;
typedef int SElemType;

//node foe Queue
typedef struct Qnode
{
	struct Qnode* next;
	SElemType data;

}Qnode;
typedef Qnode *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
	
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(Qnode));
    if(!Q->front)
    {
        perror("failed in malloc");
        exit(OVERFLOW);
    }
    Q->front->next=NULL;
    return OK;
    
}

Status DestoryQueue(LinkQueue *Q)
{
    while(Q->front)  //注意这里的循环条件不是Q->front!=Q->rear而是Q->front
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}
/*
 *清空队列，先销毁后初始化
 */
Status ClearQueue(LinkQueue *Q)
{
    DestoryQueue(Q);
    InitQueue(Q);
}


Status IsEmpty(LinkQueue *Q)
{
/*
    if(Q->front=Q->rear) //此条件不完全正穷，可能会存在循环队列
        return TRUE;
    else
        return FALSE;
*/
    if(Q->front->next == NULL)
        return TRUE;
    else
        return FALSE;
}

//获取队列长度的方法就是采用类似复制标记的方法
SElemType GetLength(LinkQueue *Q)
{
    QueuePtr Qptr=Q->front;
    SElemType length=0;
    while(Q->rear!=Qptr)
    {
        Qptr=Qptr->next;
        ++length;    
    }
    return length;
}

QueuePtr GetHead(LinkQueue *Q)
{

}
//在队列尾部插入元素

Status Enqueue(LinkQueue *Q,SElemType e)
{
    QueuePtr p=(QueuePtr)malloc(sizeof(Qnode));
    if(p!=NULL)
    {
        p->data=e;
        p->next=NULL;
     //   p->next=Q->rear;//next 的方向反了，next在rear的后面
        Q->rear->next=p;
        Q->rear=p;
        return OK;
    }
    else
        exit(OVERFLOW);   
}

Status Dequeue(LinkQueue *Q,SElemType *e)
{
    QueuePtr P=Q->front;
    while(P!=Q->rear)
    {
        if(P->next==Q->rear)
        {
            *e=Q->rear->data;
            free(Q->rear);
            P->next=NULL;
            Q->rear=P;
            break;
        }
        P=P->next;
    }
    return OK;


}
/*
 * 访问元素
 */
void visit(SElemType e)
{
    printf("%d ", e);
}

/*
 * 遍历队列
 */
Status TraverseQueue(LinkQueue Q, void (*visit)(SElemType))
{
    QueuePtr p = Q.front->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    return OK;
}


int main()
{
	LinkQueue Q;
	InitQueue(&Q);
	SElemType popData[10];
	printf("Initial the queue sucessfully!\n");
	for(SElemType i=0;i<10;i++)
	{
	    Enqueue(&Q,i);
	}
	printf("Enqueue sucessfully!\n");
	
	TraverseQueue(Q,*visit);
    printf("\n");
	for(SElemType i=0;i<10;i++)
	{
	    Dequeue(&Q,popData+i);
	    TraverseQueue(Q,*visit);
	    printf("\n");
	}
	printf("Dequeue sucessfully!\n");
	
	TraverseQueue(Q,*visit);

}













