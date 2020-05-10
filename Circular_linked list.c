#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void cirdisplay(struct node *last)
{
    struct node *p;
    if(last==NULL)
    {
        printf("\nList is empty");
        return;
    }
        p=last->next;
    do
        {
            printf("%d->",p->data);
            p=p->next;
        }
        while(p!=last->next);
        printf("\n");
}
struct node *ciraddbeg(struct node *last,int num)
{
    printf("\nEnter the number to be inserted->");
    scanf("%d",&num);
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    if(last==NULL)
    {
        temp->data=num;
        last=temp;
        temp->next=last;
        return last;
    }
    else
    {
        temp->data=num;
        temp->next=last->next;
        last->next=temp;
        return last;
    }
}
struct node *ciraddend(struct node *last,int num)
{
    printf("\nEnter the number to be inserted->");
    scanf("%d",&num);
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=last->next;
    last->next=temp;
    last=temp;
    return last;
}
struct node *cirdel(struct node *last,int num)
{
    printf("\nEnter the number to be deleted->");
    scanf("%d",&num);
    struct node *p,*temp;
    if(last==NULL)
    {
        printf("\nList is empty");
        return;
    }
    p=last;
    while(p->next->data!=num)
        p=p->next;
    temp=p->next;
    p->next=temp->next;
    if(temp==last)
    {
        last=p;
    }
    free(temp);
    return last;
}
struct node *concatenates(struct node *last,int num)
{
    char x;
    struct node *last1=NULL,*last2=NULL,*temp;
    printf("\nCreate list 1");
    last1=ciraddbeg(last1,num);
    do
    {
        last1=ciraddend(last1,num);
        printf("\nDo you want to add more nodes Y/N");
    }
    while(x=getch()!='N');
    printf("\nCreate list 2");
    last2=ciraddbeg(last2,num);
    do
    {
        last2=ciraddend(last2,num);
        printf("\nDo you want to add more nodes Y/N");
    }
    while(x=getch()!='N');
    printf("\n");
    cirdisplay(last1);
    cirdisplay(last2);
    printf("\nConcatenated List is\n");
    temp=last1->next;
    last1->next=last2->next;
    last2->next=temp;
    last=last2;
    cirdisplay(last);
    return last;
}
void main()
{
    struct node *last=NULL;
    int choice,num,num2;
    while(1)
    {
        printf("\n\t\t***********************Main Menu************************");
        printf("\n\t\t*\t1.Display                                      *");
        printf("\n\t\t*\t2.Add node to empty list/add at beginning      *");
        printf("\n\t\t*\t3.Add at end                                   *");
        printf("\n\t\t*\t4.Delete from list                             *");
        printf("\n\t\t*\t5.Concatenates                                 *");
        printf("\n\t\t*\t6.exit                                         *");
        printf("\n\t\t********************************************************\n->");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                cirdisplay(last);
                break;
            }
        case 2:
            {
                last=ciraddbeg(last,num);
                break;
            }
        case 3:
            {
                last=ciraddend(last,num);
                break;
            }
        case 4:
            {
                last=cirdel(last,num);
                break;
            }
        case 5:
            {
                last=concatenates(last,num);
                break;
            }
        case 6:
            {
                exit(1);
            }
        default :
            printf("\nInvalid Choice");
        }
    }
}
