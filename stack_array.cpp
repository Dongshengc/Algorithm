#include<iostream>
#include<stdlib.h>
using namespace std;

const int STACK_SIZE = 100;

// define variables
int stack[STACK_SIZE], top = -1;

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
	if (top == STACK_SIZE-1)
	{
		cout << "Memory Overflow" << endl;
	}
	else
	{
		cout << "Enter the value of element: " << ends;
		int val; 
		cin	>> val;
		top++;
		stack[top] = val;
	}	
	
}

int pop()
{
	if (top == -1)
	{
		cout << "Memory Underflow" << endl;
	}
	else
	{
		return stack[top--];
	}
}

void show()
{
	if (top	== -1)
	{
		cout << "stack is empty " << endl;
	}
	else
	{

	for (int i = top; i > -1; --i)
		{
			cout << stack[i] << endl;		
		}
	}
}