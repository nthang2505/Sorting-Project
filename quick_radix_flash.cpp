
void quick_sort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r, temp;
    while (i <= j)
    {
        while (a[i] < a[l])
            i++;
        while (a[j] > a[l]) 
            j--;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, i, r);
}

void radix_sort(int *&a, int n)
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

void quick_sort(int *a, int l, int r, int &count_compare)
{
    count_compare++;
    if (l >= r)
        return;
    int i = l, j = r, temp;
    while (count_compare++ && i <= j)
    {
        while (count_compare++ && a[i] < a[l])
            i++;
        while (count_compare++ && a[j] > a[l])
            j--;
        if (count_compare++ && i <= j)
        {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(a, l, j, count_compare);
    quick_sort(a, i, r, count_compare);
}

void radix_sort(int *&a, int n, int &count_compare)
{
    int max = 0, exp = 0;
    for (int i = 0; ++count_compare && i < n; i++)
    {
        if (exp < a[i])
            exp = a[i];
        count_compare++;
    }
    while (++count_compare && exp > 0)
    {
        max++;
        exp /= 10;
    }
    int count[10], *output;
    output = new int[n];
    exp = 1;
    while (++count_compare && max--)
    {
        for (int i = 0; ++count_compare && i < 10; i++)
            count[i] = 0;
        for (int i = 0; ++count_compare && i < n; i++)
            count[(a[i] / exp) % 10]++;
        for (int i = 1; ++count_compare && i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; ++count_compare && i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for (int i = 0; ++count_compare && i < n; i++)
            a[i] = output[i];
        exp *= 10;
    }
    delete[] output;
}

void flash_Sort(int a[], int n, int &count_compare)
{
    int minVal = a[0], max = a[0], hold;
    int m = int(0.45 * n);
    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > max)
            max = a[i];
        count_compare += 2;
    }
    if (++count_compare && max == minVal)
        return;
    int *l = new int[m];
    for (int i = 0; ++count_compare && i < m; i++)
        l[i] = 0;
    double c = (double)(m - 1) / (max - minVal);
    for (int i = 0; ++count_compare && i < n; i++)
    {
        int k = int(c * (a[i] - minVal));
        l[k]++;
    }
    for (int i = 1; ++count_compare && i < m; i++)
        l[i] += l[i - 1];
    int move = 0;
    int j = 0;
    m--;
    while (++count_compare && move < n - 1)
    {
        while (++count_compare && j > l[m] - 1)
        {
            j++;
            m = int(c * (a[j] - minVal));
        }
        while (++count_compare && j != l[m])
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
    for (int i = 1; ++count_compare && i < n; i++)
    {
        hold = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > hold)
        {
            a[j + 1] = a[j];
            j = j - 1;
            count_compare += 2;
        }
        count_compare += 2;
        a[j + 1] = hold;
    }
}
