#include <iostream>
#include "fibonacci.h"

using namespace std;

int
main(int argc, char **argv)
{
	int n = 0;
	cout << "n: ";
	cin >> n;

	class Fibonacci<int> fibonint;
	class Fibonacci<long> fibonlong;
	class Fibonacci<float> fibonfloat;
	class Fibonacci<double> fibondouble;

	cout << "int: " << fibonint.getNItem(n) << endl;
	cout << "long: " << fibonlong.getNItem(n) << endl;
	cout << "float: " << fibonfloat.getNItem(n) << endl;
	cout << "double: " << fibondouble.getNItem(n) << endl;

	return 0;
}

