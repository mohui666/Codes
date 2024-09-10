#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int c;
    struct Node *next;        
};

struct Node *create()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->c = -1;
    head->next = NULL;

    struct Node *pRear = head;

    int val = -1;
    printf("Input data(-1 to exit):\n");
    while(true)
    {
        scanf("%d",&val);
        if(val == -1)
        {
            printf("--------------------\n");
            break;
        }

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->c = val;
        newNode->next = NULL;
        
        pRear->next = newNode;
        pRear = newNode;
    }
    return head;
}

void foreach(struct Node *head)
{
    if(head==NULL)
    {
        return;
    }
    struct Node *pCurrent = head->next;
    while(pCurrent != NULL)
    {
        printf("%d\n",pCurrent->c);
        pCurrent = pCurrent->next;
    }
}

void Insert(struct Node *head,int oldval,int newval)
{
    if(NULL == head)
    {
        return;
    }

    struct Node *pPre = head;
    struct Node *pCurrent = pPre->next;

    while(pCurrent!=NULL)
    {
        if(pCurrent->c == oldval)
        {
            break;
        }
        pPre = pCurrent;
        pCurrent = pCurrent->next;
    }

#if 0
    if(pCurrent==NULL)
    {
        return;
    }
#endif

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->c = newval;
    newNode->next= NULL;
    
    newNode->next = pCurrent;
    pPre->next = newNode;
} 

void Clear(struct Node *head)
{
    if(head->next == NULL)
    {
        return;
    }

    struct Node *pCurrent = head->next;

    while(pCurrent!=NULL)
    {
        struct Node *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    head->next = NULL;
    printf("--------------------\n");
    printf("Already Cleared!\n");
}

void Remove(struct Node *head,int delVal)
{
    if(NULL == head)
    {
        return;
    }

    struct Node *pPre = head;
    struct Node *pCurrent = pPre->next;

    while(pCurrent!=NULL)
    {
        if(pCurrent->c == delVal)
        {
            pPre->next = pCurrent->next;
            free(pCurrent);
            break;
        }
        pPre = pCurrent;
        pCurrent = pCurrent->next;
    }
}

void Destroy(struct Node *head)
{
    Clear(head);
    free(head);
}

int main()
{
    struct Node *head = create();
    while(true)
    {               
        int n;
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            foreach(head);
            printf("--------------------\n");
            break;
        
        case 2:
            printf("Please enter the num you want to insert:\n");
            int a,b;
            scanf("%d %d",&a,&b);
            Insert(head,a,b);
            printf("--------------------\n");
            break;
        case 3:
            Clear(head);
            printf("--------------------\n");
            break;
        case 4:
            int c;
            scanf("Please enter the num you wang to remove:\n");
            Remove(head,c);
            printf("--------------------\n");
        }
    }
}