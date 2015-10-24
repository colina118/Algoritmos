////#include "stdafx.h"
#include "Snap.h"
#include <string>
#include <vector>
#include <deque>
#include <string>
#include <limits>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include "distanciaId.h"


struct {
	bool operator()(distanciaId* a, distanciaId* b)
	{
		return a->getDistancia() < b->getDistancia();
	}
} comparaDistancia;
struct {
	bool operator()(distanciaId* a, distanciaId* b)
	{
		return a->getId() < b->getId();
	}
} comparaId;

void Dijkstra(TPt<TNodeEDatNet<TInt, TFlt>>, int);
void Prim(TPt<TNodeEDatNet<TInt, TFlt>>, int);
void floydwarshall(TPt<TNodeEDatNet<TInt, TFlt>>, int);
void Kruskal(TPt<TNodeEDatNet<TInt, TFlt> >  g);
int findSet(int x, int parent[]);
void setUnion(int u, int v, int parent[]);

int main(int argc, char* argv[]) {
	int opc;
	int cont =1;
	int origen;
	int destino;
	int peso;
	class myVis {
	public:
		myVis() { }
		myVis(const int& Nodes) { }
		void DiscoverNode(int NId) {
			printf("%i\n", NId);
		}
		void FinishNode(const int& NId) { }
		void ExamineEdge(const int& NId1, const int& NId2) { }
		void TreeEdge(const int& NId1, const int& NId2) { }
		void BackEdge(const int& NId1, const int& NId2) { }
		void FwdEdge(const int& NId1, const int& NId2) { }
	};
	TPt<TNodeEDatNet<TInt, TFlt>>  G = TNodeEDatNet<TInt, TFlt>::New();

	opc = 0;
	while (opc != 11)
	{
		std::cout << "1. Anadir nodo" << std::endl;
		std::cout << "2. Eliminar nodo" << std::endl;
		std::cout << "3. Anadir arista" << std::endl;
		std::cout << "4. Eliminar arista" << std::endl;
		std::cout << "5. DFS" << std::endl;
		std::cout << "6. BFS" << std::endl;
		std::cout << "7. Prim" << std::endl;
		std::cout << "8. Kruskal" << std::endl;
		std::cout << "9. Floyd-Warshall" << std::endl;
		std::cout << "10. Dijkstra" << std::endl;
		std::cout << "11. Salir del programa" << std::endl;
		std::cin >> opc;
		switch (opc)
		{
		case 1:
		{
			G->AddNode(cont);
			std::wcout << "Se agrego el nodo: " << cont << std::endl;
			cont++;
			break;
		}
		case 2:
		{
			G->DelNode(cont - 1);
			std::cout << "se borro el nodo" << std::endl;
			cont--;
			break;
		}
		case 3:
		{
			std::cout << "Escriba el nodo origen" << std::endl;
			std::cin >> origen;
			std::cout << "Escriba el nodo destino" << std::endl;
			std::cin >> destino;
			std::cout << "Escriba el peso de la arista" << std::endl;
			std::cin >> peso;
			if (G->GetNodes() > destino-1)
			{
				G->AddEdge(origen, destino, peso);
				std::cout << "se agrego la arista" << std::endl;
			}
			else
			{
				std::cout << "nodos no validos" << std::endl;
			}
			break;
		}
		case 4:
		{
			std::cout << "Escriba el nodo origen" << std::endl;
			std::cin >> origen;
			std::cout << "Escriba el nodo destino" << std::endl;
			std::cin >> destino;
			if (G->IsEdge(origen, destino))
			{
				G->DelEdge(origen, destino);
				std::cout << "se borro la arista" << std::endl;
			}
			else
			{
				std::cout << "No existe una arista entre esos nodos" << std::endl;
			}
			break;
		}
		case 5:
		{
			std::cout << "---DFS---" << std::endl;
			if (G->GetNodes() > 0)
			{
				myVis vis(G->GetNodes());
				TCnCom::GetDfsVisitor(G, vis);
			}
			break;
		}
		case 6:
		{
			std::cout << "---BFS---" << std::endl;
			if (G->GetNodes() > 0)
			{
				PNGraph GBFS = TSnap::GetBfsTree(G, 1, true, true);
				for (TNGraph::TNodeI NI = GBFS->BegNI(); NI < GBFS->EndNI(); NI++)
				{
					printf("%d\n", NI.GetId());
			
				}
			}
			break;
		}
		case 7:
		{
			std::cout << "-------Prim------" << std::endl;
			if (G->GetNodes() > 0)
			{
				Prim(G, 1);
			}
			break;
		}
		case 8:
		{
			std::cout << "-----------Kruskal-------" << std::endl;
			if (G->GetNodes() > 0)
			{
				Kruskal(G);
			}
			break;
		}
		case 9:
		{
			std::cout << "-------Floyd-Warshall-----" << std::endl;
			int nodos = G->GetNodes();
			if (G->GetNodes() > 0)
			{
				floydwarshall(G, nodos);
			}
			break;
		}
		case 10:
		{
			std::cout << "-------Dijkstra------" << std::endl;
			if (G->GetNodes() > 0)
			{
				Dijkstra(G, 1);
			}
			break;
		}
		default:
		{
			std::cout << "Esa opcion no es calida" << std::endl;
			break;
		}
	}
}
	//printf("Creando el grafo:\n");
	//for (int n = 1; n < 15; n++) {
	//	G->AddNode(n);
	//}

	//G->AddEdge(1, 4, 8);
	//G->AddEdge(1, 3, 8);
	//G->AddEdge(2, 5, 7);
	//G->AddEdge(3, 2, 7);
	//G->AddEdge(3, 10, 4);
	//G->AddEdge(3, 5, 8);
	//G->AddEdge(4, 7, 3);
	//G->AddEdge(4, 8, 2);
	//G->AddEdge(4, 5, 1);
	//G->AddEdge(5, 6, 9);
	//G->AddEdge(6, 13, 4);
	//G->AddEdge(7, 4, 6);
	//G->AddEdge(8, 7, 3);
	//G->AddEdge(8, 9, 3);
	//G->AddEdge(9, 10, 2);
	//G->AddEdge(9, 12, 4);
	//G->AddEdge(10, 6, 6);
	//G->AddEdge(10, 3, 10);
	//G->AddEdge(11, 12, 6);
	//G->AddEdge(12, 9, 2);
	//G->AddEdge(12, 11, 8);
	//G->AddEdge(12, 14, 9);
	//G->AddEdge(13, 14, 6);
	//G->AddEdge(14, 13, 2);


	//std::cout << "---DFS---" << std::endl;
	//myVis vis(G->GetNodes());
	//std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	//TCnCom::GetDfsVisitor(G, vis);
	//std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	//std::cout << " DFS : " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	//std::cout << "---BFS---" << std::endl;
	//begin = std::chrono::high_resolution_clock::now();
	//PNGraph GBFS = TSnap::GetBfsTree(G, 1, true, true);
	//end = std::chrono::high_resolution_clock::now();
	//duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	//std::cout << " BFS : " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;
	//for (TNGraph::TNodeI NI = GBFS->BegNI(); NI < GBFS->EndNI(); NI++)
	//{
	//	printf("%d\n", NI.GetId());
	//}

	//std::cout << "-------Dijkstra------" << std::endl;
	//
	//Dijkstra(G, 1);
	//
	//std::cout << std::endl;
	//std::cout << "-------Floyd-Warshall-----" << std::endl;
	//int nodos = G->GetNodes();
	//floydwarshall(G, nodos);

	//std::cout << "-------Prim------" << std::endl;
	//Prim(G, 1);

	//std::cout << "-----------Kurskal-------" << std::endl;
	//Kruskal(G);

	
}

void Dijkstra(TPt<TNodeEDatNet<TInt, TFlt>> Grafo, int nombre)
{
	double inf = std::numeric_limits<double>::infinity();
	int u;
	int cont = 0;
	int tempId;
	std::vector<distanciaId*> delta (Grafo->GetNodes());
	std::deque<int> Q (Grafo->GetNodes());
	std::deque<distanciaId*> A(Grafo->GetNodes());
	std::deque<int> S;
	
	for (TNodeEDatNet< TInt, TFlt >::TNodeI NI = Grafo->BegNI(); NI < Grafo->EndNI(); NI++)
	{
		distanciaId* temp = new distanciaId();
		temp->setDistancia(inf);
		temp->setId(NI.GetId());
		delta[NI.GetId()-1] = temp;
		A[NI.GetId()-1] = temp;
		
	}
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	delta[nombre-1]->setDistancia(0);
	
	while (!A.empty())
	{
		
		//std::sort(delta.begin(), delta.end(), comparaDistancia);
		std::sort(A.begin(), A.end(), comparaDistancia);
		tempId = delta[cont]->getId();
		S.push_back(A[0]->getId());
		u = A[0]->getId();
		A.pop_front();
		
		for (auto i : delta)
		{
			if (Grafo->IsEdge(u, i->getId()))
			{
				if (i->getDistancia() > delta[u-1]->getDistancia() + Grafo->GetEDat(u, i->getId()))
				{
					i->setDistancia(delta[u-1]->getDistancia() + Grafo->GetEDat(u, i->getId()));
					i->setPadre(u);
				}
			}
		}
		
		cont++;
	}
	std::sort(delta.begin(), delta.end(), comparaId);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Dijkstra : " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;
	std::sort(delta.begin(), delta.end(), comparaId);
	for (auto i : delta)
	{
		std::cout << "Tiempo al nodo " << i->getId() << " es: " << i->getDistancia() << " y su padre es " << i->getPadre() << std::endl;
	}
}

void Prim(TPt<TNodeEDatNet<TInt, TFlt>> Grafo, int source)
{
	double inf = std::numeric_limits<double>::infinity();
	distanciaId* u;
	int cont = 0;
	int verdad;
	std::deque<distanciaId*> delta(Grafo->GetNodes());
	std::deque<int> Q(Grafo->GetNodes());
	std::deque<distanciaId*> S;
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	for (TNodeEDatNet< TInt, TFlt >::TNodeI NI = Grafo->BegNI(); NI < Grafo->EndNI(); NI++)
	{
		distanciaId* temp = new distanciaId();
		temp->setDistancia(inf);
		temp->setId(NI.GetId());
		delta[NI.GetId() - 1] = temp;
	}
	
	delta[source-1]->setDistancia(0);
	while (!delta.empty())
	{
		std::sort(delta.begin(), delta.end(), comparaDistancia);
		u = delta[0];
		for (auto i : delta)
		{
			if (Grafo->IsEdge(u->getId(), i->getId()))
			{
				if (i->getDistancia() > Grafo->GetEDat(u->getId(), i->getId()))
				{
					i->setPadre(u->getId());
					i->setDistancia(Grafo->GetEDat(u->getId(), i->getId()));
				}
			}
		}
		S.push_back(delta[0]);
		delta.pop_front();
	}
	std::sort(delta.begin(), delta.end(), comparaId);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Prim : " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;
	for (auto i : S)
	{
		std::cout << i->getPadre() << "--->" << i->getId() << std::endl;
	}
}

void floydwarshall(TPt<TNodeEDatNet<TInt, TFlt> >  G, int vertices) {

	int infinito = 1000000;
	std::vector<int> fila;
	std::vector< std::vector<int> > mat;

	
	for (int i = 0; i < vertices; i++) 
	{
		for (int j = 0; j < vertices; j++) 
		{
			fila.push_back(-2);
		}

		mat.push_back(fila);
	}

	
	for (int i = 0; i < vertices; i++) {

		for (int j = 0; j < vertices; j++) {

			if (i == j)
			{
				mat[i][j] = 0;
			}
			else if (G->IsEdge(i + 1, j + 1))
			{
				mat[i][j] = G->GetEDat(i + 1, j + 1);
			}
			else 
			{
				mat[i][j] = infinito;
			}

		}

	}

	 
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	
	for (int k = 0; k < vertices; ++k)
	{

		for (int i = 0; i < vertices; ++i)
		{

			for (int j = 0; j < vertices; ++j) 
			{

				int temp = mat[i][k] + mat[k][j];
				if (temp < mat[i][j]) {
					mat[i][j] = temp;
				}

			}

		}

	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Floyd-Warshall : " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	  
	  for (int i = 0; i < vertices; i++)
	  {
	    for (int j = 0; j < vertices; j++) 
		{
	      
	      if (mat[i][j] == infinito)
		  {
	        std::cout << "Del nodo " << i+1 << " al nodo " << j+1 << " : inf" << std::endl;
	      }
	      else 
		  {
	        std::cout << "Del nodo " << i+1 << " al nodo " << j+1 << " : " << mat[i][j] << std::endl;
	      }
	      
	    }
	    std::cout << std::endl;
	  }
}

void Kruskal(TPt<TNodeEDatNet<TInt, TFlt> >  g) {
	int n = g->GetNodes();
	int * parent = new int[n];
	std::vector<std::pair<int, TPt<TNodeEDatNet<TInt, TFlt> >::TObj::TEdgeI> > edges;
	std::queue<TPt<TNodeEDatNet<TInt, TFlt>>::TObj::TEdgeI> tree;
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	for (TPt<TNodeEDatNet<TInt, TFlt>>::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++) {
		int id = NI.GetId();
		parent[id - 1] = id;
	}

	for (TPt<TNodeEDatNet<TInt, TFlt> >::TObj::TEdgeI ei = g->BegEI(); ei < g->EndEI(); ei++)
		edges.push_back(std::make_pair(ei.GetDat(), ei));

	std::sort(edges.begin(), edges.end());

	for (unsigned int i = 0; i < edges.size(); ++i) {
		int u = edges[i].second.GetSrcNId();
		int v = edges[i].second.GetDstNId();
		if (findSet(u, parent) != findSet(v, parent)) {
			tree.push(edges[i].second);
			setUnion(u, v, parent);
		}
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Floyd-Warshall : " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;
	while (!tree.empty()) {
		std::cout << "Arista entre " << tree.front().GetSrcNId() << " y " << tree.front().GetDstNId();
		std::cout << ", tiene peso de = " << tree.front().GetDat() << std::endl;
		tree.pop();
	}
	delete[] parent;
}

int findSet(int x, int parent[]) {
	if (parent[x - 1] != x)
		parent[x - 1] = findSet(parent[x - 1], parent);
	return parent[x - 1];
}

void setUnion(int u, int v, int parent[]) {
	u = findSet(u, parent);
	v = findSet(v, parent);
	parent[u - 1] = v;
}

