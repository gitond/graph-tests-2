# configuration
CC = g++	# the compiler
EX = tb	# main executable outputted by compiler
# main program dependencies
MAINDEP = main.cpp classes/datastructures/adj_list_graph.cpp classes/datastructures/adj_matrix_graph.cpp

# complete main compilation process here
all: $(MAINDEP)
	$(CC) $(MAINDEP) -o $(EX)

# for testing during development
matrixtest: classes/datastructures/adj_matrix_graph.cpp
	$(CC) classes/datastructures/adj_matrix_graph.cpp -o $(EX)

listtest: classes/datastructures/adj_list_graph.cpp
	$(CC) classes/datastructures/adj_list_graph.cpp -o $(EX)

# cleanup
clean:
	$(RM) $(EX)
