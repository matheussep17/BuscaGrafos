// DFS

#include <iostream>
#include <list>
#include <algorithm> 
#include <stack> 
 
using namespace std;
 
class Grafo
{
	int vertices; 
	list<int> *adj; 
 
public:
	Grafo(int V); // método construtor
	void add(int v1, int v2); // adiciona uma aresta
 
	// função DFS
	void dfs(int v);
};
 
Grafo::Grafo(int V)
{
	this->vertices = V; // atribui o número de vértices
	adj = new list<int>[vertices]; // cria as listas
}
 
void Grafo::add(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}
 
void Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[vertices]; // visitados
 
	// não visitados
	for(int i = 0; i < vertices; i++)
		visitados[i] = false;
 
	while(true)
	{
		if(!visitados[v])
		{
			cout << "Visitando vertice " << v << " ...\n";
			visitados[v] = true; // marca como visitado
			pilha.push(v); // insere "v" na pilha
		}
 
		bool achou = false;
		list<int>::iterator it;
 
		// busca não visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				achou = true;
				break;
			}
		}
 
		if(achou)
			v = *it; // atualiza o "v"
		else
		{
			
			// remove da pilha
			pilha.pop();
			
			if(pilha.empty())
				break;
			//pega o elemento do topo
			v = pilha.top();
		}
	}
}
 
int main()
{
	int vertices = 8;
 
	Grafo grafo(vertices);
 
	// adicionando as arestas
	grafo.add(0, 1);
	grafo.add(0, 2);
	grafo.add(1, 3);
	grafo.add(1, 4);
	grafo.add(2, 5);
	grafo.add(2, 6);
	grafo.add(6, 7);
	
	grafo.dfs(0);
 
	return 0;
}
