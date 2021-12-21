#include <stdio.h>
#include <stdbool.h>
#include "double_linked_list.h"

int main(int argc, char **argv){

    int choise, key, key2;
    bool init = false;
    linked_list *list;

    while(1){
        printf("\n---------------------------------------------\n");
        printf("WHAT DO YOU WANT TO DO?\n");
        printf("\t- 1:  INIZIALIZE A LINKED LIST\n");
        printf("\t- 2:  ADD A NODE TO THE LIST\n");
        printf("\t- 3:  DELETE A NODE THAT CONTAINS A KEY\n");
        printf("\t- 4:  DELETE ALL THE NODES THAT CONTAINS A KEY\n");
		printf("\t- 5:  DELETE A NODE BY INDEX\n");
		printf("\t- 6:  SWAP TWO NODE\n");
		printf("\t- 7:  SORT THE LIST\n");	
		printf("\t- 8:  GET KEY BY INDEX\n");
		printf("\t- 9:  GET THE LIST'S LENGTH\n");
		printf("\t- 10: GET THE MAX KEY\n");
		printf("\t- 11: PRINT THE LIST\n");
        printf("---------------------------------------------\n");
        printf("\nCHOISE: "); scanf("%d", &choise);

        switch(choise){
            case 1: if(!init){
						printf("\nINSERT THE FIRST KEY: "); scanf("%d", &key);
                        list = inzialize_linked_list(inizialize_element(inzialize_key(key))); 
                        init = true; printf("DONE!\n");
                    }else{
                        printf("THE LIST ALREADY EXISTS!\n");
                    } break;
            case 2: if(init){
						printf("\nINSERT THE NEW NODE'S KEY: "); scanf("%d", &key);
                    	add_node(&list, inizialize_element(inzialize_key(key))); 
                    	printf("DONE!\n");
					}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					} break;
            case 3: if(init){
						printf("\nINSERT THE KEY OF THE NODE TO DELETE: "); scanf("%d", &key);
                    	delete_node(&list, inzialize_key(key));
                    	printf("DONE!\n");
			 		}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					} break;
            case 4: if(init){
						printf("\nINSERT THE KEY OF THE NODES TO DELETE: "); scanf("%d", &key);
                    	while(list_include(list, inzialize_key(key))){
                        	delete_node(&list, inzialize_key(key));
                    	} 
						printf("DONE!\n");
					}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					} break;
            case 5: if(init){
						printf("\nINSERT THE INDEX OF THE NODE TO DELETE : "); scanf("%d", &key);
                    	delete_node_from_index(&list, key);
                    	printf("DONE!\n");
			 		}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					} break;
            case 6: if(init){
						printf("FIRST NODE INDEX: "); scanf("%d", &key); printf("SECOND NODE INDEX: "); scanf("%d", &key2); 
                    	swap_node(&list, key, key2);
						printf("DONE!\n");
			 		}else{
				 		printf("INIZIALIZE THE LIST FIRST!\n");
			 		} break;
			case 7: if(init){
						quicksort(&list, 0, node_count(list) - 1); printf("DONE!\n");
			 		}else{
				 		printf("INIZIALIZE THE LIST FIRST!\n");
			 		} break;
            case 8: if(init){
						printf("INSERT THE NODE'S INDEX: "); scanf("%d", &key); printf("\nNODE N° %d HAS KEY: %d\n", key, get_element_key(get_node_by_index(list, key) -> elem));
					}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					} break;
            case 9: if(init){
						printf("THE LIST CONTAINS %d NODES\n", node_count(list)); 
					}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					} break;
			case 10: if(init){
						printf("THE MAX KEY IS: %d\n", get_max_key(list));
					}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					}break;
			case 11: if(init){
						print_all_list(list); 
					}else{
						printf("INIZIALIZE THE LIST FIRST!\n");
					}break;
           
            default: printf("!! NOT VALID CHOISE !!\n"); break;
        }
    }
    
    return 0;
}