#ifndef _SWAP_HPP_
#define _SWAP_HPP_

template <typename T>
void swapWithThirdVariable(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
void swapWithoutThirdVariable(T &a, T &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

#endif