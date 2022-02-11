#pragma once
#include <iostream>
using namespace std;

// https://youtu.be/m7rrk65GiXY
// https://www.geeksforgeeks.org/data-structures/linked-list/#singlyLinkedList

class Node
{
public:
	int data = 0;
	Node *next = nullptr;
};

class SinglyLinkedList
{
private:
	Node* head;
	Node* tail;
	int count;

public:
	/*CONSTRUCTOR*/
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& original);

	/*METHODS*/
	void Print() const;
	int GetCount() const;
	int IndexOf(int data) const;
	int LastIndexOf(int data) const;
	bool IsEmpty() const;
	bool Equals(SinglyLinkedList other) const;
	bool Contains(int value) const;

	void AddToHead(int data);
	void AddToTail(int data);
	void InsertInto(int data, int position);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteByIndex(int position);
	void Clear();
	void Reverse();
	void SetAt(int index, int value);
	void MergeWith(const SinglyLinkedList& other);
	void Shuffle();
	void SortAsc();
	void SortDesc();

	int GetElementValue(int index);
	int* ToArray();

	SinglyLinkedList Clone();

	/*OPERATORS*/
	friend ostream& operator<<(ostream& output, const SinglyLinkedList& src);
	bool operator<(const SinglyLinkedList& list);
	bool operator>(const SinglyLinkedList& list);
	bool operator<=(const SinglyLinkedList& list);
	bool operator>=(const SinglyLinkedList& list);
	bool operator==(const SinglyLinkedList& list);
	bool operator!=(const SinglyLinkedList& list);
	int operator[](int index);
	void operator=(const SinglyLinkedList& other);
	void operator+(int value);
	void operator+=(const SinglyLinkedList& other);
	operator int* ();

	/*DEST-GET-SET*/
	~SinglyLinkedList();
};

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