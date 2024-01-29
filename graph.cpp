#include "graph.h"

UnweightedGraph::UnweightedGraph(const std::string& filename){
    std::ifstream infile;
    infile.open(filename);
    if(!infile.is_open()){
        infile.close();
        throw std::runtime_error(FAILED_OPEN_MSG);
    }
    std::string line;
    getline(infile, line);
    numVerticies = std::stoi(line);
    std::vector<bool> v(numVerticies, false);
    std::vector<std::vector<bool>> matrix(numVerticies, v);
    while(getline(infile, line)){
        int x,y;
        std::vector<int> edge;
        std::istringstream s(line);
        s >> x;
        s >> y;
        if((x==y) || (x>=numVerticies) || (y>=numVerticies) || matrix[x][y]){
            infile.close();
            throw std::runtime_error(INVALID_GRAPH_MSG);
        }
        matrix[x][y]=true;
        edge.push_back(x);
        edge.push_back(y);
        edges.push_back(edge);
        numEdges += 1;
    }
    infile.close();
}

int UnweightedGraph::getNumVertices() const{
    return numVerticies;
}

std::vector<std::vector<bool>> UnweightedGraph::getAdjacencyMatrix() const{
    std::vector<std::vector<int>> list = getAdjacencyLists();
    std::vector<std::vector<bool>> matrix;
    for(int i=0; i<numVerticies;i++) {
        std::vector<bool> e;
        for(int j=0; j<numVerticies; j++){
            if(std::find(list[i].begin(), list[i].end(), j)!=list[i].end()){
                e.push_back(true);
            }
            else{
                e.push_back(false);
            }
        }
        matrix.push_back(e);
    }
    return matrix;
}

std::vector<std::vector<int>> UnweightedGraph::getAdjacencyLists() const{
    std::vector<std::vector<int>> list;
    for(int i=0; i<numVerticies;i++){
        std::vector<int> t;
        for(int j=0; j<numEdges; j++){
            if(edges[j][0]==i){
                t.push_back(edges[j][1]);
            }
        }
        list.push_back(t);
    }
    return list;
}

std::vector<int> UnweightedGraph::getBFSOrdering(int start) const{
    if((start > numVerticies-1)||(start < 0)){
        return std::vector<int>();
    }
    std::vector<int> ordering;
    std::queue<int> q;
    std::vector<bool> discovered(numVerticies, false);
    std::vector<std::vector<int>> list = getAdjacencyLists();
    discovered[start] = false;
    q.push(start);
    int cur_node;
    while(!q.empty()){
        cur_node = q.front();
        q.pop();
        discovered[cur_node] = true;
        ordering.push_back(cur_node);
        for(int n:list[cur_node]){
            if(!discovered[n]){
                discovered[n] = true;
                q.push(n);
            }
        }
    }
    return ordering;
}

std::vector<int> UnweightedGraph::getDFSOrdering(int start) const{
    if((start > numVerticies-1)||(start<0)){
        return std::vector<int>();
    }
    std::vector<int> ordering;
    std::stack<int> s;
    std::vector<bool> processed(numVerticies, false);
    std::vector<std::vector<int>> list = getAdjacencyLists();
    s.push(start);
    int cur_node;
    while(!s.empty()){
        cur_node = s.top();
        s.pop();
        if(!processed[cur_node]){
            ordering.push_back(cur_node);
            processed[cur_node] = true;
            for(int n:list[cur_node]){
                if(!processed[n]){
                    s.push(n);
                }
            }
        }
    }
    return ordering;
}

std::vector<std::vector<bool>> UnweightedGraph::getTransitiveClosure() const{
    std::vector<std::vector<bool>> trans;
    std::vector<std::vector<int>> list = getAdjacencyLists();
    for(int i=0; i<numVerticies;i++){
        std::vector<bool> l;
        std::vector<int> verticies;
        verticies = getBFSOrdering(i);
        for(int j=0; j<numVerticies;j++){
            if(std::find(verticies.begin(), verticies.end(), j)!=verticies.end()){
                l.push_back(true);
            }
            else{
                l.push_back(false);
            }
        }
        trans.push_back(l);
    }
    return trans;
}
