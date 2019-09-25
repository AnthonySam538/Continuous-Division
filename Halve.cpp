#include <iostream>

using namespace std;

short number;

//divide by 2
void halve()
{
	_asm
	{
		shr ax, 1;
	}
}

int main()
{
	//retrieve user input
	cout << "Enter a number: ";
	cin >> number;

	_asm
	{
		mov ax, number;
		call halve;
		mov number, ax;
	}

	cout << number;

	return 0;
}