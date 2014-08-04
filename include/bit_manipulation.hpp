#ifndef _BIT_MANIPULATION_HPP_
#define _BIT_MANIPULATION_HPP_

#include <string>
#include <sstream>
using namespace std;

/* @brief Returns true if the machine is little-endian, false if the machine is big-endian */
bool checkLittleEndianWithCharPointer()
{
	// set an integer to 1
	int testNum = 1;
	
	// cast a pointer to the integer as a char *
	unsigned char *ptr = (unsigned char *) &testNum;

	// If the dereference pointer is 1, the machine is little-endian
	// because the LSB (least-significant byte) is at the lowest memory address.
	// If the dereference pointer is 0, the machine is big-endian
	// because the MSB (most-significant byte) is at the lowest memory address.
	return (*ptr); /* Returns the byte at the lowest address */
}

/* @brief Returns true if the machine is little-endian, false if the machine is big-endian */
bool checkLittleEndianWithUnion()
{
	// union
	union {
		int	theInteger;
		char	singleByte;
	} endianTest;

	// set the integer to 1
	endianTest.theInteger = 1;

	// return the first byte
	return endianTest.singleByte;
}

/* @brief count the number of ones in binary */
int countOnesInBinaryWithMask(unsigned int number)
{
	// unsigned integer to make sure that the new bits that are added during the right shift will be 0's

	// start with count = 0
	int n = 0;

	// while the integer is not 0
	while(number != 0)
	{
		// if the integer AND 1 equals 1, increment count
		if((number & 1) == 1)	n++;
		
		// shift the integer one bit to the right
		number = number >> 1;
	}

	// return count
	return n;
}

/* @brief count the number of ones in binary */
int countOnesInBinaryWithSubtraction(int number)
{
	// start with count = 0
	int n = 0;

	// while the integer is not 0
	while(number != 0)
	{
		// AND the integer with the integer -1
		number = number & (number-1);

		// increment count
		n++;
	}

	// return count
	return n;

	// for(int i=0; n > 0; i++) n &= (n-1);
	// return i;
}

int maxInteger()
{
	// MAX_INT
	return (unsigned int)-1 >> 1;
}

// hexadecimal or octal numbers
// octal
// 0 - 000
// 1 - 001
// 2 - 010
// 3 - 011
// 4 - 100
// 5 - 101
// 6 - 110
// 7 - 111 
// 
// e.g)
// 0345 - octal number 345 = 011 100 101
//
// hex
// 0 - 0000
// 1 - 0001
// 2 - 0010
// 3 - 0011
// 4 - 0100
// 5 - 0101
// 6 - 0110
// 7 - 0111
// 8 - 1000
// 9 - 1001
// A - 1010
// B - 1011
// C - 1100
// D - 1101
// E - 1110
// F - 1111 
//
// e.g)
// 0x3F7 - hex number 3F7 = 0011 1111 0111
// 1 byte = 2 hexadecimal numbers
//
// It is easier going from Hex to binary that from Decimal to binary

/* @brief Function to convert decimal to hexadecimal. */
string decimal2hex(int n)
{
	stringstream ss;
	while(n != 0)
	{
		const int rem = n%16;	// remainder
		switch(rem)
		{
		case 10: ss << "A"; break;
		case 11: ss << "B"; break;
		case 12: ss << "C"; break;
		case 13: ss << "D"; break;
		case 14: ss << "E"; break;
		case 15: ss << "F"; break;
		default: ss << rem;
		}
		n = n/16;
	}

	// reverse the string
	string strHex = ss.str();
	strHex = string(strHex.rbegin(), strHex.rend());

	return strHex;
}

/* Function to convert hexadecimal to decimal. */
int hex2decimal(const string strHex)
{
	int sum = 0;
	for(size_t i = 0; i < strHex.size(); i++)
	{
		const char cDigit = strHex[i];
		if(cDigit >= '0' && cDigit <= '9') sum += (cDigit-'0')*pow(16.f, strHex.size()-1.f-i);
		if(cDigit >= 'A' && cDigit <= 'F') sum += (cDigit-55) *pow(16.f, strHex.size()-1.f-i);
		if(cDigit >= 'a' && cDigit <= 'f') sum += (cDigit-87) *pow(16.f, strHex.size()-1.f-i);
	}
	return sum;
}

/* @brief logical right shift */
int logical_right_shift(int x, int n)
{
	// usually sizeof(int) is 4 bytes (32 bits)
	int numberOfBits = sizeof(int) * 8;

	// 0x1 << numberOfBits
	// (10000000 00000000 00000000 00000000)
	// 
	// ((0x1 << numberOfBits) >> 5) << 1
	// (11111000 00000000 00000000 00000000)
	//
	// ~(((0x1 << numberOfBits) >> n) << 1)
	// (00000111 11111111 11111111 11111111)
	return (x >> n) & ~(((0x1 << numberOfBits) >> n) << 1);
}
#endif 