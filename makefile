FLAGS = -Wall -g

.PHONY: all clean

all: my_mat.a my_graph my_Knapsack

# Generating library part 1:
my_mat.o: my_mat.c my_mat.h
	gcc ${FLAGS} -fPIC -c my_mat.c -o my_mat.o

my_mat.a: my_mat.o
	ar -rcs my_mat.a my_mat.o
	ranlib my_mat.a

# Generating main part 1:
main.o: main.c my_mat.h
	gcc ${FLAGS} -c main.c -o main.o

my_graph: main.o my_mat.a
	gcc ${FLAGS} main.o my_mat.a -o my_graph

# Generating main part 2:
my_Knapsack: my_Knapsack.c  
	gcc ${FLAGS} my_Knapsack.c -o my_Knapsack

# Cleaning:
clean:
	rm -f my_graph my_Knapsack *.a *.o