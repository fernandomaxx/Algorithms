#include "adjacency_list.hpp"

AdjacencyList::AdjacencyList(int size):
        size { size }
{
    this->adj = new std::vector<std::pair<int, int>>[size];
}

AdjacencyList::~AdjacencyList()
{
    delete[] adj;
}

void AdjacencyList::addEdge(int u, int v, int weight)
{
    this->adj[u].push_back(std::make_pair(v, weight));
}

int AdjacencyList::getSize()
{
    return this->size;
}