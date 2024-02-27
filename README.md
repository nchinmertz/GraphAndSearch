This project constructs an unweighted graph from a given file. The file structure is: the number of verticies in the graph followed by pairs of relations within the graph. 

The program will display the adjacency matrix and adjacency list of the graph. Additionally, it provides the breadth-first search order beginning at verticies 0 and 2 and the depth-first search order starting at vertex 3. 

To compile, execute `g++ -std=c++14 main.cpp graph.cpp -o main`

To run, use `./main tests_files/filename`
