#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

class AdjacencyMatrix
{
public:
    AdjacencyMatrix(int size);

    ~AdjacencyMatrix();

    void addEdge(int u, int v, int weight);

    int getSize();

    int **matrix;

private:
    int size;

};

#endif