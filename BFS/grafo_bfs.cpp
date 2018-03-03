#include <iostream>
#include <list>
#include <queue> //

using namespace std;

class Grafo
{
	int V; //número de vértices
	list <int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V);
	void adicionarAresta(int v1, int v2); //adiciona uma aresta no grafo
	bool ehVizinho(int v1, int v2); // verifica de v2 é vizinho de v1

	// faz uma DFS a partir de um vértice
	void bfs(int v);
};

Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v)
{
	queue<int> fila;
	bool visitados[v] = {false}; // vetor de visitados

	cout << "Visitando vertice" << v << "...\n";
	visitados[v] = true; // marca como visitado

	while (true)
	{
		list<int>::iterator it = adj[v].begin();
		for (int i = 0; i < adj[v].size(); ++i)
		{
			if (!visitados[*it])
			{
				cout << "Visitando vertice" << *it << "...\n";
				visitados[*it] = true; // marca como visitado
				fila.push(*it); // insere na fila
			}

			it++;
		}

		if (!fila.empty())
		{
			v = fila.front(); // obtem o primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
	
}

int main	(int argc, char const *argv[])
{
	//criando um grafo de 8 vértices
	Grafo grafo(8);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.bfs(0);

	return 0;
}