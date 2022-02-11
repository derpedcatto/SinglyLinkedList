#include "SinglyLinkedStack.h"
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	SinglyLinkedStack l1;
	l1.Push(10);
	l1.Push(20);
	l1.Push(30);
	l1.Pop();
	l1.Peek();
}