#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;
void push();
void pop();
void sort();
void display();
int length();
int main()
{
    int choice;
    while(1)
    {
        printf("enter your choice\n");
        printf("1 for push\n2 for pop\n3 for display\n4 for sorting of linked list and display\n5 for find the length\n6 for exit the prog.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:sort();break;
            case 5:printf("%d elements are present in list\n",length());break;
            case 6:exit(0);
            default:printf("WRONG CHOICE!!\nTRY AGAIN WITH CORRECT CHOICE(1-6):\n");
        }
    }
}
void push()
{
    int num;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data that you want to enter\n");
    scanf("%d",&num);
    temp->data=num;
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}
void pop()
{
    struct node *temp;
    int pos,l;
    l=length();
    if(l==0)
    {
        printf("list is empty!!\n");
    }
    else
    {   printf("%d elements are in the linked list\nwhich one you want to delet,enter position\n",l);
        scanf("%d",&pos);
        if(pos>l)
        {
            printf("invalid location\n");
        }
        else if(pos==1)
        {
            temp=front;
            front=temp->link;
            temp->link=NULL;
            printf("%d is deleted\n",temp->data);
            free(temp);
        }
        else
        {
            struct node *p=front,*q;
            int i=1;
            while(i<pos-1)
            {
                p=p->link;
                i++;
            }
            q=p->link;
            p->link=q->link;
            q->link=NULL;
            printf("%d is deleted\n",q->data);
            free(q);
        }
    }
}
int length()
{
    int i=0;
    struct node *p=front;
    while(p)
    {
        i++;
        p=p->link;
    }
    return i;
}
void display()
{
    struct node *p=front;
    printf("data of linked are:\n");
    while(p)
    {
        printf("%d\n",p->data);
        p=p->link;
    }
}
void sort()
{
    int swap;
    struct node *s=front,*t;
    for(s;s!=NULL;s=s->link)
    {
        for(t=s->link;t!=NULL;t=t->link)
        {
            if(s->data>t->data)
            {
                swap=s->data;
                s->data=t->data;
                t->data=swap;
            }
        }
    }
}
