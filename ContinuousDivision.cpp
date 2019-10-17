#include <iostream>

using namespace std;

short myNum = 37658;

void display_myNum()
{
	cout << myNum << endl;
}

int main()
{
	_asm
	{
		mov cx, myNum; //initialize cx to myNum

	WhileLoop:
		//if all 1s have been right-shifted away, exit the loop
		cmp cx, 0;
		je ExitLoop;

		//move cx into myNum so it can be displayed
		mov myNum, cx;
		call display_myNum;

		//right-shift cx, and repeat
		mov cx, myNum; //the cx register lost its value in the function call; we must replace it
		shr cx, 1;
		jmp WhileLoop;
	ExitLoop:

	//	//Better solution: (there's no reason to use a register for this)
	//WhileLoop:
	//	cmp myNum, 0;
	//	je ExitLoop;

	//	call display_myNum;

	//	shr myNum, 1;
	//	jmp WhileLoop;
	//ExitLoop:
	}
	
	return 0;
}
