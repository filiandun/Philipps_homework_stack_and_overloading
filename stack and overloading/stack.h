#pragma once
#include <iostream>
#include <stdarg.h>

class Node
{
public:
	Node() = delete;
	Node(unsigned long long int num);

	~Node() = default;

public:
	unsigned long long int data;
	Node* previous_node;
};

class Stack
{
public:
	Stack();
	Stack(const Stack& stack);
	Stack(Node* node);
	Stack(unsigned long long int count, ...);

	~Stack() = default;
	//~Stack(); // not works



private:
	Node* top_node;

public:
	void push(unsigned long long int num);
	void pop();
	void print() const;

	bool comparing(unsigned long long int num);

	Node* copy_in(Stack& stack_copy) const;
	Node* operator+(Stack& stack) const;
	Node* operator*(Stack& stack) const;
};

