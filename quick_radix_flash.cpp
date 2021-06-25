void quick_sort(int *a, int l, int r)
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

void radix_sort(int *&a, int n, int exp)
{
    int count[10], *output;
    output = new int[n];
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
    delete[] output;
}

void flash_Sort(int a[], int n)
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