#include <iostream>
#include "OrdenamientoGenerico.h"
#include <vector>
#include <chrono>
#include <string>


void copiar(int[], int[], int);

int main()
{
	int n = 1000000;
	int* prueba = new int[n];
	int* temp = new int[n];
	int max = 0;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		*(prueba + i) = rand() % 100;
	}


	copiar(prueba, temp, n);
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::bucketSort(temp, n);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Bucket Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;



	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::countingSort(temp, n, 99);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Counting Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;


	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::mergesort(temp, 0, n - 1, Ordenamiento<int>::asc, n);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Merge Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;


	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::radixSort(temp, n, 100);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Radix Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::shellSort(temp, n);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Shell Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::heapSort(temp, n);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Heap Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::quicksort(temp, 0, n-1, Ordenamiento<int>::asc);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Quick Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	


	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::treesort(temp, n);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Tree Sort: " << duration << " micro s" << " = " << duration / 100000 << " s." << std::endl;

	
	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::cocktailSort(temp, n);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Cocktail Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::insercion(temp, n, Ordenamiento<int>::asc);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Insertion Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::seleccion(temp, n, Ordenamiento<int>::asc);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Selection Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	copiar(prueba, temp, n);
	begin = std::chrono::high_resolution_clock::now();
	Ordenamiento<int>::burbuja(temp, n, Ordenamiento<int>::asc);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Bubble Sort: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

}

void copiar(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(b + i) = *(a + i);
	}
}