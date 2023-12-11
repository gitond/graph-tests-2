# configuration
CC = g++	# the compiler
MAINEX = tb	# main executable outputted by compiler
# main program dependencies
MAINDEP = main.cpp classes/datastructures/adj_list_graph.cpp classes/datastructures/adj_matrix_graph.cpp

# complete main compilation process here
all: $(MAINDEP)
	$(CC) $(MAINDEP) -o $(MAINEX)

# cleanup
clean:
	$(RM) $(MAINEX)
