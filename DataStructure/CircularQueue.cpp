#include <stdio.h>
#define MAX_QUEUE_SIZE 100002

template <typename T>
class Queue
{
public:
	T data[MAX_QUEUE_SIZE];
	int rear;
	int front;
	int size;

	Queue()
	{
		rear = 0;
		front = 0;
		size = 0;
	}

	void push(T item)
	{
		data[rear] = item;
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		size++;
	}

	T pop()
	{
		T result = data[front];
		size--;
		front = (front + 1) % MAX_QUEUE_SIZE;

		return result;
	}

	bool isEmpty() {return (this->front == this->rear);}
	bool isFull() { return (this->front == (this->rear + 1) % MAX_QUEUE_SIZE); }
};