// STL
#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Mine
#include "include/bit_manipulation.hpp"
#include "include/operators.hpp"
#include "include/swap.hpp"
#include "include/prime_number.hpp"
#include "include/string.hpp"
#include "include/array.hpp"

int main()
{
	// little-endian check
	if(checkLittleEndianWithCharPointer()) cout << "This machine is little-endian." << endl;
	else												cout << "This machine is big-endian." << endl;
	if(checkLittleEndianWithUnion())			cout << "This machine is little-endian." << endl;
	else												cout << "This machine is big-endian." << endl;
	cout << endl;

	// nmber of ones in binary
	cout << "1 has " << countOnesInBinaryWithMask(1) << " ones." << endl;
	cout << "2 has " << countOnesInBinaryWithMask(2) << " ones." << endl;
	cout << "3 has " << countOnesInBinaryWithMask(3) << " ones." << endl;
	cout << "8 has " << countOnesInBinaryWithMask(8) << " ones." << endl;
	cout << "-1 has " << countOnesInBinaryWithMask(-1) << " ones." << endl;
	cout << endl;
	cout << "1 has " << countOnesInBinaryWithSubtraction(1) << " ones." << endl;
	cout << "2 has " << countOnesInBinaryWithSubtraction(2) << " ones." << endl;
	cout << "3 has " << countOnesInBinaryWithSubtraction(3) << " ones." << endl;
	cout << "8 has " << countOnesInBinaryWithSubtraction(8) << " ones." << endl;
	cout << "-1 has " << countOnesInBinaryWithSubtraction(-1) << " ones." << endl;
	cout << endl;

	// max integer
	cout << "INT_MAX = " << maxInteger() << " or " << INT_MAX << endl;
	cout << endl;

	// hexadecimal
	printf("%X\n", 399);
	printf("%08X\n", 399);
	printf("%#X\n", 399);
	printf("%#08X\n", 399);
	cout << decimal2hex(399) << " = " << hex2decimal(decimal2hex(399)) << endl;
	cout << endl;

	// logical right shift vs arithmetic right shift
	cout << "logical right shift: -8 >> 1 = " << logical_right_shift(-8, 1) << endl;
	cout << "arithmetic right shift: -8 >> 1 = " << (-8>>1) << endl;
	cout << endl;

	// size
	cout << "integer: " << countSizeWithoutSizeof<int>() << " bytes." << endl;
	cout << "float: " << countSizeWithoutSizeof<float>() << " bytes." << endl;
	cout << "double: " << countSizeWithoutSizeof<double>() << " bytes." << endl;
	cout << "char: " << countSizeWithoutSizeof<char>() << " bytes." << endl;
	cout << endl;

	// conditional operator
	cout << "true ? 1, 2 = " << conditionalOperator(true, 1, 2) << endl;
	cout << "false ? 1, 2 = " << conditionalOperator(false, 1, 2) << endl;
	cout << endl;

	// swap
	int a = 3, b = 5;
	cout << "before swapping: a = " << a << ", b = " << b << endl;
	swapWithoutThirdVariable(a, b);
	cout << "after swapping: a = " << a << ", b = " << b << endl;
	swapWithThirdVariable(a, b);
	cout << "before swapping: a = " << a << ", b = " << b << endl;
	cout << endl;

	// prime numbers
	printPrimeNumbers(10);

	// reverse string
	string str("reverse_string");
	cout << str << " -> ";
	reverseString(str);
	cout << str << endl;
	cout << endl;

	// array
	Array2D<int> array2D(3, 4);
	cout << "before: " << array2D[0][0] << endl;
	array2D[0][0] = 3;
	cout << "after: " << array2D[0][0] << endl;

	system("pause");
	return 0;
}