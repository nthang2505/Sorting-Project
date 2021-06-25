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
void insertion_sort(T* a, int n)
{
	int i, j;
	T key;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

template <class T>
void shell_sort(T* a, int n)
{
	int i, j, k;
	T temp;

	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				if (a[k + i] >= a[k])
					break;
				else
				{
					temp = a[k];
					a[k] = a[k + i];
					a[k + i] = temp;
				}
			}
		}
	}
}

template <class T>
void heapify(T* a, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

template <class T>
void heap_sort(T* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

template <class T>
void insertionSort(T* a, int n, int &compare)
{
	compare = 0;
	int i, j;
	T key;
	for (i = 1; ++compare && i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while (++compare && j >= 0 && a[j] > key && ++compare)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

template <class T>
void shellSort(T* a, int n, int &compare)
{
	compare = 0;
	int i, j, k;
	T temp;

	for (i = n / 2; ++compare && i > 0; i = i / 2)
	{
		for (j = i; j < n && ++compare; j++)
		{
			for (k = j - i; k >= 0 && ++compare; k = k - i)
			{
				if (a[k + i] >= a[k] && ++compare)
					break;
				else
				{
					temp = a[k];
					a[k] = a[k + i];
					a[k + i] = temp;
				}
			}
		}
	}
}

template <class T>
void Heapify(T* a, int n, int i,int &compare)
{
	compare = 0;
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest]&&++compare&&++compare)
		largest = l;

	if (r < n && a[r] > a[largest]&&++compare)
		largest = r;

	if (largest != i&& ++compare)
	{
		swap(a[i], a[largest]);
		Heapify(a, n, largest,compare);
	}
}

template <class T>
void heapSort(T* a, int n,int &compare)
{
	compare = 0;
	for (int i = n / 2 - 1; i >= 0&&++compare; i--)
		Heapify(a, n, i,compare);

	for (int i = n - 1; i > 0&&++compare; i--)
	{
		swap(a[0], a[i]);
		Heapify(a, i, 0,compare);
	}
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

int main() {
	int* a = new int[MAX];
	int n;
	cin >> n;
	Input_Random(a, n);
	cout << endl;
	Output_random(a, n);
	cout << endl;
	while (1 < 2) {
	cout << "In4\n";
	cout << "1.Insertion Sort \n";
	cout << "2.Shell Sort \n";
	cout << "1.Heap Sort \n";
	cout << "1.Time Insertion Sort \n";
	cout << "2.Time Shell Sort \n";
	cout << "1.Time Heap Sort \n";
	cout << "What your chosen: \n";
	int chose, compare = 0;
	cin >> chose;
		//system("cls");
		if (chose == 1) {
			insertionSort(a, n,compare);
			cout << "compare: " << compare << endl;
			Output_random(a, n);
			cout << endl;
			system("pause");
		}
		else if (chose == 2) {
			shellSort(a, n,compare);
			cout << "compare: " << compare << endl;
			Output_random(a, n);
			cout << endl;
			system("pause");
		}
		else if (chose == 3) {
			heapSort(a, n,compare);
			cout << "compare: " << compare << endl;
			Output_random(a, n);
			cout << endl;
			system("pause");
		}
		else if (chose == 4) {
			cout << "\n\n\t\t BAN DA CHON INSERTION_SORT \n\n";
			cout << "\t\t==> Times  : " << Time_Insertion_sort(a, n);
			cout << endl;
			cout << endl;
			system("pause");
		}
		else if (chose == 5) {
			cout << "\n\n\t\t BAN DA CHON SHELL_SORT \n\n";
			cout << "\t\t==> Times  : " << Time_Shell_sort(a, n);
			cout << endl;
			cout << endl;
			system("pause");
		}
		else if (chose == 6) {
			cout << "\n\n\t\t BAN DA CHON HEAP_SORT \n\n";
			cout << "\t\t==> Times  : " << Time_Heap_sort(a, n);
			cout << endl;
			cout << endl;
			system("pause");
		}
		else
			break;
	}
}
