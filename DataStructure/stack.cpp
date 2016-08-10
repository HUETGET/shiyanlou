#define MAXSIZE 1024
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INCREMENTAL 30
#include <iostream>
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
		exit(OVERFLOW);
	}
	S->top=S->base;

	S->size=MAXSIZE;
	return OK;
}
/*
 *destory the stack 
 */
Status DestoryStack(SqStack *S)
{
	free(S->base);
	S->base=NULL;
	S->top=S->base;
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

	*e=*(S->top)
	S->top-=sizeof(SElemType);
	s->size--;
	return OK;
}

void visit(SElemType e)
{

}

Status TraverseStack(SqStack *S, void(*visit)(SElemType))
{


}

int main()
{
	SqStack *S1, *S2;
	int a=InitStack(S1);
	if(a==OK)
	{
		for(int i=0;i!=S1->size;i++)
		{
			Push(S1,i);
		
		}
	SElemType *a;
	a=S1->top;
	while(a!=S1->base)
	{
		cout<<(*a)<<" ";
		a-=sizeof(SElemType);

	}

	}
	return ERROR;

}
