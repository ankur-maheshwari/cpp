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

Node *skipMdeleteN(Node *head, int M, int N){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* newHead = NULL;
    Node* newTail = NULL;

    int skipped = N, inserted = 0;
    bool skipDone = false, insertDone = false;

    while(head != NULL){
        Node* newNode = new Node(head -> data);
        if(inserted < M && insertDone == false){
            if(newHead == NULL){
                newHead = newNode;
                newTail = newNode;
                inserted++;
            }
            else{
                inserted++;
                newTail -> next = newNode;
                newTail = newNode;
            }
        }
        else if(inserted == M && insertDone == false){
            inserted = 0;
            insertDone = true;
            skipDone = false;
            continue;
        }
        else if(skipped == 0 && insertDone == true){
            skipped = N;
            skipDone = true;
            insertDone = false;
            continue;
        }
        else if(skipped > 0 && skipDone == false && head != NULL){
            skipped--;
        }

        head = head -> next;
    }
    return newHead;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
