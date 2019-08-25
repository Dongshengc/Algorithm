#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *head;

// declare operations
void push();
int pop();
void show();

int main(int argc, char const *argv[])
{
	unsigned choice = 0;
	while (choice != 4)
	{
		cout << "/**********Main Manu**********/" << endl;
		cout << "Choose one option from the following list: " << endl;
		cout << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Show" << endl;
		cout << "4. Exit" << endl; 
		cout << endl;
		cout << "Enter your choice:" << ends;
		cin >> choice;
		switch (choice)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: show();
				break;
			case 4: exit(0);
				break;
			default: cout << "Please enter the valid choice" << endl;
		}
	}
	return 0;
}

void push()
{
	node *ptr;
	ptr = new (nothrow) node;
	if (ptr == nullptr)
	{
		cout << "Memory Overflow" << endl; 
	}
	else
	{
		cout << "Enter the element: " << ends;
		int val;
		cin	>> val;
		ptr->data = val;

		ptr->next = head;
		head = ptr;
	}
	cout << "Node pushed" << endl;
}

int pop()
{
	int item; 
	node *ptr;
	if (head == nullptr)
	{
		cout << "Memory Underflow" << endl;
	}
	else
	{
		item = head->data;
		ptr = head;
		head = head->next;
		free(ptr);
		cout << "Node popped: " << item << endl;
	}
}

void show()
{
	node *temp;
	if (head == nullptr)
	{
		 cout << "Empty stack" << endl;
	}
	else
	{
		temp = head;
		while (temp->next != nullptr)
		{
			cout << temp->data << ", " << ends;
			temp = temp->next;
		}
	}
}