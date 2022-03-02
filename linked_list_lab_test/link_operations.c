#include "link.h"
#include<assert.h>

List *initialize()
{
    List *my_list;
    my_list=(List*)malloc(sizeof(List));
    if(my_list==NULL)//check if memeory is allocated or not
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
    if(newnode==NULL)//memory not allocated
        return NULL;
    if(my_list->node_count==0)//check if list is empty
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

int insert_at_end(List *my_list,int data)
{
    Node *newnode;
    newnode=get_node(data);
    if(newnode==NULL)//memory not allocated
        return NULL;
    if(my_list->node_count==0)//no nodes in list
    {
        my_list->head=my_list->tail=newnode;
    }
    else{
        my_list->tail->next=newnode;
        my_list->tail=newnode;
    }
    my_list->node_count++;
    return 1;
}

int display(List *my_list)
{
    Node *temp;
    if(temp==NULL)return NULL;
    temp=my_list->head;
    while(temp!=NULL)
    {
        printf("\t %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    //printf("\n %d",my_list->node_count);
    return 1;
}

int insert_after_pos(List *my_list,int data,int pos)
{
    Node *newnode,*temp;
    int i=1;
    newnode=get_node(data);
    if(newnode==NULL)return NULL;
    if(my_list->node_count==0)
    {
        my_list->head=my_list->tail=newnode;
    }
    if(pos<1 || pos>my_list->node_count)
    {
        return NULL;
    }
    else{
        temp=my_list->head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    my_list->node_count++;
    return 1;
}

int insert_after_value(List *my_list,int data,int value)
{
    Node *newnode,*temp;
    newnode=get_node(data);
    if(newnode==NULL)return NULL;
    if(my_list->node_count==0)
    {
        my_list->head=my_list->tail=newnode;
    }
    else{
        temp=my_list->head;
        while(temp!=NULL)
        {
            if(temp->data==value)
                break;
            temp=temp->next;

        }
        if(temp==NULL)
            return NULL;//element not found
        newnode->next=temp->next;
        temp->next=newnode;
    }
    my_list->node_count++;
    return 1;
}

int insert_at_middle(List *my_list,int data,int position)
{

    Node *newnode,*temp;
    int i;
    newnode=get_node(data);
    if(newnode==NULL)return NULL;
    if(my_list->node_count==0)
    {
        my_list->head=my_list->tail=newnode;
    }
    else{
        temp=my_list->head;
        for(i=2;i<=position-1;i++)
        {
            temp=temp->next;
            if(temp==NULL)
                break;
        }
        if(temp!=NULL)
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    my_list->node_count++;
    return 1;
}

int no_of_elements(List *my_list)
{
    return my_list->node_count;
}

int get_min_element(List *my_list)
{
    Node *temp;
    temp=my_list->head;
    int min=temp->data;
    for(temp=my_list->head;temp!=NULL;temp=temp->next)
    {
        if(min>temp->data)
            min=temp->data;
    }
    return min;
}

int get_max_element(List *my_list)
{
    Node *temp;
    temp=my_list->head;
    int max=temp->data;
    for(temp=my_list->head;temp!=NULL;temp=temp->next)
    {
        if(max<temp->data)
            max=temp->data;
    }
    return max;
}

int search_element(List *my_list,int search_ele)
{
    Node *temp;
    for(temp=my_list->head;temp!=NULL;temp=temp->next)
    {
        if(temp->data==search_ele)
            return 1;
    }
    return 0;
}

int sort_list(List *my_list)
{
    Node *temp1,*temp2;
    int element;
    for(temp1=my_list->head;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        {
            if(temp2->data<temp1->data)
            {
                element=temp1->data;
                temp1->data=temp2->data;
                temp2->data=element;
            }
        }
    }
    display(my_list);
    return 1;
}

//check this out
List *intersection(List *list_a,List *list_b)
{
    Node *temp;
    List *result;
    if(list_a->head == NULL || list_b->head == NULL) return NULL;

    result = initialize();

    temp = list_a->head;

    while(temp != NULL)
    {
        if(search_element(list_b, temp->data) && !search_element(result, temp->data ))
            assert(insert_at_end(result, temp->data));
        temp = temp->next;
    }
    return result;
}
//check this code
List *Union(List *list_a,List *list_b)
{
    List *result;
    Node *temp;
    result=initialize();
    temp=list_a->head;
    while(temp!=NULL)
    {
        insert_at_end(result,temp->data);
        temp=temp->next;
    }
    while(list_b!=NULL)
    {
        if(!search_element(list_a,list_b->head->data))
        {
            insert_at_end(result,list_b->head->data);
        }
        list_b=list_b->head->next;
    }
}

List *merge(List *list_a,List *list_b)
{
    List *result;
    Node *temp;
    temp=list_a->head;
    while(temp!=NULL)
    {
        insert_at_end(result,list_a->head->data);
        temp=temp->ptr;
    }
    while(list_b!=NULL)
    {
        insert_at_end(result,list_b->head->next);
        list_b=list_b->head->next;
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



