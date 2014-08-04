#ifndef _OPERATORS_HPP_
#define _OPERATORS_HPP_

template <typename T>
int countSizeWithoutSizeof()
{
	T variable;
	return (int)(&variable + 1) - (int)(&variable);
}

template <typename T>
T conditionalOperator(bool a, T b, T c)
{
	// return a ? b : c;
	//return a*b + !a*c;
	return !!a*b + !a*c; // a can be any non-zero value
}

#endif