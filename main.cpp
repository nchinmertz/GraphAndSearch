#include "graph.h"
#include <iostream>
#include <vector>

void printAdjMatrix(const std::vector<std::vector<bool>>& matrix){
    for (auto row : matrix)
    {
        for (bool val : row)
            std::cout << val << ' ';
        std::cout << '\n';
    }
}

void printGraphInfo(const UnweightedGraph& graph){
    std::cout << "Number of vertices: " << graph.getNumVertices() << '\n';
    std::cout << "Adjacency matrix:\n";
    auto adjMatrix = graph.getAdjacencyMatrix();
    printAdjMatrix(adjMatrix);
    std::cout << "Adjacency lists:\n";
    auto adjLists = graph.getAdjacencyLists();
    for (unsigned i = 0; i < adjLists.size(); ++i)
    {
        std::cout << "Vertex #" << i << ": ";
        for (int neighbor : adjLists[i])
            std::cout << neighbor << ' ';
        std::cout << '\n';
    }
    std::cout << "One BFS ordering (many are possible), starting at 0:\n";
    std::vector<int> ordering = graph.getBFSOrdering(0);
    for (int v : ordering)
        std::cout << v << ' ';
    std::cout << '\n';
    std::cout << "Another BFS ordering, starting at 2:\n";
    ordering = graph.getBFSOrdering(2);
    for (int v : ordering)
        std::cout << v << ' ';
    std::cout << '\n';
    std::cout << "One DFS ordering, starting at 3:\n";
    ordering = graph.getDFSOrdering(3);
    for (int v : ordering)
        std::cout << v << ' ';
    std::cout << '\n';
    std::cout << "Transitive closure:\n";
    auto tc = graph.getTransitiveClosure();
    printAdjMatrix(tc);
}


int main(int argc, char *argv[]){
    UnweightedGraph graph(argv[1]);
    printGraphInfo(graph);
    return 0;
}
