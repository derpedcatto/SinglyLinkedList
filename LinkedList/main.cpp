#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	SinglyLinkedList sll1;
	SinglyLinkedList sll2;

	sll1 + 10;
	sll1 + 20;
	sll2 + 30;
	sll2 + 40;
	sll1 = sll2;

	cout << sll1;
}