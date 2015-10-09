#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
La complejidad O(n*m) porque se recorren ambos arreglos para
poder generar la matriz e ir chechando hasta llegar al tamaño
maximo de las subsecuencias
*/

template<class T>
std::vector<int> calcularSub(std::vector<T>, std::vector<T>);

int main()
{
	std::vector<int> primera = { 1,3,6,12,45,78,96,2,4,87,34,5 };
	std::vector<int> segunda = { 1,54,7,9,2,3,4,5,6 };
	std::vector<int> subsecuencia;

	subsecuencia = calcularSub(primera, segunda);

	std::cout << "La subsecuencia mas larga es: { ";
	for (int i = subsecuencia.size(); i > 0; i--)
	{
		std::cout << subsecuencia[i-1];
	}

	std::cout << " }" << std::endl;
	return 0;
}

template<class T>
std::vector<int> calcularSub(std::vector<T> primera, std::vector<T> segunda)
{
	int tamPrim = primera.size()-1;
	int tamSeg = segunda.size()-1;
	std::vector<std::vector<int>> matrizSub(primera.size() + 1, std::vector<int>(segunda.size() + 1));
	for (int i = 1; i < primera.size(); i++)
	{
		for (int j = 1; j < segunda.size(); j++)
		{
			if (primera[i - 1] == segunda[j - 1])
			{
				matrizSub[i][j] = matrizSub[i-1][j-1] + 1;
			}
			else
			{
				matrizSub[i][j] = std::max(matrizSub[i - 1][j], matrizSub[i][j - 1]);
			}
		}
	}
	for (int i = 1; i < primera.size(); i++)
	{
		for (int j = 1; j < segunda.size(); j++)
		{
			std::cout << matrizSub[i][j];
		}
		std::cout << std::endl;
	}

	
	int tam = matrizSub[tamPrim][tamSeg];
	std::vector<int> subsecuencia;
	
	while (tamPrim > -1 && tamSeg > -1)
	{
		if (primera[tamPrim] == segunda[tamSeg])
		{
			subsecuencia.push_back(primera[tamPrim]);
			tamPrim--;
			tamSeg--;
			tam--;
		}
		else if( primera[tamPrim] > segunda[tamSeg])
		{
			tamPrim--;
		}
		else
		{
			tamSeg--;
		}
	}
	return subsecuencia;
}