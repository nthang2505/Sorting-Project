#include<time.h>
#include <iostream>
#include <string>
#include <string.h>
//#include<windows.h>
#define MAX 1e6

using namespace std;

template <class T>
void Input_Random(T* a, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = 0 + (rand() / (RAND_MAX / (800 - 0))); // rad_max la so nguyen lon nhat co the ramdom duoc
	}
}
template <class T>
void Output_random(T* a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++) {
		dem++;
		cout << a[i] << "   ";

		if (i % 10 == 0 && i != 0)
			cout << endl;
	}
	cout << endl;
	cout << "\n\t\t==> Co tat ca " << dem << " phan tu !\n\n";
}

template <class T>
double Time_Insertion_sort(T* a, int  n)
{
	double cpu_time_used;
	clock_t start = clock();
	insertion_sort(a, n);
	clock_t end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}

template <class T>
double Time_Shell_sort(T* a, int  n)
{
	double cpu_time_used;
	clock_t start = clock();
	shell_sort(a, n);
	clock_t end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}

template <class T>
double Time_Heap_sort(T* a, int  n)
{
	double cpu_time_used;
	clock_t start = clock();
	heap_sort(a, n);
	clock_t end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}

