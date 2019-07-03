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
	void random_insert();
	void begin_delete();
	void last_delete();
	void specify_delete();
	void search();
	void display();

int main(int argc, char const *argv[])
{
	unsigned choice = 0;
	while (choice != 9)
	{
		cout << endl;
		cout << "/**********Main Manu**********/" << endl;
		cout << "Choose one option from the following list: " << endl;
		cout << endl;
		cout << "1. Insert in the beginning" << endl;
		cout << "2. Insert at the last" << endl;
		cout << "3. Insert at random location" << endl;
		cout << "4. Delete in the beginning" << endl;
		cout << "5. Delete at the last" << endl;
		cout << "6. Delete at random location" << endl;
		cout << "7. Search for an element" << endl;
		cout << "8. Display" << endl;
		cout << "9. Exit" << endl; 
		cout << endl;
		cout << "Enter your choice:" << ends;
		cin >> choice;
		switch (choice)
		{
			case 1: begin_insert();
				break;
			case 2: last_insert();
				break;
			case 3: random_insert();
				break;
			case 4: begin_delete();
				break;
			case 5: last_delete();
				break;
			case 6: specify_delete();
				break;
			case 7: search();
				break;
			case 8: display();
				break;
			case 9: exit(0);
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
		node *ptr;
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
				ptr->prev = nullptr;
				ptr->next = nullptr;
				head = ptr;
			}
			else
			{
				ptr->next = head;
				ptr->prev = nullptr;
				head->prev = ptr;
				head = ptr;
			}
			cout << "Node inserted" << endl;
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
				ptr->prev = nullptr;
				ptr->next = nullptr;
				head = ptr;
			}
			else
			{
				temp = head;
				while(temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = ptr;
				ptr->next = nullptr;
				ptr->prev = temp;
			}
			cout << "Node inserted" << endl;
		}
	}

	void random_insert()
	{
		unsigned val, location;
		node *ptr = new (nothrow) node, *temp;
		if (ptr == nullptr)
		{
			cout << "Memory overflow" << endl;
		}
		else
		{
			cout << "Input the location of Insertion: " << ends;
			cin >> location;
			temp = head;
			for (int i = 0; i < location; ++i)
			{
				if (temp->next == nullptr)
				{
					cout << "Out of Subscript" << ends;
					return ;
				}
				temp = temp->next;
			}
			cout << "Input the value of Insertion: " << ends;
			cin >> val;
			ptr->data = val;
			cout << endl;
			ptr->next = temp->next;
			ptr->prev = temp;
			temp->next = ptr;
			temp->next->prev = ptr;
			cout << "Node inserted" << endl;
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
			if (head == nullptr)
			{
				head = nullptr;
				free(head);
				cout << "Node deleted" << endl;
			}
			else
			{
				ptr = head;
				head = ptr->next;
				head->prev = nullptr;
				free(ptr);
				cout << "Node deleted" << endl;
			}
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
			if (head->next == nullptr)
			{
				head == nullptr;
				free(head);
				cout << "Node deleted" << endl;
			}
			else
			{
				ptr = head;
				while (ptr->next != nullptr)
				{
					ptr = ptr->next;
				}
				ptr->prev->next = nullptr;
				free(ptr);
				cout << "Node deleted" << endl;
			}
		}

	}

	void specify_delete()
	{
		node *ptr, *temp;
		unsigned data;
		if (head == nullptr)
		{
			cout << "Memory Underflow" << endl;
		}
		else
		{
			ptr = head;
			cout << "Input the data after which deletion is performed: " << ends;
			cin >> data;
			while (ptr->data != data)
			{
				ptr = ptr->next;
				if (ptr == nullptr)
				{
					break;
				}
			}
			if (ptr == nullptr)
			{
				cout << "Data not found" << endl;
			}
			else if (ptr->next == nullptr)
			{
				cout << "Can't delete empty object" << endl;
			}
			else if (ptr->next->next == nullptr)
			{
				temp = ptr->next;
				ptr->next = nullptr;
				free(temp);
				cout << "Node deleted " << endl;
			}
			else
			{
				temp = ptr->next;
				ptr->next = temp->next;
				temp->next->prev = ptr;
				free(temp);
				cout << "Node deleted " << endl;
			}
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
		while(temp != nullptr)
		{
			if (temp->data == element)
			{
				cout << "ELement found at " << cnt << endl;
				flag = true;
			}
			temp = temp->next;
			++cnt;
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
			while(temp != nullptr)
			{
				cout << temp->data << ", " << ends;
				temp = temp->next;
			}
		}
	}

