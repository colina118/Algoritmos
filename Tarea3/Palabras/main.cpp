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
	std::vector<float> tama�o;
	for (int i = 0; i < palabras.size(); i++)
	{
		tama�o.push_back(palabras[i].length());
	}
	std::vector<std::string> line;
	float tama�oLinea = 20;
	float tama�oIdealEspacio = 1;
	float tama�oPalabrasCompleto = 0;
	float tama�oPalabrasEspacios = 0;
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
			tama�oPalabrasCompleto = 0;
		}

		tama�oPalabrasCompleto += tama�o[j];
		tama�oPalabrasEspacios = tama�oPalabrasCompleto + ((j - i)*tama�oIdealEspacio);
		if (tama�oPalabrasEspacios>tama�oLinea) {
			sobra = tama�oPalabrasEspacios - tama�oLinea;
			bR = tama�oIdealEspacio - (sobra / (j - i));
			bA = tama�oIdealEspacio + (tama�oLinea - ((tama�oPalabrasCompleto - tama�o[j]) + (tama�oIdealEspacio*(j - i - 1)))) / (j - i - 1);

			if (costoAmpliar(bA,tama�oIdealEspacio,j,i)>costoReduce(bR, tama�oIdealEspacio,j,i) && bR > 0)
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

float costoAmpliar(float bA, float tama�oIdeal, int j, int i)
{
	return (fabs(bA - tama�oIdeal)*(j - i - 1));
}
float costoReduce(float bR, float tama�oIdeal, int j, int i)
{
	return (fabs(bR - tama�oIdeal)*(j - i));
}