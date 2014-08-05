#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <vector>
using namespace std;

template <typename T>
class Array2D
{
public:
	Array2D(const unsigned int rows, const unsigned int cols)
		: data(rows, vector<T>(cols))
	{
	}

	vector<T>& operator[] (const unsigned int row)
	{
		return data[row];
	}

protected:
	vector< vector<T> > data;
};

#endif