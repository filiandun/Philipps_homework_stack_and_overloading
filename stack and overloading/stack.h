#pragma once
#include <iostream>
#include <stdarg.h>

class Node
{
public:
	Node() = delete;
	Node(unsigned long long int num);

public:
	unsigned long long int data;
	Node* previous_node;
};

class Stack
{
public:
	Stack();
	Stack(const Stack& stack);
	Stack(unsigned long long int count, ...);
	Stack(Node* node);
	~Stack();

private:
	Node* top_node;

public:
	void push(unsigned long long int num);
	void pop();
	void print();

	bool comparing(unsigned long long int num);
	Stack mirror() const;

	Node* copy_in(Stack& stack_copy) const;
	Node* operator+(Stack& stack);
	Node* operator*(Stack& stack);


};

