#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "sortTime.cpp"
#include "sortCompare.cpp"
#include "DataGenerator.cpp"

using namespace std;
bool So(string array)
{
    char *p;
    strtol(array.c_str(), &p, 10);
    return *p == 0;
}

int main(int argc, char* argv[])
{
    vector<string> array;
    for (int i = 0; i < argc; i++)
    {
        string s(argv[i]);
        array.push_back(s);
    }

    if (array[1] == "-a")
    {
        if (argc == 5)
        {
            //commandline 1
            if (!So(array[3]))
            {
                cout << "ALGORITHM MODE" << endl;
                cout << "Algorithm: " << array[2] << endl;
                cout << "Input file: " << array[3] << endl;

                ifstream file;
                file.open(array[3]);
                int n;
                file >> n;
                cout << "Input size: " << n << endl;
                cout << "--------------------" << endl;
                int *a1 = new int[n];
                int *a2 = new int[n];
                for (int i = 0; i < n; i++)
                {
                    file >> a1[i];
                    a2[i] = a1[i];
                }
                if (array[4] == "-time")
                {
                    double time = time_sort(a1, n, array[2]);
                    cout << "Running time (if required): " << time << endl;
                    delete [] a1;
                    delete [] a2;
                }
                else if (array[4] == "-comp")
                {
                    long long compare = 0;
                    compare_sort(a2, n, compare, array[2]);
                    cout << "Comparisions (if required): " << compare << endl;
                    delete [] a1;
                    delete [] a2;
                }
                else
                {
                    double time = time_sort(a1, n, array[2]);
                    cout << "Running time (if required): " << time << endl;
                    long long compare = 0;
                    compare_sort(a2, n, compare, array[2]);
                    cout << "Comparisions (if required): " << compare << endl;
                    delete [] a1;
                    delete [] a2;
                }
            }
            //commandline 3
            else
            {
                cout << "ALGORITHM MODE" << endl;
                cout << "Algorithm: " << array[2] << endl;
                cout << "Input size: " << array[3] << endl;

                string a[4] = {"Randomize", "Nerly Sorted", "Sorted", "Reversed"};
                int i = 0;
                int* a1;
                int* a2;
                int n = stoi(array[3]);
                while (i != 4)
                {
                    cout << "Input order: " << a[i] << endl;
                    cout << "--------------------" << endl;
                    a1 = new int[n];
                    a2 = new int[n];
                    GenerateData(a1, n, i);
                    GenerateData(a2, n, i);
                    
                    if (array[5] == "-time")
                    {
                        double time = time_sort(a1, n, array[2]);
                        cout << "Running time (if required): " << time << endl;
                        delete [] a1;
                        delete [] a2;
                    }
                    else if (array[5] == "-comp")
                    {
                        long long compare = 0;
                        compare_sort(a2, n, compare, array[2]);
                        cout << "Comparisions (if required): " << compare << endl;
                        delete [] a1;
                        delete [] a2;
                    }
                    else
                    {
                        double time = time_sort(a1, n, array[2]);
                        cout << "Running time (if required): " << time << endl;
                        long long compare = 0;
                        compare_sort(a2, n, compare, array[2]);
                        cout << "Comparisions (if required): " << compare << endl;
                        delete [] a1;
                        delete [] a2;
                    }
                    cout << endl;
                    i++;
                }
                
            }
        }
        //commandline 2
        else if (argc == 6)
        {
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << array[2] << endl;
            cout << "Input size: " << array[3] << endl;
            cout << "Input oder: " << array[4] << endl;

            int n = stoi(array[3]);
            int *a1 = new int[n];
            int *a2 = new int[n];
            if (array[4] == "-rand")
            {
                GenerateData(a1, n, 0);
                GenerateData(a2, n, 0);
            }
            else if (array[4] == "-sorted")
            {
                GenerateData(a1, n, 1);
                GenerateData(a2, n, 1);
            }
            else if (array[4] == "-rev")
            {
                GenerateData(a1, n, 2);
                GenerateData(a2, n, 2);
            }
            else if (array[4] == "-nsorted")
            {
                GenerateData(a1, n, 3);
                GenerateData(a2, n, 3);
            }

            if (array[5] == "-time")
            {
                double time = time_sort(a1, n, array[2]);
                cout << "Running time (if required): " << time << endl;
                delete [] a1;
                delete [] a2;
            }
            else if (array[5] == "-comp")
            {
                long long compare = 0;
                compare_sort(a2, n, compare, array[2]);
                cout << "Comparisions (if required): " << compare << endl;
                delete [] a1;
                delete [] a2;
            }
            else
            {
                double time = time_sort(a1, n, array[2]);
                cout << "Running time (if required): " << time << endl;
                long long compare = 0;
                compare_sort(a2, n, compare, array[2]);
                cout << "Comparisions (if required): " << compare << endl;
                delete [] a1;
                delete [] a2;
            }
        }
    }
    else if (array[1] == "-c")
    {
        //commandline 4
        if (argc == 5)
        {
            cout << "COMPARE MODE" << endl;
            cout << "Algorithm: " << array[2] << " | " << array[3] << endl;
            cout << "Input file: " << array[4] << endl;
            ifstream file;
            file.open(array[4]);
            int n;
            file >> n;
            cout << "Input size: " << n << endl;
            cout << "--------------------" << endl;
            int *a1 = new int[n];
            int *a2 = new int[n];
            int *a3 = new int[n];
            int *a4 = new int[n];
            for (int i = 0; i < n; i++)
            {
                file >> a1[i];
                a2[i] = a1[i];
                a3[i] = a1[i];
                a4[i] = a1[i];
            }
            double time1 = time_sort(a1, n, array[2]);
            double time2 = time_sort(a2, n, array[3]);
            long long compare1 = 0, compare2 = 0;
            compare_sort(a3, n, compare1, array[2]);
            compare_sort(a4, n, compare1, array[3]);
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout << "Comparisions: " << compare1 << " | " << compare2 << endl;
            delete [] a1;
            delete [] a2;
            delete [] a3;
            delete [] a4;
        }
        //commandline 5
        else if (argc == 6)
        {
            cout << "COMPARE MODE" << endl;
            cout << "Algorithm: " << array[2] << " | " << array[3] << endl;
            int n = stoi(array[4]);
            cout << "Input size: " << n << endl;
            cout << "Input order: " << array[5] << endl;
            cout << "--------------------" << endl;
            
            int* a1 = new int[n];
            int* a2 = new int[n];
            int* a3 = new int[n];
            int* a4 = new int[n];
            if (array[5] == "-rand")
            {
                GenerateData(a1, n, 0);
                GenerateData(a2, n, 0);
                GenerateData(a3, n, 0);
                GenerateData(a4, n, 0);
            }
            else if (array[5] == "-sorted")
            {
                GenerateData(a1, n, 1);
                GenerateData(a2, n, 1);
                GenerateData(a3, n, 1);
                GenerateData(a4, n, 1);
            }
            else if (array[5] == "-rev")
            {
                GenerateData(a1, n, 2);
                GenerateData(a2, n, 2);
                GenerateData(a3, n, 2);
                GenerateData(a4, n, 2);
            }
            else if (array[5] == "-nsorted")
            {
                GenerateData(a1, n, 3);
                GenerateData(a2, n, 3);
                GenerateData(a3, n, 3);
                GenerateData(a4, n, 3);
            }

            double time1 = time_sort(a1, n, array[2]);
            double time2 = time_sort(a2, n, array[3]);
            long long compare1 = 0, compare2 = 0;
            compare_sort(a3, n, compare1, array[2]);
            compare_sort(a4, n, compare1, array[3]);
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout << "Comparisions: " << compare1 << " | " << compare2 << endl;
            delete [] a1;
            delete [] a2;
            delete [] a3;
            delete [] a4;
        }
    }
    
    system("pause");
    return 0;
}
