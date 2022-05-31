// // Mykola Vasyclhuk Lab 4(bonus);
#include <iostream> 
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;
/*
double func_x(double x, double y) {
	return 5 * sin(2 * x - y) - 2.0/6.0;
}

double func_y(double x) {
	return sqrt((8.0 / 6.0) * x * x - 10.0 / 6.0);
}
*/
double func_x(double x, double y) {
	return (0.9 + cos(y)) / 3;
}

double func_y(double x) {
	return sin(x - 0.6) - 1.6;
}

void simpleIteration() {
	double x[100], y[100];
	x[0] = 1.25;
	y[0] = 0;
	cout << "Starting x[0] = " << x[0] << ", y[0] = " << y[0] << endl;
	double eps = 0.001;

	x[1] = func_x(x[0], y[0]);
	y[1] = func_y(x[0]);

	cout << setprecision(10) << "Iteration 1:\n" << "x[1] = " << x[1] << "\ny[1] = " << y[1] << endl;
	int i = 1;
	while (max(abs(x[i] - x[i - 1]), abs(y[i] - y[i - 1])) > eps) {
		i++;
		x[i] = func_x(x[i - 1], y[i - 1]);
		y[i] = func_y(x[i - 1]);
		cout << setprecision(10) << "Iteration" << " (" << i << "):\n" << "x[" << i << "] = " << x[i] << "\n" << "y[" << i << "] = " << y[i] << "\n";
	}
}

void maxEigenValue() {
	double a[5][5] = { {0,4,-1,1,0},
						{0,-1,4,-1,1},
						{0,1,-1,4,-1},
						{0,1,-1,4,-1},
						{0,0,1,-1,4} };
	int n = 4;
	double eps = 0.001;
	cout << "Matrix:\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << "\t";
		};
		cout << "\n";
	};
	cout << "\nStarting vector ( 1, 1, 1, 1 )";
	double temp, lambda_n;
	int i = 1;
	double x[5] = { 0,1,1,1,1 };
	double x_new[5];

	double lambda_old = 1;
up:
	for (int i = 1; i <= n; i++)
	{
		temp = 0;
		for (int j = 1; j <= n; j++)
		{
			temp = temp + a[i][j] * x[j];
		}
		x_new[i] = temp;
	}
	for (int i = 1; i <= n; i++)
	{
		x[i] = x_new[i];
	}

	lambda_n = fabs(x[1]);
	for (int i = 2; i <= n; i++)
	{
		if (fabs(x[i]) > lambda_n)
		{
			lambda_n = fabs(x[i]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		x[i] = x[i] / lambda_n;
	}

	if (fabs(lambda_n - lambda_old) > eps)
	{
		lambda_old = lambda_n;
		i++;
		goto up;
	}

	cout << "\n\nMax eigenvalue = " << lambda_n << endl;
}

void iterationProcess() {
	while (true) {
		cout << "Choose (undefined symbol = exit):\n(1) Simple iteration\n(2) Power iteration\n";
		int i;
		cin >> i;
		if (i == 1) {
			simpleIteration();
			iterationProcess();
			break;
		}
		else if (i == 2) {
			maxEigenValue();
			iterationProcess();
			break;
		}
		else { break; };
	}
}

int main()
{
	iterationProcess();
	return 0;
}

