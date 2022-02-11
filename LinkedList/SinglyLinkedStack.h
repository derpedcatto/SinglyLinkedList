#include "SinglyLinkedList.h"

class SinglyLinkedStack
{
private:
	const int SIZE = 128;
	SinglyLinkedList list;
	int index = 0;

public:
	void Push(int value);
	void Pop();
	void Peek();
	void Clear();
	bool IsEmpty();

};