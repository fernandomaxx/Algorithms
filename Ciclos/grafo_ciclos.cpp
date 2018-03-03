
#include <iostream>
#include <list>
#include <stack> // pilha para usar na dfs
using namespace std;

class Grafo
{
	int V;
	list<int> *adj;

public:
	Grafo(int V);
	void adicionarAresta(int v1, int v2);

	// faz uma DFS a partir de um vértice, retorna se achou ciclo ou não
	bool dfs(int v);
	
	// verifica se o grafo direcionado tem ciclo
	bool temCiclo();
};

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2)
{
	adj[v1].push_back(v2);
}

bool Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[V] = {false}, pilha_rec[V] = {false};

	// faz uma DFS
	while (true)
	{
		bool achou_vizinho = false;
		list<int>::iterator it = adj[v].begin();

		if (!visitados[v])
		{
			pilha.push(v);
			visitados[v] = pilha_rec[v] = true;
		}

		for (int i = 0; i < adj[v].size(); ++i, it++)
		{
			// se o vizinho jã estã na pilha é porque existe ciclo
			if (pilha_rec[*it])
				return true;
			else if (!visitados[*it])
			{
				// se não estã na pilha e não foi visitado, indica que achou
				achou_vizinho = true;
				break;
			}
		}

		if (!achou_vizinho)
		{
			pilha_rec[pilha.top()] = false; // marca que saiu da pilha
			pilha.pop(); // remova da pilha
			if (pilha.empty())
				break;
			v = pilha.top();
		}
		else
			v = *it;
	}

	return false;
}

bool Grafo::temCiclo()
{
	for(int i = 0; i < V; i++)
	{
		if(dfs(i))
			return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	Grafo grafo(4);

	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(3, 0);

	if (grafo.temCiclo())
		cout <<"Contem ciclo \n";
	else
		cout << "Nao contem ciclo\n";
	return 0;
}