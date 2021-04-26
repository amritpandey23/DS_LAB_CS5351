#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

void multiply(int a[3][3], int b[3][3])
{
	int M[3][3], sum;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum = 0;
			for (int k = 0; k < 3; k++)
				sum += a[i][k] + b[k][j];
			M[j][i] = sum;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << M[j][i] << " ";
		}
		cout << "\n";
	}
}

void sumit(int A[3][3], int B[3][3])
{
	int S[3][3];
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

int main()
{
	int A[3][3], B[3][3], sum[3][3], mul[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &A[i][j]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &B[i][j]);
	sumit(A, B);
	multiply(A, B);
	return 0;
}
