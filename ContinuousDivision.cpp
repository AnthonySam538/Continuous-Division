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
  WhileLoop:
    //if all 1s have been right-shifted away, exit the loop
    cmp myNum, 0;
    je ExitLoop;

    //display myNum
    call display_myNum;

    //halve myNum, and jump back up
    shr myNum, 1;
    jmp WhileLoop;
  ExitLoop:
  }
  
  return 0;
}
