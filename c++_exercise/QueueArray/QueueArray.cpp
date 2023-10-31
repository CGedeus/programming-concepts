/*
* Carson Gedeus, 10/30/2023
* Queue implementation using arrays
*/

#define SIZE 10

#include <iostream>

using namespace std;

class QueueArray
{
	public:
		int begin = 0;
		int added = -1;
		int* queue = new int[10];

		int* push(int data)
		{
			added++;
			queue[added] = data;

			return queue;
		}

		int* pop()
		{
			int i = 0;
			queue[begin] = NULL;

			/** for (int* ptr = &queue[0]; ptr != &queue[sizeof(queue)]; ++ptr) */
			for (int i = 0; i < (added + 1); i++)
			{
				queue[i] = queue[i + 1];
				i++;
			}

			return queue;
		}

		int peek()
		{
			cout << "Beginning of queue is " << queue[begin] << endl;
			return queue[begin];
		}

		bool isEmpty()
		{
			if (queue[begin] == NULL)
			{
				cout << "queue is empty." << endl;
				return true;
			}
			else
			{
				return false;
			}
		}
};

int main(void)
{
	QueueArray queueDS;

	queueDS.push(23);
	queueDS.push(54);
	queueDS.push(12);

	queueDS.peek();

	queueDS.pop();
	queueDS.pop();

	queueDS.isEmpty();

	return 0;
}