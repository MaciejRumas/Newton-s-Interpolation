#include<iostream>

using namespace std;


double b(double* tabx, double* taby, int n);
double w(int n, double* tabx, double* taby, double x);
double p(int n, double* tabx, double* taby, double x);
void coutPolynominal(int n, double* tabx, double* taby);

int main()
{
	cout << "Enter quantity: ";
	int pointsQuantity;
	cin >> pointsQuantity;
	double *tabx = new double[pointsQuantity];
	double *taby = new double[pointsQuantity];


	for (int i = 0; i<pointsQuantity; i++)
	{
		cout << "Enter x" << i + 1 << " : ";
		cin >> tabx[i];

		cout << "Enter f(x" << i + 1 << ") : ";
		cin >> taby[i];

	}
	int i;
	cout << "Enter the degree of interpolation polynomial: ";
	cin >> i;
	coutPolynominal(i, tabx, taby);
	

	int x;
	while (true)
	{
		cout << "Enter argument for which you want W(x): ";
		cin >> x;
		cout << "W(" << x <<") = " << w(pointsQuantity, tabx, taby, x) << endl;
	
	}
	

	return 0;

}


double b(double* tabx, double* taby, int n)
{
	double product = 1;
	double sum = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j != i)
			{
				product *= (tabx[i] - tabx[j]);
			}
		}
		sum += (taby[i] / product);
		product = 1;
	}
	return sum;
}


double w(int n, double* tabx, double* taby, double x)
{


	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		
		sum += b(tabx, taby, i)*p(i, tabx, taby, x);
	}
	return sum;
}

double p(int n, double* tabx, double* taby, double x)
{
	double product = 1;

	for (int i = 0;i < n;i++)
	{
		product *= (x - tabx[i]);
	}

	return product;
}

void coutPolynominal(int n, double* tabx, double* taby)
{

	cout << "W(x) = ";
	for (int i = 0;i < n;i++)
	{
		cout << b(tabx, taby, i);
		for (int j = 0;j < i;j++)
		{
			cout << "(x - " << tabx[j] << ")";
		}
		if(i < n-1)
			cout << " + ";
	}

	cout << endl;
}

