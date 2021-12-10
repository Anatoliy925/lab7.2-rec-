#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo);

void SearchRow(int** a, const int  rowNo, const int N, int colNo, int &min, int &Imin, int &Jmin);
void SearchRows(int** a, const int  rowNo, const int N, int colNo, int &min, int &Imin, int &Jmin);
void SearchRowMax(int** a, const int  rowNo, const int N, int colNo, int& max, int &Imax, int &Jmax);
void SearchRowsMax(int** a, const int  rowNo, const int N, int colNo, int& max, int &Imax, int &Jmax);

int Sum(int min, int max);

int main(){
    
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    int max = 0, min = 100;
    cout << "n = "; cin >> n;
    
    int **a = new int*[n];
    for (int i=0; i<n; i++)
        a[i] = new int[n];
    
    CreateRows(a, n, Low, High, 0);
    PrintRows(a, n, 0);
    
    int Imin, Jmin, Imax, Jmax;
    SearchRows(a, 0, n, 0, min, Imin, Jmin);
    SearchRowsMax(a, 0, n, n-1, max, Imax, Jmax);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    swap(a[Imax][Jmax], a[Imin][Jmin]);
    PrintRows(a, n, 0);
    cout << "Сума: "<< Sum(min, max);
    cout << endl;
    
    for (int i=0; i<n; i++)
            delete [] a[i];
        delete [] a;
    
    return 0;
}

int Sum(int min, int max)
{
    return min + max;
}
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High-Low+1);
    if ( colNo < N-1 )
            CreateRow(a, rowNo, N, Low, High, colNo+1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if ( rowNo < N-1 )
        CreateRows(a, N, Low, High, rowNo+1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if ( colNo < N-1 )
        PrintRow(a, rowNo, N, colNo+1);
    else
        cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if ( rowNo < N-1 )
        PrintRows(a, N, rowNo+1);
    else
        cout << endl;
}
void SearchRow(int** a, const int  rowNo, const int N, int colNo, int& min, int &Imin, int &Jmin)
{
    if(a[rowNo][colNo] < min)
    {
        min = a[rowNo][colNo];
        Imin = rowNo;
        Jmin = colNo;
    }
    if(colNo < N - 2 - rowNo)
        SearchRow(a, rowNo, N, colNo+1, min, Imin, Jmin);
        
}
void SearchRows(int** a, const int  rowNo, const int N, int colNo, int& min, int &Imin, int &Jmin)
{
        SearchRow(a, rowNo, N, 0, min, Imin, Jmin);
    if(rowNo < N - 2)
        SearchRows(a, rowNo+1, N, colNo, min, Imin, Jmin);
}
void SearchRowMax(int** a, const int  rowNo, const int N, int colNo, int& max, int &Imax, int &Jmax)
{
    if(a[rowNo][colNo] > max)
    {
        max = a[rowNo][colNo];
        Imax = rowNo;
        Jmax = colNo;
    }
    if(colNo > N  - rowNo)
        SearchRowMax(a, rowNo, N, colNo-1, max, Imax, Jmax);
        
}
void SearchRowsMax(int** a, const int  rowNo, const int N, int colNo, int& max, int &Imax, int &Jmax)
{
        SearchRowMax(a, rowNo, N, N-1, max, Imax, Jmax);
        if(rowNo < N - 1)
        SearchRowsMax(a, rowNo+1, N, colNo, max, Imax, Jmax);
}

