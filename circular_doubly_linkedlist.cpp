#include<iostream>
#include<stdlib.h>
using namespace std;


	// define linked list node
	struct node
	{
		int data;
		node *prev;
		node *next;
	};

	node *head;

	// declare operations
	void begin_insert();
	void last_insert();
	void begin_delete();
	void last_delete();
	void search();
	void display();

int main(int argc, char const *argv[])
{
	unsigned choice = 0;
	while (choice != 7)
	{
		cout << "/**********Main Manu**********/" << endl;
		cout << "Choose one option from the following list: " << endl;
		cout << endl;
		cout << "1. Insert in the beginning" << endl;
		cout << "2. Insert at the last" << endl;
		cout << "3. Delete in the beginning" << endl;
		cout << "4. Delete at the last" << endl;
		cout << "5. Search for an element" << endl;
		cout << "6. Display" << endl;
		cout << "7. Exit" << endl; 
		cout << endl;
		cout << "Enter your choice:" << ends;
		cin >> choice;
		switch (choice)
		{
			case 1: begin_insert();
				break;
			case 2: last_insert();
				break;
			case 3: begin_delete();
				break;
			case 4: last_delete();
				break;
			case 5: search();
				break;
			case 6: display();
				break;
			case 7: exit(0);
				break;
			default: cout << "Please enter the valid choice" << endl;
		}
	}
	return 0;
}

	// define operation functions
	void begin_insert()
	{
		unsigned val;
		node *ptr, *temp;
		ptr = new (nothrow) node;
		if (ptr == nullptr)
		{
			cerr << "Memory overflow" << endl;
		}
		else
		{
			cout << "Input the value of insertion: " << ends;
			cin >> val; 
			ptr->data = val;

			if (head == nullptr)
			{
				head = ptr;
				head->prev = head;
				head->next = head;
			}
			else
			{
				temp = head;
				while (temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = ptr;
				ptr->prev = temp;
				ptr->next = head;
				head->prev = ptr;
				head = ptr;
			}
			cout << "Node inserted at beginning" << endl;
		}

	}

	void last_insert()
	{
		unsigned val;
		node *ptr = new (nothrow) node, *temp;
		if (ptr == nullptr)
		{
			cerr << "Memory overflow" << endl;
		}
		else
		{
			cout << "Input the value of Insertion: " << ends;
			cin >> val;
			ptr->data = val;
			if (head == nullptr)
			{
				head = ptr;
				head->prev = head;
				head->next = head;
			}
			else
			{
				temp = head;
				while(temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = ptr;
				ptr->prev = temp;
				head->prev = temp;
				ptr->next = head;
			}
			cout << "Node inserted at the end" << endl;
		}

	}

	void begin_delete()
	{
		node *ptr;
		if (head == nullptr)
		{
			cout << "Memory Underflow" << endl;
		}
		else
		{
			if (head->next == head)
			{
				head = nullptr;
				free(head);
			}
			ptr = head;
			while (ptr->next != head)
			{
				ptr = ptr->next;
			}
			ptr->next = head->next;
			head->next->prev = ptr;
			free(head);
			head = ptr->next;
			cout << "Node deleted at the beginning" << endl;
		}

	}

	void last_delete()
	{
		node *ptr;
		if (head == nullptr)
		{
			cout << "Memory Underflow" << endl;
		}
		else
		{
			if (head->next == head)
			{
				head == nullptr;
				free(head);
			}
			else
			{
				ptr = head;
				while (ptr->next != head)
				{
					ptr = ptr->next;
				}
				ptr->prev->next = head;
				head->prev = ptr->prev;
				free(ptr);
			}
			cout << "Node deleted at the end" << endl;
		}

	}

	void search()
	{
		node *temp;
		unsigned element, cnt = 0;
		bool flag = false;
		cout << "Input the element looking for: " << ends;
		cin >> element;
		temp = head;
		while(temp->next != head)
		{
			if (temp->data == element)
			{
				cout << "ELement found at " << cnt << endl;
				flag = true;
				break;
			}
			temp = temp->next;
			++cnt;
		}
		if (temp->data == element)
		{
			cout << "element found at " << cnt << endl;
			flag = true;
		}
		if (flag == false)
		{
			cout << "ELement not in range" << endl;
		}


	}

	void display()
	{
		node *temp;
		temp = head;
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
		}
		else
		{
			while(temp->next != head)
			{
				cout << temp->data << ", " << ends;
				temp = temp->next;
			}
			cout << temp->data << endl;
		}
	}

