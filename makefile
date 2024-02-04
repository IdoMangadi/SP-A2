FLSGS = -Wall -g

.PHONY all clean 

all: my_mat.a mainprog


#Generating library:

my_mat.o : my_mat.c my_mat.h
	gcc ${FLSGS} -fPIC -c my_mat.c -o my_mat.o

my_mat.a : my_mat.o
	ar -rcs my_mat.a my_mat.o
	ranlib my_mat.a


#Generating main:

main.o : main.c my_mat.h
	gcc ${FLSGS} -c main.c -o main.o

mainprog : main.o my_mat.a
	gcc ${FLSGS} main.o my_mat.o -o mainprog


#cleanning:

clean: 
	rm -f mainprog *.a *.o

 