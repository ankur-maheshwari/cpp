//bubble sort iterative
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


int length(Node* head){
    int l=0;
    while(head != NULL){
        head = head -> next;
        l++;
    }
    return l;
}
Node *bubbleSort(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    int l = length(head);
    Node *temp = head;
    while(l--){
        temp = head;
        for(int i=0; i<l; i++){
            if(head -> next != NULL){
                if(temp -> data > temp -> next -> data){
                    swap(temp -> data, temp -> next -> data);
                }
                temp = temp -> next;
            }
        }
    }
    return head;
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
