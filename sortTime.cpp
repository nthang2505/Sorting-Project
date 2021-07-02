#include <iostream>
#include <time.h>
using namespace std;

template <class T>
void selectionSort(T* a, int n)
{
	int min;
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}

template <class T>//insertion sort
void insertionSort(T* a, int n) {
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
void bubbleSort(T* a, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = n - 1;j > i; j--)
		{
			if (a[j] < a[j - 1]) 
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

template <class T>//heap sort
void heapify(T* a, int n, int i) {
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
void heapSort(T* a, int n)
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
void mergeSort(T* a, int l, int r) {
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

template <class T>
int partition (T *a, int low, int high)
{
    int pivot = a[high/2 + low/2];    // pivot
    int left = low;
    int right = high;
    while(true){
        while(left <= right && a[left] < pivot) 
            left++; 
        while(right >= left && a[right] > pivot) 
            right--;
        if (left >= right) 
            break; 

        swap(a[left], a[right]);
        left++; 
        right--; 
    }
    swap(a[left], a[high/2 + low/2]);
    return left; 
}

template <class T>
void quickSort(T *a, int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition(a, left, right);
    quickSort(a, left, pivot - 1);
    quickSort(a, pivot + 1, right);
}


template <class T>//radix sort
void radixSort(T* a, int n)
{
    int max = 0, exp = 0;
    for (int i = 0; i < n; i++)
        exp = exp > a[i] ? exp : a[i];
    while (exp > 0)
    {
        max++;
        exp /= 10;
    }
    int count[10], *output;
    output = new int[n];
    exp = 1;
    while (max--)
    {
        for (int i = 0; i < 10; i++)
            count[i] = 0;
        for (int i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++)
            a[i] = output[i];
        exp *= 10;
    }
    delete[] output;
}

template <class T>//sharker sort
void shakerSort(T* a, int n) {
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
void shellSort(T* a, int n) {
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

template <class T>//flash sort
void flashSort(T* a, int n)
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
void countingSort(T* a, int n)
{
	int* arr_out = new int[n]; // mảng arr_out[] sẽ chứa phần tử sau khi sort
	int max = a[0];
	int min = a[0];
 
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i]; // giá trị lớn nhất trong mảng
		else if (a[i] < min)
 
			min = a[i]; // giá trị nhỏ nhất trong mảng
	}
 
	int k = max - min + 1; // kích thước mảng đếm
	int* count_arr = new int[k];  // Tạo một mảng đếm để lưu trữ số lượng của từng giá trị đầu vào
	fill_n(count_arr, k, 0); //Khởi tạo các phần tử count_array[] bằng 0
 
	for (int i = 0; i < n; i++)
		count_arr[a[i] - min]++; // lưu số lượng giá trị đầu vào
 
	// thay đổi count_arr[] để count_arr[] hiện tại chứa cái vị trí các giá trị đầu vào của mảng arr_out[]
 
	for (int i = 1; i < k; i++)
		count_arr[i] += count_arr[i - 1];
 
	// Điền arr_out[] bằng cách sử dụng count_arr[] và a[]
 
	for (int i = 0; i < n; i++)
	{
		arr_out[count_arr[a[i] - min] - 1] = a[i];
		count_arr[a[i] - min]--;
	}
 
	// Sao chép arr_out[] vào a[], để đầu vào bây giờ chứa các giá trị đã được sắp xếp
	for (int i = 0; i < n; i++)
		a[i] = arr_out[i];
}


template <class T>
double time_sort(T* a, int n, string sort) {
	if (sort == "selection-sort"){
		double cpu_time_used;
		clock_t start = clock();
		selectionSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    
	else if (sort == "insertion-sort"){
        double cpu_time_used;
		clock_t start = clock();
		insertionSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }

    else if (sort == "bubble-sort"){
        double cpu_time_used;
		clock_t start = clock();
		bubbleSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    
	else if (sort == "heap-sort"){
        double cpu_time_used;
		clock_t start = clock();
		heapSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    
	else if (sort == "merge-sort"){
        double cpu_time_used;
		clock_t start = clock();
		mergeSort(a, 0, n-1);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    
	else if (sort == "quick-sort"){
        double cpu_time_used;
		clock_t start = clock();
		quickSort(a, 0, n-1);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }

    else if (sort == "radix-sort"){
        double cpu_time_used;
		clock_t start = clock();
		radixSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
	
	else if (sort == "shaker-sort"){
        double cpu_time_used;
		clock_t start = clock();
		shakerSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    
	else if (sort == "shell-sort"){
        double cpu_time_used;
		clock_t start = clock();
		shellSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
    
    else if (sort == "counting-sort"){
        double cpu_time_used;
		clock_t start = clock();
		countingSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }

    else if (sort == "flash-sort"){
        double cpu_time_used;
		clock_t start = clock();
		flashSort(a, n);
		clock_t end = clock();
		cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;
		return cpu_time_used;
    }
}
