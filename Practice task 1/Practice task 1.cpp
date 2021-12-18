#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* Next;
	Node* Previous;
};
class Dlist
{
	Node* front;
	Node* rear;
public:
	Dlist()
	{
		front = NULL;
		rear = NULL;
	}
	void insertatfront(Node* N, int val)
	{
		N = new Node();
		if (front == NULL)
		{
			N->data = val;
			N->Next = NULL;
			N->Previous = NULL;
			front = N;
			rear = N;
		}
		else
		{
			N->data = val;
			N->Next = front;
			N->Previous = NULL;
			front->Previous = N;
			front = N;
		}

	}
	void insertatend(Node *N,int val)
	{
		N = new Node();
		if (front == NULL)
		{
			insertatfront(N, val);
		}
		N->data = val;
		N->Next = NULL;
		N->Previous = rear;
		rear->Next = N;
		rear = N;
	}
	void deleteatfront()
	{
		Node* N = front;
		front = front->Next;
		front->Previous = NULL;
		free(N);
	}
	void deleteatend()
	{
		Node* N = rear;
		rear = rear->Previous;
		rear->Next = NULL;
		free(N);
	}
	void display()
	{
		Node* N = front;
		while (N != NULL)
		{
			cout << N->data << "\t";
			N = N->Next;
		}
		cout << endl;
	}

};
int main()
{
	Node* N{};
	Dlist D;
	D.insertatfront(N, 56);
	D.insertatend(N, 67);
	D.insertatfront(N, 33);
	D.insertatend(N, 69);
	D.display();
	D.deleteatfront();
	D.display();
	D.deleteatend();
	D.display();
	D.insertatend(N, 69);
	D.insertatfront(N, 33);
	D.display();
}