#include<iostream>
#include<stdlib.h>
using namespace std;

const int QUEUE_SIZE = 100;

// define variables
int queue[QUEUE_SIZE], front = -1, rear = -1;

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
	if (rear == QUEUE_SIZE-1)
	{
		cout << "Memory Overflow" << endl;
	}
	else
	{
		cout << "Enter the element: " << ends;
		int val;
		cin	>> val;

		if (front == -1 && rear == -1)
		{
			front = rear = 0;
			queue[rear] = val;
		}
		else
		{
			queue[++rear] = val;
		}
	}
}

int dequeue()
{
	if (front == -1 && front > rear)
	{
		cout << "Memory Underflow" << endl;
	}
	else
	{
		cout << queue[front++] << " dequeue" << endl;
	}
}

void display()
{
	if (front == -1)
	{
		 cout << "Empty Queue" << endl;
	}
	else
	{
		for (int i = front; i <= rear; ++i)
		{
			cout << queue[i] << endl;
		}
	}

}