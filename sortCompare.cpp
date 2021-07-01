#include <iostream>
using namespace std;


template <class T>
void selectionSort_c(T* a, int n, long long& compare)
{
	int min; 
	int temp;
	for (int i = 0; ++compare && i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; ++compare && j < n; j++)
		{
			if (++compare && a[j] < a[min])
				min = j;
		}
		if (++compare && min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}

template <class T>
void insertionSort_c(T* a, int n, long long& compare)
{
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
void bubbleSort_c(T* a, int n, long long& compare)
{
	for (int i = 0; ++compare && i <= n - 1; i++)
	{
		for (int j = n - 1; ++compare && j > i; j--)
		{
			if (++compare && a[j] < a[j - 1])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

template <class T>
void Heapify(T* a, int n, int i, long long& compare)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if ((++compare && l < n) && (++compare && a[l] > a[largest]))
		largest = l;

	if ((++compare && r < n) && (++compare && a[r] > a[largest]))
		largest = r;

	if ((++compare && largest != i))
	{
		swap(a[i], a[largest]);
		Heapify(a, n, largest,compare);
	}
}
template <class T>
void heapSort_c(T* a, int n, long long& compare)
{
	for (int i = n / 2 - 1;++compare && i >= 0; i--)
		Heapify(a, n, i,compare);

	for (int i = n - 1;++compare && i > 0; i--)
	{
		swap(a[0], a[i]);
		Heapify(a, i, 0,compare);
	}
}

template <class T>//merge sort
void Merge(T* a, int l, int m, int r, long long& compare) {
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
void mergeSort_c(T* a, int l, int r, long long& compare) {
    if (++compare && l < r)
    {
        int m = (l + r) / 2;
        mergeSort_c(a, l, m, compare);
        mergeSort_c(a, m + 1, r, compare);
        Merge(a, l, m, r, compare);
    }
}

template <class T>
int partition_c (T *a, int low, int high,long long& compare)
{
    int pivot = a[high/2 + low/2];    // pivot
    int left = low;
    int right = high;
    while(true){
        while((++compare && left <= right) && (++compare &&  a[left] < pivot)) 
            left++; 
        while((++compare && right >= left) && (++compare && a[right] > pivot)) 
            right--;
        if (++compare && left >= right) 
            break; 

        swap(a[left], a[right]);
        left++; 
        right--; 
    }
    swap(a[left], a[high/2 + low/2]);
    return left; 
}

template <class T>
void quickSort_c(T *a, int left, int right,long long& compare)
{
    if (++compare && left >= right)
        return;
    int pivot = partition_c(a, left, right,compare);
    quickSort_c(a, left, pivot - 1,compare);
    quickSort_c(a, pivot + 1, right,compare);
}


template <class T>
void radixSort_c(T* &a, int n, long long& compare)
{
    int max = 0, exp = 0;
    for (int i = 0; ++compare && i < n; i++)
    {
        if (++compare && exp < a[i])
            exp = a[i];
    }
    while (++compare && exp > 0)
    {
        max++;
        exp != 10;
    }
    int b[10], *output;
    output = new int[n];
    exp = 1;
    while (++compare && max--)
    {
        for (int i = 0; ++compare && i < 10; i++)
            b[i] = 0;
        for (int i = 0; ++compare && i < n; i++)
            b[(a[i] / exp) % 10]++;
        for (int i = 1; ++compare && i < 10; i++)
            b[i] += b[i - 1];
        for (int i = n - 1; ++compare && i >= 0; i--)
        {
            output[b[(a[i] / exp) % 10] - 1] = a[i];
            b[(a[i] / exp) % 10]--;
        }
        for (int i = 0; ++compare && i < n; i++)
            a[i] = output[i];
        exp *= 10;
    }
    delete[] output;
}

template <class T>//sharker sort
void shakerSort_c(T* a, int n, long long& compare){
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
void shellSort_c(T* a, int n, long long& compare)
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
void flashSort_c(T* a, int n, long long& compare)
{
    int minVal = a[0], max = a[0], hold;
    int m = int(0.45 * n);
    for (int i = 1; ++compare && i < n; i++)
    {
        if (++compare && a[i] < minVal)
            minVal = a[i];
        if (++compare && a[i] > max)
            max = a[i];
    }
    if (++compare && max == minVal)
        return;
    int *l = new int[m];
    for (int i = 0; ++compare && i < m; i++)
        l[i] = 0;
    double c = (double)(m - 1) / (max - minVal);
    for (int i = 0; ++compare && i < n; i++)
    {
        int k = int(c * (a[i] - minVal));
        l[k]++;
    }
    for (int i = 1; ++compare && i < m; i++)
        l[i] += l[i - 1];
    int move = 0;
    int j = 0;
    m--;
    while (++compare && move < n - 1)
    {
        while (++compare && j > l[m] - 1)
        {
            j++;
            m = int(c * (a[j] - minVal));
        }
        while (++compare && j != l[m])
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
    for (int i = 1; ++compare && i < n; i++)
    {
        hold = a[i];
        j = i - 1;
        while ((++compare && j >= 0) && (++compare && a[j] > hold))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = hold;
    }
}

template <class T>
void countingSort_c(T* a, int n, long long& compare)
{
	int* arr_out = new int[n]; 
	int max = a[0];
	int min = a[0];
 
	for (int i = 1;	++compare && i < n; i++)
	{
		if (++compare && a[i] > max)
		{
			max = a[i];
		}
		else if (++compare && a[i] < min) 
			min = a[i];
	}
	int k = max - min + 1; 
	int* count_arr = new int[k]; 
	fill_n(count_arr, k, 0);
	for (int i = 0; ++compare && i < n; i++)
		count_arr[a[i] - min]++; 
 
	for (int i = 1;	++compare && i < k; i++)
		count_arr[i] += count_arr[i - 1];
 
	for (int i = 0;	++compare && i < n; i++)
	{
		arr_out[count_arr[a[i] - min] - 1] = a[i];
		count_arr[a[i] - min]--;
	}
 
	for (int i = 0;	++compare && i < n; i++)
		a[i] = arr_out[i];
}

template <class T>
void compare_sort(T* a, int n, long long& compare, string sort){
    
    if (sort == "selection-sort"){
        compare = 0;
        selectionSort_c(a, n, compare);
        return;
    }  
    else if (sort == "insertion-sort"){
       compare = 0; 
       insertionSort_c(a, n, compare);
       return;
    }
    else if (sort == "bubble-sort"){
        compare = 0;
        bubbleSort_c(a, n, compare);
        return;
    }
    else if (sort == "heap-sort"){
        compare = 0;
        heapSort_c(a, n, compare);
        return;
    }
    else if (sort == "merge-sort"){
        compare = 0;
        mergeSort_c(a, 0, n-1, compare);
        return;
    }
    else if (sort == "quick-sort"){
        compare = 0;
        quickSort_c(a, 0, n-1, compare);
        return;
    }
    else if (sort == "radix-sort"){
        compare = 0;
        radixSort_c(a, n, compare);
        return;
    }
    else if (sort == "shaker-sort"){
        compare = 0;
        shakerSort_c(a, n, compare);
        return;
    }
    else if (sort == "shell-sort"){
        compare = 0;
        shellSort_c(a, n, compare);
        return;
    }
    else if (sort == "counting-sort"){
        compare = 0;
        countingSort_c(a, n, compare);
        return;
    }
    else if (sort == "flash-sort"){
        compare = 0;
        flashSort_c(a, n, compare);
        return;
    }
}

