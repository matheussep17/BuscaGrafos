// DIJKSTRA

#include <iostream>
#include <list>
#include <queue>
#define TAM 10000000

using namespace std;

class Grafo
{
	private:
	int vertice;
	list<pair<int, int> > * adj;

public:

	Grafo(int vertice) // metodo construtor
	{
		this->vertice = vertice; // atribui o número de vértices

		adj = new list<pair<int, int> >[vertice];
	}

	// adiciona uma aresta ao grafo de v1 à v2
	void add(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// Dijkstra
	int dijkstra(int orig, int dest)
	{
	
		int dist[vertice];
		int visitados[vertice];

		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(int i = 0; i < vertice; i++)
		{
			dist[i] = TAM;
			visitados[i] = false;
		}

		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// se vértice não expandido
			if(visitados[u] == false)
			{
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		return dist[dest];
	}
};

int main(int argc, char *argv[])
{
	Grafo g(5);

	g.add(0, 1, 4);
	g.add(0, 2, 2);
	g.add(0, 3, 5);
	g.add(1, 4, 1);
	g.add(2, 1, 1);
	g.add(2, 3, 2);
	g.add(2, 4, 1);
	g.add(3, 4, 1);

	cout << g.dijkstra(0, 4) << endl;

	return 0;
}
