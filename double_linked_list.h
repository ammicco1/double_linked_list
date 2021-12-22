#include "element.h"

typedef struct double_linked_list{
    element *elem;
    struct double_linked_list *next, *prev;
} double_linked_list;

double_linked_list *inzialize_double_linked_list(element *elem);

void add_node(double_linked_list **list, element *elem);

int delete_node(double_linked_list **list, key *chiave);

int delete_node_from_index(double_linked_list **list, int index);

void print_all_list(double_linked_list *list);

bool list_include(double_linked_list *list, key *key);

void swap_node(double_linked_list **list, int index1, int index2);

int node_count(double_linked_list *list);

double_linked_list *get_node_by_index(double_linked_list *list, int index);

int get_max_key(double_linked_list *list);

int get_min_key(double_linked_list *list);

double_linked_list *get_prev_node(double_linked_list *list);

int get_node_information(double_linked_list *list, int index);

int partition(double_linked_list **list, int first_ind, int last_ind);

void quicksort(double_linked_list **list, int first_ind, int last_ind);