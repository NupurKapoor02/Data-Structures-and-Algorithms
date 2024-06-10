#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

void display(struct node* s1);
struct node* insert_begin(struct node * s1);
void insert_end(struct node* start);
void insert_index(struct node* start);

int main()
{
    struct node* start=(struct node *)malloc(sizeof(struct node));
    start->data=NULL;
    int choice;
    while(2>1)
    {
        printf("\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Insert at an index");
        printf("\n4.Display the queue");
        printf("\n5.Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        if(choice==1)
        {
            start=insert_begin(start);
        }
        else if(choice==2)
        {
            insert_end(start);
        }
        else if(choice==3)
        {
            insert_index(start);
        }
        else if(choice==4)
        {
            display(start);
        }
        else if(choice==5)
        {
            break;
        }
        else
        {
            printf("Enter a valid choice");
        }
    }
}

struct node* insert_begin(struct node* start)
{
    if(start->data==NULL)
    {
        int a;
        printf("Enter the value to be inserted:");
        scanf("%d",&a);
        start->data=a;
        start->link=NULL;
        return start;
    }
    else
    {
        struct node* ptr=(struct node *)malloc(sizeof(struct node));
        int a;
        printf("Enter the value to be inserted:");
        scanf("%d",&a);
        ptr->data=a;
        ptr->link=start;
        return ptr;
    }
}

void insert_end(struct node* start)
{
    if(start->data==NULL)
    {
        int a;
        printf("Enter the value to be inserted:");
        scanf("%d",&a);
        start->data=a;
        start->link=NULL;
        return start;
    }
    else 
    {
        struct node* ptr=(struct node *)malloc(sizeof(struct node));
        int a;
        printf("Enter the value to be inserted:");
        scanf("%d",&a);
        while(start->link!=NULL)
        {
            start=start->link;
        }
        ptr->data=a;
        ptr->link=NULL;
        start->link=ptr;
    }
}

void insert_index(struct node* start)
{
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    int a,i;
    int c=1;
    printf("Enter the index at which you want to insert the node:");
    scanf("%d",&i);
    printf("Enter the value to be inserted:");
    scanf("%d",&a);
    while(c<i)
    {
        start=start->link;
        c++;
    }
    ptr->data=a;
    ptr->link=start->link;
    start->link=ptr;
}

void display(struct node* s1)
{
    printf("Linked List: ");
    struct node *ptr=s1;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
