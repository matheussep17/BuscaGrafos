3
// PRIM

#include <iostream>

using namespace std;

void aceita(int G[20][20], int n, int e);
void exibir(int G[20][20], int n, int e);

int main(){
	
	int G[20][20];
	int n;
	int e;
	int i, j;
	
	cout << "Informe o neumero do vertice: ";
	cin >> n >> e;
	
	for(i=0; i<n; i++){
		
		for(j=0; j<n; j++){
			G[i][j] = 0;
		}
	}
	
	aceita(G, n, e);
	
	exibir(G, n, e);
	
	return 0;
}

void aceita(int G[20][20], int n, int e){
	
	int cost, src, dest;
	int i, j;
	
	for(i=0; i<e; i++){
	
		cout <<  "\nDigite 3 valores: ";
		cin >> src >> dest >> cost;
		G[src][dest] = cost;	
		G[dest][src] = cost;
	}
}

void exibir(int G[20][20], int n, int e){
	
	int i, j;

	for(i-0; i<n; i++){
		
		cout << "\n";
		for(j=0; j<n; j++){
			cout << "\t" << G[i][j];
		}
	}
}


