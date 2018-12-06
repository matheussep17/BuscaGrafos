// BFS

#include <iostream>
#include <list>
#include <queue> 

using namespace std;

class Grafo
{
	int vertices;
	list<int> *adj; 

public:
	Grafo(int vertices); // método construtor
	void add(int v1, int v2); // adiciona aresta

	// função BFS
	void bfs(int v);
};

Grafo::Grafo(int vertices)
{
	this->vertices = vertices; // atribuição de valor
	adj = new list<int>[vertices]; // criar lista
}

void Grafo::add(int v1, int v2)
{
	// adiciona v2 a lista de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v)
{
	queue<int> fila;
	bool visitados[vertices]; //visitados

	for(int i = 0; i < vertices; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << v << " ...\n";
	visitados[v] = true; //  visitado

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true; 
				fila.push(*it); // insere na fila
			}
		}

		// Varificação de lista != de vazia
		if(!fila.empty())
		{
			v = fila.front(); // pega primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
}

int main()
{
	int vertices = 8;

	Grafo grafo(vertices);

	// adiciona arestas
	grafo.add(0, 1);
	grafo.add(0, 2);
	grafo.add(1, 3);
	grafo.add(1, 4);
	grafo.add(2, 5);
	grafo.add(2, 6);
	grafo.add(6, 7);

	grafo.bfs(0);

	return 0;
}
