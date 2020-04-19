#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

// Функция создает динамическую целочисленную матрицу размера  n x n
// возвращает её адрес в памяти
int** CreateMatrix(int n)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;
}

// Функция выводит матрицу a  размера n x n  на консольный экран
void PrintMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	return;
}

// Функция заполняет матрицу a  числами 0, 1, 2, .... n^2-1 по
// данной схеме расположения
void FillMatrix(int** a, int n)
{

	int k = 0;
	int t = 0;
	for (int j = 0; j < ((n /2) + 1); j++) {
		if (j % 2 == 0) {
			for (int i = 0; i < n; i++)
				a[i][j] = k++;
		}
		else {
			for (int i = n - 1; i >= 0; i--)
				a[i][j] = k++;
		}
	}
	if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                for (int j = (n /2) + 1; j < n ; j++) {
                    a[i][j] = k++;
                }
            } else {
                for (int j = n - 1; j > n /2 ; j--) {
                    a[i][j] = k++;
                }
            }
        }
	} else {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                for (int j = n /2; j < n ; j++) {
                    a[i][j] = k++;
                }
            } else {
                for (int j = n - 1; j > (n / 2) - 1 ; j--) {
                    a[i][j] = k++;
                }
            }
        }
	}

}

int main()
{
	setlocale(0, "Russian");
	int n;
	do
	{
		cout << "Enter n: ";
		cin >> n;
	} while ((n < 1) || (n > 10));

	int** a;
	a = CreateMatrix(n);

	FillMatrix(a, n);

	cout << " Matrix " << endl;
	PrintMatrix(a, n);

	return 0;
}
