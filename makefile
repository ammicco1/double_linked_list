FLAGS = -Wall -ansi -pedantic
OBJS = double_list_main.o key.o element.o double_linked_list.o
EXEC = double_linked_list_main

$(EXEC): $(OBJS)
	gcc $(FLAGS) -o $(EXEC) $(OBJS)

$(EXEC).o: $(EXEC).c
	gcc $(FLAGS) -c $(EXEC).c

double_linked_list.o: double_linked_list.c
	gcc $(FLAGS) -c double_linked_list.c

element.o: element.c
	gcc $(FLAGS) -c element.c

key.o: key.c
	gcc $(FLAGS) -c key.c

clean: 
	rm -f *.o $(EXEC) $(OBJS)