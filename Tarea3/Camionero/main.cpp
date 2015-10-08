#include <iostream>
#include <string>
#include <vector>

int main()
{
	int n = 50;
	int cantGas = n;
	std::vector<int> distancias = {30, 25, 12, 10, 14, 33};
	std::vector<int> gasolineras;
	for (int i = 0; i < distancias.size(); i++)
	{
		if (cantGas < distancias[i])
		{
			gasolineras.push_back(i-1);
			cantGas = n;
			i--;
		}
		else
		{
			cantGas = cantGas - distancias[i];
		}
	}
	for (int j = 0; j < gasolineras.size(); j++)
	{
		std::cout << "Te tienes que parar en la gasolinera: " << gasolineras[j] + 1 << std::endl;
	}
	return 0;
}