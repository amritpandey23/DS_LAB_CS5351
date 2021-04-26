#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
private:
    int A[3][3], B[3][3], S[3][3], M[3][3];

public:
    Matrix()
    {
        cout << "Populate A, B 3x3 matrix: " << endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                scanf("%d", &A[i][j]);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                scanf("%d", &B[i][j]);
    }

    void sum()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                S[i][j] = A[i][j] + B[i][j];
            }
        }
        cout << "---SUM---" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << S[i][j] << setw(4);
            }
            cout << "\n";
        }
    }

    void multiply()
    {
        int sum;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum = 0;
                for (int k = 0; k < 3; k++)
                {
                    sum += A[i][k] + B[k][j];
                }
                M[i][j] = sum;
            }
        }
        cout << "---MULTIPLICATION---" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << M[i][j] << setw(4);
            }
            cout << "\n";
        }
    }
};

int main()
{
    Matrix m;
    m.sum();
    m.multiply();
    return 0;
}
