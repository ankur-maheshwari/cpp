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


Node *swapNodes(Node *head, int i, int j){

    if(i == j || head -> next == NULL){
        return head;
    }

    int c = 0;

    Node* p1 = NULL;
    Node* c1 = NULL;
    Node* p2 = NULL;
    Node* c2 = NULL;
    Node* e = NULL;
    Node* r = NULL;
    Node* temp = head;

    if(i == 0 && j == 1){
        e = head -> next -> next;
        c2 = head -> next;
        c1 = head;
        c2 -> next = c1;
        c1 -> next = e;
        head = c2;
        return head;
    }
  
    else if(i == 0){
        while(temp != NULL){
            if(c == j-1){
                c1 = head;
                p2 = temp;
                c2 = temp -> next;
                r = c1 -> next;
                e = c2 -> next;
                break;
            }
            c++;
            temp = temp -> next;
        }
        c2 -> next = r;
        c1 -> next = e;
        p2 -> next = c1;
        return c2;
    }

    else if(max(i,j) - min(i,j) == 1){
        while(temp != NULL){
            if(c == i-1){
                p1 = temp;
                c1 = temp -> next;
                c2 = c1 -> next;
                e = c2 -> next;
                break;
            }
            c++;
            temp = temp -> next;
        }
        c2 -> next = c1;
        c1 -> next = e;
        p1 -> next = c2;
        return head;

    }

    else{
        while(temp != NULL){
            if(c == i-1){
                p1 = temp;
                c1 = temp -> next;
            }		
            else if(c == j-1){
                p2 = temp;
                c2 = temp -> next;
            }
            c++;
            temp = temp -> next;
        }

        e = c2 -> next;
        r = c1 -> next;
        c2 -> next = r;
        c1 -> next = e;
        p2 -> next = c1;
        p1 -> next = c2;
        return head;
    }
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
