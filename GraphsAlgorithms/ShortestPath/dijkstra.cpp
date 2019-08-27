#include "../GraphRepresentation/adjacency_list.hpp"
#include <iostream>
#include <queue>
#include <limits>

int dijkstra(AdjacencyList *Graph_adj, int s, int t)
{
    int size = Graph_adj->getSize();
    auto *adj = Graph_adj->adj;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
    int distance[size];
    bool visited[size];

    for (int i = 0; i < size; i++)
    {
        distance[i] = std::numeric_limits< int >::max();
        visited[i] = false;
    }

    distance[s] = 0;
    queue.push(std::make_pair(0, s));

    while (true)
    {
        int current = -1;

        while (!queue.empty())
        {
            int v = queue.top().second;
            queue.pop();

            if (!visited[v])
            {
                visited[v] = true;
                current = v;
                break;
            }
        }

        if (current == -1)
            break;

        for (auto it = adj[current].begin(); it != adj[current].end(); it++)
        {
            if (distance[current] + it->second < distance[it->first])
            {
                distance[it->first] = distance[current] + it->second;
                queue.push(std::make_pair(distance[it->first], it->first));
            }   
        }   
    }
    
    return visited[t] ? distance[t] : -1;
}