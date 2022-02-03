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



Node *midPoint(Node *head)
{
    Node *temp = head;
    int length = 0;
     while(temp){
		length++;
         temp = temp->next;
    }
    int middle = length/2;
    temp = head;
    while(temp && middle--)
        temp = temp->next;
    return temp;
}

// ----------------------------
// -------- ANOTHER APPROACH FAST AND SLOW -------------

Node *midPoint (Node *head) {                                   // east and best approach
if(head == NULL || head->next == NULL){
  return head;
}
  if(head->next->next == NULL){
    return head->next;
  }
  Node *slow = head;
  Node *fast = head->next;
  while(fast != NULL)
  {
    fast = fast->next;
    if(fast != NULL) {
      fast = fast->next;
    }
    slow = slow->next;
  }
  return slow;
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}
