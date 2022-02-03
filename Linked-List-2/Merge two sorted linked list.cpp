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

// ----------- ITERATIVE APPROACH ---------------
Node *merge(Node *l1 , Node *l2) {
Node *p1 = l1;
Node *p2 = l2;
  Node *dummyNode = new Node(-1);
  Node *p3 = dummyNode;
  while(p1 != NULL && p2 != NULL) {
  if(p1->data < p2->data) {
  p3->next = p1;
    p1 = p1->next;
  }
    else {
     p3->next = p2;
      p2 = p2->next;
    }
    p3 = p3->next;
  }
  while(p1 != NULL) {
    p3->next = p1;
    p1 = p1->next;
    p3 = p3->next;
  }
  while(p2 != NULL) {
    p3->next = p2;
    p2 = p2->next;
    p3 = p3->next;
  }
  
  return dummyNode=>next;
}

// -------------- RECURSIVE APPROACH -----------
Node* merge(Node* l1, Node* l2) {
      Node* list1 = l1;
    Node* list2 =l2;
    Node* result = NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val <= list2->val){
            result = list1;
            result->next = merge(list1->next,list2);
        }
        else{
            result = list2;
            result->next = merge(list1,list2->next);
        }
        return result;
    }

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = merge(head1, head2);
		print(head3);
	}
	return 0;
}
