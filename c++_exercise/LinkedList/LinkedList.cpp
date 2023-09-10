// Carson Gedeus, 08/16/2023
// Basic Linked-List implementation in C++

#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	public:
		char *nAme;
		int iD;
		Node* next;

		Node(char* name, int id) {
			this->nAme = name;
			this->iD = id;
		};
};

class LinkedList
{
	private:
		Node* head;

	public:
		LinkedList()
		{
			this->head = NULL;
		}

		// Insert at the head
		void insertAtHead(char* name, int data)
		{
			Node* node = new Node(name, data);
			node->next = head;
			head = node;
		}

		// Insert at the end
		void insertAtEnd(char* name, int data)
		{
			Node* node = new Node(name, data);

			if (head == NULL)
			{
				head = node;
				return;
			}
			else
			{
				Node* move = head;
				while (move->next != NULL)
				{
					move = move->next;
				}
				move->next = node;
			}
		}

		void printMethod(LinkedList linkedList)
		{
			Node* traverse;

			traverse = linkedList.head;
			while (traverse != NULL)
			{
				cout << traverse->nAme << " " << traverse->iD << endl;
				traverse = traverse->next;
			}
		}
};

	int main(void)
	{
		LinkedList linkedList;
		char name[] = "Carson Gedeus";

		linkedList.insertAtEnd(name, 25);
		linkedList.insertAtEnd(name, 10);
		linkedList.insertAtEnd(name, 30);

		linkedList.printMethod(linkedList);

		return 0;
	}