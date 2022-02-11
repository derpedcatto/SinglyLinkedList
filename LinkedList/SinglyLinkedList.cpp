#include "SinglyLinkedList.h"

/*CONSTRUCTOR*/
SinglyLinkedList::SinglyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& original)
{
	Node* og_current = original.head;

	while (og_current != nullptr)
	{
		AddToTail(og_current->data);
		og_current = og_current->next;
	}
}

/*METHODS*/
void SinglyLinkedList::Print() const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
int SinglyLinkedList::GetCount() const
{
	return count;
}
int SinglyLinkedList::IndexOf(int data) const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return -1;
	}
	Node* temp = head;
	int i = 0;
	while (i < count)
	{
		if (data == temp->data)
		{
			return i;
		}
		i++;
		temp = temp->next;
	}

	return -1;
}
int SinglyLinkedList::LastIndexOf(int data) const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return -1;
	}

	Node* temp = head;

	int i = 0;
	int index = -1;
	for (; i < count; i++)
	{
		if (data == temp->data)
			index = i;
		temp = temp->next;
	}

	if (index == -1)
		return -1;
	else
		return index;
}
bool SinglyLinkedList::IsEmpty() const
{
	if (count == 0)
		return true;
	return false;
}
bool SinglyLinkedList::Equals(SinglyLinkedList other) const
{
	if (count != other.count)
		return false;

	Node* first = head;
	Node* second = other.head;
	while (first != nullptr)
	{
		if (first->data != second->data)
			return false;
		
		first = first->next;
		second = second->next;
	}
	return true;
}
bool SinglyLinkedList::Contains(int value) const
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == value)
			return true;
		current = current->next;
	}
	return false;
}

void SinglyLinkedList::AddToHead(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	newElem->next = head;
	if (head == nullptr)
	{
		tail = newElem;
	}
	head = newElem;
	count++;
}
void SinglyLinkedList::AddToTail(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	if (tail == nullptr)
	{
		head = newElem;
	}
	else
	{
		tail->next = newElem;
	}
	tail = newElem;
	count++;
}
void SinglyLinkedList::InsertInto(int data, int position)
{
	if (position >= count)
	{
		AddToTail(data);
		return;
	}
	else if (position <= 0)
	{
		AddToHead(data);
		return;
	}

	Node* newElem = new Node();
	newElem->data = data;
	int i = 1;
	Node* beforeNew = head;
	while (i++ != position)
	{
		beforeNew = beforeNew->next;
	}
	newElem->next = beforeNew->next;
	beforeNew->next = newElem;

	count++;
}
void SinglyLinkedList::DeleteFromHead()
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	count--;
	if (head == nullptr)
	{
		tail = nullptr;
	}
}
void SinglyLinkedList::DeleteFromTail()
{
	if (count == 0) {
		cout << "Empty list!\n";
		return;
	}
	DeleteByIndex(count - 1);
}
void SinglyLinkedList::DeleteByIndex(int position)
{
	if (position <= 0)
	{
		DeleteFromHead();
		return;
	}

	if (position >= count)
	{
		position = count - 1;
	}

	int i = 1;
	Node* beforeDel = head;
	while (i++ != position)
	{
		beforeDel = beforeDel->next;
	}
	Node* sacrifice = beforeDel->next;
	beforeDel->next = sacrifice->next;
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
		tail = beforeDel;
	}
}
void SinglyLinkedList::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}
void SinglyLinkedList::Reverse()
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = head;
	Node* previous = nullptr;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}
void SinglyLinkedList::SetAt(int index, int value)
{
	if (index > count - 1)
		return;

	Node* current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	current->data = value;
}
void SinglyLinkedList::MergeWith(const SinglyLinkedList& other)
{
	count += other.count;
	
	Node* current = other.head;
	int tmpcount = other.count;
	while(tmpcount > 0)
	{
		AddToTail(current->data);
		current = current->next;
		tmpcount--;
	}
}
void SinglyLinkedList::Shuffle()
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	int* arr = new int[count];

	Node* current = head;
	for (int i = 0; i < count; i++)
	{
		arr[i] = current->data;
		current = current->next;
	}

	for (int i = 0; i < count; i++)
		swap(arr[i], arr[rand() % count]);

	current = head;
	for (int i = 0; i < count; i++)
	{
		current->data = arr[i];
		current = current->next;
	}
	
	delete[] arr;
}
void SinglyLinkedList::SortAsc()
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* index = head;
	Node* current;

	while (index != tail)
	{
		current = index;
		while (current != nullptr)
		{
			if (index->data > current->data)
				swap(index->data, current->data);

			current = current->next;
		}

		index = index->next;
	}
}
void SinglyLinkedList::SortDesc()
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* index = head;
	Node* current;

	while (index != tail)
	{
		current = index;
		while (current != nullptr)
		{
			if (index->data < current->data)
				swap(index->data, current->data);

			current = current->next;
		}

		index = index->next;
	}
}

int SinglyLinkedList::GetElementValue(int index)
{
	Node* current = head;
	for (int i = 0; i < index; i++)
	{
		head = head->next;
	}
	return head->data;
}
int* SinglyLinkedList::ToArray()
{
	int* arr = new int[count];

	Node* current = head;
	for (int i = 0; i < count; i++)
	{
		arr[i] = current->data;
		current = current->next;
	}

	return arr;
}

SinglyLinkedList SinglyLinkedList::Clone()
{
	SinglyLinkedList* newlist = new SinglyLinkedList();;

	Node* current = head;
	while (current != nullptr)
	{
		newlist->AddToTail(current->data);
		current = current->next;
	}

	return *newlist;
}

/*OPERATORS*/
ostream& operator<<(ostream& output, const SinglyLinkedList& src)
{
	src.Print();
	return output;
}
bool SinglyLinkedList::operator<(const SinglyLinkedList& other)
{
	return count < other.count;
}
bool SinglyLinkedList::operator>(const SinglyLinkedList& other)
{
	return count > other.count;
}
bool SinglyLinkedList::operator<=(const SinglyLinkedList& other)
{
	return count <= other.count;
}
bool SinglyLinkedList::operator>=(const SinglyLinkedList& other)
{
	return count >= other.count;
}
bool SinglyLinkedList::operator==(const SinglyLinkedList& other)
{
	return Equals(other);
}
bool SinglyLinkedList::operator!=(const SinglyLinkedList& other)
{
	return !(Equals(other));
}
int SinglyLinkedList::operator[](int index)
{
	if (index >= count || index < 0)
		throw "ERROR";

	Node* current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	return current->data;
}
void SinglyLinkedList::operator=(const SinglyLinkedList& other)
{
	Clear();
	MergeWith(other);
}
void SinglyLinkedList::operator+(int value)
{
	AddToTail(value);
}
void SinglyLinkedList::operator+=(const SinglyLinkedList& other)
{
	MergeWith(other);
}
SinglyLinkedList::operator int* ()
{
	return ToArray();
}


/*DEST-GET-SET*/
SinglyLinkedList::~SinglyLinkedList()
{
	Node* current = head;
	Node* next;
	while(current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
}