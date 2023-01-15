#pragma once
#include <iostream>

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
	~Stack();

private:
	Node* top_node;

public:
	void push(unsigned long long int num);
	void pop();
	void print();

};

