#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *kReverse(Node *head,int  k){                   //   recursive approach
if(head == NULL) {  return NULL ;  }

  // BASE CASE (REVERSE FIRST K-NODES)
  
  Node *next = NULL;
  Node *current = head;
  Node *prev = NULL;
  int count = 0;
  while(next != NULL & count <k) {
    next = current->next;
    current->next = prev;
    
    prev = current;
    current = next;
    
    count++;
  }
  // recursion 
  
  if(next != NULL) {
   head->next = kReverse(next,k);
  }
  
  return prev;
}


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}
