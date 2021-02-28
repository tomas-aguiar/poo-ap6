#include "fibonacci.h"

template <typename T>
T Fibonacci<T>::getNItem(int n)
{
	T prev, curr, next;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
			prev = i;
		else if (i == 1)
			curr = i;
		else
		{
			next = prev + curr;
			prev = curr; 
			curr = next;
		}
	}

	return curr;
}

template class Fibonacci<int>;
template class Fibonacci<long>;
template class Fibonacci<float>;
template class Fibonacci<double>;

