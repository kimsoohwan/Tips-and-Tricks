#ifndef _STRING_HPP_
#define _STRING_HPP_

#include <string>
using namespace std;

void reverseString(string &str)
{
	// check size
	const int size = str.size();
	if(size == 0) return;

	for(size_t i = 0; i < size/2; i++)
	{
		swap(str[i], str[size - i - 1]);
	}
}

#endif