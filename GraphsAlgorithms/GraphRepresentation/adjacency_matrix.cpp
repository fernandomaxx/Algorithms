#include "adjacency_matrix.hpp"

AdjacencyMatrix::AdjacencyMatrix(int size):
        size {size}
{
    this->matrix = new int*[size];

    for (int i = 0; i < size; i++)
        this->matrix[i] = new int[size];
    
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    for (int i = 0; i < this->size; i++)
    {
        delete this->matrix[i];
    }

    delete[] this->matrix;
}

void AdjacencyMatrix::addEdge(int u, int v, int weight)
{
    this->matrix[u][v] = weight;
}

int AdjacencyMatrix::getSize()
{
    return this->size;
}