#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *front, *rear;

// declare operations
void enqueue();
int dequeue();
void display();

int main(int argc, char const *argv[])
{
	unsigned choice = 0;
	while (choice != 4)
	{
		cout << "/**********Main Manu**********/" << endl;
		cout << "Choose one option from the following list: " << endl;
		cout << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl; 
		cout << endl;
		cout << "Enter your choice:" << ends;
		cin >> choice;
		switch (choice)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
			default: cout << "Please enter the valid choice" << endl;
		}
	}
	return 0;
}

void enqueue()
{
	Node *ptr;
	ptr = new (nothrow) Node;
	if (ptr == nullptr)
	{
		 cout << "Memory Overflow" << endl;
	}
	else
	{
		cout << "Enter the element: " << ends;
		int val; 
		cin >> val;
		ptr->data = val;

		if (front == nullptr && rear == nullptr)
		{
			front = rear = ptr;
			front->next = rear->next = nullptr;
		}
		else
		{
			rear->next = ptr;
			ptr->next = nullptr;
			rear = ptr;
		}
	}
}

int dequeue()
{
	if (front == nullptr)
	{
		 cout << "Memory Underflow" << endl; 
	}
	else
	{
		Node *ptr;
		ptr = front;
		front = front->next;
		free(ptr);
	}

}

void display()
{
	if (front == nullptr)
	{
		cout << "Empty Queue" << endl;	
	}
	else
	{
		Node *ptr = front;
		while(ptr != nullptr)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}

}