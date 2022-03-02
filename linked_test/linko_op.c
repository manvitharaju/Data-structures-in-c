

#include<stdlib.h>
#include<assert.h>
#include "linko.h"

List * initialize_list()
{
    List *my_list;

    my_list = (List *)malloc(sizeof(List));

    if(my_list == NULL) return NULL; // check whether memory allocated

    my_list->head = my_list->tail = NULL; // List is empty
    my_list->count = 0;

    return my_list;
}

Node * get_node(int data)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    new_node->ptr = NULL;

    return new_node;
}

int insert_data_beg(List *my_list, int data)
{
    Node *new_node;

    new_node = get_node(data);

    if(new_node == NULL) return 0;

    if(my_list->count == 0){ // check whether list is empty
        my_list->head = my_list->tail = new_node;
    }
    else {
        new_node->ptr = my_list->head;
        my_list->head = new_node;
    }

    my_list->count++;

    return 1;

}

int insert_data_end(List *my_list, int data)
{
     Node *new_node;

    new_node = get_node(data);

    if(new_node == NULL) return 0;

    if(my_list->count == 0){ // check whether list is empty
        my_list->head = my_list->tail = new_node;
    }
    else {
    my_list->tail->ptr = new_node;
    my_list->tail = new_node;
    }

    my_list->count++;

    return 1;

}

int insert_after_position(List *my_list,int data,int pos)
{
    Node *new_node,*temp;
    int i;
    new_node=get_node(data);
    if(new_node==NULL)return 0;
    if(my_list->count==0)
    {
        my_list->head=my_list->tail=new_node;
    }
    else
    {
        temp=my_list->head;
        for(i=2;i<=pos-1;i++)
        {
            temp=temp->ptr;
            if(temp==NULL)//if you have reached the end of the list
                break;
        }
        if(temp!=NULL)
        {
            new_node->ptr=temp->ptr;
            temp->ptr=new_node;
        }
    }my_list->count++;
 return 1;
}
int insert_data_after_value(List *my_list, int data, int value)
{
    Node *temp,*new_node;
    new_node=get_node(data);
    if(new_node==NULL)return 0;
    if(my_list->count==0)
    {
        my_list->head=my_list->tail=new_node;
    }
    else
    {
        for(temp=my_list->head;temp!=NULL;temp=temp->ptr)
        {
            if(temp->data==data)
            {
                new_node->ptr=temp->ptr;
                temp->ptr=new_node;
            }
        }

    }
    my_list->count++;
    return 1;
}

int count_nodes(List *my_list)
{
    return my_list->count;
}
// checks whether data is present or not. returns 1 if present, 0 otherwise
int search(List *my_list, int data)
{
    Node *temp;

    if(my_list->head == NULL) return 0;

    for(temp = my_list->head; temp != NULL; temp = temp->ptr)
    {
        if(temp->data == data) return 1;
    }
    return 0;

}

Node * pull_data(List *my_list, int data)
{
     Node *temp;

    if(my_list->head == NULL) return NULL;

    for(temp = my_list->head; temp != NULL; temp = temp->ptr)
    {
        if(temp->data == data) return temp;
    }
    return NULL;
}

int sort_list(List *my_list)
{
    Node *temp1,*temp2;
    int element;
    for(temp1=my_list->head;temp1!=NULL;temp1=temp1->ptr)
    {
        for(temp2=temp1->ptr;temp2!=NULL;temp2=temp2->ptr)
        {
            if(temp2->data<temp1->data)
            {
                element=temp1->data;
                temp1->data=temp2->data;
                temp2->data=element;
            }
        }
    }
    display_elements(my_list);
    return 1;
}
/*
int search(List *my_list, int data);
{
    Node *temp;
    temp = my_list->head;

    while(temp != NULL)
    {
        if(temp->data == data)
            return 1;
        temp = temp->ptr;
    }
    return 0;
}
*/

List * merge_sort(List *list_a, List *list_b)
{
    Node *temp;
    List *result;
     if(list_a->head == NULL || list_b->head == NULL) return NULL;
     result=initialize_list();
    temp=list_a->head;
    while(temp->ptr!=NULL)
    {
        temp-temp->ptr;
        assert(insert_data_end(result,temp->data));
    }
    temp->ptr=list_b;
    return result;
}

List *intersection(List *list_a, List *list_b)
{
    List *result;
    Node *temp;


    if(list_a->head == NULL || list_b->head == NULL) return NULL;

    result = initialize_list();

    temp = list_a->head;

    while(temp != NULL)
    {
        if(search(list_b, temp->data) && !search(result, temp->data ))
            assert(insert_data_end(result, temp->data));
        temp = temp->ptr;
    }
    return result;
}

//deleting node at the beginning
int delete_list_beginning(List * my_list)
{
    Node *temp;
    if (my_list -> head == NULL && my_list->tail == NULL)
    {
       return 0;
    }

    if(my_list->head == my_list->tail)
    {
        free(my_list->head);
        my_list->head = my_list->tail = NULL;
    }
    else
    {
      temp = my_list->head;
      my_list ->head = my_list->head->ptr;
      free(temp);
    }
    my_list->count--;
    return 1;
}

int delete_list_end(List *my_list)
{
     Node *temp;
    if (my_list -> head == NULL && my_list->tail == NULL)
    {
       return 0;
    }

    if(my_list->head == my_list->tail)
    {
        free(my_list->head);
        my_list->head = my_list->tail = NULL;
    }
    else{
        temp = my_list->head;

        for(; temp->ptr != my_list->tail; temp = temp->ptr);

        free(temp->ptr);
        temp->ptr = NULL;

        my_list->tail = temp;

        }
        my_list->count--;
        return 1;

}

int push(List *stack, int data)
{
    return insert_data_beg(stack,data);
}

int display_elements(List *my_list)
{
    Node* temp=my_list->head;
    int node_count=0;
    if(temp==NULL)
        return NULL;//list is empty
    while(temp!=NULL)
    {
        printf("\n %d",temp->data);
        temp=temp->ptr;
        node_count++;
    }
    return node_count;
}

