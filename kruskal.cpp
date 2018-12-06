// KRUSKAL

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string.h> 

using namespace std;

class Aresta
{
	int vertice1, vertice2, peso;

public:

	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int pegarVertice1()
	{
		return vertice1;
	}

	int pegarVertice2()
	{
		return vertice2;
	}

	int pegarPeso()
	{
		return peso;
	}

	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

class Grafo
{
	int vertices; 
	vector<Aresta> arestas; // vetor

public:

	Grafo(int vertices)
	{
		this->vertices = vertices;
	}

	// adiciona aresta
	void add(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	// busca o subconjunto de um elemento 
	int buscar(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// unir dois subconjuntos em um subconjunto
	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	// Kruskal
	void kruskal()
	{
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		// ordena as arestas pelo menor peso
		sort(arestas.begin(), arestas.end());

		// aloca memória para criar vertices subconjuntos
		int * subset = new int[vertices];

		// inicializa todos os subconjuntos como conjuntos de um elemento
		memset(subset, -1, sizeof(int) * vertices);

		for(int i = 0; i < size_arestas; i++)
		{
			int v1 = buscar(subset, arestas[i].pegarVertice1());
			int v2 = buscar(subset, arestas[i].pegarVertice2());

			if(v1 != v2)
			{
				// se diferentes NÃO forma ciclo
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2); // faz a união
			}
		}

		int size_arvore = arvore.size();

		// mostra as arestas selecionadas com seus pesos
		for(int i = 0; i < size_arvore; i++)
		{
			char v1 = 'A' + arvore[i].pegarVertice1();
			char v2 = 'A' + arvore[i].pegarVertice2();
			cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].pegarPeso() << endl;
		}
	}
};

int main(int argc, char *argv[])
{
	Grafo g(7);
	
	// adiciona as arestas
	g.add(0, 1, 7);
	g.add(0, 3, 5);
	g.add(1, 2, 8);
	g.add(1, 3, 9);
	g.add(1, 4, 7);
	g.add(2, 4, 5);
	g.add(3, 4, 15);
	g.add(3, 5, 6);
	g.add(4, 5, 8);
	g.add(4, 6, 9);
	g.add(5, 6, 11);
	
	g.kruskal(); 
	
	return 0;
}
