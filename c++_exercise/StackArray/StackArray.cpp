/*
* Carson Gedeus, 10/29/2023
* Stack implemented using array
*/

#include <iostream>

#define SIZE 10

using namespace std;

class StackArray
{
	public:
		int top = -1;
		int* stack = new int[SIZE];

		bool isEmpty()
		{
			if (top > -1)
			{
				cout << "Not Empty" << endl;
				return false;
			}
			else
			{
				cout << "Empty" << endl;
				return true;
			}
		}

		int* push(int data)
		{
			top++;
			stack[top] = data;

			return stack;
		}

		int* pop()
		{
			int temp = stack[top];

			stack[top] = NULL;
			top--;

			cout << temp << " has been removed." << endl;

			return stack;
		}

		int peek()
		{
			cout << stack[top] << " is at th top." << endl;

			return stack[top];
		}
};

int main(void)
{
	StackArray stackDS;

	int option = 0, data = 0;

	while (option > -1 && option < 5 && stackDS.top <= SIZE)
	{
		cout << "Pick an option. " << endl;
		cout << "1. push(..)" << endl;
		cout << "2. pop()" << endl;
		cout << "3. peek()" << endl;
		cout << "4. isEmpty()" << endl;
		cout << "5. Exit" << endl << endl;
		cin >> option;

		switch (option)
		{
			case 1:
				cout << "Enter data to be pushed." << endl;
				cin >> data;
				stackDS.push(data);
				break;
			case 2:
				stackDS.pop();
				break;
			case 3:
				stackDS.peek();
				break;
			case 4:
				stackDS.isEmpty();
				break;
			default:
				break;
		}
	}

	return 0;
}