#include <iostream>
#include <time.h>
using namespace std;

template <class T>//insertion sort
void insertion_sort(T* a, int n){
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

template <class T>//heap sort
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

template <class T>//merge sort
void merge(T* a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* a1 = new int[n1];
    int* a2 = new int[n2];

    for (int i = 0; i < n1; i++)
        a1[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        a2[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j]) {
            a[k] = a1[i];
            i++;
        }
        else
        {
            a[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = a1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = a2[j];
        k++;
        j++;
    }
    delete[]a1;
    delete[]a2;

}
template <class T>
void merge_sort(T* a, int l, int r) {
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

template <class T>//quick sort
void quick_sort(T* a, int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i] < a[l])
            i++;
        while (a[j] > a[l])
            j--;
        swap(a[i], a[j]);
        if (i == j)
        {
            i++;
            j--;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, i, r);
}

//template <class T>//radix sort
// void radix_sort(T* a, int n, int exp)
// {
//     int count[10], *output;
//     output = new int[n];
//     for (int i = 0; i < 10; i++)
//         count[i] = 0;
//     for (int i = 0; i < n; i++)
//         count[(a[i] / exp) % 10]++;
//     for (int i = 1; i < 10; i++)
//         count[i] += count[i - 1];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         output[count[(a[i] / exp) % 10] - 1] = a[i];
//         count[(a[i] / exp) % 10]--;
//     }
//     for (int i = 0; i < n; i++)
//         a[i] = output[i];
//     delete[] output;
// }

template <class T>//sharker sort
void shaker_sort(T* a, int n){
	int l = 0, r = n-1, k = n-1;
	while (l < r)
	{
		for (int i = r; i > l; i--)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i-1], a[i]);
				k=i;
			}
		}
		l = k;
		for (int j = 0; j < r; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k=j;
			}
		}
		r = k;
		
	}
}

template <class T>//shell sort
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
void flash_sort(T* a, int n)
{
    int minVal = a[0], max = a[0], hold;
    int m = int(0.45 * n);
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > max)
            max = a[i];
    }
    if (max == minVal)
        return;
    int *l = new int[m];
    for (int i = 0; i < m; i++)
        l[i] = 0;
    double c = (double)(m - 1) / (max - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c * (a[i] - minVal));
        l[k]++;
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];
    int move = 0;
    int j = 0;
    m--;
    while (move < n - 1)
    {
        while (j > l[m] - 1)
        {
            j++;
            m = int(c * (a[j] - minVal));
        }
        while (j != l[m])
        {
            m = int(c * (a[j] - minVal));
            l[m]--;
            hold = a[l[m]];
            a[l[m]] = a[j];
            a[j] = hold;
            move++;
        }
    }
    delete[] l;
    for (int i = 1; i < n; i++)
    {
        hold = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > hold)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = hold;
    }
}

template <class T>
double time_sort(T* a, int n, string sort)
{
	
	// if (sort == "selection-sort"){
	// 	double cpu_time_used;
	// 	clock_t start = clock();
	// 	selection_sort(a, n);
	// 	clock_t end = clock();
	// 	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	// 	return cpu_time_used;
    // }
    //ok
	if (sort == "insertion-sort"){
        double cpu_time_used;
		clock_t start = clock();
		insertion_sort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    // else if (sort == "buble-sort"){
    //     double cpu_time_used;
	// 	clock_t start = clock();
	// 	buble_sort(a, n);
	// 	clock_t end = clock();
	// 	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	// 	return cpu_time_used;
    // }
    //ok
	else if (sort == "heap-sort"){
        double cpu_time_used;
		clock_t start = clock();
		heap_sort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    //ok
	else if (sort == "merge-sort"){
        double cpu_time_used;
		clock_t start = clock();
		merge_sort(a, 0, n-1);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    //ok
	else if (sort == "quick-sort"){
        double cpu_time_used;
		clock_t start = clock();
		quick_sort(a, 0, n-1);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    // else if (sort == "radix-sort"){
    //     double cpu_time_used;
	// 	clock_t start = clock();
	// 	radix_sort(a, n);
	// 	clock_t end = clock();
	// 	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	// 	return cpu_time_used;
    // }
	//ok
	else if (sort == "shaker-sort"){
        double cpu_time_used;
		clock_t start = clock();
		shaker_sort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    //ok
	else if (sort == "shell-sort"){
        double cpu_time_used;
		clock_t start = clock();
		shell_sort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    // else if (sort == "counting-sort"){
    //     double cpu_time_used;
	// 	clock_t start = clock();
	// 	counting_sort(a, n);
	// 	clock_t end = clock();
	// 	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	// 	return cpu_time_used;
    // }
    // else if (sort == "flash-sort"){
    //     double cpu_time_used;
	// 	clock_t start = clock();
	// 	flash_sort(a, n);
	// 	clock_t end = clock();
	// 	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	// 	return cpu_time_used;
    // }
}
