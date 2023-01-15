#include "stack.h"


Node::Node(unsigned long long int num)
{
	this->data = num;
	this->previous_node = nullptr;
}



Stack::Stack()
{
	this->top_node = nullptr;
}

Stack::~Stack()
{
	while (this->top_node != nullptr)
	{
		pop();
	}
}



void Stack::push(unsigned long long int num)
{
	Node* new_node = new Node(num);

	if (this->top_node != nullptr)
	{
		new_node->previous_node = this->top_node;
	}
	this->top_node = new_node;
}

void Stack::pop()
{
	if (this->top_node == nullptr)
	{
		std::cerr << "Ошибка: стек пустой!" << std::endl;
		return;
	}

	Node* temp = this->top_node->previous_node;
	delete this->top_node;
	this->top_node = temp;
}

void Stack::print()
{
	Node* temp = this->top_node;

	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->previous_node;
	}
}

