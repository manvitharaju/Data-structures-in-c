

struct _node_
{
    int data;
    struct _node_ *ptr;
};
typedef struct _node_ Node;

struct _linked_list_
{
    Node *head, *tail;
    unsigned int count;
    int op_status;
};

typedef struct _linked_list_ List;

List * initialize_list();
int insert_data_beg(List *, int);
int insert_data_end(List *, int);
int insert_after_position(List *my_list,int data,int pos);
int insert_data_after_value(List *, int data, int value);

Node * pull_data(List *my_list, int data);
int search(List *, int);
int get_min(List *);
int get_max(List *);
int count_nodes(List *);

int sort_list(List *my_list);
int swap_two_elements(List, int, int);

int merge_list(List *, List *);
List * intersection(List *, List *);

int delete_list_beginning(List *);
int delete_list_end(List *);
// Given two linked list in sorted order, merge them to list C which will be in
// sorted order in O(N) times

List * merge_sort(List *, List *);

List * free_list(List *);
int display_elements(List *my_list);
