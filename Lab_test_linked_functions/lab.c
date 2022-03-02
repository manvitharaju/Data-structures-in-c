#include "lab.h"
#include <assert.h>


List *initialize()
{
    List *my_list;
    my_list=(List*)malloc(sizeof(List));
    if(my_list==NULL)return NULL;//memory not allocated
    my_list->head=my_list->tail=NULL;
    my_list->op_status=INIT;
    my_list->n_count=0;
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
    if(newnode==NULL)return NULL;//memory is not allocated
    if(my_list->n_count==0)//list is empty
    {
        my_list->head=my_list->tail=newnode;
    }
    else{
        newnode->next=my_list->head;
        my_list->head=newnode;
    }
    my_list->n_count++;
    return 1;
}

int display_list(List *my_list){
    Node *temp;
    if(my_list->n_count==0)//no elements in list
        return NULL;
    for(temp=my_list->head;temp!=NULL;temp=temp->next)
    {
        printf("\t %d",temp->data);
    }
    printf("\n");
    return 1;
}

List *unique_data(List *list)
{
    Node *temp1,*temp2;
    List *list_a;
    temp1=list->head;
    temp2=list->head->next;
    list_a=initialize();
    //printf("\n %d \t %d",temp1->data,temp2->data);
   for(temp1,temp2;temp1!=NULL,temp2!=NULL;temp1=temp1->next,temp2=temp2->next)
   {
        if(temp1->data!=temp2->data)
           {
               insert_at_beg(list_a,temp1->data);
            //printf("\t %d",temp1->data);
           }
    }
    insert_at_beg(list_a,list->tail->data);
    return list_a;
}

List *even(List *list_a)
{
    Node *temp=list_a->head;
    List *list_b;
    list_b=initialize();
    while(temp!=NULL)
    {
        if(temp->data%2==0)
            insert_at_beg(list_b,temp->data);
        temp=temp->next;
    }
    return list_b;
}
List *odd(List *list_a)
{
    Node *temp=list_a->head;
    List *list_c;
    list_c=initialize();
    while(temp!=NULL)
    {
        if(temp->data%2!=0)
            insert_at_beg(list_c,temp->data);
        temp=temp->next;
    }
    return list_c;
}

List *union_list(List *list_b,List *list_c)
{
    Node *temp=list_b->head;
    Node *temp1=list_c->head;
    List *list_d;
    list_d=initialize();
    while(temp!=NULL)
    {
        insert_at_beg(list_d,temp->data);
        temp=temp->next;
    }
    while(temp1!=NULL)
    {
        insert_at_beg(list_d,temp1->data);
        temp1=temp1->next;
    }
    return list_d;
}

