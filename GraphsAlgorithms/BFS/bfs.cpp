#include "../GraphRepresentation/adjacency_list.hpp"
#include <iostream>
#include <queue>

int* bfs(AdjacencyList *Graph_adj, int s)
{
    int size = Graph_adj->getSize();
    auto *adj = Graph_adj->adj;
    std::queue<int> queue;
    int *distance = new int[size];
    bool visited[size];

    for (int i = 0; i < size; i++)
    {
        distance[i] = -1;
        visited[i] = false;
    }

    visited[s] = true;
    distance[s] = 0;
    queue.push(s);

    while (!queue.empty())
    {
        int v = queue.front();
        std::cout << v << " ";
        queue.pop();

        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[it->first])
            {
                visited[it->first] = true;
                distance[it->first] = distance[v] + 1;
                queue.push(it->first);
            }   
        }   
    }
    
    return distance;
}