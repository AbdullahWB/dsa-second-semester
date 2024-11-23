#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

typedef struct lqueue
{
	int *data;
	int front;
	int rear;
};

int createq(struct lqueue &q)
{
	q.data=new int[5];
	q.front=q.rear=0;
	return 0;
}
int queuein(struct lqueue &q,int i)
{
	if(q.rear==4)
	{
	q.data[q.rear]=i;
	q.rear=0;	
	}
	else
	{
	q.data[q.rear]=i;
	q.rear++;
	}
	return 0;
}
int queueout(struct lqueue &q)
{
	int v;
	if(q.front==4)
	{
	v=q.data[q.front];
	q.front=0;	
	}
	else
	{
     v=q.data[q.front];
    	q.front++;
	}
		return v;
}

int main()
{
	struct lqueue q;
	int t,i,s,c,len=4,rc;
	createq(q);
	for( i=1;i<=4;i++)
	 queuein(q, i);
	 
	printf("%d  %d input the start person and the countdown N0.:",q.front,q.rear); 
	
	scanf("%d",&c);
    rc=c;
	while(len>0)
	{
		while(rc>1)
		{
		  t=queueout(q);
		
		   queuein(q,t);
		  rc--;
		 
		 
		}
	    t=queueout(q);
		printf("%d ",t);
		rc=c;	
		len--;
	}
	 
	 
	/*for(i=1;i<=4;i++)
	{
		t=queueout(q);
		printf("%d ",t);
	}
	 
	return 0;*/
}
