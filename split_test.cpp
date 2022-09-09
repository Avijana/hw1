#include "split.h"
#include <iostream>
#include <cstddef>
using namespace std;


int main()
{
	
	Node* head = nullptr;
	Node* second = nullptr;
	Node* third =  nullptr;
	Node* tail = nullptr;

	tail = new Node(4, NULL);
	third = new Node(3, tail);
	second = new Node(2, third);
	head = new Node(0, second);
	 
   
	 

	// head-> value = 3;
	// head->next = second;

	// second-> value = 2;
	// second->next = third;

	// third-> value = 1;
	// third-> next = tail;

	// tail-> value = 4;
	// tail-> next = NULL;

	Node* even = NULL;
	Node* odd = NULL;

	split(head, odd, even);
	

	Node* t;
	t = even;
	while(t != NULL)
	{
		cout << t->value << endl;
		t = t->next;
	}

	Node* c;
	c = odd;
	while(c != NULL)
	{
		cout << c->value << endl;
		c = c->next;
	}

	delete head;
	delete second;
	delete third;
	delete tail;
	
	// cout << even->value << endl;
	// even = even->next;
	// cout << even->value << endl;
	// cout << odd->value << endl;
	// odd = odd->next;
	// cout << odd->value << endl;
}