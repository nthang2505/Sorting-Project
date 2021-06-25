#include <iostream>
using namespace std;

template <class T>
void insertionSort(T* a, int n, double& compare)
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
void Heapify(T* a, int n, int i,double& compare)
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
void heapSort(T* a, int n,double& compare)
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

template <class T>//merge sort
void Merge(T* a, int l, int m, int r, double& compare) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* a1 = new int[n1];
    int* a2 = new int[n2];

    for (int i = 0;++compare && i < n1; i++)
        a1[i] = a[l + i];
    for (int i = 0;++compare && i < n2; i++)
        a2[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while ((++compare && i < n1) &&(++compare && j < n2))
    {
        if (++compare && a1[i] < a2[j]) {
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

    while (++compare && i < n1)
    {
        a[k] = a1[i];
        k++;
        i++;
    }
    while (++compare && j < n2)
    {
        a[k] = a2[j];
        k++;
        j++;
    }
    delete[]a1;
    delete[]a2;

}
template <class T>
void mergeSort(T* a, int l, int r, double& compare) {
    if (++compare && l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m, compare);
        mergeSort(a, m + 1, r, compare);
        Merge(a, l, m, r, compare);
    }
}

template <class T>//quick sort
void quickSort(T* a, int l, int r, double& compare)
{
    if (++compare && l >= r)
        return;
    int i = l, j = r;
    while (++compare && i <= j)
    {
        while (++compare && a[i] < a[l])
            i++;
        while (++compare && a[j] > a[l])
            j--;
        swap(a[i], a[j]);
        if (++compare && i == j)
        {
            i++;
            j--;
        }
    }
    quickSort(a, l, j, compare);
    quickSort(a, i, r, compare);
}

template <class T>//sharker sort
void shakerSort(T* a, int n, double& compare){
	int l = 0, r = n-1, k = n-1;
	while (++compare && l < r)
	{
		for (int i = r; ++compare && i > l; i--)
		{
			if (++compare && a[i - 1] > a[i])
			{
				swap(a[i-1], a[i]);
				k=i;
			}
		}
		l = k;
		for (int j = 0; ++compare && j < r; j++)
		{
			if (++compare && a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k=j;
			}
		}
		r = k;
	}
}

template <class T>
void shellSort(T* a, int n, double& compare)
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
void compare_sort(T* a, int n, double& compare, string sort){
    
    if (sort == "selection-sort"){
        
    }
    //ok
    else if (sort == "insertion-sort"){
       compare = 0; 
       insertionSort(a, n, compare);
       return;
    }
    else if (sort == "buble-sort"){
        
    }
    //ok
    else if (sort == "heap-sort"){
        compare = 0;
        heapSort(a, n, compare);
        return;
    }
    //ok
    else if (sort == "merge-sort"){
        compare = 0;
        mergeSort(a, 0, n-1, compare);
        return;
    }
    //ok
    else if (sort == "quick-sort"){
        compare = 0;
        quickSort(a, 0, n-1, compare);
        return;
    }
    else if (sort == "radix-sort"){
        
    }
    //ok
    else if (sort == "shaker-sort"){
        compare = 0;
        shakerSort(a, n, compare);
        return;
    }
    //ok
    else if (sort == "shell-sort"){
        compare = 0;
        shellSort(a, n, compare);
        return;
    }
    else if (sort == "counting-sort"){
        
    }
    else if (sort == "flash-sort"){
        
    }
}

