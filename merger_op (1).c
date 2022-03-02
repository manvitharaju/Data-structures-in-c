#include "merge.h"


List *initialize()
{
    List *my_list;
    my_list=(List*)malloc(sizeof(List));
    if(my_list==NULL)//memory is not allocated
        return NULL;
    my_list->head=my_list->tail=NULL;
    my_list->node_count=0;
    my_list->op_status=INIT;
    return my_list;
}

Node *get_node(int data)
{
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

int insert_at_beg(List *my_list,int data)
{
    Node *newnode;
    newnode=get_node(data);
    if(newnode==NULL)//memory is not allocated
        return NULL;
    if(my_list->node_count==0)//no elements in the list
    {
        my_list->head=my_list->tail=newnode;
    }
    else{
        newnode->next=my_list->head;
        my_list->head=newnode;
    }
    my_list->node_count++;
    return 1;
}

int display_list(List *my_list)
{
    Node *temp;
    temp=my_list->head;
    while(temp!=NULL)
    {
        printf("\t %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 1;
}

List *merge_list(List *list_a,List *list_b)
{
    List *list_c;
    list_c=initialize();
    Node *p1=list_a->head;//p1 points to head of list_a
    Node *p2=list_b->head;//p2 points to head of list_b
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<=p2->data)
        {
            insert_at_beg(list_c,p1->data);
            p1=p1->next;
        }
        else{
            insert_at_beg(list_c,p2->data);
            p2=p2->next;
        }
        if(p1==NULL && p2!=NULL)//if p1 is null and p2 not null add the elements of p2 to list_c
        {
            insert_at_beg(list_c,p2->data);
            p2=p2->next;
        }
        if(p2==NULL && p1!=NULL)//if p2 is null and p1 not null add the elements of p1 to list_c
        {
            insert_at_beg(list_c,p1->data);
            p1=p1->next;
        }
    }
    return list_c;
}


