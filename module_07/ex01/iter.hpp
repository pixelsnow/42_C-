#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename F>
void iter(T * arr, int size, F * func)
{
	for (int i = 0; i < size; i++)
	{
		(* func)(arr[i]);
	}
}

#endif