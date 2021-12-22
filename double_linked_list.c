#include "double_linked_list.h"
#include <stdio.h>
#include <stdbool.h>

double_linked_list *inzialize_double_linked_list(element *elem){
    double_linked_list *tmp = (double_linked_list *) malloc(sizeof(double_linked_list));

    tmp -> elem = elem;
    tmp -> next = NULL;
    tmp -> prev = NULL;

    return tmp;
}

void add_node(double_linked_list **list, element *elem){
    double_linked_list *tmp = inzialize_double_linked_list(elem);
    double_linked_list *tmp_list = *list;
    tmp -> next = NULL;

    if(*list == NULL){
        *list = tmp;
    }else{
        while(tmp_list -> next){
            tmp_list = tmp_list -> next;
        }

        tmp_list -> next = tmp;
        tmp -> prev = tmp_list;
    }
}

bool list_include(double_linked_list *list, key *key){
    while(list){
        if(compare_key(list -> elem -> chiave, key) == 0){
            return true;
        }
        list = list -> next;
    }

    return false;
}

double_linked_list *get_prev_node(double_linked_list *list){
    return list -> prev;
}

int delete_node(double_linked_list **list, key *chiave){
    double_linked_list *tmp = *list;

    if(!list_include(tmp, chiave)){
        printf("element %d not included!\n", get_key(chiave));
    }

    if(compare_key(tmp -> elem -> chiave, chiave) == 0){
        if(tmp -> next){
            *list = (*list) -> next;
            (*list) -> prev = NULL;
            return 0;
        }else{
            *list = NULL;
            return 0;
        } 
    }

    while(tmp){
        if(compare_key(tmp -> elem -> chiave, chiave) == 0){
            if(tmp -> next){
                (tmp -> prev) -> next = tmp -> next;
                return 0;
            }else{
                (tmp -> prev) -> next = NULL;
                return 0;
            } 
        }

        tmp = tmp -> next;
    }

    return -1;
}

int delete_node_from_index(double_linked_list **list, int index){
    int i;
    double_linked_list *tmp = *list;

    if(index > node_count(tmp)){
        printf("index's too high\n");
        return -1;
    }

    if(index == 0){
        *list = (*list) -> next;
        (*list) -> prev = NULL;
        return 0;
    }

    for(i = 0; i != index; i++){
        tmp = tmp -> next;
    }

    if(tmp -> next == NULL){
        tmp -> prev -> next = NULL;
        return 0;
    }

    tmp -> prev -> next = tmp -> next;
    tmp -> next -> prev = tmp -> prev; 

    return 0;
}

void print_all_list(double_linked_list *list){
    int i = 0;

    if(list == NULL){
        printf("the list is empty!\n");
    }else{
        while(list -> next){
            if(get_element_key(list -> elem) < 10){
                printf("---------\n|   %d   |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
            }else if(get_element_key(list -> elem) >= 100){
                printf("---------\n|  %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
            }else{
                printf("---------\n|   %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
            }
		    list = list -> next;
		    i++;
	    }
	    if(get_element_key(list -> elem) < 10){
            printf("---------\n|   %d   |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
        }else if(get_element_key(list -> elem) >= 100){
            printf("---------\n|  %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
        }else{
            printf("---------\n|   %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
        }
    }
}

void swap_node(double_linked_list **list, int index1, int index2){
    int i = 0;
    double_linked_list *tmp = *list, *prevtmp, *node1, *node2;

    if(index1 != index2){
        while(tmp){
            if(i == index1){
                node1 = tmp;
            }

            if(i == index2){
                node2 = tmp;
            }

            tmp = tmp -> next;
            i++;
        }

        if(node1 -> prev != NULL){
            node1 -> prev -> next = node2;
        }

        if(node2 -> prev != NULL){
            node2 -> prev -> next = node1;
        }

        if(node1 -> prev == NULL){
            *list = node2;
        }
        
        if(node2 -> prev == NULL){
            *list = node1;
        }

        tmp = node1 -> next;
        prevtmp = node1 -> prev;
        node1 -> next = node2 -> next;
        node2 -> next = tmp;
        node1 -> prev = node2 -> prev;
        node2 -> prev = prevtmp;
    }
}

int node_count(double_linked_list *list){
    int counter = 0;

    if(list == NULL){
        return 0;
    }else{
        while(list){
            counter++;
            list = list -> next;
        }
    }

    return counter;
}

double_linked_list *get_node_by_index(double_linked_list *list, int index){
    int i = 0;

    if(index > node_count(list)){
        printf("index too high for get node!\n");
        return NULL;
    }

    while(i < index){
        i++;
        list = list -> next;
    }

    return list;
}

int get_max_key(double_linked_list *list){
    int max = get_element_key(list -> elem);
    int max_tmp;

    while(list -> next){
        max_tmp = get_element_key((list -> next) -> elem);
        if(max < max_tmp){
            max = max_tmp;
        }

        list = list -> next;
    }

    return max;
}

int get_min_key(double_linked_list *list){
    int min = get_element_key(list -> elem);
    int min_tmp;

    while(list -> next){
        min_tmp = get_element_key((list -> next) -> elem);
        if(min > min_tmp){
            min = min_tmp;
        }

        list = list -> next;
    }

    return min;
}

int get_node_information(double_linked_list *list, int index){
    int i, prev, next;
    double_linked_list *tmp = list; 

    if(index > node_count(list)){
        printf("INDEX TOO HIGH!\n");
        return -1;
    }else if(index < 0){
        printf("INDEX TOO LOW!\n");
        return -1;
    }

    for(i = 0; i != index; i++){
        tmp = tmp -> next;
    }

    if(tmp -> next == NULL){
        next = -1;
    }else{
        next = get_element_key(tmp -> next -> elem);
    }

    if(tmp -> prev == NULL){
        prev = -1;
    }else{
        prev = get_element_key(tmp -> prev -> elem);
    }

    printf("NODE'S INDEX: %d\n\t- PREV: %d\n\t- NEXT: %d\n\t- NODE KEY: %d", index, prev, next, get_element_key(tmp -> elem));

    return 0;
}

int partition(double_linked_list **list, int first_ind, int last_ind){
    int x, y, i, j;

    x = get_element_key(get_node_by_index(*list, last_ind) -> elem);
    i = first_ind - 1;

    for(j = first_ind; j < last_ind; j++){
        y = get_element_key(get_node_by_index(*list, j) -> elem);
        
        if(y <= x){
            i++;
            swap_node(list, i, j);
        }
    }

    swap_node(list, i + 1, last_ind);

    return i + 1;
}

void quicksort(double_linked_list **list, int first_ind, int last_ind){
    int q;

    if(first_ind < last_ind){
        q = partition(list, first_ind, last_ind);
        quicksort(list, first_ind, q - 1);
        quicksort(list, q + 1, last_ind);
    }
}