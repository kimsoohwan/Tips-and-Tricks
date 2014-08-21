#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <vector>
using namespace std;

template <typename T>
class Array2D
{
public:
	Array2D(const size_t rows, const size_t cols)
		: m_rows(rows),
		  m_cols(cols),
		  m_data(rows, vector<T>(cols))
	{
	}

	vector<T>& operator[] (const size_t row)
	{
		assert(row < m_rows);
		return m_data[row];
	}

protected:
	const size_t			m_rows;
	const size_t			m_cols;
	vector< vector<T> >	m_data;
};

#endif