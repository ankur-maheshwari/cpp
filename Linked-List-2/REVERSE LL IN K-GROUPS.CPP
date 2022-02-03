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


Node* reverseK(Node* head, int k) {
        
    Node*prv = NULL;
    Node*curr = head;
    Node*next ;
    int count = 0;
    if(head == NULL ) return head;
    while(count < k && curr != NULL )
    {
        next = curr->next;
        curr->next = prv;
        prv = curr;
        curr = next;
        count++;
    }
    if(count != k){
        return reverseK(prv, count);
    }
    head->next = reverseK(curr, k);
    

    return prv;
        
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
		head = reverseK(head, k);
		print(head);
	}
	
	return 0;
}
