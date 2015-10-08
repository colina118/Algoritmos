#include <iostream>
#include <string>
#include <vector>


bool prefiere(std::vector<std::vector<int>>, int, int, int, int); 

void parejas(std::vector<std::vector<int>>,  int);

int main()
{
	int n = 4;
	std::vector<std::vector<int>> preferencias(2 * n, std::vector<int>(n));
	preferencias = { { 6, 5, 4, 7 },
	{ 5, 7, 4, 6 },
	{ 6, 4, 7, 5 },
	{ 4, 5, 6, 7 },
	{ 0, 2, 1, 3 },
	{ 2, 3, 1, 0 },
	{ 1, 2, 3, 0 },
	{ 3, 1, 0, 2 },
	};
	parejas(preferencias, n);

}


void parejas(std::vector<std::vector<int>> preferencias, int n)
{
	std::vector<int> disponibilidadMujeres;
	std::vector<bool> asignadoHombre;

	for (int i = 0; i < n; i++)
	{
		disponibilidadMujeres.push_back(-1);
		asignadoHombre.push_back(false);
	}

	int hombresLibres = n;

	while (hombresLibres > 0)
	{
		int hombre;
		for (int i = 0; i < n; i++)
		{
			if (asignadoHombre[i] == false)
			{
				hombre = i;
				i = n;
			}
		}
		for (int i = 0; i < n && asignadoHombre[hombre] == false; i++)
		{
			int mujer = preferencias[hombre][i];
			if (disponibilidadMujeres[mujer - n] == -1)
			{
				disponibilidadMujeres[mujer - n] = hombre;
				asignadoHombre[hombre] = true;
				hombresLibres--;
			}
			else
			{
				int hombre1 = disponibilidadMujeres[mujer - n];
				if (prefiere(preferencias, hombre, mujer, hombre1, n) == false)
				{
					disponibilidadMujeres[mujer - n] = hombre;
					asignadoHombre[hombre] = true;
					asignadoHombre[hombre1] = false;
				}
			}
		}
	}

	std::cout << "Mujer   Hombre" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << " " << i + n << "\t" << disponibilidadMujeres[i] << std::endl;
	}

}


bool prefiere(std::vector<std::vector<int>> preferencias, int hombre, int mujer, int hombre1, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (preferencias[mujer][i] == hombre1)
		{
			return true;
		}
		if (preferencias[mujer][i] == hombre)
		{
			return false;
		}
	}
}