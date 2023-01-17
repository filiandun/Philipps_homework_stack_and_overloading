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

Stack::Stack(const Stack& stack)
{
	stack.copy_in(*this);
}


Stack::Stack(unsigned long long int count, ...)
{
	va_list list;
	va_start(list, count);
	for (unsigned long long int i = 0; i < count; ++i)
	{
		this->push(va_arg(list, int));
	}
	va_end(list);
}

Stack::Stack(Node* node)
{
	this->top_node = node;
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
	std::cout << std::endl;
}





bool Stack::comparing(unsigned long long int num)
{
	Node* temp_node = this->top_node;
	while (temp_node != nullptr)
	{
		if (temp_node->data == num)
		{
			return true;
		}
		temp_node = temp_node->previous_node;
	}
	return false;
}

Stack Stack::mirror() const
{
	// функция нужна для того, чтобы "развернуть" стек:
	// сначала в стек mirror_stack копируется стек stack (например, 23, 80, 1, 6),
	// а после, стек mirror_stack (6, 1, 80, 23) копируется в какой-нибудь другой стек (который получится 23, 80, 1, 6)

	Node* temp_node = this->top_node;
	Stack mirror_stack;

	while (temp_node != nullptr)
	{
		mirror_stack.push(temp_node->data);
		temp_node = temp_node->previous_node;
	}
	return mirror_stack;
}






Node* Stack::copy_in(Stack& stack_copy) const
{
	if (this->top_node != nullptr)
	{
		stack_copy.~Stack();
		Node* temp_node = this->top_node; // не смог я сюда впихнуть функцию mirror так, чтобы конструктор не ругался
		Stack temp_stack; // это вместо mirror()
		
		while (temp_node != nullptr) // это вместо mirror()
		{
			temp_stack.push(temp_node->data);
			temp_node = temp_node->previous_node;
		}

		while (temp_stack.top_node != nullptr) // копирование из стека temp_stack в стек stack_copy
		{
			stack_copy.push(temp_stack.top_node->data);
			temp_stack.top_node = temp_stack.top_node->previous_node;
		}
		return stack_copy.top_node;
	}
	std::cerr << "Ошибка: стек, который нужно скопировать, пустой!" << std::endl;
	return this->top_node;
}


Node* Stack::operator+(Stack& stack)
{
	Stack addition_stack = *this;
	Stack mirror_stack = stack.mirror();

	while (mirror_stack.top_node != nullptr) // добавление узлов из стека mirror_stack в стек addition_stack
	{
		addition_stack.push(mirror_stack.top_node->data);
		mirror_stack.top_node = mirror_stack.top_node->previous_node;
	}

	//addition_stack.print();
	return addition_stack.top_node;
}


Node* Stack::operator*(Stack& stack)
{
	Stack intersection_stack;
	Stack mirror_stack = stack.mirror();

	while (mirror_stack.top_node != nullptr) // добавление узлов из стека mirror_stack в стек intersection_stack
	{
		if (this->comparing(mirror_stack.top_node->data) == true) // функция comparing ищет одинаковые элементы
		{
			intersection_stack.push(mirror_stack.top_node->data);
		}
		mirror_stack.top_node = mirror_stack.top_node->previous_node;
	}

	//intersection_stack.print();
	return intersection_stack.top_node;
}