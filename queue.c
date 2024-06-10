#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Queue
{
	int front, rear, capacity;
	int* array;
};

struct Queue* createQueue(int capacity)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	if (!queue) 
	    return NULL;
	queue->front = -1;
    	queue->rear = -1;
	queue->capacity = capacity;
	queue->array = (int*) malloc(queue->capacity*sizeof(int));
	if (!queue->array) 
	    return NULL;
	return queue;
}

void insert(struct Queue* queue, int value);
int deletion(struct Queue* queue);
void display(struct Queue* queue);

int main()
{
    struct Queue* queue = createQueue(5);
    while(5>4)
    {
        int choice, value;
        printf("1.Insert element\n");
        printf("2.Delete element\n");
        printf("3.Display queue\n");
        printf("4.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            insert(queue,value);
        }
        else if(choice==2)
        {
            deletion(queue);
        }
        else if(choice==3)
        {
            display(queue);
        }
        else if(choice==4)
        {
            break;
        }
        else
        {
            printf("Enter a valid choice\n");
        }
    }
}

void insert(struct Queue* queue, int value)
{
    if((queue->front==0 && queue->rear==queue->capacity-1) || (queue->rear==(queue->front-1)%(queue->capacity-1)))
    {
        printf("\n Queue is Full\n");
        return;
    }
    else
    {
        int value;
        printf("Enter the element to be added: ");
        scanf("%d",&value);
        if(queue->front==-1)
        {
            queue->front=queue->rear=0;
            queue->array[queue->rear]=value;
        }
        else if(queue->rear==queue->capacity-1 && queue->front!=0)
        {
            queue->rear=0;
            queue->array[queue->rear]=value;
        }
        else
        {
            queue->rear++;
            queue->array[queue->rear]=value;
        }
    }
}

int deletion(struct Queue* queue)
{
    if (queue->front==-1)
    {
        printf("\n Queue is Empty\n");
        return 0;
    }
    int val=queue->array[queue->front];
    queue->array[queue->front]=-1;
    if (queue->front==queue->rear)
    {
        queue->front=-1;
        queue->rear=-1;
    }
    else if(queue->front==queue->capacity-1)
        queue->front=0;
    else
        queue->front++;
    return val;
}

void display(struct Queue* queue)
{
    if (queue->front==-1)
    {
        printf("\n Queue is Empty\n");
        return 0;
    }
    printf("\nElements in Queue are: \n");
    if (queue->rear>=queue->front)
    {
        for(int i=queue->front;i<=queue->rear;i++)
            printf("%d\n", queue->array[i]);
    }
    else
    {
        for (int i=queue->front;i<queue->capacity;i++)
            printf("%d\n", queue->array[i]);
 
        for (int i=0;i<=queue->rear;i++)
            printf("%d\n", queue->array[i]);
    }
}
