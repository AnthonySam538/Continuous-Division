#include <iostream>

using namespace std;

short number = 37658; //can be any value

void displayNumber()
{
	cout << number << endl; //no problem occurs when this is commented out
}

int main()
{
	_asm
	{
		mov cx, number;

	WhileLoop:
		//if all 1s have been left-shifted away, exit the loop
		cmp cx, 0;
		je ExitLoop;

		//move cx into current so it can be displayed
		mov number, cx;
		call displayNumber; //no problem occurs when this is commented out

		//left-shift cx, and repeat
		shl cx, 1;
		jmp WhileLoop;

	ExitLoop:
	}

	//cout << number; //outputs -32768 when "call displayNumber;" is commented out

	return 0;
}