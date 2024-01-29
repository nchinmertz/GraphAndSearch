#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>

#define FAILED_OPEN_MSG "Failed to open file"
#define INVALID_GRAPH_MSG "Invalid graph"

class UnweightedGraph{
public:
    UnweightedGraph(const std::string& filename);
    UnweightedGraph(const UnweightedGraph&) = delete;
    UnweightedGraph& operator=(const UnweightedGraph&) = delete;
    int getNumVertices() const;
    std::vector<std::vector<bool>> getAdjacencyMatrix() const;
    std::vector<std::vector<int>> getAdjacencyLists() const;

    /**
     * Returns a BFS ordering of all vertices reachable from the start node.
     * If start is negative or too high, instead returns empty vector.
     */
    std::vector<int> getBFSOrdering(int start) const;

    /**
     * Returns a DFS ordering of all vertices reachable from the start node.
     * If start is negative or too high, instead returns empty vector.
     */
    std::vector<int> getDFSOrdering(int start) const;

    /**
     * Returns an adjacency matrix representing the transitive closure of
     * this graph.
     */
    std::vector<std::vector<bool>> getTransitiveClosure() const;

private:
    int numVerticies;
    int numEdges = 0;
    std::vector<std::vector<int>> edges;
};

#endif // GRAPH_HPP
