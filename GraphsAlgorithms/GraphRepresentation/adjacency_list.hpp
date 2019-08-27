#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include <vector>

class AdjacencyList
{
public:
    AdjacencyList(int size);

    ~AdjacencyList();

    void addEdge(int u, int v, int weight);

    int getSize();

    std::vector<std::pair<int, int>> *adj;

private:
    int size;

};

#endif