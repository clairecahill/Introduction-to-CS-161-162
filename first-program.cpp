#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

/******************
*Author: Claire Cahill
*Date: 1/15/2017
*Description: This is the first program I've
ever written. It prints the max and min values for 
signed and unsigned ints, longs, and shorts.
*********************
 */
int main (){

	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	cout << SHRT_MIN << endl;
	cout << SHRT_MAX << endl;
	cout << LONG_MIN << endl;
	cout << LONG_MAX << endl;
	cout << UINT_MAX << endl;
	cout << USHRT_MAX << endl;
	cout << ULONG_MAX << endl;

	int x;
	cout << "Enter number of bits" << endl;
	cin >> x;
	cout << "Your unsigned max is " << pow(2,x)-1 << endl;
	cout << "Your unsigned min is " << 0 << endl;
	cout << "Your signed max is " << pow(2,x-1)-1 << endl;
	cout << "Your signed min is " << pow(-2,x-1)-1 << endl;


return 0;
}


