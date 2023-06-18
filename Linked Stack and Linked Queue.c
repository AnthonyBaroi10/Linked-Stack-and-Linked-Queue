#include <stdio.h>
struct Queue
{
    int data;
    struct Queue *next;
}*head;

struct Stack
{
    int DATA;
    struct Stack *NEXT;
}*HEAD;

void Menu(int op)
{
    int data,operation;
    if(op==1)
    {
        while(1)
        {
            printf("\n\n 1.Enqueue\n 2.Dequeue\n 3.Show List\n 4.Exit\n\n Your choice: ");
            scanf("%d",&operation);

            switch(operation)
            {
            case 1:
                printf("\nEnter data to add: ");
                scanf("%d",&data);
                Enqueue(data);
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                Show_List_Queue();
                break;

            case 4:
                break;
            }
        }
    }

    if(op==2)
    {
        while(1)
        {
            printf("\n\n 1.Push\n 2.Pop\n 3.Show List\n 4.Exit\n\n Your choice: ");
            scanf("%d",&operation);

            switch(operation)
            {
            case 1:
                printf("\nEnter data to add: ");
                scanf("%d",&data);
                Push(data);
                break;

            case 2:
                Pop();
                break;

            case 3:
                Show_List_Stack();
                break;

            case 4:
                break;
            }
        }
    }
}
void Enqueue(int data)
{
    struct Queue *toLast;

    struct Queue *newNode;
    newNode=(struct Queue*) malloc(sizeof(struct Queue));

    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL)
        head=newNode;
    else
    {
        toLast = head;
        while(toLast->next!=NULL)
            toLast = toLast->next;

        toLast->next=newNode;
    }
}

void Dequeue()
{
    struct Queue *toDelete;
    if(head == NULL)
    {
        printf("\nList is empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;
        printf("\nData deleted: %d\n", toDelete->data);
        free(toDelete);
    }
}

void Show_List_Queue()
{
    struct Queue *temp;
    if(head==NULL)
        printf("\nList is empty");

    else
    {
        temp=head;
        printf("\nData in the list \n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void Push(int DATA)
{
    struct Stack *TOLAST;

    struct Stack *NEWNODE;
    NEWNODE=(struct Stack*) malloc(sizeof(struct Stack));

    NEWNODE->DATA=DATA;
    NEWNODE->NEXT=NULL;

    if(HEAD==NULL)
        HEAD=NEWNODE;
    else
    {
        TOLAST = HEAD;
        while(TOLAST->NEXT!=NULL)
            TOLAST = TOLAST->NEXT;

        TOLAST->NEXT=NEWNODE;
    }
}

void Pop()
{
    struct Stack *DELETE, *SECONDLAST;

    if(HEAD == NULL)
        printf("\nList is already empty.");
    else
    {
        DELETE = HEAD;
        SECONDLAST = HEAD;
        while(DELETE->NEXT != NULL)
        {
            SECONDLAST = DELETE;
            DELETE = DELETE->NEXT;
        }

        if(DELETE == HEAD)
            HEAD = NULL;
        else
            SECONDLAST->NEXT = NULL;

        printf("DATA deleted: %d",DELETE->DATA);
        free(DELETE);
    }
}

void Show_List_Stack()
{
    struct Stack *TEMP;
    if(HEAD==NULL)
        printf("\nList is empty");

    else
    {
        TEMP=HEAD;
        printf("\nData in the list \n");
        while(TEMP!=NULL)
        {
            printf("%d ",TEMP->DATA);
            TEMP=TEMP->NEXT;
        }
    }
}


int main()
{
    int choice, data;
    while(1)
    {
        printf("\n\n 1.Queue\n 2.Stack\n 3.Exit\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        case 2:
            Menu(choice);
            break;
        case 3:
            break;

        default:
            printf("Wrong choice.Try again\n\n");
        }
    }
    return 0;
}

