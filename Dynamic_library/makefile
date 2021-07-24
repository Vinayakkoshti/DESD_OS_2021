sort: order.o q1a_main.o
	gcc q1a_main.o order.o -o sort
q1a_main.o:q1a_main.c 
	gcc -c q1a_main.c
order.o:order.c
	gcc -c order.c

clean: 
	rm -f *.o sort
