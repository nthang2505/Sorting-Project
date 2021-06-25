#include <iostream>
using namespace std;

template <class T>
double time_sort(T* a, int  n, string sort)
{
	double cpu_time_used;
	clock_t start = clock();
	heap_sort(a, n);
	clock_t end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}
