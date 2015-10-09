#include <iostream>
#include <string>
#include <vector>
#include <math.h>
/*
La complejidad es O(n) porque solamente esta utilizando un for para checar el espacio que esta 
ocupando y el otro for para imprimir solo imprime por linea y no lo estoy tomando en cuenta
*/

float costoAmpliar(float, float, int, int);
float costoReduce(float, float, int, int);

int main(int argc, const char * argv[]) {
	std::vector<std::string> palabras = {"Si", "necesita", "regaetton", "dale", "Sigue", "bailando","mami", "no", "pare"};
	std::vector<float> tamaño;
	for (int i = 0; i < palabras.size(); i++)
	{
		tamaño.push_back(palabras[i].length());
	}
	std::vector<std::string> line;
	float tamañoLinea = 20;
	float tamañoIdealEspacio = 1;
	float tamañoPalabrasCompleto = 0;
	float tamañoPalabrasEspacios = 0;
	float sobra;
	int i = 0;
	int j;
	bool printed = true;
	float bR;
	float bA;

	for (j = 0; j<palabras.size(); j++) {
		if (printed) {
			i = j;
			printed = false;
			line.clear();
			tamañoPalabrasCompleto = 0;
		}

		tamañoPalabrasCompleto += tamaño[j];
		tamañoPalabrasEspacios = tamañoPalabrasCompleto + ((j - i)*tamañoIdealEspacio);
		if (tamañoPalabrasEspacios>tamañoLinea) {
			sobra = tamañoPalabrasEspacios - tamañoLinea;
			bR = tamañoIdealEspacio - (sobra / (j - i));
			bA = tamañoIdealEspacio + (tamañoLinea - ((tamañoPalabrasCompleto - tamaño[j]) + (tamañoIdealEspacio*(j - i - 1)))) / (j - i - 1);

			if (costoAmpliar(bA,tamañoIdealEspacio,j,i)>costoReduce(bR, tamañoIdealEspacio,j,i) && bR > 0)
			{
				line.push_back(palabras[j]);
				for (auto v : line) {
					std::cout << v << " ";
				}
				std::cout << " " << bR;
				std::cout << std::endl;
				printed = true;


			}
			else
			{
				for (auto v : line)
				{
					std::cout << v << " ";
				}
				std::cout << " " << bA;
				std::cout << std::endl;
				j--;
				printed = true;

			}

		}
		line.push_back(palabras[j]);
	}

	for (auto v : line)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

float costoAmpliar(float bA, float tamañoIdeal, int j, int i)
{
	return (fabs(bA - tamañoIdeal)*(j - i - 1));
}
float costoReduce(float bR, float tamañoIdeal, int j, int i)
{
	return (fabs(bR - tamañoIdeal)*(j - i));
}