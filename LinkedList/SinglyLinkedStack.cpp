#include "SinglyLinkedStack.h"

void SinglyLinkedStack::Push(int value)
{
	if (list.GetCount() + 1 >= SIZE)
	{
		cout << "\nStack is full!";
		return;
	}

	list.AddToTail(value);
}
void SinglyLinkedStack::Pop()
{
	list.DeleteFromTail();
}
void SinglyLinkedStack::Peek()
{
	cout << list.GetElementValue(list.GetCount() - 1);
}
void SinglyLinkedStack::Clear()
{
	list.Clear();
}
bool SinglyLinkedStack::IsEmpty()
{
	return list.IsEmpty();
}