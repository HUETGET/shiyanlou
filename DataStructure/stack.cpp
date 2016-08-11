#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INCREMENTAL 5
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef int Status;
typedef int SElemType;

/*
typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;
*/


typedef struct 
{
	SElemType *base;
	SElemType *top;
	int size;
}SqStack;
/*
 * initial the stack
 */
Status InitStack(SqStack* S)
{
	S->base=(SElemType*)malloc(MAXSIZE*sizeof(SElemType));
	if(!S->base)
	{
		printf("error in memery application!");
		exit(OVERFLOW);
	}
	S->top=S->base;

	S->size=MAXSIZE;
	return OK;
}
/*
 *destory the stack 
 */
Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->base=NULL;
	S->top=NULL;//S->top=S->base can not be passed 
	S->size=0;
	return OK;
}

Status ClearStack(SqStack *S)
{
	S->top=S->base;

	return OK;
}

Status IsEmpty(SqStack S)
{
	if(S.base==S.top)
	{
		return TRUE;
	
	}
	else 
		return FALSE;

}


int GetLenStack(SqStack *S)
{
	return (S->top-S->base)/sizeof(SElemType);

}
/*
 *
//push,pop,
Status Push(SqStack* S,SElemType e )
{
	if(S->top<MAXSIZE-1)
	{
		S->top++;
		S->data[S->top]=e;
		return OK;
	}
	else 
		return ERROR;
}
*/

Status Push(SqStack* S,SElemType e )
{
	if(S->size<=(S->top - S->base)/sizeof(SElemType))
	{
		S->base=(SElemType*)realloc(S->base,(S->size+INCREMENTAL)*sizeof(SElemType));
		if(!S->base)
			exit(OVERFLOW);
		S->top=S->base+S->size * sizeof(SElemType);
		S->size=S->size+INCREMENTAL;
	}
	*(S->top)=e;
	S->top+=sizeof(SElemType);
	return OK;

}
/*
 *
//Pop: pop out the top element of the stack s
Status Pop(SqStack *S,SElemType* e)
{
	if(S->top==-1)
	{
		return ERROR;

	}
	e=S->data[S->top];
	S->top--;
	return OK;
}

*/

/*
 * Pop(SqStack *S,SElemType e)
 * 
 */

Status Pop(SqStack *S,SElemType *e)
{
	if(S->top==S->base)
		return ERROR;

	*e=*(S->top);
	S->top-=sizeof(SElemType);
	S->size--;
	return OK;
}

void visit(SElemType e)
{
	printf("%d ",e);
}

Status TraverseStack(SqStack *S, void(*visit)(SElemType))
{
	SElemType a;
	while(S->top!=S->base)
	{
		a=*(S->base);
		visit(a);
		S->base+=sizeof(SElemType);
	}
	return OK;


}


int Getlength(SqStack S)
{
	return (S.top -S.base)/sizeof(SElemType);

}


Status GetTop(SqStack *S,SElemType *e)
{
    if(S->top>S->base)
    {
		*e=*(S->top-sizeof(SElemType));
		return OK;
    }
	return ERROR;


}

int main()
{
/*
	SqStack *S1, *S2;
	SElemType a=InitStack(S1);
	if(a==OK)
	{
		for(int i=0;i!=S1->size;i++)
		{
			Push(S1,i);
		
		}

		TraverseStack(S1,visit); 

	}
	printf("push number failed!\n");
	return ERROR;
*/

    SqStack S;
    if (InitStack(&S))
    {
        SElemType e;
        int i;

        printf("init_success\n");

        if (IsEmpty(S))
        {
            printf("Stack is empty\n");
        }

        for (i = 0; i < 10; i++)
        {
            Push(&S, i);
        }

        GetTop(&S, &e);
        printf("The first element is %d\n", e);

		printf("length is %d\n",Getlength(S));
        Pop(&S, &e);
        printf("Pop element is %d\n", e);

        TraverseStack(&S,*visit);
        if (DestroyStack(&S))
        {
            printf("\ndestroy_success\n");
        }
    }

}
