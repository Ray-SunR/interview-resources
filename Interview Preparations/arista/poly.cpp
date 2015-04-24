#include <iostream>

using namespace std;

void poly(double* a, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (a[i] > 0)
			cout << "+ " << a[i] << "x^" << i << " ";
		else if (a[i] < 0)
			cout << "- " << a[i] << "x^" << i << " ";
	}
}

int main()
{
	double a[] = {2.0, 3.0, 4.0};
  	double b[] = {0.0, 3.0, 0.0};
  	double c[] = {2.0, -2.0, 9.0, -1.0, 8.0, -7.0};
  	double d[] = {2.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  	double e[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  	double f[] = {2.0/3.0, 1.0/7.0, 9.0/13.0};
	poly(a, sizeof(a)/sizeof(double));
	poly(b, sizeof(b)/sizeof(double));
	poly(c, sizeof(c)/sizeof(double));
	poly(d, sizeof(d)/sizeof(double));
	poly(e, sizeof(e)/sizeof(double));
	poly(f, sizeof(f)/sizeof(double));
	return 0;
}
