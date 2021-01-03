#include <iostream>

using namespace std;

template <class T>
struct Average
{
    T av1, av2;
};

template <class T> 
class Matrix
{
private:
    int n, m;
    T** arr;

public:
    Matrix(int n = 0, int m = 0) : n(n), m(m)
    {
        arr = new T * [n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
        }
    }

    Matrix(const Matrix& obj)
    {
        m = obj.m;
        n = obj.n;
        arr = new T * [n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
            for (int j = 0; j < m; j++) 
            {
                arr[i][j] = obj.arr[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete arr[i];
        }
        delete arr;
    }

    void input()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Row " << i << endl;
            for (int j = 0; j < m; j++)
            {
                cout << "Column " << j << " - ";
                cin >> arr[i][j];
            }
        }
    }

    void output()
    {
        cout << "Matrix: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << endl;
            }
            cout << endl;
        }
    }

    T max(Matrix mas1, Matrix mas2)
    {
        T temp1 = 0;
        T temp2 = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mas1.arr[i][j] > temp1)
                {
                    temp1 = mas1.arr[i][j];
                }
            }
        }


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mas2.arr[i][j] > temp2)
                {
                    temp2 = mas2.arr[i][j];
                }
            }
        }

        T max = temp1 > temp2 ? temp1 : temp2;

        cout << "Max element in 1'st array" << temp1 << endl;
        cout << "Max element in 2'nd array" << temp2 << endl;
        cout << "Max element" << max << endl;

        return max;
    }

    Average<T> average(Matrix mas1, Matrix mas2)
    {
        T av1 = 0, av2 = 0;
        T sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum1 += mas1.arr[i][j];
                sum2 += mas2.arr[i][j];
            }
        }
        av1 = sum1 / n;
        av2 = sum2 / n;
        cout << "1'st array's average - " << av1 << ". 2'nd array's average - " << av2 << endl;
        return { av1, av2 };
    }

    Matrix operator + (const Matrix& massiv)

    {
        Matrix result(*this);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result.arr[i][j] += massiv.arr[i][j];
            }
        }
            

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << result.arr[i][j] << endl;
            }
        }
        
        return result;

    }

    bool operator < (Matrix right)
    {
        Matrix left(*this);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (left.arr[i][j] >= right.arr[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};


int main()
{
    int n = 0;
    int m = 0;
    cout << "Rows: ";
    cin >> n;

    cout << "Cols: ";
    cin >> m;


    Matrix<int> sum(n, m);
    Matrix<int> arr1(n, m);

    cout << "Enter 1'st array" << endl;
    arr1.input();

    Matrix<int> arr2 = arr1;
    cout << "Enter 2'nd array" << endl;
    arr2.input();

    arr1.max(arr1, arr2);
    arr1.average(arr1, arr2);

    sum = arr2 + arr1;
    bool firstLess = arr1 < arr2;

    sum.output();
    cout << firstLess;

    return 0;

}